#include "../ui.h"

void ui_galleryscreen_screen_init(void)
{
    ui_galleryscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_galleryscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_galleryscreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_galleryscreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_galleryscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_galleryscreen, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_galleryheader = lv_obj_create(ui_galleryscreen);
    lv_obj_set_width(ui_galleryheader, 320);
    lv_obj_set_height(ui_galleryheader, 40);
    lv_obj_set_align(ui_galleryheader, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_galleryheader, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_galleryheader, lv_color_hex(0xE9E9E9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_galleryheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_galleryheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_galleryheaderlabel = lv_label_create(ui_galleryheader);
    lv_obj_set_width(ui_galleryheaderlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_galleryheaderlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_galleryheaderlabel, 10);
    lv_obj_set_y(ui_galleryheaderlabel, 0);
    lv_obj_set_align(ui_galleryheaderlabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_galleryheaderlabel, "album");

    ui_gallerybody = lv_obj_create(ui_galleryscreen);
    lv_obj_set_width(ui_gallerybody, 320);
    lv_obj_set_height(ui_gallerybody, 440);
    lv_obj_set_align(ui_gallerybody, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_gallerybody, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_gallerybody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_gallerybody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_gallerybody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_gallerybody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_gallerybody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_gallerybody, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_gallerybody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_gallerybody, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_gallerybody, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_picpanel = lv_obj_create(ui_gallerybody);
    lv_obj_set_width(ui_picpanel, 100);
    lv_obj_set_height(ui_picpanel, 100);
    lv_obj_set_align(ui_picpanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_picpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_picpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_picpanel, lv_color_hex(0xAE2222), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_picpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_picpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pic = lv_img_create(ui_picpanel);
    lv_img_set_src(ui_pic, &ui_img_qq_png);
    lv_obj_set_width(ui_pic, 100);
    lv_obj_set_height(ui_pic, 100);
    lv_obj_set_align(ui_pic, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pic, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_pic, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pic, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pic, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_picpanel1 = lv_obj_create(ui_gallerybody);
    lv_obj_set_width(ui_picpanel1, 100);
    lv_obj_set_height(ui_picpanel1, 100);
    lv_obj_set_align(ui_picpanel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_picpanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_picpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_picpanel1, lv_color_hex(0xA19DC5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_picpanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_picpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pic1 = lv_img_create(ui_picpanel1);
    lv_img_set_src(ui_pic1, &ui_img_qq_png);
    lv_obj_set_width(ui_pic1, 100);
    lv_obj_set_height(ui_pic1, 100);
    lv_obj_set_align(ui_pic1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pic1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_pic1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pic1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pic1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_picpanel2 = lv_obj_create(ui_gallerybody);
    lv_obj_set_width(ui_picpanel2, 100);
    lv_obj_set_height(ui_picpanel2, 100);
    lv_obj_set_align(ui_picpanel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_picpanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_picpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_picpanel2, lv_color_hex(0x59C661), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_picpanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_picpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pic2 = lv_img_create(ui_picpanel2);
    lv_img_set_src(ui_pic2, &ui_img_qq_png);
    lv_obj_set_width(ui_pic2, 100);
    lv_obj_set_height(ui_pic2, 100);
    lv_obj_set_align(ui_pic2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pic2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_pic2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pic2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pic2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_picpanel3 = lv_obj_create(ui_gallerybody);
    lv_obj_set_width(ui_picpanel3, 100);
    lv_obj_set_height(ui_picpanel3, 100);
    lv_obj_set_align(ui_picpanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_picpanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_picpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_picpanel3, lv_color_hex(0x5572C8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_picpanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_picpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pic3 = lv_img_create(ui_picpanel3);
    lv_img_set_src(ui_pic3, &ui_img_qq_png);
    lv_obj_set_width(ui_pic3, 100);
    lv_obj_set_height(ui_pic3, 100);
    lv_obj_set_align(ui_pic3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pic3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_pic3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pic3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pic3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_picpanel4 = lv_obj_create(ui_gallerybody);
    lv_obj_set_width(ui_picpanel4, 100);
    lv_obj_set_height(ui_picpanel4, 100);
    lv_obj_set_align(ui_picpanel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_picpanel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_picpanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_picpanel4, lv_color_hex(0xF4B75F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_picpanel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_picpanel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pic4 = lv_img_create(ui_picpanel4);
    lv_img_set_src(ui_pic4, &ui_img_qq_png);
    lv_obj_set_width(ui_pic4, 100);
    lv_obj_set_height(ui_pic4, 100);
    lv_obj_set_align(ui_pic4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_pic4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_pic4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_pic4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_pic4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_pic, ui_event_pic, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pic1, ui_event_pic1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pic2, ui_event_pic2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pic3, ui_event_pic3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_pic4, ui_event_pic4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_galleryscreen, ui_event_galleryscreen, LV_EVENT_ALL, NULL);

}
