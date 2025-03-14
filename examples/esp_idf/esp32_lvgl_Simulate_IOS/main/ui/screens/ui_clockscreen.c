#include "../ui.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <time.h>
void update_clock(lv_timer_t *timer)
{
    time_t now;
    struct tm timeinfo;

    time(&now);
    localtime_r(&now, &timeinfo);

    int hour_angle = timeinfo.tm_hour * 300 + timeinfo.tm_min;
    lv_img_set_angle(ui_clockhour, hour_angle);

    int min_angle = timeinfo.tm_min * 60 + timeinfo.tm_sec;
    lv_img_set_angle(ui_clockmin, min_angle);

    int sec_angle = timeinfo.tm_sec * 60;

    lv_img_set_angle(ui_clocksec, sec_angle);
}
void ui_clockscreen_screen_init(void)
{
    ui_clockscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_clockscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_clockscreen, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_clockscreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockbg = lv_img_create(ui_clockscreen);
    lv_img_set_src(ui_clockbg, &ui_img_bigclock_png);
    lv_obj_set_width(ui_clockbg, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clockbg, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_clockbg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_clockbg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_clockbg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_clockhour = lv_img_create(ui_clockscreen);
    lv_img_set_src(ui_clockhour, &ui_img_clockhour_png);
    lv_obj_set_width(ui_clockhour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clockhour, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_clockhour, LV_ALIGN_CENTER, 0, -34);
    lv_img_set_pivot(ui_clockhour, 5, 73);
    lv_obj_add_flag(ui_clockhour, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_clockhour, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_clockmin = lv_img_create(ui_clockscreen);
    lv_img_set_src(ui_clockmin, &ui_img_clockminute_png);
    lv_obj_set_width(ui_clockmin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clockmin, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_clockmin, LV_ALIGN_CENTER, 0, -58);
    lv_img_set_pivot(ui_clockmin, 5, 122);
    lv_obj_add_flag(ui_clockmin, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_clockmin, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_clocksec = lv_img_create(ui_clockscreen);
    lv_img_set_src(ui_clocksec, &ui_img_clocksecond_png);
    lv_obj_set_width(ui_clocksec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clocksec, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_clocksec, LV_ALIGN_CENTER, 0, -61);
    lv_img_set_pivot(ui_clocksec, 4, 142);
    lv_obj_add_flag(ui_clocksec, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_clocksec, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_clockscreen, ui_event_clockscreen, LV_EVENT_ALL, NULL);
    
    lv_timer_create(update_clock, 500, NULL);
}
