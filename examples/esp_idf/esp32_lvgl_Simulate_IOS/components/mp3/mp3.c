#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "mp3.h"
#include "dr_flac.h"
#include "dr_mp3.h"
#include "dr_wav.h"
#include "volume.h"
#include "esp_timer.h"
#include "ui_helpers.h"
#include "freertos/semphr.h"
#define MP3_BUFFER_SIZE (2048)
#define FLAC_BUFFER_SIZE (2048)
#define WAV_BUFFER_SIZE (2048)
extern i2s_chan_handle_t tx_chan; // I2S tx channel handler
static const char *TAG = "歌曲";
volatile bool change_track = false; // 定义一个全局变量作为播放控制信号
volatile bool pauseflag = false;    // 定义一个全局变量作为播放控制信号
volatile bool chanflag = false;
volatile bool seekpoint = false;
volatile bool musicloop = true; // 循环播放标志
char musicplaytime[10] = "00:00";
volatile uint64_t playsilder = 0;
uint16_t sampleRate = 0;
uint64_t pcmfram = 0;
#define LINE_BUF_SIZE 64        // 每行歌词字符数
#define LYRICS_BUFFER_SIZE 4096 // 歌词最大字符数
// #define SEEKOPEN    //开启MP3寻道功能，开启后打开MP3时等待时间长，跳转快。不开启打开时直接打开，跳转慢。
i2s_std_config_t std_cfg = {
    .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(44100),
    .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO),
    .gpio_cfg = {
        .mclk = I2S_GPIO_UNUSED, // some codecs may require mclk signal, this example doesn't need it
        .bclk = MP3_STD_BCLK_IO1,
        .ws = MP3_STD_WS_IO1,
        .dout = MP3_STD_DOUT_IO1,
        .din = I2S_GPIO_UNUSED, // In duplex mode, bind output and input to a same gpio can loopback internally
        .invert_flags = {
            .mclk_inv = false,
            .bclk_inv = false,
            .ws_inv = false,
        },
    },
};

typedef struct
{
    int minute;
    int second;
    int millisecond;
    char text[64]; // 假设每行歌词不会超过128字符
} LyricLine;

// 解析单行LRC歌词
bool parse_lrc_line(const char *line, LyricLine *lyric)
{
    lyric->minute = lyric->second = lyric->millisecond = -1;

    if (line[0] == '[' && strchr(line, ']') != NULL)
    {
        const char *time_str = line + 1;
        const char *text_start = strchr(line, ']') + 1;
        const char *text_end = strchr(text_start, '\n');

        // 查找换行符，如果有则记录它的位置
        if (text_end != NULL)
        {
            // 创建一个新的缓冲区用于存储去除换行符的文本
            size_t text_len = text_end - text_start;
            char clean_text[text_len]; // 注意留出一个空位放置终止符'\0'

            // 复制从text_start开始到text_end前的文字
            strncpy(clean_text, text_start, text_len);
            clean_text[text_len] = '\0'; // 添加终止符

            // 将干净的文本复制到lyric->text
            snprintf(lyric->text, sizeof(lyric->text), "%s\n", clean_text);
        }
        else
        {
            // 如果没有找到换行符，直接复制整个文本
            snprintf(lyric->text, sizeof(lyric->text), "%s", text_start);
        }

        sscanf(time_str, "%d:%d.%d", &lyric->minute, &lyric->second, &lyric->millisecond);
        return true;
    }
    return false;
}
// 读取并解析LRC文件
void read_and_parse_lrc(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "打开歌词文件失败 %s", filename);
        return;
    }
    char accumulated_lyrics[LYRICS_BUFFER_SIZE] = {0};
    size_t len = 0;
    char line_buf[LINE_BUF_SIZE]; // 声明line_buf缓冲区
    LyricLine lyric;
    while (fgets(line_buf, sizeof(line_buf), f))
    {
        if (parse_lrc_line(line_buf, &lyric))
        {
            char lrc_text[128];
            snprintf(lrc_text, sizeof(lrc_text), "%s", lyric.text);
            
            // 计算剩余空间并确保不溢出
            if (len + strlen(lrc_text) + 1 >= LYRICS_BUFFER_SIZE)
            {
                ESP_LOGE(TAG, "歌词缓存区已满，无法继续添加歌词");
                break;
            }

            strcat(accumulated_lyrics, lrc_text);
            len += strlen(lrc_text);
        }
    }

    fclose(f);
    xSemaphoreTake(lvglmutex, portMAX_DELAY);
    lv_roller_set_options(ui_musiclyricslabel,
                          accumulated_lyrics,
                          LV_ROLLER_MODE_NORMAL);
    xSemaphoreGive(lvglmutex);
    ESP_LOGE(TAG, "%s", accumulated_lyrics);
}

uint32_t calculateFileSize(const char *filename)
{
    FILE *file = fopen(filename, "rb"); // 以二进制只读方式打开文件
    uint32_t size = -1;

    if (file != NULL)
    {
        if (fseek(file, 0, SEEK_END) == 0)
        {                             // 定位到文件末尾
            size = ftell(file);       // 获取当前位置，即文件大小
            fseek(file, 0, SEEK_SET); // 将文件指针重新定位到文件开头
        }
        fclose(file); // 关闭文件
    }

    return size;
}

DRMP3_API drmp3_bool32 calculate_seek_points(drmp3 *pMP3, drmp3_uint32 *pSeekPointCount, drmp3_seek_point *pSeekPoints, drmp3_uint64 totalMP3FrameCount, drmp3_uint64 totalPCMFrameCount)
{
    drmp3_uint32 seekPointCount;
    drmp3_uint64 currentPCMFrame;

    if (pMP3 == NULL || pSeekPointCount == NULL || pSeekPoints == NULL)
    {
        return DRMP3_FALSE; /* 无效的参数. */
    }

    seekPointCount = *pSeekPointCount;
    if (seekPointCount == 0)
    {
        return DRMP3_FALSE; /* 客户没有要求任何搜索点。认为这是无效的参数，因为客户端可能没有打算这样做。*/
    }

    /* 在计算查找点后，我们需要返回当前样本，因此我们需要继续获取顶部的当前位置. */
    currentPCMFrame = pMP3->currentPCMFrame;

    /* 如果少于 DRMP3_SEEK_LEADING_MP3_FRAMES+1 帧，我们只报告 1 个寻道点，这将是流的开始。 */
    if (totalMP3FrameCount < DRMP3_SEEK_LEADING_MP3_FRAMES + 1)
    {
        seekPointCount = 1;
        pSeekPoints[0].seekPosInBytes = 0;
        pSeekPoints[0].pcmFrameIndex = 0;
        pSeekPoints[0].mp3FramesToDiscard = 0;
        pSeekPoints[0].pcmFramesToDiscard = 0;
    }
    else
    {
        drmp3_uint64 pcmFramesBetweenSeekPoints;
        drmp3__seeking_mp3_frame_info mp3FrameInfo[DRMP3_SEEK_LEADING_MP3_FRAMES + 1];
        drmp3_uint64 runningPCMFrameCount = 0;
        float runningPCMFrameCountFractionalPart = 0;
        drmp3_uint64 nextTargetPCMFrame;
        drmp3_uint32 iMP3Frame;
        drmp3_uint32 iSeekPoint;

        if (seekPointCount > totalMP3FrameCount - 1)
        {
            seekPointCount = (drmp3_uint32)totalMP3FrameCount - 1;
        }

        pcmFramesBetweenSeekPoints = totalPCMFrameCount / (seekPointCount + 1);

        /*
        这是我们实际计算寻道点的地方。我们需要从移动流的开头开始。然后，我们枚举每个
        MP3 框架。
        */
        if (!drmp3_seek_to_start_of_stream(pMP3))
        {
            return DRMP3_FALSE;
        }

        /*
        我们需要缓存之前 MP3 帧的字节位置。当一个新的 MP3 帧被迭代时，我们循环其中的字节位置
        数组。此数组中第一项中的值是将在下一个查找点中报告的字节位置。
        */

        /* 我们需要初始化前导 MP3 帧的 MP3 字节位置数组。*/
        for (iMP3Frame = 0; iMP3Frame < DRMP3_SEEK_LEADING_MP3_FRAMES + 1; ++iMP3Frame)
        {
            drmp3_uint32 pcmFramesInCurrentMP3FrameIn;

            /* 下一帧的字节位置将是流的光标位置，减去缓冲区中的任何内容。 */
            DRMP3_ASSERT(pMP3->streamCursor >= pMP3->dataSize);
            mp3FrameInfo[iMP3Frame].bytePos = pMP3->streamCursor - pMP3->dataSize;
            mp3FrameInfo[iMP3Frame].pcmFrameIndex = runningPCMFrameCount;

            /* 我们需要获取有关此框架的信息，以便知道它包含多少样本. */
            pcmFramesInCurrentMP3FrameIn = drmp3_decode_next_frame_ex(pMP3, NULL);
            if (pcmFramesInCurrentMP3FrameIn == 0)
            {
                return DRMP3_FALSE; /* 这绝不应该发生. */
            }

            drmp3__accumulate_running_pcm_frame_count(pMP3, pcmFramesInCurrentMP3FrameIn, &runningPCMFrameCount, &runningPCMFrameCountFractionalPart);
        }

        /*
        至此，我们将提取前导 MP3 帧的字节位置。现在，我们可以开始遍历每个寻道点
        计算它们。
        */
        nextTargetPCMFrame = 0;
        for (iSeekPoint = 0; iSeekPoint < seekPointCount; ++iSeekPoint)
        {
            nextTargetPCMFrame += pcmFramesBetweenSeekPoints;

            for (;;)
            {
                if (nextTargetPCMFrame < runningPCMFrameCount)
                {
                    /* 下一个寻道点位于当前 MP3 帧中。 */
                    pSeekPoints[iSeekPoint].seekPosInBytes = mp3FrameInfo[0].bytePos;
                    pSeekPoints[iSeekPoint].pcmFrameIndex = nextTargetPCMFrame;
                    pSeekPoints[iSeekPoint].mp3FramesToDiscard = DRMP3_SEEK_LEADING_MP3_FRAMES;
                    pSeekPoints[iSeekPoint].pcmFramesToDiscard = (drmp3_uint16)(nextTargetPCMFrame - mp3FrameInfo[DRMP3_SEEK_LEADING_MP3_FRAMES - 1].pcmFrameIndex);
                    break;
                }
                else
                {
                    size_t i;
                    drmp3_uint32 pcmFramesInCurrentMP3FrameIn;

                    /*
                   下一个搜索点不在当前 MP3 帧中，因此请继续下一个查找点。首先要做的是循环缓存
                    MP3 帧信息。
                    */
                    for (i = 0; i < DRMP3_COUNTOF(mp3FrameInfo) - 1; ++i)
                    {
                        mp3FrameInfo[i] = mp3FrameInfo[i + 1];
                    }

                    /* 缓存以前的 MP3 帧信息. */
                    mp3FrameInfo[DRMP3_COUNTOF(mp3FrameInfo) - 1].bytePos = pMP3->streamCursor - pMP3->dataSize;
                    mp3FrameInfo[DRMP3_COUNTOF(mp3FrameInfo) - 1].pcmFrameIndex = runningPCMFrameCount;

                    /*
                    转到下一个 MP3 帧。这不应该失败，但为了以防万一，我们只需设置寻道点并中断。如果发生这种情况，它
                    应该只在最后一个寻道点这样做。
                    */
                    pcmFramesInCurrentMP3FrameIn = drmp3_decode_next_frame_ex(pMP3, NULL);
                    if (pcmFramesInCurrentMP3FrameIn == 0)
                    {
                        pSeekPoints[iSeekPoint].seekPosInBytes = mp3FrameInfo[0].bytePos;
                        pSeekPoints[iSeekPoint].pcmFrameIndex = nextTargetPCMFrame;
                        pSeekPoints[iSeekPoint].mp3FramesToDiscard = DRMP3_SEEK_LEADING_MP3_FRAMES;
                        pSeekPoints[iSeekPoint].pcmFramesToDiscard = (drmp3_uint16)(nextTargetPCMFrame - mp3FrameInfo[DRMP3_SEEK_LEADING_MP3_FRAMES - 1].pcmFrameIndex);
                        break;
                    }

                    drmp3__accumulate_running_pcm_frame_count(pMP3, pcmFramesInCurrentMP3FrameIn, &runningPCMFrameCount, &runningPCMFrameCountFractionalPart);
                }
            }
        }

        /* 最后，我们需要回到原来的位置. */
        if (!drmp3_seek_to_start_of_stream(pMP3))
        {
            return DRMP3_FALSE;
        }
        if (!drmp3_seek_to_pcm_frame(pMP3, currentPCMFrame))
        {
            return DRMP3_FALSE;
        }
    }

    *pSeekPointCount = seekPointCount;
    return DRMP3_TRUE;
}

void audio_write_task(void *args)
{
    musicloop = true;
    change_track = false;
    strcpy(musicplaytime, "00:00");
    const char *name = (char *)args;
    ESP_LOGW(TAG, "MP3歌名:%s", name);
    char file_MP3[256] = MOUNT_POINT "/music/";
    ESP_LOGW(TAG, "SD卡目录:%s/music/", MOUNT_POINT);
    char *play_filename = strcat(file_MP3, name);
    ESP_LOGW(TAG, "歌曲路径:%s", play_filename);
    const char *audiofile = strrchr(play_filename, '.');
    // 读取歌词文件
    // 如果找到了后缀，则提取文件名
    if (audiofile != NULL)
    {
        size_t len = audiofile - play_filename; // 计算文件名长度
        char lrcfile[len + 1];                  // 创建足够大的缓冲区存放文件名

        // 复制文件名
        strncpy(lrcfile, play_filename, len);
        lrcfile[len] = '\0'; // 添加结束符

        // 创建一个新的字符串用于拼接".lrc"
        char audiofile_lrc[strlen(lrcfile) + strlen(".lrc") + 1];
        strcpy(audiofile_lrc, lrcfile);
        strcat(audiofile_lrc, ".lrc");

        read_and_parse_lrc(audiofile_lrc);
    }

    int32_t flsize = calculateFileSize(play_filename);
    ESP_LOGW(TAG, "文件大小:%ldKb", flsize / 1024);

    size_t i2s_bytes_written;
    gpio_set_direction(GPIO_NUM_9, GPIO_MODE_OUTPUT); // 功放开关，1为高电平，0为低电平);
    gpio_set_level(GPIO_NUM_9, 1);                    // 打开功放
    ESP_LOGI(TAG, "打开功放");
    char timeStr[10];
    if (strcasecmp(audiofile, ".mp3") == 0)
    {
        drmp3 mp3;

        if (!drmp3_init_file(&mp3, play_filename, NULL))
        {
            ESP_LOGW(TAG, "%s 文件不存在！", play_filename);
            vTaskDeleteWithCaps(NULL);
        }
        drmp3_uint32 channels = mp3.channels;
        sampleRate = mp3.sampleRate;
        drmp3_uint32 bitrate_kbps = mp3.mp3Framebitrate_kbps; // 获取比特率
        drmp3_uint64 framerederightnow = MP3_BUFFER_SIZE / 2; // MP3_BUFFER_SIZE的一半
        ESP_LOGI(TAG, "通道数: %" PRIu16 "", channels);
        ESP_LOGI(TAG, "采样率：%" PRIu16 "", sampleRate);
        ESP_LOGI(TAG, "比特率：%" PRIu16 "", bitrate_kbps);

        uint32_t totaltime = flsize * 8 / bitrate_kbps / 1000; // 计算MP3总时长秒
        drmp3_uint16 endmin = totaltime / 60;
        drmp3_uint16 endsec = totaltime % 60;
        sprintf(timeStr, "%02d:%02d", endmin, endsec);
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_slider_set_range(ui_musicslider, 0, totaltime); // 设置进度条为总秒数
        lv_label_set_text(ui_musicendtimelabel, timeStr);  // 设置显示MP3总时长
        lv_label_set_text_fmt(ui_musicart, "比特率:%uKbps", bitrate_kbps);
        xSemaphoreGive(lvglmutex);
#if defined(SEEKOPEN)
        drmp3_uint32 seekPointCount = 100; // 寻道点数量
        drmp3_seek_point *seekPoints = NULL;
        drmp3_uint64 total_pcm_frams = totaltime * sampleRate; // 计算PCM总帧数
        drmp3_uint64 total_mp3_frams = total_pcm_frams / 1152; // 计算MP3总帧数
        ESP_LOGI(TAG, "PCM总帧数: %" PRIu64 "", total_pcm_frams);
        ESP_LOGI(TAG, "MP3总帧数: %" PRIu64 "", total_mp3_frams);
        // 分配一个初始的缓冲区来尝试计算跳转点（这里假设一个初始大小）
        const size_t initialSeekPointBufferSize = 128; // 假设值，可以根据实际情况调整
        seekPoints = (drmp3_seek_point *)malloc(initialSeekPointBufferSize * sizeof(drmp3_seek_point));
        if (!calculate_seek_points(&mp3, &seekPointCount, seekPoints, total_mp3_frams, total_pcm_frams))
        {
            // 如果分配的缓冲区太小，库可能不会修改 seekPointCount 或填充任何数据
            // 检查错误代码或文档以确定如何处理这种情况
            // 可能需要重新分配更大的缓冲区再试一次
            free(seekPoints);
            seekPoints = NULL;
            ESP_LOGE(TAG, "内存分配失败，缓冲区太小");
            // 根据 drmp3_calculate_seek_points 的返回和文档决定是否尝试增大缓冲区
            // 或者检查文件是否支持查找点等
        }
        else if (seekPointCount == 0)
        {
            // 虽然分配成功但计算出的 seekPointCount 为0
            // 这可能意味着 MP3 文件不包含可搜索的帧信息或格式不受支持
            ESP_LOGI(TAG, "MP3 文件不包含有效的查找点信息");
            free(seekPoints);
            seekPoints = NULL;
        }
        if (seekPoints != NULL)
        {
            drmp3_bind_seek_table(&mp3, seekPointCount, seekPoints);
            ESP_LOGI(TAG, "跳转点数: %" PRIu16 "", mp3.seekPointCount);
        }
#endif
        drmp3_int16 *mp3_bytes = malloc(MP3_BUFFER_SIZE * channels * sizeof(drmp3_int16));
        assert(mp3_bytes != NULL);
        // 分块解码   解码逻辑
        if (chanflag)
        {
            ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
            ESP_LOGI(TAG, "关闭I2S通道！");
        }
        std_cfg.slot_cfg.slot_mode = channels; // 改变单声道
        i2s_channel_reconfig_std_slot(tx_chan, &std_cfg.slot_cfg);
        std_cfg.clk_cfg.sample_rate_hz = sampleRate;
        i2s_channel_reconfig_std_clock(tx_chan, &std_cfg.clk_cfg);
        ESP_LOGI(TAG, "打开I2S通道！");
        ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
        chanflag = true;
        while (drmp3_read_pcm_frames_s16(&mp3, framerederightnow, mp3_bytes) && !change_track)
        {
            ESP_ERROR_CHECK(i2s_channel_write(tx_chan, mp3_bytes, framerederightnow * channels * sizeof(drmp3_int16), &i2s_bytes_written, pdMS_TO_TICKS(500)));
            playsilder = mp3.currentPCMFrame / sampleRate;
            if (gpio_get_level(SDCARD_PIN_CD) == 1) // 当检测到SD卡被拔出
            {
                musicloop = false;
                xSemaphoreTake(lvglmutex, portMAX_DELAY);
                lv_obj_clean(ui_musiclist);
                xSemaphoreGive(lvglmutex);
                break;
            }

            if (seekpoint)
            {
                drmp3_seek_to_pcm_frame(&mp3, pcmfram);
                seekpoint = false;
            }
            while (pauseflag)
            {
                vTaskDelay(1 / portTICK_PERIOD_MS);
            }
        }
        drmp3_uninit(&mp3);
// 不要忘记在完成时释放 seekPoints
#if defined SEEKOPEN
        free(seekPoints);
#endif
        free(mp3_bytes);
    }
    else if (strcasecmp(audiofile, ".flac") == 0)
    {
        drflac *flac = drflac_open_file(play_filename, NULL);
        if (flac == NULL)
        {
            ESP_LOGW(TAG, "%s 文件不存在！", play_filename);
            vTaskDeleteWithCaps(NULL);
        }
        drflac_int16 *flac_bytes = malloc(FLAC_BUFFER_SIZE * flac->channels * sizeof(drflac_int16));
        assert(flac_bytes != NULL);
        drflac_uint16 bitsper = flac->bitsPerSample;
        drflac_uint16 channels = flac->channels;
        sampleRate = flac->sampleRate;
        drflac_uint64 allframes = flac->totalPCMFrameCount;
        drflac_uint64 framerederightnow = FLAC_BUFFER_SIZE / channels; // FLAC_BUFFER_SIZE的一半
        ESP_LOGI(TAG, "位宽: %" PRIu16 "", bitsper);
        ESP_LOGI(TAG, "通道数: %" PRIu16 "", channels);
        ESP_LOGI(TAG, "采样率：%" PRIu16 "", sampleRate);
        ESP_LOGI(TAG, "所有PCM帧数：%" PRIu64 "", allframes);
        uint32_t totaltime = allframes / sampleRate; // 计算flac总时长秒
        drflac_uint16 endmin = totaltime / 60;
        drflac_uint16 endsec = totaltime % 60;
        sprintf(timeStr, "%02d:%02d", endmin, endsec);
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_slider_set_range(ui_musicslider, 0, totaltime); // 设置进度条为总秒数
        lv_label_set_text(ui_musicendtimelabel, timeStr);  // 设置显示MP3总时长
        lv_label_set_text_fmt(ui_musicart, "采样率:%dHz", sampleRate);
        xSemaphoreGive(lvglmutex);
        // 分块解码   解码逻辑
        if (chanflag)
        {
            ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
            ESP_LOGI(TAG, "关闭I2S通道！");
        }
        std_cfg.slot_cfg.slot_mode = channels; // 改变单声道
        i2s_channel_reconfig_std_slot(tx_chan, &std_cfg.slot_cfg);
        std_cfg.clk_cfg.sample_rate_hz = sampleRate;
        i2s_channel_reconfig_std_clock(tx_chan, &std_cfg.clk_cfg);

        ESP_LOGI(TAG, "打开I2S通道！");
        ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
        chanflag = true;

        while (drflac_read_pcm_frames_s16(flac, framerederightnow, flac_bytes) && !change_track)
        {
            ESP_ERROR_CHECK(i2s_channel_write(tx_chan, flac_bytes, framerederightnow * flac->channels * sizeof(drflac_int16), &i2s_bytes_written, pdMS_TO_TICKS(1000)));
            playsilder = flac->currentPCMFrame / sampleRate;

            if (gpio_get_level(SDCARD_PIN_CD) == 1) // 当检测到SD卡被拔出
            {
                musicloop = false;
                xSemaphoreTake(lvglmutex, portMAX_DELAY);
                lv_obj_clean(ui_musiclist);
                xSemaphoreGive(lvglmutex);
                break;
            }
            if (seekpoint)
            {
                drflac_seek_to_pcm_frame(flac, pcmfram);
                seekpoint = false;
            }
            while (pauseflag)
            {
                vTaskDelay(1 / portTICK_PERIOD_MS);
            }
        }
        drflac_free(flac, NULL);
        free(flac_bytes);
    }
    else if (strcasecmp(audiofile, ".wav") == 0)
    {
        drwav wav;
        if (!drwav_init_file(&wav, play_filename, NULL))
        {
            ESP_LOGW(TAG, "%s 文件不存在！", play_filename);
            vTaskDeleteWithCaps(NULL);
        }
        drwav_int16 *wav_bytes = malloc(WAV_BUFFER_SIZE * wav.channels * sizeof(drwav_int16));
        /* 打开WAV文件 */
        ESP_LOGI(TAG, "播放文件 %s", play_filename);
        /* 读取 WAV 头文件 */
        drwav_uint16 bitsper = wav.bitsPerSample;
        drwav_uint16 channels = wav.channels;
        sampleRate = wav.sampleRate;
        drwav_uint64 allframes = wav.totalPCMFrameCount;
        ESP_LOGI(TAG, "所有PCM帧数: %" PRIu64 "", allframes);
        ESP_LOGI(TAG, "通道数: %" PRIu16 "", channels);
        ESP_LOGI(TAG, "每个样本的位数: %" PRIu16 "", bitsper);
        ESP_LOGI(TAG, "采样率: %" PRIu16 "", sampleRate);
        ESP_LOGI(TAG, "数据大小: %" PRIu64 "", wav.dataChunkDataSize);

        uint32_t totaltime = allframes / sampleRate; // 计算wav总时长秒
        drwav_uint16 endmin = totaltime / 60;
        drwav_uint16 endsec = totaltime % 60;
        sprintf(timeStr, "%02d:%02d", endmin, endsec);
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_slider_set_range(ui_musicslider, 0, totaltime); // 设置进度条为总秒数
        lv_label_set_text(ui_musicendtimelabel, timeStr);  // 设置显示WAV总时长
        lv_label_set_text_fmt(ui_musicart, "采样率:%dHz", sampleRate);
        xSemaphoreGive(lvglmutex);

        // 分块解码   解码逻辑
        if (chanflag)
        {
            ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
            ESP_LOGI(TAG, "关闭I2S通道！");
        }
        std_cfg.slot_cfg.slot_mode = channels; // 改变声道
        // std_cfg.slot_cfg.data_bit_width = wav.bitsPerSample; // 改变每个样本的位数
        i2s_channel_reconfig_std_slot(tx_chan, &std_cfg.slot_cfg);
        std_cfg.clk_cfg.sample_rate_hz = sampleRate; // 改变采样率
        i2s_channel_reconfig_std_clock(tx_chan, &std_cfg.clk_cfg);
        ESP_LOGI(TAG, "打开i2s通道！");
        ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
        chanflag = true;
        size_t framerederightnow = WAV_BUFFER_SIZE / channels; // FLAC_BUFFER_SIZE的一半
        while (drwav_read_raw(&wav, framerederightnow, wav_bytes) && !change_track)
        {
            ESP_ERROR_CHECK(i2s_channel_write(tx_chan, wav_bytes, framerederightnow, &i2s_bytes_written, pdMS_TO_TICKS(500)));
            playsilder = wav.readCursorInPCMFrames / sampleRate;

            if (gpio_get_level(SDCARD_PIN_CD) == 1) // 当检测到SD卡被拔出
            {
                musicloop = false;
                xSemaphoreTake(lvglmutex, portMAX_DELAY);
                lv_obj_clean(ui_musiclist);
                xSemaphoreGive(lvglmutex);
                break;
            }
            if (seekpoint)
            {
                drwav_seek_to_pcm_frame(&wav, pcmfram);
                seekpoint = false;
            }
            while (pauseflag)
            {
                vTaskDelay(1 / portTICK_PERIOD_MS);
            }
        }
        drwav_uninit(&wav);
        free(wav_bytes);
    }
    if (chanflag)
    {
        ESP_LOGI(TAG, "停止！关闭i2s通道！");
        ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
        chanflag = false;
    }
    gpio_set_level(GPIO_NUM_38, 0); // 关闭功放
    ESP_LOGI(TAG, "关闭功放！");
    xSemaphoreTake(lvglmutex, portMAX_DELAY);
    _ui_state_modify(ui_musicplaybtn, LV_STATE_CHECKED, _UI_MODIFY_FLAG_REMOVE);        // 改变按钮为停止状态
    _ui_checked_set_text_value(ui_musicplaylabel, ui_musicplaybtn, "", LV_SYMBOL_PLAY); // 改变按钮显示播放字符
    if (musicloop)                                                                      // 循环播放，发送按下下一首按钮事件。
    {
        lv_event_send(ui_musicright, LV_EVENT_CLICKED, NULL);
    }
    xSemaphoreGive(lvglmutex);
    vTaskDeleteWithCaps(NULL);
}
void stop_track(void)
{
    musicloop = false;
    change_track = true; // 设置播放控制信号以停止当前播放
    ESP_LOGI(TAG, "change_track信号true");
    pauseflag = false;
    ESP_LOGI(TAG, "pauseflag信号false");
}

void switch_track(void *new_track)
{
    musicloop = false;
    change_track = true; // 设置播放控制信号以停止当前播放
    ESP_LOGI(TAG, "change_track信号true");
    pauseflag = false;
    ESP_LOGI(TAG, "pauseflag信号false");
    char *name = (char *)new_track;
    // 等待当前播放自然结束或强制停止当前播放的其他逻辑
    vTaskDelay(200 / portTICK_PERIOD_MS);
    xTaskCreateWithCaps(audio_write_task, "audio_task", 1024 * 36, name, 20, NULL, MALLOC_CAP_SPIRAM); // 开始播放新歌曲
    xSemaphoreTake(lvglmutex, portMAX_DELAY);
    _ui_state_modify(ui_musicplaybtn, LV_STATE_CHECKED, _UI_MODIFY_FLAG_ADD);            // 改变按钮为播放状态
    _ui_checked_set_text_value(ui_musicplaylabel, ui_musicplaybtn, LV_SYMBOL_PAUSE, ""); // 改变按钮显示暂停字符
    xSemaphoreGive(lvglmutex);
    ESP_LOGI(TAG, "切换歌曲：%s", name);
    vTaskDelete(NULL);
}
void musicpause(void)
{
    pauseflag = true;

    vTaskDelay(20 / portTICK_PERIOD_MS);
    if (chanflag)
    {
        ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
        chanflag = false;
        ESP_LOGI(TAG, "暂停！关闭i2s通道");
    }
}
void musicstart(void)
{
    pauseflag = false;

    vTaskDelay(20 / portTICK_PERIOD_MS);
    if (!chanflag)
    {
        ESP_ERROR_CHECK(i2s_channel_enable(tx_chan));
        chanflag = true;
        ESP_LOGI(TAG, "播放！打开i2s通道");
    }
}
void start_track(void *new_track)
{
    char *name = (char *)new_track;
    if (xTaskGetHandle("audio_task") == NULL) // 设置播放控制信号以停止当前播放
    {
        change_track = true; // 设置播放控制信号以停止当前播放
        vTaskDelay(80 / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "第一次播放，启动播放任务！");
        // 开始播放新歌曲
        xTaskCreateWithCaps(audio_write_task, "audio_task", 1024 * 36, name, 20, NULL, MALLOC_CAP_SPIRAM);
    }
    else
    {
        musicstart();
    }
    vTaskDelete(NULL);
}