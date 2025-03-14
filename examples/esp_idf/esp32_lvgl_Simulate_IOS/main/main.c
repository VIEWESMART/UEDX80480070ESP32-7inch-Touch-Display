#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lvgl.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "lvgl_helpers.h"
#include "esp_timer.h"
#include "esp_log.h"
#include "ui.h"
#include <time.h>
#include <sys/time.h>
#include "freertos/task.h"
#include <ctype.h>
#include "volume.h"
#include "sdcard.h"
#include "wifi.h"
#include "mp3.h"
#include "rgbled.h"
#include "uart.h"
/*********************
 *      DEFINES
 *********************/
#define LV_TICK_PERIOD_MS 1
static void lv_tick_task(void *arg);
uint16_t SDCD = 0;
/**********************
 *  静态声明
 **********************/
/**********************
 *   主函数
 **********************/
// 定义全局变量和标志位
void update_time_label(lv_timer_t *timer)
{
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    static char time_str[64];
    if (!lv_obj_has_state(ui_autodatetimeswitch1, LV_STATE_CHECKED))
    {
        strftime(time_str, 64, "%p %I:%M:%S", &timeinfo); // 12小时制时间
        char *am = "am";
        char *pm = "pm";
        int len = strlen(time_str) - strlen("%p") + strlen(am) + 1;

        char *t = time_str + strlen("%p");
        if (strncasecmp(time_str, "am", 2) == 0)
        {
            memmove(time_str + strlen(am), t, len);
            memcpy(time_str, am, strlen(am));
        }
        else
        {
            memmove(time_str + strlen(pm), t, len);
            memcpy(time_str, pm, strlen(pm));
        }
    }
    else
    {
        strftime(time_str, 64, "%H:%M:%S", &timeinfo); // 24小时制时间
    }
    lv_label_set_text_fmt(ui_date, "date  %dyear%02dmonth%02dday", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
    lv_label_set_text(ui_time, time_str);
    lv_label_set_text(ui_settingtime, time_str);
    lv_label_set_text(ui_wlantime, time_str);
    lv_label_set_text(ui_bluetoothtime, time_str);
    lv_label_set_text_fmt(ui_time1, "time  %s", time_str);
    lv_label_set_text(ui_datetimetime, time_str);
    lv_label_set_text(ui_abouttime, time_str);
    lv_slider_set_value(ui_musicslider, playsilder, LV_ANIM_ON); // 更新歌曲时间进度条
    sprintf(musicplaytime, "%02d:%02d", (uint16_t)playsilder / 60, (uint16_t)playsilder % 60);
    lv_label_set_text(ui_musictimelabel, musicplaytime); // 更新歌曲播放时间
    if (lv_obj_has_state(ui_autodatetimeswitch, LV_STATE_CHECKED))
    {
        lv_calendar_set_today_date(ui_calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
        lv_calendar_set_showed_date(ui_calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1);
    }
    // 刷新SD卡列表
    if (gpio_get_level(SDCARD_PIN_CD) == 0 && SDCD == 3)
    {
        SDCD = 1; // 首次开机刷新菜单
        lv_timer_t *sdlist_time;
        sdlist_time = lv_timer_create(sdlist_timer_cb, 10, NULL); // 创建一个定时器
        lv_timer_set_repeat_count(sdlist_time, 1);                // 设置该定时器重复执行1次
    }
}
void main_init(void *pt)
{

    SDCD = 3; // 初始插卡状态
    ESP_LOGI("main", "检测到插入SD卡，初始化SD卡。");
    cardinit(); // 初始化SD卡
    volume_ledc_init();    // 初始化LED占空比，调节声音
    i2s_init_std_duplex(); // 初始化i2s
    wifi_init();           // 初始化WIFI
    rgbledinit();          // 初始化RGBLED
    vTaskDelete(NULL);
}
void lvgl_init(void *pt)
{
    /*调用并初始化LVGL*/
    lv_init();
    /* 初始化驱动程序 */
    lvgl_driver_init();
    /*建立双缓冲数据*/
    static lv_disp_draw_buf_t disp_buf;
    uint32_t size_in_px = DISP_BUF_SIZE;
    lv_color_t *buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    assert(buf1 != NULL);
    /* 不使用单色显示器时使用双缓冲 */
    lv_color_t *buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    assert(buf2 != NULL);

    /* 根据所选显示器初始化工作缓冲区. */
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);
    // 在LVGL中注册显示设备
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*显示设备基本初始化*/
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = disp_driver_flush;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.sw_rotate = 1;
    lv_disp_drv_register(&disp_drv);

    /*在LVGL中注册触摸屏*/
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          /*输入设备基本初始化*/
    indev_drv.type = LV_INDEV_TYPE_POINTER; /*输入设备类型.*/
    indev_drv.read_cb = touch_driver_read;  /*回调函数.*/
    // /*在LVGL中注册驱动程序并保存创建的输入设备对象*/
    lv_indev_drv_register(&indev_drv);
    ESP_LOGI("main", "安装 LVGL 滴答计时器");
    // LVGL 的滴答接口(使用 esp_timer 生成 1ms 周期性事件)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &lv_tick_task,
        .name = "lvgl_tick"};
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, LV_TICK_PERIOD_MS * 1000));
    ui_init();
    lv_timer_create(update_time_label, 500, NULL);
    while (1)
    {
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_timer_handler();
        xSemaphoreGive(lvglmutex);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
void app_main(void)
{
    struct timeval tv; // 初始化时间
    struct tm timeinfo;
    setenv("TZ", "Asia/Shanghai", 1);
    tzset();
    gettimeofday(&tv, NULL);
    localtime_r(&tv.tv_sec, &timeinfo);
    timeinfo.tm_year = 123;
    timeinfo.tm_mon = 0;
    timeinfo.tm_mday = 1;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    tv.tv_sec = mktime(&timeinfo); // 将 struct tm 转换为 time_t 类型timeval
    settimeofday(&tv, NULL);
    lvglmutex = xSemaphoreCreateMutex();
    xTaskCreateWithCaps(lvgl_init, "lvglinit", 1024 * 200, NULL, 4, NULL, MALLOC_CAP_SPIRAM); // 开始LVGL任务
    xTaskCreate(main_init, "maininit", 1024 * 8, NULL, 5, NULL);
    vTaskDelete(NULL);
}

static void lv_tick_task(void *arg)
{
    lv_tick_inc(LV_TICK_PERIOD_MS);
}