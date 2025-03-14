#include "../ui.h"

void ui_filemanagerscreen_screen_init(void)
{
    ui_filemanagerscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_filemanagerscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_filemanagerscreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_filemanagerscreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_row(ui_filemanagerscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_filemanagerscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filemanagerheader = lv_obj_create(ui_filemanagerscreen);
    lv_obj_set_width(ui_filemanagerheader, 320);
    lv_obj_set_height(ui_filemanagerheader, 40);
    lv_obj_set_align(ui_filemanagerheader, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_filemanagerheader, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_filemanagerheader, lv_color_hex(0xE9E9E9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_filemanagerheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_filemanagerheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_filemanagerheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_filemanagerheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_filemanagerheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_filemanagerheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_filemanagerheader, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filemanagerheaderleft = lv_label_create(ui_filemanagerheader);
    lv_obj_set_width(ui_filemanagerheaderleft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_filemanagerheaderleft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_filemanagerheaderleft, 10);
    lv_obj_set_y(ui_filemanagerheaderleft, 0);
    lv_obj_set_align(ui_filemanagerheaderleft, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_filemanagerheaderleft, LV_SYMBOL_LEFT);
    lv_obj_set_style_text_color(ui_filemanagerheaderleft, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_filemanagerheaderleft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_filemanagerheaderleft, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filemanagerheaderright = lv_label_create(ui_filemanagerheader);
    lv_obj_set_width(ui_filemanagerheaderright, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_filemanagerheaderright, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_filemanagerheaderright, -10);
    lv_obj_set_y(ui_filemanagerheaderright, 0);
    lv_obj_set_align(ui_filemanagerheaderright, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_filemanagerheaderright, "sdcard");
    lv_obj_add_flag(ui_filemanagerheaderright, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_filemanagerbody = lv_obj_create(ui_filemanagerscreen);
    lv_obj_set_width(ui_filemanagerbody, 320);
    lv_obj_set_height(ui_filemanagerbody, 440);
    lv_obj_set_x(ui_filemanagerbody, -1);
    lv_obj_set_y(ui_filemanagerbody, -1);
    lv_obj_set_align(ui_filemanagerbody, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_filemanagerbody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_filemanagerbody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_filemanagerbody, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_filemanagerbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_filemanagerbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_filemanagerbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filelist = lv_obj_create(ui_filemanagerbody);
    lv_obj_set_width(ui_filelist, 300);
    lv_obj_set_height(ui_filelist, 40);
    lv_obj_set_align(ui_filelist, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_filelist, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_filelist, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_filelist, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_filelist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_filelist, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_filelist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_filelist, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filelisticon = lv_label_create(ui_filelist);
    lv_obj_set_width(ui_filelisticon, 30);
    lv_obj_set_height(ui_filelisticon, 20);
    lv_obj_set_x(ui_filelisticon, 2);
    lv_obj_set_y(ui_filelisticon, -57);
    lv_obj_set_align(ui_filelisticon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelisticon, LV_SYMBOL_DIRECTORY);

    ui_filelistlabel = lv_label_create(ui_filelist);
    lv_obj_set_width(ui_filelistlabel, 240);
    lv_obj_set_height(ui_filelistlabel, 20);
    lv_obj_set_align(ui_filelistlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelistlabel, "music");

    ui_filelistright = lv_label_create(ui_filelist);
    lv_obj_set_width(ui_filelistright, 30);
    lv_obj_set_height(ui_filelistright, 20);
    lv_obj_set_align(ui_filelistright, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelistright, LV_SYMBOL_RIGHT);

    ui_filelist2 = lv_obj_create(ui_filemanagerbody);
    lv_obj_set_width(ui_filelist2, 300);
    lv_obj_set_height(ui_filelist2, 40);
    lv_obj_set_align(ui_filelist2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_filelist2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_filelist2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_filelist2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_filelist2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_filelist2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_filelist2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_filelist2, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_filelisticon2 = lv_label_create(ui_filelist2);
    lv_obj_set_width(ui_filelisticon2, 30);
    lv_obj_set_height(ui_filelisticon2, 20);
    lv_obj_set_x(ui_filelisticon2, 2);
    lv_obj_set_y(ui_filelisticon2, -57);
    lv_obj_set_align(ui_filelisticon2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelisticon2, LV_SYMBOL_DIRECTORY);

    ui_filelistlabel2 = lv_label_create(ui_filelist2);
    lv_obj_set_width(ui_filelistlabel2, 240);
    lv_obj_set_height(ui_filelistlabel2, 20);
    lv_obj_set_align(ui_filelistlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelistlabel2, "video");

    ui_filelistright2 = lv_label_create(ui_filelist2);
    lv_obj_set_width(ui_filelistright2, 30);
    lv_obj_set_height(ui_filelistright2, 20);
    lv_obj_set_align(ui_filelistright2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filelistright2, LV_SYMBOL_RIGHT);

    lv_obj_add_event_cb(ui_filemanagerheaderright, ui_event_filemanagerheaderright, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_filelistlabel, ui_event_filelistlabel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_filemanagerscreen, ui_event_filemanagerscreen, LV_EVENT_ALL, NULL);
}
