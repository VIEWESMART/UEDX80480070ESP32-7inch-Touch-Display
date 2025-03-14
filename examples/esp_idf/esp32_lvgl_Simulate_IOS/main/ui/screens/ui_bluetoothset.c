#include "../ui.h"

void ui_bluetoothset_screen_init(void)
{
    ui_bluetoothset = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_bluetoothset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothset, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bluetoothset, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothheader = lv_obj_create(ui_bluetoothset);
    lv_obj_set_width(ui_bluetoothheader, 320);
    lv_obj_set_height(ui_bluetoothheader, 60);
    lv_obj_set_align(ui_bluetoothheader, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_bluetoothheader, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_bluetoothheader, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_bluetoothheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_bluetoothheader, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bluetoothheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bluetoothheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bluetoothheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bluetoothheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_bluetoothheader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bluetoothheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bluetoothheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothmobile = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothmobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothmobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothmobile, 10);
    lv_obj_set_y(ui_bluetoothmobile, 7);
    lv_label_set_text(ui_bluetoothmobile, "Mobile");

    ui_bluetoothwifi = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothwifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothwifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothwifi, 78);
    lv_obj_set_y(ui_bluetoothwifi, 7);
    lv_label_set_text(ui_bluetoothwifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_bluetoothwifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_bluetoothwifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothbattery = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothbattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothbattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothbattery, -10);
    lv_obj_set_y(ui_bluetoothbattery, 7);
    lv_obj_set_align(ui_bluetoothbattery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_3);
    lv_obj_set_style_text_font(ui_bluetoothbattery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothtime = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothtime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothtime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothtime, 0);
    lv_obj_set_y(ui_bluetoothtime, 7);
    lv_obj_set_align(ui_bluetoothtime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bluetoothtime, "12:12");

    ui_bluetoothbatteryp = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothbatteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothbatteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothbatteryp, -35);
    lv_obj_set_y(ui_bluetoothbatteryp, 7);
    lv_obj_set_align(ui_bluetoothbatteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_bluetoothbatteryp, "89%");

    ui_bluetoothtitle = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothtitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothtitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothtitle, 30);
    lv_obj_set_y(ui_bluetoothtitle, -2);
    lv_obj_set_align(ui_bluetoothtitle, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_bluetoothtitle, "Bluetooth settings");

    ui_bluetoothbackico = lv_label_create(ui_bluetoothheader);
    lv_obj_set_width(ui_bluetoothbackico, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothbackico, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothbackico, 10);
    lv_obj_set_y(ui_bluetoothbackico, -3);
    lv_obj_set_align(ui_bluetoothbackico, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_bluetoothbackico, LV_SYMBOL_LEFT);
    lv_obj_add_flag(ui_bluetoothbackico, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_font(ui_bluetoothbackico, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothpannel = lv_obj_create(ui_bluetoothset);
    lv_obj_set_width(ui_bluetoothpannel, 320);
    lv_obj_set_height(ui_bluetoothpannel, 420);
    lv_obj_set_x(ui_bluetoothpannel, 0);
    lv_obj_set_y(ui_bluetoothpannel, 60);
    lv_obj_set_align(ui_bluetoothpannel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_bluetoothpannel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_bluetoothpannel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_bluetoothpannel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothpannel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothpannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothwitchpanel = lv_obj_create(ui_bluetoothpannel);
    lv_obj_set_width(ui_bluetoothwitchpanel, 280);
    lv_obj_set_height(ui_bluetoothwitchpanel, 40);
    lv_obj_set_align(ui_bluetoothwitchpanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_bluetoothwitchpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothwitchpanel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothwitchpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bluetoothwitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothsetlabel = lv_label_create(ui_bluetoothwitchpanel);
    lv_obj_set_width(ui_bluetoothsetlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothsetlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothsetlabel, 0);
    lv_obj_set_y(ui_bluetoothsetlabel, 4);
    lv_label_set_text(ui_bluetoothsetlabel, "Bluetooth");

    ui_bluetoothswitch = lv_switch_create(ui_bluetoothwitchpanel);
    lv_obj_set_width(ui_bluetoothswitch, 45);
    lv_obj_set_height(ui_bluetoothswitch, 24);
    lv_obj_set_align(ui_bluetoothswitch, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_bluetoothswitch, lv_color_hex(0xAAAAAA), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothswitch, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothswitch, lv_color_hex(0x00D200), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_bluetoothswitch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_bluetoothconnect = lv_obj_create(ui_bluetoothpannel);
    lv_obj_set_width(ui_bluetoothconnect, 280);
    lv_obj_set_height(ui_bluetoothconnect, 70);
    lv_obj_set_x(ui_bluetoothconnect, 0);
    lv_obj_set_y(ui_bluetoothconnect, 45);
    lv_obj_set_align(ui_bluetoothconnect, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_bluetoothconnect, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_bluetoothconnect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothconnect, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothconnect, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothconnect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothconnect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothsymbol = lv_label_create(ui_bluetoothconnect);
    lv_obj_set_width(ui_bluetoothsymbol, LV_SIZE_CONTENT);   /// 104
    lv_obj_set_height(ui_bluetoothsymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluetoothsymbol, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_bluetoothsymbol, LV_SYMBOL_BLUETOOTH_B);
    lv_obj_set_style_text_color(ui_bluetoothsymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bluetoothsymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bluetoothsymbol, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothname = lv_label_create(ui_bluetoothconnect);
    lv_obj_set_width(ui_bluetoothname, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothname, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothname, 35);
    lv_obj_set_y(ui_bluetoothname, 0);
    lv_label_set_text(ui_bluetoothname, "GV9850");
    lv_obj_set_style_text_color(ui_bluetoothname, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bluetoothname, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothstats = lv_label_create(ui_bluetoothconnect);
    lv_obj_set_width(ui_bluetoothstats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothstats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothstats, 35);
    lv_obj_set_y(ui_bluetoothstats, 0);
    lv_obj_set_align(ui_bluetoothstats, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_bluetoothstats, "Connected | In use");
    lv_obj_set_style_text_color(ui_bluetoothstats, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bluetoothstats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothconright = lv_label_create(ui_bluetoothconnect);
    lv_obj_set_width(ui_bluetoothconright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothconright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluetoothconright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_bluetoothconright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_color(ui_bluetoothconright, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bluetoothconright, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bluetoothconright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothscan = lv_obj_create(ui_bluetoothpannel);
    lv_obj_set_width(ui_bluetoothscan, 280);
    lv_obj_set_height(ui_bluetoothscan, 30);
    lv_obj_set_x(ui_bluetoothscan, 0);
    lv_obj_set_y(ui_bluetoothscan, 125);
    lv_obj_set_align(ui_bluetoothscan, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(ui_bluetoothscan, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_bluetoothscan, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_bluetoothscan, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_bluetoothscan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothscan, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothscan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_bluetoothscan, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_bluetoothscan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothscan, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_bluetoothscan, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bluetoothscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bluetoothscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bluetoothscan, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bluetoothscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothselecttitle = lv_label_create(ui_bluetoothscan);
    lv_obj_set_height(ui_bluetoothselecttitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_flex_grow(ui_bluetoothselecttitle, 1);
    lv_obj_set_align(ui_bluetoothselecttitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_bluetoothselecttitle, "available equipment");
    lv_obj_set_style_text_font(ui_bluetoothselecttitle, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothselecttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoohtrefresh = lv_img_create(ui_bluetoothscan);
    lv_img_set_src(ui_bluetoohtrefresh, &ui_img_refresh_png);
    lv_obj_set_width(ui_bluetoohtrefresh, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoohtrefresh, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoohtrefresh, 0);
    lv_obj_set_y(ui_bluetoohtrefresh, 0);
    lv_obj_set_align(ui_bluetoohtrefresh, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bluetoohtrefresh, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_bluetoohtrefresh, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    ui_bluetoothlist = lv_obj_create(ui_bluetoothpannel);
    lv_obj_set_width(ui_bluetoothlist, 280);
    lv_obj_set_height(ui_bluetoothlist, 40);
    lv_obj_set_align(ui_bluetoothlist, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bluetoothlist, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_bluetoothlist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluetoothlist, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluetoothlist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_bluetoothlist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothsymbol1 = lv_label_create(ui_bluetoothlist);
    lv_obj_set_width(ui_bluetoothsymbol1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothsymbol1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluetoothsymbol1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_bluetoothsymbol1, LV_SYMBOL_BLUETOOTH_B);
    lv_obj_set_style_text_font(ui_bluetoothsymbol1, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothlistname = lv_label_create(ui_bluetoothlist);
    lv_obj_set_width(ui_bluetoothlistname, 200);
    lv_obj_set_height(ui_bluetoothlistname, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothlistname, 30);
    lv_obj_set_y(ui_bluetoothlistname, 0);
    lv_obj_set_align(ui_bluetoothlistname, LV_ALIGN_LEFT_MID);
    lv_label_set_long_mode(ui_bluetoothlistname, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_bluetoothlistname, "IQiYI");
    lv_obj_add_flag(ui_bluetoothlistname, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE);     /// Flags

    ui_bluetoothlistright = lv_label_create(ui_bluetoothlist);
    lv_obj_set_width(ui_bluetoothlistright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothlistright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluetoothlistright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_bluetoothlistright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_font(ui_bluetoothlistright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_blacklistpanel = lv_obj_create(ui_bluetoothpannel);
    lv_obj_set_width(ui_blacklistpanel, 280);
    lv_obj_set_height(ui_blacklistpanel, 30);
    lv_obj_set_x(ui_blacklistpanel, 0);
    lv_obj_set_y(ui_blacklistpanel, 125);
    lv_obj_set_align(ui_blacklistpanel, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(ui_blacklistpanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_blacklistpanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_blacklistpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_blacklistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_blacklistpanel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_blacklistpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_blacklistpanel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_blacklistpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_blacklistpanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_blacklistpanel, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_blacklistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_blacklistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_blacklistpanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_blacklistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothblacklist = lv_label_create(ui_blacklistpanel);
    lv_obj_set_height(ui_bluetoothblacklist, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_flex_grow(ui_bluetoothblacklist, 1);
    lv_obj_set_align(ui_bluetoothblacklist, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_bluetoothblacklist, "Bluetooth device blacklist");
    lv_obj_set_style_text_font(ui_bluetoothblacklist, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluetoothblacklist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_blacklistright = lv_label_create(ui_blacklistpanel);
    lv_obj_set_width(ui_blacklistright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_blacklistright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_blacklistright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_blacklistright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_font(ui_blacklistright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_enterbluetooth = lv_obj_create(ui_bluetoothset);
    lv_obj_set_width(ui_enterbluetooth, 320);
    lv_obj_set_height(ui_enterbluetooth, 350);
    lv_obj_set_x(ui_enterbluetooth, 0);
    lv_obj_set_y(ui_enterbluetooth, 720);
    lv_obj_set_align(ui_enterbluetooth, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_enterbluetooth, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_enterbluetooth, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_enterbluetooth, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_enterbluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_enterbluetooth, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_enterbluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_enterbluetooth, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_enterbluetooth1 = lv_obj_create(ui_enterbluetooth);
    lv_obj_set_width(ui_enterbluetooth1, 280);
    lv_obj_set_height(ui_enterbluetooth1, 200);
    lv_obj_set_align(ui_enterbluetooth1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_enterbluetooth1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_enterbluetooth1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_enterbluetooth1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_enterbluetooth1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_enterbluetooth1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bluetoothnamelabel = lv_label_create(ui_enterbluetooth1);
    lv_obj_set_width(ui_bluetoothnamelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothnamelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluetoothnamelabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bluetoothnamelabel, "Do you want to pair with IQiYI?");
    lv_obj_set_style_text_font(ui_bluetoothnamelabel, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_blacklist = lv_btn_create(ui_enterbluetooth1);
    lv_obj_set_width(ui_blacklist, 200);
    lv_obj_set_height(ui_blacklist, 40);
    lv_obj_set_x(ui_blacklist, -10);
    lv_obj_set_y(ui_blacklist, 0);
    lv_obj_set_align(ui_blacklist, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_blacklist, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_blacklist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_blacklist, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_blacklist, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_blacklist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_blacklist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_blacklist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_blacklist, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_blacklist, 50, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_blacklist, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_blacklist, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_blacklist, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_blacklist, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_blacklist, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_blacklist, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_blacklisttext = lv_label_create(ui_blacklist);
    lv_obj_set_width(ui_blacklisttext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_blacklisttext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_blacklisttext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_blacklisttext, "Add to blacklist");

    ui_canceltbtn1 = lv_btn_create(ui_enterbluetooth1);
    lv_obj_set_width(ui_canceltbtn1, 200);
    lv_obj_set_height(ui_canceltbtn1, 40);
    lv_obj_set_x(ui_canceltbtn1, -10);
    lv_obj_set_y(ui_canceltbtn1, 0);
    lv_obj_set_align(ui_canceltbtn1, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_canceltbtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_canceltbtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_canceltbtn1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_canceltbtn1, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_canceltbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_canceltbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_canceltbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_canceltbtn1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_canceltbtn1, 50, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_canceltbtn1, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_canceltbtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_canceltbtn1, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_canceltbtn1, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_canceltbtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_canceltbtn1, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_canceltext1 = lv_label_create(ui_canceltbtn1);
    lv_obj_set_width(ui_canceltext1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_canceltext1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_canceltext1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_canceltext1, "cancel");

    ui_connectbtn1 = lv_btn_create(ui_enterbluetooth1);
    lv_obj_set_width(ui_connectbtn1, 200);
    lv_obj_set_height(ui_connectbtn1, 40);
    lv_obj_set_x(ui_connectbtn1, 10);
    lv_obj_set_y(ui_connectbtn1, 0);
    lv_obj_set_align(ui_connectbtn1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_connectbtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_connectbtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_connectbtn1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_connectbtn1, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_connectbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_connectbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_connectbtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_connectbtn1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_connectbtn1, 50, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_connectbtn1, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_connectbtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_connectbtn1, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_connectbtn1, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_connectbtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_connectbtn1, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_connecttext1 = lv_label_create(ui_connectbtn1);
    lv_obj_set_width(ui_connecttext1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_connecttext1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_connecttext1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connecttext1, "pairing");

    ui_keypannel1 = lv_obj_create(ui_enterbluetooth);
    lv_obj_set_width(ui_keypannel1, 320);
    lv_obj_set_height(ui_keypannel1, 160);
    lv_obj_set_align(ui_keypannel1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_keypannel1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_keypannel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Keyboard1 = lv_keyboard_create(ui_keypannel1);
    lv_obj_set_width(ui_Keyboard1, 320);
    lv_obj_set_height(ui_Keyboard1, 160);
    lv_obj_set_align(ui_Keyboard1, LV_ALIGN_CENTER);

    lv_obj_set_style_text_font(ui_Keyboard1, &misans16, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_bluetoothbackico, ui_event_bluetoothbackico, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoothswitch, ui_event_bluetoothswitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoohtrefresh, ui_event_bluetoohtrefresh, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoothlistname, ui_event_bluetoothlistname, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoothlist, ui_event_bluetoothlist, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_blacklist, ui_event_blacklist, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_canceltbtn1, ui_event_canceltbtn1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_connectbtn1, ui_event_connectbtn1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoothset, ui_event_bluetoothset, LV_EVENT_ALL, NULL);

}
