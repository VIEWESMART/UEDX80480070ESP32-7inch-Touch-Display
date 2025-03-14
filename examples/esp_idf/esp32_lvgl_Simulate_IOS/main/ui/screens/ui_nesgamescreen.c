#include "../ui.h"

void ui_nesgamescreen_screen_init(void)
{
    ui_nesgamescreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_nesgamescreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    ui_nesgamebody = lv_obj_create(ui_nesgamescreen);
    lv_obj_set_width(ui_nesgamebody, 320);
    lv_obj_set_height(ui_nesgamebody, 480);
    lv_obj_set_align(ui_nesgamebody, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_nesgamebody, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_nesgamebody, lv_color_hex(0xE9E9E9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_nesgamebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_nesgamebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_nesgamebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_nesgamebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_nesgamebody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_nesgamebody, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_nesgamepanel = lv_img_create(ui_nesgamebody);
    nesimg = malloc(sizeof(lv_img_dsc_t));
    memset(nesimg, 0, sizeof(lv_img_dsc_t));
    nesimg->data=0;
    nesimg->header.w = 256;
    nesimg->header.h = 240;
    nesimg->data_size = 256 * 240 * LV_COLOR_DEPTH / 8;
    nesimg->header.cf = LV_IMG_CF_TRUE_COLOR; // Adjust according to your color format
    lv_img_set_src(ui_nesgamepanel, nesimg);
    lv_obj_set_width(ui_nesgamepanel, 256);  /// 1
    lv_obj_set_height(ui_nesgamepanel, 240); /// 1
    lv_obj_set_align(ui_nesgamepanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_nesgamepanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_neskeyup=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyup,40,40);
    lv_obj_set_x(ui_neskeyup, 60);
    lv_obj_set_y(ui_neskeyup, 310);
    ui_neskeyuplabel=lv_label_create(ui_neskeyup);
    lv_obj_set_align(ui_neskeyuplabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyuplabel,LV_SYMBOL_UP);
    lv_obj_add_event_cb(ui_neskeyup,ui_event_neskey,LV_EVENT_ALL,NULL);
    ui_neskeyleft=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyleft,40,40);
    lv_obj_set_x(ui_neskeyleft, 10);
    lv_obj_set_y(ui_neskeyleft, 360);
    ui_neskeyleftlabel=lv_label_create(ui_neskeyleft);
    lv_obj_set_align(ui_neskeyleftlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyleftlabel,LV_SYMBOL_LEFT);
    lv_obj_add_event_cb(ui_neskeyleft,ui_event_neskey,LV_EVENT_ALL,NULL);
    ui_neskeyright=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyright,40,40);
    lv_obj_set_x(ui_neskeyright, 110);
    lv_obj_set_y(ui_neskeyright, 360);
    ui_neskeyrightlabel=lv_label_create(ui_neskeyright);
    lv_obj_set_align(ui_neskeyrightlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyrightlabel,LV_SYMBOL_RIGHT);
    lv_obj_add_event_cb(ui_neskeyright,ui_event_neskey,LV_EVENT_ALL,NULL);
    ui_neskeydown=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeydown,40,40);
    lv_obj_set_x(ui_neskeydown, 60);
    lv_obj_set_y(ui_neskeydown, 410);
    ui_neskeydownlabel=lv_label_create(ui_neskeydown);
    lv_obj_set_align(ui_neskeydownlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeydownlabel,LV_SYMBOL_DOWN);
    lv_obj_add_event_cb(ui_neskeydown,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeyzoomup=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyzoomup,30,30);
    lv_obj_set_x(ui_neskeyzoomup, 140);
    lv_obj_set_y(ui_neskeyzoomup, 300);
    ui_neskeyzoomuplabel=lv_label_create(ui_neskeyzoomup);
    lv_obj_set_align(ui_neskeyzoomuplabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyzoomuplabel,LV_SYMBOL_PLUS);
    lv_obj_add_event_cb(ui_neskeyzoomup,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeyzoomdown=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyzoomdown,30,30);
    lv_obj_set_x(ui_neskeyzoomdown, 180);
    lv_obj_set_y(ui_neskeyzoomdown, 300);
    ui_neskeyzoomdownlabel=lv_label_create(ui_neskeyzoomdown);
    lv_obj_set_align(ui_neskeyzoomdownlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyzoomdownlabel,LV_SYMBOL_MINUS);
    lv_obj_add_event_cb(ui_neskeyzoomdown,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeyselect=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyselect,40,40);
    lv_obj_set_x(ui_neskeyselect, 140);
    lv_obj_set_y(ui_neskeyselect, 430);
    ui_neskeyselectlabel=lv_label_create(ui_neskeyselect);
    lv_obj_set_align(ui_neskeyselectlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyselectlabel,LV_SYMBOL_LIST);
    lv_obj_add_event_cb(ui_neskeyselect,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeystart=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeystart,40,40);
    lv_obj_set_x(ui_neskeystart, 190);
    lv_obj_set_y(ui_neskeystart, 430);
    ui_neskeystartlabel=lv_label_create(ui_neskeystart);
    lv_obj_set_align(ui_neskeystartlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeystartlabel,LV_SYMBOL_PLAY);
    lv_obj_add_event_cb(ui_neskeystart,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeya=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeya,40,40);
    lv_obj_set_x(ui_neskeya, 270);
    lv_obj_set_y(ui_neskeya, 350);
    ui_neskeyalabel=lv_label_create(ui_neskeya);
    lv_obj_set_align(ui_neskeyalabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyalabel,"A");
    lv_obj_add_event_cb(ui_neskeya,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeyb=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyb,40,40);
    lv_obj_set_x(ui_neskeyb, 220);
    lv_obj_set_y(ui_neskeyb, 350);
    ui_neskeyblabel=lv_label_create(ui_neskeyb);
    lv_obj_set_align(ui_neskeyblabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyblabel,"B");
    lv_obj_add_event_cb(ui_neskeyb,ui_event_neskey,LV_EVENT_ALL,NULL);

    ui_neskeyquit=lv_btn_create(ui_nesgamebody);
    lv_obj_set_size(ui_neskeyquit,40,40);
    lv_obj_set_x(ui_neskeyquit, 270);
    lv_obj_set_y(ui_neskeyquit, 430);
    ui_neskeyquitlabel=lv_label_create(ui_neskeyquit);
    lv_obj_set_align(ui_neskeyquitlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_neskeyquitlabel,LV_SYMBOL_HOME);
    
    lv_obj_add_event_cb(ui_neskeyquit,ui_event_neskey,LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui_nesgamescreen, ui_event_nesgamescreen, LV_EVENT_ALL, NULL);
}
