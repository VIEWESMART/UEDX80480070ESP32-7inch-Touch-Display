#include "../ui.h"
#include "esp_idf_version.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_psram.h"
#include "esp_mac.h"

void ui_aboutui_screen_init(void)
{
    esp_chip_info_t chipinfo;
    esp_chip_info(&chipinfo);
    char *esp_type;
    switch (chipinfo.model)
    {
    case CHIP_ESP32 /* constant-expression */:
        esp_type = "ESP32"; /* code */
        break;
    case CHIP_ESP32S2 /* constant-expression */:
        esp_type = "ESP32-S2"; /* code */
        break;
    case CHIP_ESP32S3 /* constant-expression */:
        esp_type = "ESP32-S3"; /* code */
        break;
    case CHIP_ESP32C3 /* constant-expression */:
        esp_type = "ESP32-C3"; /* code */
        break;
    case CHIP_ESP32H2 /* constant-expression */:
        esp_type = "ESP32-H2"; /* code */
        break;
    case CHIP_ESP32C2 /* constant-expression */:
        esp_type = "ESP32-C2"; /* code */
        break;
    default:
        esp_type = "未知型号";
        break;
    }
    ui_aboutui = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_aboutui, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutui, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutui, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutui, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_aboutui, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutheader = lv_obj_create(ui_aboutui);
    lv_obj_set_width(ui_aboutheader, 320);
    lv_obj_set_height(ui_aboutheader, 60);
    lv_obj_set_align(ui_aboutheader, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutheader, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutheader, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutheader, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_aboutheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_aboutheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_aboutheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_aboutheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_aboutheader, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_aboutheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutmobile = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_aboutmobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutmobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aboutmobile, 10);
    lv_obj_set_y(ui_aboutmobile, 7);
    lv_label_set_text(ui_aboutmobile, "Mobile");

    ui_aboutwifi = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_aboutwifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutwifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aboutwifi, 78);
    lv_obj_set_y(ui_aboutwifi, 7);
    lv_label_set_text(ui_aboutwifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_aboutwifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_aboutwifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutbattery = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_aboutbattery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutbattery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aboutbattery, -10);
    lv_obj_set_y(ui_aboutbattery, 7);
    lv_obj_set_align(ui_aboutbattery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_3);
    lv_obj_set_style_text_font(ui_aboutbattery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_abouttime = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_abouttime, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_abouttime, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_abouttime, 0);
    lv_obj_set_y(ui_abouttime, 7);
    lv_obj_set_align(ui_abouttime, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_abouttime, "12:12");

    ui_aboutbatteryp = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_aboutbatteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutbatteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_aboutbatteryp, -35);
    lv_obj_set_y(ui_aboutbatteryp, 7);
    lv_obj_set_align(ui_aboutbatteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_aboutbatteryp, "89%");

    ui_abouttitle = lv_label_create(ui_aboutheader);
    lv_obj_set_width(ui_abouttitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_abouttitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_abouttitle, 0);
    lv_obj_set_y(ui_abouttitle, -2);
    lv_obj_set_align(ui_abouttitle, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_abouttitle, "About this machine");

    ui_aboutbody = lv_obj_create(ui_aboutui);
    lv_obj_set_width(ui_aboutbody, 320);
    lv_obj_set_height(ui_aboutbody, 420);
    lv_obj_set_x(ui_aboutbody, 0);
    lv_obj_set_y(ui_aboutbody, 60);
    lv_obj_set_align(ui_aboutbody, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_aboutbody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_aboutbody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_aboutbody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutbody, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutbody, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_aboutbody, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_aboutbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelname = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelname, 320);
    lv_obj_set_height(ui_aboutpanelname, 40);
    lv_obj_set_align(ui_aboutpanelname, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelname, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelname, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelname, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelname, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelname, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelname, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelname, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelname, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutnamelabel = lv_label_create(ui_aboutpanelname);
    lv_obj_set_width(ui_aboutnamelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutnamelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutnamelabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutnamelabel, "name");

    ui_aboutnamelabel1 = lv_label_create(ui_aboutpanelname);
    lv_obj_set_width(ui_aboutnamelabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutnamelabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutnamelabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_aboutnamelabel1, "VIEWE 1.2");
    lv_obj_set_style_text_color(ui_aboutnamelabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutnamelabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelversion = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelversion, 320);
    lv_obj_set_height(ui_aboutpanelversion, 40);
    lv_obj_set_align(ui_aboutpanelversion, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelversion, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelversion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelversion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelversion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelversion, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelversion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelversion, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelversion, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutversionlabel = lv_label_create(ui_aboutpanelversion);
    lv_obj_set_width(ui_aboutversionlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutversionlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutversionlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutversionlabel, "IDF versions");

    ui_aboutversion1 = lv_label_create(ui_aboutpanelversion);
    lv_obj_set_width(ui_aboutversion1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutversion1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutversion1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_aboutversion1, esp_get_idf_version());
    lv_obj_set_style_text_color(ui_aboutversion1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutversion1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelmodel = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelmodel, 320);
    lv_obj_set_height(ui_aboutpanelmodel, 40);
    lv_obj_set_align(ui_aboutpanelmodel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelmodel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelmodel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelmodel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelmodel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelmodel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelmodel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelmodel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelmodel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutmodellabel = lv_label_create(ui_aboutpanelmodel);
    lv_obj_set_width(ui_aboutmodellabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutmodellabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutmodellabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutmodellabel, "CPU Model");

    ui_aboutmodellabel1 = lv_label_create(ui_aboutpanelmodel);
    lv_obj_set_width(ui_aboutmodellabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutmodellabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutmodellabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_aboutmodellabel1, esp_type);
    lv_obj_set_style_text_color(ui_aboutmodellabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutmodellabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelcore = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelcore, 320);
    lv_obj_set_height(ui_aboutpanelcore, 40);
    lv_obj_set_align(ui_aboutpanelcore, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelcore, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelcore, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelcore, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelcore, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelcore, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelcore, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelcore, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelcore, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutcorelabel = lv_label_create(ui_aboutpanelcore);
    lv_obj_set_width(ui_aboutcorelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutcorelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutcorelabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutcorelabel, "CPU core count");

    ui_aboutcorelabel1 = lv_label_create(ui_aboutpanelcore);
    lv_obj_set_width(ui_aboutcorelabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutcorelabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutcorelabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text_fmt(ui_aboutcorelabel1, "%dpcs", chipinfo.cores);
    lv_obj_set_style_text_color(ui_aboutcorelabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutcorelabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelreversion = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelreversion, 320);
    lv_obj_set_height(ui_aboutpanelreversion, 40);
    lv_obj_set_align(ui_aboutpanelreversion, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelreversion, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelreversion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelreversion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelreversion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelreversion, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelreversion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelreversion, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelreversion, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutreversionlabel = lv_label_create(ui_aboutpanelreversion);
    lv_obj_set_width(ui_aboutreversionlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutreversionlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutreversionlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutreversionlabel, "CPU amendment number");

    ui_aboutreversionlabel1 = lv_label_create(ui_aboutpanelreversion);
    lv_obj_set_width(ui_aboutreversionlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutreversionlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutreversionlabel1, LV_ALIGN_RIGHT_MID);
    unsigned major_rev = chipinfo.revision / 100;
    unsigned minor_rev = chipinfo.revision % 100;
    lv_label_set_text_fmt(ui_aboutreversionlabel1, "%d.%d", major_rev, minor_rev);
    lv_obj_set_style_text_color(ui_aboutreversionlabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutreversionlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpaneflash = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpaneflash, 320);
    lv_obj_set_height(ui_aboutpaneflash, 40);
    lv_obj_set_align(ui_aboutpaneflash, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpaneflash, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpaneflash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpaneflash, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpaneflash, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpaneflash, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpaneflash, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpaneflash, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpaneflash, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutflashlabel = lv_label_create(ui_aboutpaneflash);
    lv_obj_set_width(ui_aboutflashlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutflashlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutflashlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutflashlabel, "storage space");

    ui_aboutflashlabel1 = lv_label_create(ui_aboutpaneflash);
    lv_obj_set_width(ui_aboutflashlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutflashlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutflashlabel1, LV_ALIGN_RIGHT_MID);
    uint32_t flash_size;
    if (esp_flash_get_size(NULL, &flash_size) != ESP_OK)
    {
        lv_label_set_text(ui_aboutflashlabel1, "Failed to acquire storage space");
    }
    else
    {
        lv_label_set_text_fmt(ui_aboutflashlabel1, "%luMB", flash_size / (1024 * 1024));
    }
    lv_obj_set_style_text_color(ui_aboutflashlabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutflashlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutscreenpanel = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutscreenpanel, 320);
    lv_obj_set_height(ui_aboutscreenpanel, 40);
    lv_obj_set_align(ui_aboutscreenpanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutscreenpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutscreenpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutscreenpanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutscreenpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutscreenpanel, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutscreenpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutscreenpanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutscreenpanel, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutscreenlabel = lv_label_create(ui_aboutscreenpanel);
    lv_obj_set_width(ui_aboutscreenlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutscreenlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutscreenlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutscreenlabel, "Memory capacity");

    ui_aboutscreenlabel1 = lv_label_create(ui_aboutscreenpanel);
    lv_obj_set_width(ui_aboutscreenlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutscreenlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutscreenlabel1, LV_ALIGN_RIGHT_MID);
    if (esp_psram_get_size() == 0)
    {
        lv_label_set_text(ui_aboutscreenlabel1, "Failed to get memory capacity");
    }
    else
    {
        lv_label_set_text_fmt(ui_aboutscreenlabel1, "%dMB", esp_psram_get_size() / (1024 * 1024));
    }
    lv_obj_set_style_text_color(ui_aboutscreenlabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutscreenlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutpanelmac = lv_obj_create(ui_aboutbody);
    lv_obj_set_width(ui_aboutpanelmac, 320);
    lv_obj_set_height(ui_aboutpanelmac, 40);
    lv_obj_set_align(ui_aboutpanelmac, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_aboutpanelmac, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_aboutpanelmac, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_aboutpanelmac, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_aboutpanelmac, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_aboutpanelmac, lv_color_hex(0xB4B4B4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_aboutpanelmac, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_aboutpanelmac, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_aboutpanelmac, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_aboutmaclabel = lv_label_create(ui_aboutpanelmac);
    lv_obj_set_width(ui_aboutmaclabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutmaclabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutmaclabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_aboutmaclabel, "MAC Address");

    ui_aboutmaclabel1 = lv_label_create(ui_aboutpanelmac);
    lv_obj_set_width(ui_aboutmaclabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_aboutmaclabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_aboutmaclabel1, LV_ALIGN_RIGHT_MID);
    uint8_t macadd[6] = {0};
    if (esp_efuse_mac_get_default(macadd) != ESP_OK)
    {
        printf("Failed to obtain MAC address");
        return;
    }
    lv_label_set_text_fmt(ui_aboutmaclabel1, "%X-%X-%X-%X-%X-%X", macadd[0], macadd[1], macadd[2], macadd[3], macadd[4], macadd[5]);
    lv_obj_set_style_text_color(ui_aboutmaclabel1, lv_color_hex(0x787878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_aboutmaclabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_aboutui, ui_event_aboutui, LV_EVENT_ALL, NULL);

}
