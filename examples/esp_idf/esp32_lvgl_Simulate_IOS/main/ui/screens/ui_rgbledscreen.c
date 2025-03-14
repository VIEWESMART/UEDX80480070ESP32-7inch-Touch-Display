#include "../ui.h"

void ui_rgbledscreen_screen_init(void)
{
    ui_rgbledscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_rgbledscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_rgbledheader = lv_obj_create(ui_rgbledscreen);
    lv_obj_set_width(ui_rgbledheader, 320);
    lv_obj_set_height(ui_rgbledheader, 50);
    lv_obj_set_align(ui_rgbledheader, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_rgbledheader, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_rgbledheader, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_rgbledheader, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_rgbledheader, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_rgbledheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rgblabel = lv_label_create(ui_rgbledheader);
    lv_obj_set_width(ui_rgblabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_rgblabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_rgblabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_rgblabel, "Flashlight");

    ui_rgbswitch = lv_switch_create(ui_rgbledheader);
    lv_obj_set_width(ui_rgbswitch, 50);
    lv_obj_set_height(ui_rgbswitch, 25);
    lv_obj_set_align(ui_rgbswitch, LV_ALIGN_CENTER);


    ui_rgbledbody = lv_obj_create(ui_rgbledscreen);
    lv_obj_set_width(ui_rgbledbody, 320);
    lv_obj_set_height(ui_rgbledbody, 320);
    lv_obj_set_align(ui_rgbledbody, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_rgbledbody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_rgbledbody, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_rgbledbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_rgbledbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rgbcolorwheel = lv_colorwheel_create(ui_rgbledbody, true);
    lv_obj_set_width(ui_rgbcolorwheel, 220);
    lv_obj_set_height(ui_rgbcolorwheel, 220);
    lv_obj_set_align(ui_rgbcolorwheel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_rgbcolorwheel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_rgbcolorwheel, LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_set_style_arc_width(ui_rgbcolorwheel, 30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_rgbswitch, ui_event_rgbswitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_rgbcolorwheel, ui_event_rgbcolorwheel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_rgbledscreen, ui_event_rgbledscreen, LV_EVENT_ALL, NULL);

}
