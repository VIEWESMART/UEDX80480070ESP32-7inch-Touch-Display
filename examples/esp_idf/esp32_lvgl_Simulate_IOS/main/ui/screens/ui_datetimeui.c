#include "../ui.h"
#include <time.h>
void ui_datetimeui_screen_init(void)
{
    ui_datetimeui = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_datetimeui, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_datetimeui, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimeui, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimeui, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_datetimeui, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimeheader = lv_obj_create(ui_datetimeui);
    lv_obj_set_width(ui_datetimeheader, 320);
    lv_obj_set_height(ui_datetimeheader, 60);
    lv_obj_set_align(ui_datetimeheader, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_datetimeheader, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_datetimeheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimeheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimeheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_datetimeheader, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_datetimeheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimeheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_datetimeheader, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_datetimeheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_datetimeheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_datetimeheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_datetimeheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_datetimeheader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_datetimeheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_datetimeheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimemobile = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimemobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimemobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimemobile, 10);
    lv_obj_set_y(ui_datetimemobile, 7);
    lv_label_set_text(ui_datetimemobile, "Mobile");

    ui_datetimewifi = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimewifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimewifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimewifi, 78);
    lv_obj_set_y(ui_datetimewifi, 7);
    lv_label_set_text(ui_datetimewifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_datetimewifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_datetimewifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimebattery = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimebattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimebattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimebattery, -10);
    lv_obj_set_y(ui_datetimebattery, 7);
    lv_obj_set_align(ui_datetimebattery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_3);
    lv_obj_set_style_text_font(ui_datetimebattery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimetime = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimetime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimetime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimetime, 0);
    lv_obj_set_y(ui_datetimetime, 7);
    lv_obj_set_align(ui_datetimetime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_datetimetime, "12:12");

    ui_datetimebatteryp = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimebatteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimebatteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimebatteryp, -35);
    lv_obj_set_y(ui_datetimebatteryp, 7);
    lv_obj_set_align(ui_datetimebatteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_datetimebatteryp, "89%");

    ui_datetimetitle = lv_label_create(ui_datetimeheader);
    lv_obj_set_width(ui_datetimetitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimetitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_datetimetitle, 0);
    lv_obj_set_y(ui_datetimetitle, -2);
    lv_obj_set_align(ui_datetimetitle, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_datetimetitle, "Date and time");

    ui_datetimebody = lv_obj_create(ui_datetimeui);
    lv_obj_set_width(ui_datetimebody, 320);
    lv_obj_set_height(ui_datetimebody, 420);
    lv_obj_set_x(ui_datetimebody, 0);
    lv_obj_set_y(ui_datetimebody, 60);
    lv_obj_set_align(ui_datetimebody, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_datetimebody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_datetimebody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_scrollbar_mode(ui_datetimebody, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimebody, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimebody, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_datetimebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimepanel = lv_obj_create(ui_datetimebody);
    lv_obj_set_width(ui_datetimepanel, 320);
    lv_obj_set_height(ui_datetimepanel, 40);
    lv_obj_set_align(ui_datetimepanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_datetimepanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_datetimepanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimepanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimepanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_datetimepanel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_datetimepanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimepanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_datetimepanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_autodatetimelabel1 = lv_label_create(ui_datetimepanel);
    lv_obj_set_width(ui_autodatetimelabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_autodatetimelabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_autodatetimelabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_autodatetimelabel1, "24 hour clock");

    ui_autodatetimeswitch1 = lv_switch_create(ui_datetimepanel);
    lv_obj_set_width(ui_autodatetimeswitch1, 45);
    lv_obj_set_height(ui_autodatetimeswitch1, 24);
    lv_obj_set_align(ui_autodatetimeswitch1, LV_ALIGN_RIGHT_MID);
    lv_obj_add_state(ui_autodatetimeswitch1, LV_STATE_CHECKED);       /// States

    lv_obj_set_style_bg_color(ui_autodatetimeswitch1, lv_color_hex(0xAAAAAA), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_autodatetimeswitch1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_autodatetimeswitch1, lv_color_hex(0x00D200), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_autodatetimeswitch1, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_datetimepanel1 = lv_obj_create(ui_datetimebody);
    lv_obj_set_width(ui_datetimepanel1, 320);
    lv_obj_set_height(ui_datetimepanel1, 40);
    lv_obj_set_align(ui_datetimepanel1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_datetimepanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_datetimepanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimepanel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimepanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_datetimepanel1, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_datetimepanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimepanel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_datetimepanel1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_autodatetimelabel = lv_label_create(ui_datetimepanel1);
    lv_obj_set_width(ui_autodatetimelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_autodatetimelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_autodatetimelabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_autodatetimelabel, "Automatically set the time");

    ui_autodatetimeswitch = lv_switch_create(ui_datetimepanel1);
    lv_obj_set_width(ui_autodatetimeswitch, 45);
    lv_obj_set_height(ui_autodatetimeswitch, 24);
    lv_obj_set_align(ui_autodatetimeswitch, LV_ALIGN_RIGHT_MID);
    lv_obj_add_state(ui_autodatetimeswitch, LV_STATE_CHECKED);       /// States

    lv_obj_set_style_bg_color(ui_autodatetimeswitch, lv_color_hex(0xAAAAAA), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_autodatetimeswitch, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_autodatetimeswitch, lv_color_hex(0x00D200), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_autodatetimeswitch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_setdate = lv_obj_create(ui_datetimebody);
    lv_obj_set_width(ui_setdate, 320);
    lv_obj_set_height(ui_setdate, 40);
    lv_obj_set_align(ui_setdate, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_setdate, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_setdate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_setdate, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setdate, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setdate, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_setdate, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_setdate, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    time_t now;
    // char strftime_buf[64];
    struct tm timeinfo;
    time(&now);
    // 将时区设置为中国标准时间
    setenv("TZ", "CST-8", 1);
    tzset();
    localtime_r(&now, &timeinfo);
    ui_date = lv_label_create(ui_setdate);
    lv_obj_set_width(ui_date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_date, LV_ALIGN_LEFT_MID);
    lv_label_set_text_fmt(ui_date, "Date  %dyear%2dmonth%2dday", timeinfo.tm_year+1900, timeinfo.tm_mon+1, timeinfo.tm_mday);

    ui_dateright = lv_label_create(ui_setdate);
    lv_obj_set_width(ui_dateright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_dateright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_dateright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_dateright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_color(ui_dateright, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_dateright, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_dateright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settime = lv_obj_create(ui_datetimebody);
    lv_obj_set_width(ui_settime, 320);
    lv_obj_set_height(ui_settime, 40);
    lv_obj_set_align(ui_settime, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_settime, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_settime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settime, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_settime, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_time1 = lv_label_create(ui_settime);
    lv_obj_set_width(ui_time1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_time1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_time1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_time1, "time  12:12");

    ui_timeright = lv_label_create(ui_settime);
    lv_obj_set_width(ui_timeright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_timeright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_timeright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_timeright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_color(ui_timeright, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_timeright, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_timeright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimecountry = lv_obj_create(ui_datetimebody);
    lv_obj_set_width(ui_datetimecountry, 320);
    lv_obj_set_height(ui_datetimecountry, 40);
    lv_obj_set_align(ui_datetimecountry, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_datetimecountry, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_datetimecountry, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimecountry, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimecountry, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_datetimecountry, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_datetimecountry, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimecountry, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_datetimecountry, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimecountrylabel = lv_label_create(ui_datetimecountry);
    lv_obj_set_width(ui_datetimecountrylabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimecountrylabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_datetimecountrylabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_datetimecountrylabel, "Time Zone");

    ui_datetimelabel1 = lv_label_create(ui_datetimecountry);
    lv_obj_set_width(ui_datetimelabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimelabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_datetimelabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_datetimelabel1, "Beijing");
    lv_obj_set_style_text_color(ui_datetimelabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_datetimelabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_setdateing = lv_obj_create(ui_datetimeui);
    lv_obj_set_width(ui_setdateing, 320);
    lv_obj_set_height(ui_setdateing, 480);
    lv_obj_set_x(ui_setdateing, 0);
    lv_obj_set_y(ui_setdateing, 480);
    lv_obj_set_align(ui_setdateing, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_setdateing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setdateing, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_setdateing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_calendar = lv_calendar_create(ui_setdateing);
    lv_calendar_set_today_date(ui_calendar, timeinfo.tm_year+1900, timeinfo.tm_mon+1, timeinfo.tm_mday);
    lv_calendar_set_showed_date(ui_calendar, timeinfo.tm_year+1900, timeinfo.tm_mon+1);
    lv_obj_t * ui_calendar_header = lv_calendar_header_arrow_create(ui_calendar);
    lv_obj_set_style_text_font(ui_calendar_header, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(ui_calendar, 320);
    lv_obj_set_height(ui_calendar, 260);
    lv_obj_set_x(ui_calendar, 0);
    lv_obj_set_y(ui_calendar, 120);
    lv_obj_set_align(ui_calendar, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_calendar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_calendar, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_calendar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_calendar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settimeing = lv_obj_create(ui_datetimeui);
    lv_obj_set_width(ui_settimeing, 320);
    lv_obj_set_height(ui_settimeing, 480);
    lv_obj_set_x(ui_settimeing, 0);
    lv_obj_set_y(ui_settimeing, 480);
    lv_obj_set_align(ui_settimeing, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_settimeing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settimeing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settimeing, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settimeing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settimeing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settimes = lv_obj_create(ui_settimeing);
    lv_obj_set_width(ui_settimes, 320);
    lv_obj_set_height(ui_settimes, 220);
    lv_obj_set_x(ui_settimes, 0);
    lv_obj_set_y(ui_settimes, 220);
    lv_obj_set_align(ui_settimes, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_settimes, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_settimes, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_settimes, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settimes, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settimes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settimes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_settimes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settimelabel = lv_obj_create(ui_settimes);
    lv_obj_set_width(ui_settimelabel, 320);
    lv_obj_set_height(ui_settimelabel, 40);
    lv_obj_set_align(ui_settimelabel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_settimelabel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settimelabel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settimelabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settimelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settimelabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settimetext = lv_label_create(ui_settimelabel);
    lv_obj_set_width(ui_settimetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settimetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_settimetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_settimetext, "set time");

    ui_settimepanel = lv_obj_create(ui_settimes);
    lv_obj_set_width(ui_settimepanel, 320);
    lv_obj_set_height(ui_settimepanel, 120);
    lv_obj_set_align(ui_settimepanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_settimepanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_settimepanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_settimepanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_settimepanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sethour = lv_roller_create(ui_settimepanel);
    lv_roller_set_options(ui_sethour,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23",
                          LV_ROLLER_MODE_INFINITE);
    lv_roller_set_selected(ui_sethour, timeinfo.tm_hour, LV_ANIM_ON);
    lv_obj_set_width(ui_sethour, 80);
    lv_obj_set_height(ui_sethour, 100);
    lv_obj_set_align(ui_sethour, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_sethour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sethour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sethour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sethour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_sethour, lv_color_hex(0x0078F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_sethour, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sethour, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sethour, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_hourtext = lv_label_create(ui_settimepanel);
    lv_obj_set_width(ui_hourtext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_hourtext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_hourtext, -20);
    lv_obj_set_y(ui_hourtext, 2);
    lv_obj_set_align(ui_hourtext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_hourtext, "hour");
    lv_obj_add_flag(ui_hourtext, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_set_style_text_color(ui_hourtext, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_hourtext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_setminute = lv_roller_create(ui_settimepanel);
    lv_roller_set_options(ui_setminute,
                          "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59",
                          LV_ROLLER_MODE_INFINITE);
    lv_roller_set_selected(ui_setminute, timeinfo.tm_min, LV_ANIM_ON);
    lv_obj_set_width(ui_setminute, 80);
    lv_obj_set_height(ui_setminute, 100);
    lv_obj_set_align(ui_setminute, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_setminute, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setminute, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setminute, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_setminute, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_setminute, lv_color_hex(0x0078F5), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_setminute, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setminute, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setminute, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_minutetext = lv_label_create(ui_settimepanel);
    lv_obj_set_width(ui_minutetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_minutetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_minutetext, 67);
    lv_obj_set_y(ui_minutetext, 2);
    lv_obj_set_align(ui_minutetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_minutetext, "minute");
    lv_obj_add_flag(ui_minutetext, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_set_style_text_color(ui_minutetext, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_minutetext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settimeokpanel = lv_obj_create(ui_settimes);
    lv_obj_set_width(ui_settimeokpanel, 320);
    lv_obj_set_height(ui_settimeokpanel, 60);
    lv_obj_set_align(ui_settimeokpanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_settimeokpanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_settimeokpanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_settimeokpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settimeokpanel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settimeokpanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settimeokpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_settimeokpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_settimeokpanel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cenceltimebtn = lv_btn_create(ui_settimeokpanel);
    lv_obj_set_width(ui_cenceltimebtn, 110);
    lv_obj_set_height(ui_cenceltimebtn, 40);
    lv_obj_set_align(ui_cenceltimebtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cenceltimebtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_cenceltimebtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cenceltimebtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cenceltimebtn, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cenceltimebtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_cenceltimebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_cenceltimebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cenceltimetext = lv_label_create(ui_cenceltimebtn);
    lv_obj_set_width(ui_cenceltimetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cenceltimetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_cenceltimetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cenceltimetext, "cancel");
    lv_obj_set_style_text_color(ui_cenceltimetext, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cenceltimetext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_oktimebtn = lv_btn_create(ui_settimeokpanel);
    lv_obj_set_width(ui_oktimebtn, 110);
    lv_obj_set_height(ui_oktimebtn, 40);
    lv_obj_set_align(ui_oktimebtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_oktimebtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_oktimebtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_oktimebtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_oktimebtn, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_oktimebtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_oktimebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_oktimebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_oktimetext = lv_label_create(ui_oktimebtn);
    lv_obj_set_width(ui_oktimetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_oktimetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_oktimetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_oktimetext, "confirm");

    lv_obj_add_event_cb(ui_autodatetimeswitch1, ui_event_autodatetimeswitch1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_autodatetimeswitch, ui_event_autodatetimeswitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_setdate, ui_event_setdate, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settime, ui_event_settime, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_calendar, ui_event_calendar, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_setdateing, ui_event_setdateing, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_cenceltimebtn, ui_event_cenceltimebtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_oktimebtn, ui_event_oktimebtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settimeing, ui_event_settimeing, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_datetimeui, ui_event_datetimeui, LV_EVENT_ALL, NULL);

}
