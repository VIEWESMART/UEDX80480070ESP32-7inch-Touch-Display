#include "../ui.h"

void ui_wifiset_screen_init(void)
{
    ui_wifiset = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_wifiset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wifiset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifiset, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifiset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifiset, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlanheader = lv_obj_create(ui_wifiset);
    lv_obj_set_width(ui_wlanheader, 320);
    lv_obj_set_height(ui_wlanheader, 60);
    lv_obj_set_align(ui_wlanheader, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_wlanheader, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wlanheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wlanheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wlanheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_wlanheader, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wlanheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wlanheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_wlanheader, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wlanheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wlanheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wlanheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wlanheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_wlanheader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wlanheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wlanheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlanmobile = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlanmobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlanmobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlanmobile, 10);
    lv_obj_set_y(ui_wlanmobile, 7);
    lv_label_set_text(ui_wlanmobile, "Mobile");

    ui_wlanwifi = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlanwifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlanwifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlanwifi, 78);
    lv_obj_set_y(ui_wlanwifi, 7);
    lv_label_set_text(ui_wlanwifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_wlanwifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_wlanwifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlanbattery = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlanbattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlanbattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlanbattery, -10);
    lv_obj_set_y(ui_wlanbattery, 7);
    lv_obj_set_align(ui_wlanbattery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_3);
    lv_obj_set_style_text_font(ui_wlanbattery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlantime = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlantime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlantime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlantime, 0);
    lv_obj_set_y(ui_wlantime, 7);
    lv_obj_set_align(ui_wlantime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_wlantime, "12:12");

    ui_wlanbatteryp = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlanbatteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlanbatteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlanbatteryp, -35);
    lv_obj_set_y(ui_wlanbatteryp, 7);
    lv_obj_set_align(ui_wlanbatteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_wlanbatteryp, "89%");

    ui_wlantitle = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_wlantitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlantitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlantitle, 30);
    lv_obj_set_y(ui_wlantitle, -2);
    lv_obj_set_align(ui_wlantitle, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_wlantitle, "WLAN set");

    ui_headerbackico = lv_label_create(ui_wlanheader);
    lv_obj_set_width(ui_headerbackico, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_headerbackico, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_headerbackico, 10);
    lv_obj_set_y(ui_headerbackico, -3);
    lv_obj_set_align(ui_headerbackico, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_headerbackico, LV_SYMBOL_LEFT);
    lv_obj_add_flag(ui_headerbackico, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_font(ui_headerbackico, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlansetpannel = lv_obj_create(ui_wifiset);
    lv_obj_set_width(ui_wlansetpannel, 320);
    lv_obj_set_height(ui_wlansetpannel, 420);
    lv_obj_set_x(ui_wlansetpannel, 0);
    lv_obj_set_y(ui_wlansetpannel, 60);
    lv_obj_set_align(ui_wlansetpannel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_wlansetpannel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_wlansetpannel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(ui_wlansetpannel, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_wlansetpannel, LV_DIR_VER);
    lv_obj_set_style_radius(ui_wlansetpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wlansetpannel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wlansetpannel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wlansetpannel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlanswitchpanel = lv_obj_create(ui_wlansetpannel);
    lv_obj_set_width(ui_wlanswitchpanel, 280);
    lv_obj_set_height(ui_wlanswitchpanel, 40);
    lv_obj_set_align(ui_wlanswitchpanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_wlanswitchpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wlanswitchpanel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wlanswitchpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wlanswitchpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wlansetlabel = lv_label_create(ui_wlanswitchpanel);
    lv_obj_set_width(ui_wlansetlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wlansetlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wlansetlabel, 0);
    lv_obj_set_y(ui_wlansetlabel, 4);
    lv_label_set_text(ui_wlansetlabel, "WLAN");

    ui_wlanswitch = lv_switch_create(ui_wlanswitchpanel);
    lv_obj_set_width(ui_wlanswitch, 45);
    lv_obj_set_height(ui_wlanswitch, 24);
    lv_obj_set_align(ui_wlanswitch, LV_ALIGN_TOP_RIGHT);

    lv_obj_set_style_bg_color(ui_wlanswitch, lv_color_hex(0xAAAAAA), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wlanswitch, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wlanswitch, lv_color_hex(0x00D200), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_wlanswitch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_wificonnect = lv_obj_create(ui_wlansetpannel);
    lv_obj_set_width(ui_wificonnect, 280);
    lv_obj_set_height(ui_wificonnect, 70);
    lv_obj_set_x(ui_wificonnect, 0);
    lv_obj_set_y(ui_wificonnect, 45);
    lv_obj_set_align(ui_wificonnect, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_wificonnect, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_wificonnect, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wificonnect, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wificonnect, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wificonnect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wificonnect, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifisymbol = lv_label_create(ui_wificonnect);
    lv_obj_set_width(ui_wifisymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifisymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifisymbol, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_wifisymbol, LV_SYMBOL_WIFI);
    lv_obj_set_style_text_color(ui_wifisymbol, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifisymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifisymbol, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifiname = lv_label_create(ui_wificonnect);
    lv_obj_set_width(ui_wifiname, 180);   /// 1
    lv_obj_set_height(ui_wifiname, LV_SIZE_CONTENT);    /// 1
    lv_label_set_long_mode(ui_wifiname,LV_LABEL_LONG_DOT);
    lv_obj_set_x(ui_wifiname, 35);
    lv_obj_set_y(ui_wifiname, 0);
    lv_label_set_text(ui_wifiname, "cmcc-4g");
    lv_obj_set_style_text_color(ui_wifiname, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifiname, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifistats = lv_label_create(ui_wificonnect);
    lv_obj_set_width(ui_wifistats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifistats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifistats, 35);
    lv_obj_set_y(ui_wifistats, 0);
    lv_obj_set_align(ui_wifistats, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_wifistats, "Connected");
    lv_obj_set_style_text_color(ui_wifistats, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifistats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wificlock = lv_label_create(ui_wificonnect);
    lv_obj_set_width(ui_wificlock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wificlock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wificlock, -20);
    lv_obj_set_y(ui_wificlock, 0);
    lv_obj_set_align(ui_wificlock, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wificlock, LV_SYMBOL_LOCK);
    lv_obj_set_style_text_color(ui_wificlock, lv_color_hex(0xDFDFDF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wificlock, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wificlock, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wificonright = lv_label_create(ui_wificonnect);
    lv_obj_set_width(ui_wificonright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wificonright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wificonright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_wificonright, LV_SYMBOL_RIGHT);
    lv_obj_set_style_text_color(ui_wificonright, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wificonright, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wificonright, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifiscan = lv_obj_create(ui_wlansetpannel);
    lv_obj_set_width(ui_wifiscan, 280);
    lv_obj_set_height(ui_wifiscan, 30);
    lv_obj_set_x(ui_wifiscan, 0);
    lv_obj_set_y(ui_wifiscan, 125);
    lv_obj_set_align(ui_wifiscan, LV_ALIGN_LEFT_MID);
    lv_obj_set_flex_flow(ui_wifiscan, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_wifiscan, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(ui_wifiscan, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_wifiscan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wifiscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifiscan, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifiscan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_wifiscan, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wifiscan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifiscan, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_wifiscan, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_wifiscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_wifiscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_wifiscan, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_wifiscan, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifiselecttitle = lv_label_create(ui_wifiscan);
    lv_obj_set_height(ui_wifiselecttitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_flex_grow(ui_wifiselecttitle, 1);
    lv_obj_set_align(ui_wifiselecttitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_wifiselecttitle, "Select a nearby WLAN");
    lv_obj_set_style_text_font(ui_wifiselecttitle, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifiselecttitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifirefresh = lv_img_create(ui_wifiscan);
    lv_img_set_src(ui_wifirefresh, &ui_img_refresh_png);
    lv_obj_set_width(ui_wifirefresh, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifirefresh, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifirefresh, 0);
    lv_obj_set_y(ui_wifirefresh, 0);
    lv_obj_set_align(ui_wifirefresh, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_wifirefresh, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_wifirefresh, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_wifilistpanel = lv_obj_create(ui_wlansetpannel);
    lv_obj_set_width(ui_wifilistpanel, 280);
    lv_obj_set_height(ui_wifilistpanel, LV_SIZE_CONTENT);    /// 2
    lv_obj_set_align(ui_wifilistpanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_wifilistpanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_wifilistpanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_wifilistpanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_wifilistpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_wifilistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifilistpanel, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifilistpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifilistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_enterwifipass = lv_obj_create(ui_wifiset);
    lv_obj_set_width(ui_enterwifipass, 320);
    lv_obj_set_height(ui_enterwifipass, 350);
    lv_obj_set_x(ui_enterwifipass, 0);
    lv_obj_set_y(ui_enterwifipass, 610);
    lv_obj_set_align(ui_enterwifipass, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_enterwifipass, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_enterwifipass, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_enterwifipass, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_enterwifipass, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_enterwifipass, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_enterwifipass, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_enterwifipass, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_passpannel = lv_obj_create(ui_enterwifipass);
    lv_obj_set_width(ui_passpannel, 280);
    lv_obj_set_height(ui_passpannel, 170);
    lv_obj_set_align(ui_passpannel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_passpannel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_wifinamelabel = lv_label_create(ui_passpannel);
    lv_obj_set_width(ui_wifinamelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifinamelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifinamelabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_wifinamelabel, "MAXHUB-433");
    lv_obj_set_style_text_font(ui_wifinamelabel, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifipassinput = lv_textarea_create(ui_passpannel);
    lv_obj_set_width(ui_wifipassinput, 260);
    lv_obj_set_height(ui_wifipassinput, LV_SIZE_CONTENT);    /// 40
    lv_obj_set_x(ui_wifipassinput, 0);
    lv_obj_set_y(ui_wifipassinput, -10);
    lv_obj_set_align(ui_wifipassinput, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_wifipassinput, 64);
    lv_textarea_set_placeholder_text(ui_wifipassinput, "password");
    lv_textarea_set_one_line(ui_wifipassinput, true);
    lv_textarea_set_password_mode(ui_wifipassinput, true);
    lv_obj_clear_flag(ui_wifipassinput, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_border_color(ui_wifipassinput, lv_color_hex(0x0079F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_wifipassinput, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifipassinput, 1, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_connectbtn = lv_btn_create(ui_passpannel);
    lv_obj_set_width(ui_connectbtn, 100);
    lv_obj_set_height(ui_connectbtn, 40);
    lv_obj_set_x(ui_connectbtn, 10);
    lv_obj_set_y(ui_connectbtn, 0);
    lv_obj_set_align(ui_connectbtn, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_connectbtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_connectbtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_connectbtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_connectbtn, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_connectbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_connectbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_connectbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_connectbtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_connectbtn, 50, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_connectbtn, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_connectbtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_connectbtn, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_connectbtn, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_connectbtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_connectbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_connecttext = lv_label_create(ui_connectbtn);
    lv_obj_set_width(ui_connecttext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_connecttext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_connecttext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_connecttext, "connect");

    ui_canceltbtn = lv_btn_create(ui_passpannel);
    lv_obj_set_width(ui_canceltbtn, 100);
    lv_obj_set_height(ui_canceltbtn, 40);
    lv_obj_set_x(ui_canceltbtn, -10);
    lv_obj_set_y(ui_canceltbtn, 0);
    lv_obj_set_align(ui_canceltbtn, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_canceltbtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_canceltbtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_canceltbtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_canceltbtn, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_canceltbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_canceltbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_canceltbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_canceltbtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_canceltbtn, 50, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_canceltbtn, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_canceltbtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_canceltbtn, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_canceltbtn, lv_color_hex(0x1D87F5), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_canceltbtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_canceltbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_canceltext = lv_label_create(ui_canceltbtn);
    lv_obj_set_width(ui_canceltext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_canceltext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_canceltext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_canceltext, "cancel");

    ui_keypannel = lv_obj_create(ui_enterwifipass);
    lv_obj_set_width(ui_keypannel, 320);
    lv_obj_set_height(ui_keypannel, 160);
    lv_obj_set_align(ui_keypannel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_keypannel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Keyboard = lv_keyboard_create(ui_keypannel);
    lv_obj_set_width(ui_Keyboard, 320);
    lv_obj_set_height(ui_Keyboard, 160);
    lv_obj_set_align(ui_Keyboard, LV_ALIGN_CENTER);

    lv_obj_set_style_text_font(ui_Keyboard, &misans16, LV_PART_ITEMS | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_headerbackico, ui_event_headerbackico, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wlanswitch, ui_event_wlanswitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wifirefresh, ui_event_wifirefresh, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_wifilistname, ui_event_wifilistname, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wifipassinput, ui_event_wifipassinput, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_connectbtn, ui_event_connectbtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_canceltbtn, ui_event_canceltbtn, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_Keyboard, ui_wifipassinput);
    lv_obj_add_event_cb(ui_wifiset, ui_event_wifiset, LV_EVENT_ALL, NULL);

}
