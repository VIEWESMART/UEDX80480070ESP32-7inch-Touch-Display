#ifndef SDCARD_H
#define SDCARD_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"
#include "driver/gpio.h"
#include "dirent.h"
#include "lvgl.h"
#include "ui.h"
#define SDCARD_PIN_CMD 17
#define SDCARD_PIN_CLK 14
#define SDCARD_PIN_D0 16
#define SDCARD_PIN_D1 18
#define SDCARD_PIN_D2 15
#define SDCARD_PIN_D3 21
#define SDCARD_PIN_CD -1       // SD卡检测IO
#define MOUNT_POINT "/sdcard" // SD卡挂载路径
extern sdmmc_card_t *card;
    void cardinit(void);
    void sdlist_timer_cb(lv_timer_t *timer);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif