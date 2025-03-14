#ifndef WIFI_H
#define WIFI_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include <string.h>
#include "ui.h"
#include "lvgl.h"
#include "esp_task_wdt.h"
/* Set the SSID and Password via project configuration, or can set directly here */
#define WIFI_SCAN BIT23
// #define WIFI_SCANDONE BIT1

// #define WIFI_SCAN_TIMEOUT (4 * 1000 / portTICK_PERIOD_MS) // 4 秒超时
extern char* wifi_ssid;
extern char* wifi_pass;
extern SemaphoreHandle_t lvglmutex;
extern EventGroupHandle_t s_wifi_event_group;
    void wifi_init(void);
    void wifi_de_init(void);
    void wifi_scan(void *pt);
    void wifi_timer_cb(lv_timer_t *timer);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif