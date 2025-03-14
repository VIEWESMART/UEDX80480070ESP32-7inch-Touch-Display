#include "nesgame.h"
#include "InfoNES_System.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_log.h"
#include "lvgl/lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "driver/i2s_std.h"
#include "volume.h"
#include "esp_task_wdt.h"
uint8_t stats = 0;
extern SemaphoreHandle_t lvglmutex;
extern i2s_chan_handle_t tx_chan; // I2S tx channel handler
size_t bytes_written;
void nesmain(void *args)
{
    WorkFrame = (WORD *)malloc(NES_DISP_HEIGHT * NES_DISP_WIDTH * sizeof(WORD));
    if (WorkFrame == NULL)
    {
        ESP_LOGI("NES", "无法分配 WorkFrame。");
        return;
    }
    memset(WorkFrame, 0, NES_DISP_HEIGHT * NES_DISP_WIDTH * sizeof(WORD));

    InfoNES_Main();

    free(WorkFrame);
    free(final_wave);
    lv_timer_del(nes_time);
    ESP_LOGI("NES", "退出游戏。");
    ESP_ERROR_CHECK(i2s_channel_disable(tx_chan));
    ESP_LOGI("NES", "关闭I2S通道！");
    vTaskDeleteWithCaps(NULL);
}
void nes_flush(void)
{
    nesimg->data = (const uint8_t *)WorkFrame;
    vTaskDelay(1);
}

void nesstart(char *name)
{

    char file_nes[256] = MOUNT_POINT "/nes/rom/";
    char *play_nesname = strcat(file_nes, name);
    if (start_application(play_nesname))
    {
        ESP_LOGI("NES", "读取游戏:%s", play_nesname);
        nes_time = lv_timer_create(nes_timer_cb, 5, NULL); // 创建一个定时器,传入nes名称
        stats = 1;
        xTaskCreatePinnedToCoreWithCaps(nesmain, "nesmain", 1024 * 500, NULL, 5, NULL, 1, MALLOC_CAP_SPIRAM); // 开始NES任务
    }
    else
    {
        ESP_LOGI("NES", "%s不是 NES 格式文件！", play_nesname);
    }
}
void nes_timer_cb(lv_timer_t *timer)
{
    lv_img_set_src(ui_nesgamepanel, nesimg); // 更新NES画面。
}
