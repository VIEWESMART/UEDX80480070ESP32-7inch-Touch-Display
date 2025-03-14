#include "../ui.h"

void ui_weatherscreen_screen_init(void)
{
    ui_weatherscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_weatherscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_weatherscreen, &ui_img_weatherbg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherscreen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherscreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherscreen, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherbody = lv_obj_create(ui_weatherscreen);
    lv_obj_set_width(ui_weatherbody, 320);
    lv_obj_set_height(ui_weatherbody, 480);
    lv_obj_set_x(ui_weatherbody, 0);
    lv_obj_set_y(ui_weatherbody, -1);
    lv_obj_set_align(ui_weatherbody, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherbody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_weatherbody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherbody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherbody, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherheader = lv_obj_create(ui_weatherbody);
    lv_obj_set_width(ui_weatherheader, 320);
    lv_obj_set_height(ui_weatherheader, 50);
    lv_obj_set_x(ui_weatherheader, -121);
    lv_obj_set_y(ui_weatherheader, 40);
    lv_obj_set_align(ui_weatherheader, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherheader, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherheader, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_weatherheader, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherheader, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherset = lv_label_create(ui_weatherheader);
    lv_obj_set_width(ui_weatherset, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherset, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weatherset, 118);
    lv_obj_set_y(ui_weatherset, -217);
    lv_obj_set_align(ui_weatherset, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherset, "Settings");
    lv_obj_add_flag(ui_weatherset, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_weathercity = lv_obj_create(ui_weatherbody);
    lv_obj_set_width(ui_weathercity, 320);
    lv_obj_set_height(ui_weathercity, 30);
    lv_obj_set_x(ui_weathercity, 0);
    lv_obj_set_y(ui_weathercity, -160);
    lv_obj_set_align(ui_weathercity, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weathercity, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weathercity, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weathercity, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weathercity, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weathercity, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weathercity, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weathercity, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weathercity, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weathercity, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherprovincelabel = lv_label_create(ui_weathercity);
    lv_obj_set_width(ui_weatherprovincelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherprovincelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weatherprovincelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherprovincelabel, "Guangdong");

    ui_weathercitylabel = lv_label_create(ui_weathercity);
    lv_obj_set_width(ui_weathercitylabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weathercitylabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weathercitylabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weathercitylabel, "Shenzhen");

    ui_weathertemperature = lv_obj_create(ui_weatherbody);
    lv_obj_set_width(ui_weathertemperature, 320);
    lv_obj_set_height(ui_weathertemperature, 90);
    lv_obj_set_x(ui_weathertemperature, -1);
    lv_obj_set_y(ui_weathertemperature, 0);
    lv_obj_set_align(ui_weathertemperature, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weathertemperature, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weathertemperature, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weathertemperature, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weathertemperature, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weathertemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weathertemperature, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weathertemperature, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weathertemperature, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weathertemperature, &ui_font_misans96, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weathertemperaturelabel = lv_label_create(ui_weathertemperature);
    lv_obj_set_width(ui_weathertemperaturelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weathertemperaturelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weathertemperaturelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weathertemperaturelabel, "13°");

    ui_weatherpanel = lv_obj_create(ui_weatherbody);
    lv_obj_set_width(ui_weatherpanel, 320);
    lv_obj_set_height(ui_weatherpanel, 20);
    lv_obj_set_x(ui_weatherpanel, -5);
    lv_obj_set_y(ui_weatherpanel, 65);
    lv_obj_set_align(ui_weatherpanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherpanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherpanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherpanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherpanel, lv_color_hex(0xF4F4F4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherpanel, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherlabel1 = lv_label_create(ui_weatherpanel);
    lv_obj_set_width(ui_weatherlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weatherlabel1, -26);
    lv_obj_set_y(ui_weatherlabel1, -8);
    lv_obj_set_align(ui_weatherlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherlabel1, "sunny");

    ui_weatherabel2 = lv_label_create(ui_weatherpanel);
    lv_obj_set_width(ui_weatherabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weatherabel2, -63);
    lv_obj_set_y(ui_weatherabel2, -18);
    lv_obj_set_align(ui_weatherabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherabel2, "Maximum temperature 14 °");

    ui_weatherabel3 = lv_label_create(ui_weatherpanel);
    lv_obj_set_width(ui_weatherabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weatherabel3, 46);
    lv_obj_set_y(ui_weatherabel3, 17);
    lv_obj_set_align(ui_weatherabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherabel3, "Minimum temperature -1 °");

    ui_weatherabel4 = lv_label_create(ui_weatherpanel);
    lv_obj_set_width(ui_weatherabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weatherabel4, 96);
    lv_obj_set_y(ui_weatherabel4, 6);
    lv_obj_set_align(ui_weatherabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherabel4, "Humidity 62%");

    ui_weatherpanel1 = lv_obj_create(ui_weatherbody);
    lv_obj_set_width(ui_weatherpanel1, 320);
    lv_obj_set_height(ui_weatherpanel1, 20);
    lv_obj_set_align(ui_weatherpanel1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherpanel1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherpanel1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherpanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherpanel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherpanel1, lv_color_hex(0xF4F4F4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherpanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherpanel1, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherabel5 = lv_label_create(ui_weatherpanel1);
    lv_obj_set_width(ui_weatherabel5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weatherabel5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherabel5, "northwest wind");

    ui_weatherabel6 = lv_label_create(ui_weatherpanel1);
    lv_obj_set_width(ui_weatherabel6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weatherabel6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherabel6, "Level 1-3");

    ui_weatherfoot = lv_obj_create(ui_weatherscreen);
    lv_obj_set_width(ui_weatherfoot, 280);
    lv_obj_set_height(ui_weatherfoot, 150);
    lv_obj_set_x(ui_weatherfoot, 0);
    lv_obj_set_y(ui_weatherfoot, 150);
    lv_obj_set_align(ui_weatherfoot, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherfoot, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_weatherfoot, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherfoot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_weatherfoot, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_weatherfoot, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherfoot, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherfoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_weatherfoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_weatherfoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherfuture = lv_obj_create(ui_weatherfoot);
    lv_obj_set_width(ui_weatherfuture, 240);
    lv_obj_set_height(ui_weatherfuture, 42);
    lv_obj_set_align(ui_weatherfuture, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherfuture, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherfuture, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherfuture, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherfuture, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherfuture, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_weatherfuture, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_weatherfuture, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherfuture, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_weatherfuture, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherfuture, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherfuture, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherfuture, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label10 = lv_label_create(ui_weatherfuture);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Tomorrow");

    ui_Label13 = lv_label_create(ui_weatherfuture);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "cloudy");

    ui_Label14 = lv_label_create(ui_weatherfuture);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "-1°");

    ui_Label15 = lv_label_create(ui_weatherfuture);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "14°");

    ui_weatherfuture1 = lv_obj_create(ui_weatherfoot);
    lv_obj_set_width(ui_weatherfuture1, 240);
    lv_obj_set_height(ui_weatherfuture1, 42);
    lv_obj_set_align(ui_weatherfuture1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherfuture1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherfuture1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherfuture1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherfuture1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherfuture1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_weatherfuture1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_weatherfuture1, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherfuture1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_weatherfuture1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherfuture1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherfuture1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherfuture1, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_weatherfuture1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "dieb tert");

    ui_Label16 = lv_label_create(ui_weatherfuture1);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "sunny");

    ui_Label17 = lv_label_create(ui_weatherfuture1);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "-2°");

    ui_Label18 = lv_label_create(ui_weatherfuture1);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "10°");

    ui_weatherfuture2 = lv_obj_create(ui_weatherfoot);
    lv_obj_set_width(ui_weatherfuture2, 240);
    lv_obj_set_height(ui_weatherfuture2, 42);
    lv_obj_set_align(ui_weatherfuture2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weatherfuture2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_weatherfuture2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherfuture2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_weatherfuture2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_weatherfuture2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_weatherfuture2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_weatherfuture2, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weatherfuture2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_weatherfuture2, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_weatherfuture2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherfuture2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherfuture2, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_weatherfuture2);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Saturday");

    ui_Label19 = lv_label_create(ui_weatherfuture2);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "sunny");

    ui_Label20 = lv_label_create(ui_weatherfuture2);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "0°");

    ui_Label21 = lv_label_create(ui_weatherfuture2);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "13°");

    ui_weathercitypanel = lv_obj_create(ui_weatherscreen);
    lv_obj_set_width(ui_weathercitypanel, 150);
    lv_obj_set_height(ui_weathercitypanel, 120);
    lv_obj_set_x(ui_weathercitypanel, 80);
    lv_obj_set_y(ui_weathercitypanel, -160);
    lv_obj_set_align(ui_weathercitypanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_weathercitypanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_weathercitypanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_weathercitypanel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_weathercitypanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_weathercityarea = lv_textarea_create(ui_weathercitypanel);
    lv_obj_set_width(ui_weathercityarea, 100);
    lv_obj_set_height(ui_weathercityarea, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weathercityarea, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_weathercityarea, 8);
    lv_textarea_set_text(ui_weathercityarea, "371702");
    lv_textarea_set_placeholder_text(ui_weathercityarea, "zoning code..");
    lv_textarea_set_one_line(ui_weathercityarea, true);
    lv_obj_set_style_border_color(ui_weathercityarea, lv_color_hex(0xAAAAAA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_weathercityarea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_weathercityarea, 1, LV_PART_MAIN | LV_STATE_DEFAULT);



    ui_weatherbutton = lv_btn_create(ui_weathercitypanel);
    lv_obj_set_width(ui_weatherbutton, 80);
    lv_obj_set_height(ui_weatherbutton, 30);
    lv_obj_set_align(ui_weatherbutton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_weatherbutton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_weatherbutton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(ui_weatherbutton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_weatherbutton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherbuttontext = lv_label_create(ui_weatherbutton);
    lv_obj_set_width(ui_weatherbuttontext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weatherbuttontext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_weatherbuttontext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weatherbuttontext, "confirm");

    ui_weatherkey = lv_obj_create(ui_weatherscreen);
    lv_obj_set_width(ui_weatherkey, 320);
    lv_obj_set_height(ui_weatherkey, 160);
    lv_obj_set_x(ui_weatherkey, 0);
    lv_obj_set_y(ui_weatherkey, 640);
    lv_obj_set_align(ui_weatherkey, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_weatherkey, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_weatherkey, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_weatherkey, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Keyboard2 = lv_keyboard_create(ui_weatherkey);
    lv_obj_set_width(ui_Keyboard2, 320);
    lv_obj_set_height(ui_Keyboard2, 160);
    lv_obj_set_align(ui_Keyboard2, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_weatherset, ui_event_weatherset, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_weatherbutton, ui_event_weatherbutton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_weatherscreen, ui_event_weatherscreen, LV_EVENT_ALL, NULL);

}
