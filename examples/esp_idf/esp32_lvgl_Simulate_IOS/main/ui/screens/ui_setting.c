#include "../ui.h"

void ui_setting_screen_init(void)
{
    ui_setting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_setting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_setting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setting, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_setting, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingheader = lv_obj_create(ui_setting);
    lv_obj_set_width(ui_settingheader, 320);
    lv_obj_set_height(ui_settingheader, 60);
    lv_obj_set_align(ui_settingheader, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_settingheader, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_settingheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_settingheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_settingheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_settingheader, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_settingheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_settingheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_settingheader, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_settingheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_settingheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_settingheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_settingheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_settingheader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_settingheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_settingheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingmobile = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingmobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingmobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingmobile, 10);
    lv_obj_set_y(ui_settingmobile, 7);
    lv_label_set_text(ui_settingmobile, "Mobile");

    ui_settingwifi = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingwifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingwifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingwifi, 78);
    lv_obj_set_y(ui_settingwifi, 7);
    lv_label_set_text(ui_settingwifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_settingwifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_settingwifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingbattery = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingbattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingbattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingbattery, -10);
    lv_obj_set_y(ui_settingbattery, 7);
    lv_obj_set_align(ui_settingbattery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_3);
    lv_obj_set_style_text_font(ui_settingbattery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_settingtime = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingtime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingtime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingtime, 0);
    lv_obj_set_y(ui_settingtime, 7);
    lv_obj_set_align(ui_settingtime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_settingtime, "12:12");

    ui_settingbatteryp = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingbatteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingbatteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingbatteryp, -35);
    lv_obj_set_y(ui_settingbatteryp, 7);
    lv_obj_set_align(ui_settingbatteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_settingbatteryp, "89%");

    ui_settingtext = lv_label_create(ui_settingheader);
    lv_obj_set_width(ui_settingtext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingtext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingtext, 0);
    lv_obj_set_y(ui_settingtext, -2);
    lv_obj_set_align(ui_settingtext, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_settingtext, "Set");

    ui_setpannel = lv_obj_create(ui_setting);
    lv_obj_set_width(ui_setpannel, 320);
    lv_obj_set_height(ui_setpannel, 420);
    lv_obj_set_x(ui_setpannel, 0);
    lv_obj_set_y(ui_setpannel, 60);
    lv_obj_set_align(ui_setpannel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_setpannel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_setpannel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_setpannel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_setpannel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_setpannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_setpannel, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_setpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpannel = lv_obj_create(ui_setpannel);
    lv_obj_set_width(ui_aboutpannel, 320);
    lv_obj_set_height(ui_aboutpannel, 40);
    lv_obj_set_align(ui_aboutpannel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpannel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_aboutpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpannel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpannel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpannel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpannel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutlabel = lv_label_create(ui_aboutpannel);
    lv_obj_set_width(ui_aboutlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutlabel, "About this machine");
    lv_obj_clear_flag(ui_aboutlabel, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags

    ui_aboutlabel1 = lv_label_create(ui_aboutpannel);
    lv_obj_set_width(ui_aboutlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aboutlabel1, -20);
    lv_obj_set_y(ui_aboutlabel1, 0);
    lv_obj_set_align(ui_aboutlabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_aboutlabel1, "VIEWE 1.2");
    lv_obj_clear_flag(ui_aboutlabel1, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_aboutlabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutlabel2 = lv_label_create(ui_aboutpannel);
    lv_obj_set_width(ui_aboutlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutlabel2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_aboutlabel2, LV_SYMBOL_RIGHT);
    lv_obj_clear_flag(ui_aboutlabel2, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_aboutlabel2, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_aboutlabel2, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimepannel = lv_obj_create(ui_setpannel);
    lv_obj_set_width(ui_datetimepannel, 320);
    lv_obj_set_height(ui_datetimepannel, 40);
    lv_obj_set_x(ui_datetimepannel, 166);
    lv_obj_set_y(ui_datetimepannel, 2);
    lv_obj_set_align(ui_datetimepannel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_datetimepannel,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_datetimepannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_datetimepannel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_datetimepannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_datetimepannel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_datetimepannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_datetimepannel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_datetimepannel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_datetimelabel = lv_label_create(ui_datetimepannel);
    lv_obj_set_width(ui_datetimelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_datetimelabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_datetimelabel, "Date and time");
    lv_obj_clear_flag(ui_datetimelabel, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags

    ui_datetimelabel2 = lv_label_create(ui_datetimepannel);
    lv_obj_set_width(ui_datetimelabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_datetimelabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_datetimelabel2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_datetimelabel2, LV_SYMBOL_RIGHT);
    lv_obj_clear_flag(ui_datetimelabel2, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_datetimelabel2, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_datetimelabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_datetimelabel2, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifipanel = lv_obj_create(ui_setpannel);
    lv_obj_set_width(ui_wifipanel, 320);
    lv_obj_set_height(ui_wifipanel, 40);
    lv_obj_set_align(ui_wifipanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_wifipanel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wifipanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifipanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifipanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_wifipanel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wifipanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifipanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_wifipanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifitext = lv_label_create(ui_wifipanel);
    lv_obj_set_width(ui_wifitext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifitext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifitext, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_wifitext, "WIFI");
    lv_obj_clear_flag(ui_wifitext, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags

    ui_wifionlabel = lv_label_create(ui_wifipanel);
    lv_obj_set_width(ui_wifionlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifionlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifionlabel, -20);
    lv_obj_set_y(ui_wifionlabel, 0);
    lv_obj_set_align(ui_wifionlabel, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wifionlabel, "Closed");
    lv_obj_clear_flag(ui_wifionlabel, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_wifionlabel, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifionlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifionlabel1 = lv_label_create(ui_wifipanel);
    lv_obj_set_width(ui_wifionlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifionlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifionlabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wifionlabel1, LV_SYMBOL_RIGHT);
    lv_obj_clear_flag(ui_wifionlabel1, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_wifionlabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifionlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifionlabel1, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifipanel1 = lv_obj_create(ui_setpannel);
    lv_obj_set_width(ui_wifipanel1, 320);
    lv_obj_set_height(ui_wifipanel1, 40);
    lv_obj_set_align(ui_wifipanel1, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_wifipanel1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wifipanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifipanel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifipanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_wifipanel1, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wifipanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifipanel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_wifipanel1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifitext1 = lv_label_create(ui_wifipanel1);
    lv_obj_set_width(ui_wifitext1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifitext1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifitext1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_wifitext1, "Bluetooth");
    lv_obj_clear_flag(ui_wifitext1, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags

    ui_wifionlabel2 = lv_label_create(ui_wifipanel1);
    lv_obj_set_width(ui_wifionlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifionlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifionlabel2, -20);
    lv_obj_set_y(ui_wifionlabel2, 0);
    lv_obj_set_align(ui_wifionlabel2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wifionlabel2, "Opened");
    lv_obj_clear_flag(ui_wifionlabel2, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_wifionlabel2, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifionlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifionlabel3 = lv_label_create(ui_wifipanel1);
    lv_obj_set_width(ui_wifionlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifionlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifionlabel3, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wifionlabel3, LV_SYMBOL_RIGHT);
    lv_obj_clear_flag(ui_wifionlabel3, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_style_text_color(ui_wifionlabel3, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifionlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifionlabel3, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_aboutpannel, ui_event_aboutpannel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_datetimepannel, ui_event_datetimepannel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wifipanel, ui_event_wifipanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wifipanel1, ui_event_wifipanel1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_setting, ui_event_setting, LV_EVENT_ALL, NULL);

}
