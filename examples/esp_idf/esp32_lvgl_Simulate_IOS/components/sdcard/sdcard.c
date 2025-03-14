#include "sdcard.h"
#include "lvgl.h"
sdmmc_card_t *card;
static const char *TAG = "SD卡";
void cardinit(void)
{
    esp_err_t ret;

    // Options for mounting the filesystem.
    // If format_if_mount_failed is set to true, SD card will be partitioned and
    // formatted in case when mounting fails.
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {

        .format_if_mount_failed = false,
        .max_files = 100, // 打开文件的最大数量
        .allocation_unit_size = 4 * 1024};
    // sdmmc_card_t *card;
    const char mount_point[] = MOUNT_POINT;
    ESP_LOGI(TAG, "初始化 SD 卡");

    // Use settings defined above to initialize SD card and mount FAT filesystem.
    // Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
    // Please check its source code and implement error recovery when developing
    // production applications.

    ESP_LOGI(TAG, "使用 SDMMC 外设");
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
    host.max_freq_khz = SDMMC_FREQ_HIGHSPEED;
    ;
    // This initializes the slot without card detect (CD) and write protect (WP) signals.
    // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
    slot_config.cd = SDCARD_PIN_CD,
    // Set bus width to use:
        slot_config.width = 4;
    // On chips where the GPIOs used for SD card can be configured, set them in
    // the slot_config structure:
    slot_config.clk = SDCARD_PIN_CLK;
    slot_config.cmd = SDCARD_PIN_CMD;
    slot_config.d0 = SDCARD_PIN_D0;
    slot_config.d1 = SDCARD_PIN_D1;
    slot_config.d2 = SDCARD_PIN_D2;
    slot_config.d3 = SDCARD_PIN_D3;
    // Enable internal pullups on enabled pins. The internal pullups
    // are insufficient however, please make sure 10k external pullups are
    // connected on the bus. This is for debug / example purpose only.
    slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

    ESP_LOGI(TAG, "挂载文件系统");
    ret = esp_vfs_fat_sdmmc_mount(mount_point, &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            ESP_LOGE(TAG, "挂载文件系统失败。 "
                          "如果要格式化卡，请设置EXAMPLE_FORMAT_IF_MOUNT_FAILED菜单配置选项。");
        }
        else
        {
            ESP_LOGE(TAG, "初始化卡失败 (%s). "
                          "确保 SD 卡线具有上拉电阻。",
                     esp_err_to_name(ret));
        }
        return;
    }
    ESP_LOGI(TAG, "文件系统挂载");

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);
}

void sdlist_timer_cb(lv_timer_t *timer)
{
    lv_fs_stdio_init();
    lv_fs_dir_t dir;
    lv_fs_res_t res = lv_fs_dir_open(&dir, "S:/music/");
    if (res != LV_FS_RES_OK)
        ESP_LOGI(TAG, "打开文件目录失败！");
    ESP_LOGI(TAG, "开始刷新文件列表");
    lv_obj_clean(ui_musiclist);
    ESP_LOGI(TAG, "已清空文件列表");
    char fn[256];
    int i = 1;
    int count = 100;
    lv_obj_t *ui_musiclistname[count];
    ESP_LOGI(TAG, "已创建musiclistname对象");
    lv_obj_t *ui_musicnames[count];
    ESP_LOGI(TAG, "已创建ui_musicnames对象");
    while (1)
    {
        res = lv_fs_dir_read(&dir, fn);
        if (res != LV_FS_RES_OK)
        {
            ESP_LOGI(TAG, "打开文件目录失败！");
            break;
        }

        /*fn is empty, if not more files to read*/
        if (strlen(fn) == 0)
        {
            break;
        }
        const char *audiofile = strrchr(fn, '.');

        ESP_LOGI(TAG, "%s", fn);

        if (audiofile != NULL)
        {
            if (strcasecmp(audiofile, ".mp3") == 0 || strcasecmp(audiofile, ".wav") == 0 || strcasecmp(audiofile, ".flac") == 0)
            {
                ui_musiclistname[i] = lv_obj_create(ui_musiclist);
                lv_obj_set_width(ui_musiclistname[i], 300);
                lv_obj_set_height(ui_musiclistname[i], 30);
                lv_obj_set_align(ui_musiclistname[i], LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_musiclistname[i], LV_OBJ_FLAG_CHECKABLE);    /// Flags
                lv_obj_clear_flag(ui_musiclistname[i], LV_OBJ_FLAG_SCROLLABLE); /// Flags

                lv_obj_set_style_bg_opa(ui_musiclistname[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(ui_musiclistname[i], lv_color_hex(0xF0F0F0), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_musiclistname[i], 255, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_set_style_border_width(ui_musiclistname[i], 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_side(ui_musiclistname[i], LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_radius(ui_musiclistname[i], 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_musiclistname[i], lv_color_hex(0x202020), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_opa(ui_musiclistname[i], 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_musiclistname[i], lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_opa(ui_musiclistname[i], 255, LV_PART_MAIN | LV_STATE_CHECKED);

                ui_musicnames[i] = lv_label_create(ui_musiclistname[i]);
                lv_obj_set_height(ui_musicnames[i], 20);
                lv_obj_set_width(ui_musicnames[i], lv_pct(90));
                lv_obj_set_align(ui_musicnames[i], LV_ALIGN_CENTER);
                lv_label_set_long_mode(ui_musicnames[i], LV_LABEL_LONG_SCROLL_CIRCULAR);
                lv_label_set_text_fmt(ui_musicnames[i], "%s", fn);
                lv_obj_clear_flag(ui_musicnames[i], LV_OBJ_FLAG_SCROLLABLE); /// Flags
                lv_obj_add_event_cb(ui_musiclistname[i], ui_event_musiclistname, LV_EVENT_ALL, NULL);
                if (i == 1)
                {
                    lv_label_set_text_fmt(ui_musicnamelabel, "%s", fn);
                    _ui_state_modify(ui_musiclistname[i], LV_STATE_CHECKED, _UI_MODIFY_FLAG_ADD);
                }
            }
        }
        i++;
    }

    res = lv_fs_dir_open(&dir, "S:/nes/rom/");
    if (res != LV_FS_RES_OK)
        ESP_LOGI(TAG, "打开文件目录失败！");
    lv_obj_clean(ui_nesbody);
    ESP_LOGI(TAG, "已清空文件列表");
    ESP_LOGI(TAG, "开始刷新游戏文件列表");
    i = 1;
    lv_obj_t *ui_neslist[count];
    ESP_LOGI(TAG, "已创建ui_neslist对象");
    lv_obj_t *ui_neslisticon[count];
    ESP_LOGI(TAG, "已创建ui_neslisticon对象");
    lv_obj_t *ui_neslistlabel[count];
    ESP_LOGI(TAG, "已创建ui_neslistlabel对象");
    char buffer[12]; // 缓冲区用于存储转换后的字符串
    while (1)
    {
        res = lv_fs_dir_read(&dir, fn);
        if (res != LV_FS_RES_OK)
        {
            ESP_LOGI(TAG, "打开文件目录失败！");
            break;
        }

        /*fn is empty, if not more files to read*/
        if (strlen(fn) == 0)
        {
            break;
        }
        const char *nesfile = strrchr(fn, '.');
        ESP_LOGI(TAG, "%s", fn);

        if (nesfile != NULL)
        {
            if (strcasecmp(nesfile, ".nes") == 0)
            {
                snprintf(buffer, sizeof(buffer), "%d", i); // 使用 snprintf 限制写入的最大字符数
                ui_neslist[i] = lv_obj_create(ui_nesbody);
                lv_obj_set_width(ui_neslist[i], 300);
                lv_obj_set_height(ui_neslist[i], 40);
                lv_obj_set_align(ui_neslist[i], LV_ALIGN_CENTER);
                lv_obj_set_flex_flow(ui_neslist[i], LV_FLEX_FLOW_ROW);
                lv_obj_set_flex_align(ui_neslist[i], LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
                lv_obj_clear_flag(ui_neslist[i], LV_OBJ_FLAG_SCROLLABLE); /// Flags
                lv_obj_set_style_border_width(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_left(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_right(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_top(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_bottom(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_row(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_pad_column(ui_neslist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_neslist[i], lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_opa(ui_neslist[i], 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_neslist[i], &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
                ui_neslisticon[i] = lv_label_create(ui_neslist[i]);
                lv_obj_set_width(ui_neslisticon[i], 30);
                lv_obj_set_height(ui_neslisticon[i], 20);
                lv_obj_set_x(ui_neslisticon[i], 2);
                lv_obj_set_y(ui_neslisticon[i], -57);
                lv_obj_set_align(ui_neslisticon[i], LV_ALIGN_CENTER);
                lv_label_set_text_fmt(ui_neslisticon[i], "%s", buffer);

                ui_neslistlabel[i] = lv_label_create(ui_neslist[i]);
                lv_obj_set_width(ui_neslistlabel[i], 270);
                lv_obj_set_height(ui_neslistlabel[i], 20);
                lv_obj_set_align(ui_neslistlabel[i], LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_neslistlabel[i], LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE);
                lv_label_set_text_fmt(ui_neslistlabel[i], "%s", fn);
                lv_obj_add_event_cb(ui_neslistlabel[i], ui_event_neslistlabel, LV_EVENT_ALL, NULL);
            }
        }
        i++;
    }

    lv_fs_dir_close(&dir);
}