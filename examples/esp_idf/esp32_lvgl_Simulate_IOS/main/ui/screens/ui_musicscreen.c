#include "../ui.h"

void ui_musicscreen_screen_init(void)
{
    ui_musicscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_musicscreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_flex_flow(ui_musicscreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musicscreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(ui_musicscreen, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicscreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musicscreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicheader = lv_obj_create(ui_musicscreen);
    lv_obj_set_width(ui_musicheader, 320);
    lv_obj_set_height(ui_musicheader, 380);
    lv_obj_set_x(ui_musicheader, 0);
    lv_obj_set_y(ui_musicheader, -1);
    lv_obj_set_align(ui_musicheader, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_musicheader, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musicheader, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_musicheader, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicheader, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicheader, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musicheader, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicheadpanel = lv_obj_create(ui_musicheader);
    lv_obj_set_width(ui_musicheadpanel, 320);
    lv_obj_set_height(ui_musicheadpanel, 50);
    lv_obj_set_x(ui_musicheadpanel, 0);
    lv_obj_set_y(ui_musicheadpanel, -1);
    lv_obj_set_align(ui_musicheadpanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicheadpanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicheadpanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicheadpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicback = lv_obj_create(ui_musicheadpanel);
    lv_obj_set_width(ui_musicback, 35);
    lv_obj_set_height(ui_musicback, 35);
    lv_obj_set_x(ui_musicback, 15);
    lv_obj_set_y(ui_musicback, 5);
    lv_obj_clear_flag(ui_musicback, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicback, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicback, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicback, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicback, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musicback, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musicback, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicback, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicback, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musicback, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musicback, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicbacklabel = lv_label_create(ui_musicback);
    lv_obj_set_width(ui_musicbacklabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicbacklabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicbacklabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicbacklabel, LV_SYMBOL_LEFT);
    lv_obj_set_style_text_color(ui_musicbacklabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicbacklabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclistbtn = lv_obj_create(ui_musicheadpanel);
    lv_obj_set_width(ui_musiclistbtn, 35);
    lv_obj_set_height(ui_musiclistbtn, 35);
    lv_obj_set_x(ui_musiclistbtn, -15);
    lv_obj_set_y(ui_musiclistbtn, 5);
    lv_obj_set_align(ui_musiclistbtn, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_musiclistbtn, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musiclistbtn, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclistbtn, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclistbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclistbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musiclistbtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musiclistbtn, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musiclistbtn, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musiclistbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musiclistbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musiclistbtn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclistlabel = lv_label_create(ui_musiclistbtn);
    lv_obj_set_width(ui_musiclistlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musiclistlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musiclistlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musiclistlabel, LV_SYMBOL_BARS);
    lv_obj_set_style_text_color(ui_musiclistlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclistlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicbody = lv_obj_create(ui_musicheader);
    lv_obj_set_width(ui_musicbody, 320);
    lv_obj_set_height(ui_musicbody, 300);
    lv_obj_set_align(ui_musicbody, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_musicbody, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musicbody, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicbody, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicbody, lv_color_hex(0x292C31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musicbody, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicpicbgpanel = lv_obj_create(ui_musicbody);
    lv_obj_set_width(ui_musicpicbgpanel, 320);
    lv_obj_set_height(ui_musicpicbgpanel, 220);
    lv_obj_set_align(ui_musicpicbgpanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicpicbgpanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_musicpicbgpanel, lv_color_hex(0x292C31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicpicbgpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicpicbg = lv_obj_create(ui_musicpicbgpanel);
    lv_obj_set_width(ui_musicpicbg, 180);
    lv_obj_set_height(ui_musicpicbg, 180);
    lv_obj_set_align(ui_musicpicbg, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_musicpicbg, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicpicbg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicpicbg, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicpicbg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_musicpicbg, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicpicbg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musicpicbg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musicpicbg, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicpicbg, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicpicbg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musicpicbg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musicpicbg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicbg = lv_img_create(ui_musicpicbg);
    lv_img_set_src(ui_musicbg, &ui_img_musicbg_png);
    lv_obj_set_width(ui_musicbg, LV_SIZE_CONTENT);  /// 160
    lv_obj_set_height(ui_musicbg, LV_SIZE_CONTENT); /// 135
    lv_obj_set_align(ui_musicbg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musicbg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_musicbg, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_musicname = lv_obj_create(ui_musicbody);
    lv_obj_set_width(ui_musicname, 280);
    lv_obj_set_height(ui_musicname, 60);
    lv_obj_set_align(ui_musicname, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_musicname, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musicname, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicname, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicname, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicname, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicname, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicname, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicnamelabel = lv_label_create(ui_musicname);
    lv_obj_set_width(ui_musicnamelabel, 280); /// 1
    lv_obj_set_height(ui_musicnamelabel, 30); /// 1
    lv_obj_set_align(ui_musicnamelabel, LV_ALIGN_CENTER);
    lv_obj_set_style_text_align(ui_musicnamelabel, LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_text(ui_musicnamelabel, "music file name");
    lv_label_set_long_mode(ui_musicnamelabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_musicnamelabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicnamelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musicnamelabel, &misansbold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicart = lv_label_create(ui_musicname);
    lv_obj_set_width(ui_musicart, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicart, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicart, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicart, "sample rate");
    lv_obj_set_style_text_color(ui_musicart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musicart, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclyrics = lv_obj_create(ui_musicbody);
    lv_obj_set_width(ui_musiclyrics, 320);
    lv_obj_set_height(ui_musiclyrics, 300);
    lv_obj_set_align(ui_musiclyrics, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musiclyrics, LV_OBJ_FLAG_HIDDEN);           /// Flags
    lv_obj_clear_flag(ui_musiclyrics, LV_OBJ_FLAG_GESTURE_BUBBLE); /// Flags
    lv_obj_set_style_radius(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclyrics, lv_color_hex(0x292C31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musiclyrics, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_musiclyrics, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclyrics, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musiclyrics, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclyricslabel = lv_roller_create(ui_musiclyrics);
    lv_roller_set_options(ui_musiclyricslabel,
                          "亲爱的小孩(国语)(Album Version) - 刘德华\n作词：Yang Li De\n作曲：Chen Fu Ming\n小小的小孩\n今天有没有哭\n是否朋友都已经离去\n留下了带不走的孤独\n漂亮的小孩\n今天有没有哭\n是否弄脏了美丽的衣服\n却找不到别人倾诉\n聪明的小孩\n今天有没有哭\n是否遗失了心爱的礼物\n在风中寻找从清晨到日暮\n我亲爱的小孩\n为什么你不让我看清楚\n是否让风吹熄了蜡烛\n在黑暗中独自漫步\n亲爱的小孩\n快快擦干你的泪珠\n我愿意陪伴你走上回家的路\n亲爱的小孩\n今天有没有哭\n是否朋友都已经离去\n留下了带不走的孤独\n亲爱的小孩\n今天有没有哭\n是否遗失了心爱的礼物\n在风中寻找从清晨到日暮\n我亲爱的小孩\n为什么你不让我看清楚\n是否让风吹熄了蜡烛\n在黑暗中独自漫步\n亲爱的小孩\n快快擦干你的泪珠\n我愿意陪伴你走上回家的路",
                          LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_musiclyricslabel, 320);
    lv_obj_set_height(ui_musiclyricslabel, 300);
    lv_obj_set_align(ui_musiclyricslabel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musiclyricslabel, LV_OBJ_FLAG_CHECKABLE); /// Flags
    lv_obj_set_style_text_color(ui_musiclyricslabel, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclyricslabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_musiclyricslabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musiclyricslabel, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclyricslabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclyricslabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_musiclyricslabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_musiclyricslabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_musiclyricslabel, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclyricslabel, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclyricslabel, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclyricslabel, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_musicbarpanel = lv_obj_create(ui_musicheader);
    lv_obj_set_width(ui_musicbarpanel, 320);
    lv_obj_set_height(ui_musicbarpanel, 30);
    lv_obj_set_align(ui_musicbarpanel, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_musicbarpanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_musicbarpanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_musicbarpanel, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicbarpanel, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicbarpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musicbarpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musicbarpanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musictimelabel = lv_label_create(ui_musicbarpanel);
    lv_obj_set_width(ui_musictimelabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musictimelabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musictimelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musictimelabel, "00:00");
    lv_obj_set_style_text_color(ui_musictimelabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musictimelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicslider = lv_slider_create(ui_musicbarpanel);
    lv_slider_set_value(ui_musicslider, 0, LV_ANIM_OFF);
    if (lv_slider_get_mode(ui_musicslider) == LV_SLIDER_MODE_RANGE)
        lv_slider_set_left_value(ui_musicslider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_musicslider, 190);
    lv_obj_set_height(ui_musicslider, 3);
    lv_obj_set_align(ui_musicslider, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_musicslider, lv_color_hex(0x64696E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_musicslider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_musicslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_musicslider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_musicslider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicslider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_musicendtimelabel = lv_label_create(ui_musicbarpanel);
    lv_obj_set_width(ui_musicendtimelabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicendtimelabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicendtimelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicendtimelabel, "03:00");
    lv_obj_set_style_text_color(ui_musicendtimelabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicendtimelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiccontrl = lv_obj_create(ui_musicscreen);
    lv_obj_set_width(ui_musiccontrl, 320);
    lv_obj_set_height(ui_musiccontrl, 100);
    lv_obj_set_x(ui_musiccontrl, 1);
    lv_obj_set_y(ui_musiccontrl, 0);
    lv_obj_set_align(ui_musiccontrl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_musiccontrl, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_musiccontrl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_musiccontrl, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiccontrl, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiccontrl, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musiccontrl, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musiccontrl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musiccontrl, 40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicleft = lv_obj_create(ui_musiccontrl);
    lv_obj_set_width(ui_musicleft, 50);
    lv_obj_set_height(ui_musicleft, 50);
    lv_obj_set_x(ui_musicleft, 1);
    lv_obj_set_y(ui_musicleft, 0);
    lv_obj_set_align(ui_musicleft, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicleft, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicleft, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicleft, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicleft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musicleft, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musicleft, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicleft, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musicleft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musicleft, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicleftlabel = lv_label_create(ui_musicleft);
    lv_obj_set_width(ui_musicleftlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicleftlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicleftlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicleftlabel, LV_SYMBOL_PREV);
    lv_obj_set_style_text_color(ui_musicleftlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicleftlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicplay = lv_obj_create(ui_musiccontrl);
    lv_obj_set_width(ui_musicplay, 80);
    lv_obj_set_height(ui_musicplay, 80);
    lv_obj_set_x(ui_musicplay, 0);
    lv_obj_set_y(ui_musicplay, -1);
    lv_obj_set_align(ui_musicplay, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musicplay, LV_OBJ_FLAG_CHECKABLE);    /// Flags
    lv_obj_clear_flag(ui_musicplay, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicplay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicplay, lv_color_hex(0x657592), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicplay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicplay, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musicplay, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musicplay, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicplay, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicplay, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musicplay, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musicplay, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicplaybtn = lv_btn_create(ui_musicplay);
    lv_obj_set_width(ui_musicplaybtn, 80);
    lv_obj_set_height(ui_musicplaybtn, 80);
    lv_obj_set_align(ui_musicplaybtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musicplaybtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_musicplaybtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);   /// Flags
    lv_obj_set_style_radius(ui_musicplaybtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicplaybtn, lv_color_hex(0x657592), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicplaybtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicplaybtn, lv_color_hex(0x657592), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_musicplaybtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_shadow_spread(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui_musicplaybtn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_musicplaybtn, lv_color_hex(0x657592), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_musicplaybtn, 0, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);

    ui_musicplaylabel = lv_label_create(ui_musicplay);
    lv_obj_set_width(ui_musicplaylabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicplaylabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicplaylabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicplaylabel, LV_SYMBOL_PLAY);
    lv_obj_set_style_text_color(ui_musicplaylabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicplaylabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicright = lv_obj_create(ui_musiccontrl);
    lv_obj_set_width(ui_musicright, 50);
    lv_obj_set_height(ui_musicright, 50);
    lv_obj_set_align(ui_musicright, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musicright, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musicright, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musicright, lv_color_hex(0x282D32), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musicright, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musicright, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_musicright, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_musicright, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_musicright, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_musicright, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_musicright, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_musicright, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musicrightlabel = lv_label_create(ui_musicright);
    lv_obj_set_width(ui_musicrightlabel, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musicrightlabel, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musicrightlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musicrightlabel, LV_SYMBOL_NEXT);
    lv_obj_set_style_text_color(ui_musicrightlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musicrightlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclistpanel = lv_obj_create(ui_musicscreen);
    lv_obj_set_width(ui_musiclistpanel, 320);
    lv_obj_set_height(ui_musiclistpanel, 480);
    lv_obj_set_x(ui_musiclistpanel, 0);
    lv_obj_set_y(ui_musiclistpanel, 480);
    lv_obj_set_align(ui_musiclistpanel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_musiclistpanel, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(ui_musiclistpanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_bg_color(ui_musiclistpanel, lv_color_hex(0x797979), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclistpanel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclistpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclists = lv_obj_create(ui_musiclistpanel);
    lv_obj_set_width(ui_musiclists, 300);
    lv_obj_set_height(ui_musiclists, 280);
    lv_obj_set_align(ui_musiclists, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_musiclists, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musiclists, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_musiclists, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(ui_musiclists, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_musiclists, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclists, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclists, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musiclists, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musiclists, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclisttitle = lv_obj_create(ui_musiclists);
    lv_obj_set_width(ui_musiclisttitle, 300);
    lv_obj_set_height(ui_musiclisttitle, 30);
    lv_obj_set_align(ui_musiclisttitle, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_musiclisttitle, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_border_color(ui_musiclisttitle, lv_color_hex(0xF0F0F0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_musiclisttitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclisttitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_musiclisttitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_musiclisttitle, lv_color_hex(0x464646), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclisttitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclisttitletop = lv_label_create(ui_musiclisttitle);
    lv_obj_set_width(ui_musiclisttitletop, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_musiclisttitletop, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_musiclisttitletop, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musiclisttitletop, "music list");
    lv_obj_set_style_text_color(ui_musiclisttitletop, lv_color_hex(0x0000ff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_musiclisttitletop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_musiclist = lv_obj_create(ui_musiclists);
    lv_obj_set_width(ui_musiclist, 300);
    lv_obj_set_height(ui_musiclist, 250);
    lv_obj_set_align(ui_musiclist, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_musiclist, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_musiclist, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_musiclist, LV_OBJ_FLAG_FLOATING); /// Flags
    lv_obj_set_scrollbar_mode(ui_musiclist, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_radius(ui_musiclist, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_musiclist, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_musiclist, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_musiclist, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_musiclist, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_musicback, ui_event_musicback, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musiclistbtn, ui_event_musiclistbtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicpicbg, ui_event_musicpicbg, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musiclyricslabel, ui_event_musiclyricslabel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musiclyrics, ui_event_musiclyrics, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicslider, ui_event_musicslider, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicbarpanel, ui_event_musicbarpanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicleft, ui_event_musicleft, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicplaybtn, ui_event_musicplaybtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicright, ui_event_musicright, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_musiclistpanel, ui_event_musiclistpanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_musicscreen, ui_event_musicscreen, LV_EVENT_ALL, NULL);
}
