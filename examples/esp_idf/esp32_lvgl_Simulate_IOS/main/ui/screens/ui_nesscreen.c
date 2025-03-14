#include "../ui.h"

void ui_nesscreen_screen_init(void)
{
    ui_nesscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_nesscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_nesscreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_nesscreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_row(ui_nesscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_nesscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_nesheader = lv_obj_create(ui_nesscreen);
    lv_obj_set_width(ui_nesheader, 320);
    lv_obj_set_height(ui_nesheader, 40);
    lv_obj_set_align(ui_nesheader, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_nesheader, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_nesheader, lv_color_hex(0xE9E9E9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_nesheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_nesheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_nesheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_nesheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_nesheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_nesheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_nesheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_nesheaderleft = lv_label_create(ui_nesheader);
    lv_obj_set_width(ui_nesheaderleft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_nesheaderleft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_nesheaderleft, 10);
    lv_obj_set_y(ui_nesheaderleft, 0);
    lv_obj_set_align(ui_nesheaderleft, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_nesheaderleft, LV_SYMBOL_LEFT);
    lv_obj_set_style_text_color(ui_nesheaderleft, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_nesheaderleft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_nesheaderleft, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_nesheaderright = lv_label_create(ui_nesheader);
    lv_obj_set_width(ui_nesheaderright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_nesheaderright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_nesheaderright, -10);
    lv_obj_set_y(ui_nesheaderright, 0);
    lv_obj_set_align(ui_nesheaderright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_nesheaderright, "sdcard");
    lv_obj_add_flag(ui_nesheaderright, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_nesbody = lv_obj_create(ui_nesscreen);
    lv_obj_set_width(ui_nesbody, 320);
    lv_obj_set_height(ui_nesbody, 440);
    lv_obj_set_x(ui_nesbody, -1);
    lv_obj_set_y(ui_nesbody, -1);
    lv_obj_set_align(ui_nesbody, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_nesbody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_nesbody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    //lv_obj_clear_flag(ui_nesbody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scroll_dir(ui_nesbody,LV_DIR_VER);
    lv_obj_set_scrollbar_mode(ui_nesbody, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_border_width(ui_nesbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_nesbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_nesbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);



    lv_obj_add_event_cb(ui_nesscreen, ui_event_nesscreen, LV_EVENT_ALL, NULL);
}
