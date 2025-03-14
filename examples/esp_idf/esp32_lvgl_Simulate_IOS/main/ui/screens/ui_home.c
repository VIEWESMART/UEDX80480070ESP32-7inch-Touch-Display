#include "../ui.h"

void ui_home_screen_init(void)
{
    ui_home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_home, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_home, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_header = lv_obj_create(ui_home);
    lv_obj_set_width(ui_header, 320);
    lv_obj_set_height(ui_header, 30);
    lv_obj_set_align(ui_header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_header, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_header, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_header, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_header, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_body = lv_obj_create(ui_home);
    lv_obj_set_width(ui_body, 320);
    lv_obj_set_height(ui_body, 360);
    lv_obj_set_x(ui_body, 0);
    lv_obj_set_y(ui_body, -30);
    lv_obj_set_align(ui_body, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_body, LV_OBJ_FLAG_SCROLL_ONE);     /// Flags
    lv_obj_clear_flag(ui_body, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE);      /// Flags
    lv_obj_set_scrollbar_mode(ui_body, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_x(ui_body, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scroll_dir(ui_body, LV_DIR_HOR);
    lv_obj_set_style_radius(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_body, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_body, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_width(ui_body, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    ui_home1 = lv_obj_create(ui_body);
    lv_obj_set_width(ui_home1, 320);
    lv_obj_set_height(ui_home1, 360);
    lv_obj_set_align(ui_home1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_home1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_home1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_home1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_home1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_home1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_home1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_home1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_home1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_home1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_home1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_home1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_camera = lv_img_create(ui_home1);
    lv_img_set_src(ui_camera, &ui_img_camera_png);
    lv_obj_set_width(ui_camera, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_camera, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_camera, -111);
    lv_obj_set_y(ui_camera, -130);
    lv_obj_set_align(ui_camera, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_camera, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_camera, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_cameratext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_cameratext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cameratext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cameratext, -111);
    lv_obj_set_y(ui_cameratext, -90);
    lv_obj_set_align(ui_cameratext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cameratext, "Camera");
    lv_obj_clear_flag(ui_cameratext, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE |
                      LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_clock = lv_img_create(ui_home1);
    lv_img_set_src(ui_clock, &ui_img_clock_png);
    lv_obj_set_width(ui_clock, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clock, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_clock, -37);
    lv_obj_set_y(ui_clock, -130);
    lv_obj_set_align(ui_clock, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_clock, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_clock, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_clocktext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_clocktext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_clocktext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_clocktext, -37);
    lv_obj_set_y(ui_clocktext, -90);
    lv_obj_set_align(ui_clocktext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_clocktext, "Clock");
    lv_obj_clear_flag(ui_clocktext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_gallery = lv_img_create(ui_home1);
    lv_img_set_src(ui_gallery, &ui_img_gallery_png);
    lv_obj_set_width(ui_gallery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_gallery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_gallery, 37);
    lv_obj_set_y(ui_gallery, -130);
    lv_obj_set_align(ui_gallery, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_gallery, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_gallery, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_gallerytext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_gallerytext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_gallerytext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_gallerytext, 37);
    lv_obj_set_y(ui_gallerytext, -90);
    lv_obj_set_align(ui_gallerytext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_gallerytext, "Album");
    lv_obj_clear_flag(ui_gallerytext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_music = lv_img_create(ui_home1);
    lv_img_set_src(ui_music, &ui_img_music_png);
    lv_obj_set_width(ui_music, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_music, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_music, 111);
    lv_obj_set_y(ui_music, -130);
    lv_obj_set_align(ui_music, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_music, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_music, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_musictext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_musictext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_musictext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_musictext, 111);
    lv_obj_set_y(ui_musictext, -90);
    lv_obj_set_align(ui_musictext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_musictext, "Music");
    lv_obj_clear_flag(ui_musictext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_settings = lv_img_create(ui_home1);
    lv_img_set_src(ui_settings, &ui_img_settings_png);
    lv_obj_set_width(ui_settings, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settings, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settings, -111);
    lv_obj_set_y(ui_settings, -30);
    lv_obj_set_align(ui_settings, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_settings, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_settings, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_settingstext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_settingstext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_settingstext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_settingstext, -111);
    lv_obj_set_y(ui_settingstext, 10);
    lv_obj_set_align(ui_settingstext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_settingstext, "Settings");
    lv_obj_clear_flag(ui_settingstext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_notes = lv_img_create(ui_home1);
    lv_img_set_src(ui_notes, &ui_img_notes_png);
    lv_obj_set_width(ui_notes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_notes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_notes, -37);
    lv_obj_set_y(ui_notes, -30);
    lv_obj_set_align(ui_notes, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_notes, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_notes, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_notestext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_notestext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_notestext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_notestext, -37);
    lv_obj_set_y(ui_notestext, 10);
    lv_obj_set_align(ui_notestext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_notestext, "Notes");
    lv_obj_clear_flag(ui_notestext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_weather = lv_img_create(ui_home1);
    lv_img_set_src(ui_weather, &ui_img_weather_png);
    lv_obj_set_width(ui_weather, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weather, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weather, 37);
    lv_obj_set_y(ui_weather, -30);
    lv_obj_set_align(ui_weather, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_weather, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_weather, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_weathertext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_weathertext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_weathertext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_weathertext, 37);
    lv_obj_set_y(ui_weathertext, 10);
    lv_obj_set_align(ui_weathertext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_weathertext, "Weather");
    lv_obj_clear_flag(ui_weathertext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_contacts = lv_img_create(ui_home1);
    lv_img_set_src(ui_contacts, &ui_img_contacts_png);
    lv_obj_set_width(ui_contacts, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_contacts, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_contacts, 111);
    lv_obj_set_y(ui_contacts, -30);
    lv_obj_set_align(ui_contacts, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_contacts, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_contacts, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_contactstext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_contactstext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_contactstext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_contactstext, 111);
    lv_obj_set_y(ui_contactstext, 10);
    lv_obj_set_align(ui_contactstext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_contactstext, "Contacts");
    lv_obj_clear_flag(ui_contactstext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_caculator = lv_img_create(ui_home1);
    lv_img_set_src(ui_caculator, &ui_img_calculator_png);
    lv_obj_set_width(ui_caculator, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_caculator, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_caculator, -111);
    lv_obj_set_y(ui_caculator, 70);
    lv_obj_set_align(ui_caculator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_caculator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_caculator, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_caculatortext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_caculatortext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_caculatortext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_caculatortext, -111);
    lv_obj_set_y(ui_caculatortext, 110);
    lv_obj_set_align(ui_caculatortext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_caculatortext, "Calculator");
    lv_obj_clear_flag(ui_caculatortext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_filemanager = lv_img_create(ui_home1);
    lv_img_set_src(ui_filemanager, &ui_img_filemanager_png);
    lv_obj_set_width(ui_filemanager, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_filemanager, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_filemanager, -37);
    lv_obj_set_y(ui_filemanager, 70);
    lv_obj_set_align(ui_filemanager, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_filemanager, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_filemanager, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_filemanagertext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_filemanagertext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_filemanagertext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_filemanagertext, -37);
    lv_obj_set_y(ui_filemanagertext, 110);
    lv_obj_set_align(ui_filemanagertext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_filemanagertext, "File");
    lv_obj_clear_flag(ui_filemanagertext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_video = lv_img_create(ui_home1);
    lv_img_set_src(ui_video, &ui_img_videos_png);
    lv_obj_set_width(ui_video, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_video, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_video, 37);
    lv_obj_set_y(ui_video, 70);
    lv_obj_set_align(ui_video, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_video, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_video, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_videotext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_videotext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_videotext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_videotext, 37);
    lv_obj_set_y(ui_videotext, 110);
    lv_obj_set_align(ui_videotext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_videotext, "Video");
    lv_obj_clear_flag(ui_videotext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_car = lv_img_create(ui_home1);
    lv_img_set_src(ui_car, &ui_img_car_png);
    lv_obj_set_width(ui_car, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_car, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_car, 111);
    lv_obj_set_y(ui_car, 70);
    lv_obj_set_align(ui_car, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_car, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_car, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_cartext = lv_label_create(ui_home1);
    lv_obj_set_width(ui_cartext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cartext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cartext, 111);
    lv_obj_set_y(ui_cartext, 110);
    lv_obj_set_align(ui_cartext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_cartext, "RC Car");
    lv_obj_clear_flag(ui_cartext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_home2 = lv_obj_create(ui_body);
    lv_obj_set_width(ui_home2, 320);
    lv_obj_set_height(ui_home2, 360);
    lv_obj_set_x(ui_home2, 320);
    lv_obj_set_y(ui_home2, 0);
    lv_obj_set_align(ui_home2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_home2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_home2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_home2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_home2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_home2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_home2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_home2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_home2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_home2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_home2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_home2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_jionet = lv_img_create(ui_home2);
    lv_img_set_src(ui_jionet, &ui_img_jionet_png);
    lv_obj_set_width(ui_jionet, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_jionet, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_jionet, -111);
    lv_obj_set_y(ui_jionet, -130);
    lv_obj_set_align(ui_jionet, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_jionet, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_jionet, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_jionettext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_jionettext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_jionettext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_jionettext, -111);
    lv_obj_set_y(ui_jionettext, -90);
    lv_obj_set_align(ui_jionettext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_jionettext, "WIFI");
    lv_obj_clear_flag(ui_jionettext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_qrbarcode = lv_img_create(ui_home2);
    lv_img_set_src(ui_qrbarcode, &ui_img_qrbarcode_png);
    lv_obj_set_width(ui_qrbarcode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_qrbarcode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_qrbarcode, -37);
    lv_obj_set_y(ui_qrbarcode, -130);
    lv_obj_set_align(ui_qrbarcode, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_qrbarcode, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_qrbarcode, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_qrbarcodetext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_qrbarcodetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_qrbarcodetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_qrbarcodetext, -37);
    lv_obj_set_y(ui_qrbarcodetext, -90);
    lv_obj_set_align(ui_qrbarcodetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_qrbarcodetext, "QR code");
    lv_obj_clear_flag(ui_qrbarcodetext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_bluetoothcontrl = lv_img_create(ui_home2);
    lv_img_set_src(ui_bluetoothcontrl, &ui_img_bluetoothcontrl_png);
    lv_obj_set_width(ui_bluetoothcontrl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothcontrl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothcontrl, 37);
    lv_obj_set_y(ui_bluetoothcontrl, -130);
    lv_obj_set_align(ui_bluetoothcontrl, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_bluetoothcontrl, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_bluetoothcontrl,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_bluetoothcontrltext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_bluetoothcontrltext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluetoothcontrltext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bluetoothcontrltext, 37);
    lv_obj_set_y(ui_bluetoothcontrltext, -90);
    lv_obj_set_align(ui_bluetoothcontrltext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_bluetoothcontrltext, "Bluetooth");
    lv_obj_clear_flag(ui_bluetoothcontrltext,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_miremote = lv_img_create(ui_home2);
    lv_img_set_src(ui_miremote, &ui_img_mi_remote_png);
    lv_obj_set_width(ui_miremote, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_miremote, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_miremote, 111);
    lv_obj_set_y(ui_miremote, -130);
    lv_obj_set_align(ui_miremote, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_miremote, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_miremote, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_miremotetext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_miremotetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_miremotetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_miremotetext, 111);
    lv_obj_set_y(ui_miremotetext, -90);
    lv_obj_set_align(ui_miremotetext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_miremotetext, "Control");
    lv_obj_clear_flag(ui_miremotetext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_colorlight = lv_img_create(ui_home2);
    lv_img_set_src(ui_colorlight, &ui_img_tips_png);
    lv_obj_set_width(ui_colorlight, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_colorlight, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_colorlight, -111);
    lv_obj_set_y(ui_colorlight, -30);
    lv_obj_set_align(ui_colorlight, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_colorlight, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_colorlight, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_colorlighttext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_colorlighttext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_colorlighttext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_colorlighttext, -111);
    lv_obj_set_y(ui_colorlighttext, 10);
    lv_obj_set_align(ui_colorlighttext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_colorlighttext, "Torch");
    lv_obj_clear_flag(ui_colorlighttext,
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_nes = lv_img_create(ui_home2);
    lv_img_set_src(ui_nes, &ui_img_nes_png);
    lv_obj_set_width(ui_nes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_nes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_nes, -37);
    lv_obj_set_y(ui_nes, -30);
    lv_obj_set_align(ui_nes, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_nes, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_clear_flag(ui_nes, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_nestext = lv_label_create(ui_home2);
    lv_obj_set_width(ui_nestext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_nestext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_nestext, -37);
    lv_obj_set_y(ui_nestext, 10);
    lv_obj_set_align(ui_nestext, LV_ALIGN_CENTER);
    lv_label_set_text(ui_nestext, "Game");
    lv_obj_clear_flag(ui_nestext, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM);     /// Flags

    ui_footer = lv_obj_create(ui_home);
    lv_obj_set_width(ui_footer, 320);
    lv_obj_set_height(ui_footer, 90);
    lv_obj_set_align(ui_footer, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_footer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_footer, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_footer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_footer, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_footer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_phone = lv_img_create(ui_home);
    lv_img_set_src(ui_phone, &ui_img_phone_png);
    lv_obj_set_width(ui_phone, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_phone, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_phone, -111);
    lv_obj_set_y(ui_phone, -23);
    lv_obj_set_align(ui_phone, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_phone, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_phone, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_phonet = lv_label_create(ui_home);
    lv_obj_set_width(ui_phonet, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_phonet, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_phonet, -111);
    lv_obj_set_y(ui_phonet, -2);
    lv_obj_set_align(ui_phonet, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_phonet, "Phone");
    lv_obj_clear_flag(ui_phonet, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_phonet, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_phonet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_email = lv_img_create(ui_home);
    lv_img_set_src(ui_email, &ui_img_email_png);
    lv_obj_set_width(ui_email, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_email, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_email, -37);
    lv_obj_set_y(ui_email, -23);
    lv_obj_set_align(ui_email, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_email, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_email, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_emailt = lv_label_create(ui_home);
    lv_obj_set_width(ui_emailt, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_emailt, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_emailt, -37);
    lv_obj_set_y(ui_emailt, -2);
    lv_obj_set_align(ui_emailt, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_emailt, "E-mail");
    lv_obj_clear_flag(ui_emailt, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_emailt, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_emailt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_browser = lv_img_create(ui_home);
    lv_img_set_src(ui_browser, &ui_img_browser_png);
    lv_obj_set_width(ui_browser, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_browser, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_browser, 37);
    lv_obj_set_y(ui_browser, -23);
    lv_obj_set_align(ui_browser, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_browser, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_browser, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_browsert = lv_label_create(ui_home);
    lv_obj_set_width(ui_browsert, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_browsert, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_browsert, 37);
    lv_obj_set_y(ui_browsert, -2);
    lv_obj_set_align(ui_browsert, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_browsert, "Safari");
    lv_obj_clear_flag(ui_browsert, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_browsert, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_browsert, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_message = lv_img_create(ui_home);
    lv_img_set_src(ui_message, &ui_img_messaging_png);
    lv_obj_set_width(ui_message, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_message, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_message, 111);
    lv_obj_set_y(ui_message, -23);
    lv_obj_set_align(ui_message, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_message, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_message, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    ui_messages = lv_label_create(ui_home);
    lv_obj_set_width(ui_messages, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_messages, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_messages, 111);
    lv_obj_set_y(ui_messages, -2);
    lv_obj_set_align(ui_messages, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_messages, "iMessage");
    lv_obj_clear_flag(ui_messages, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_messages, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_messages, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_mobile = lv_label_create(ui_home);
    lv_obj_set_width(ui_mobile, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_mobile, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_mobile, 10);
    lv_obj_set_y(ui_mobile, 7);
    lv_label_set_text(ui_mobile, "Mobile");
    lv_obj_clear_flag(ui_mobile, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_mobile, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_mobile, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifi = lv_label_create(ui_home);
    lv_obj_set_width(ui_wifi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_wifi, 78);
    lv_obj_set_y(ui_wifi, 7);
    lv_label_set_text(ui_wifi, LV_SYMBOL_WIFI);
    lv_obj_add_flag(ui_wifi, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_wifi, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_wifi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifi, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_battery = lv_label_create(ui_home);
    lv_obj_set_width(ui_battery, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_battery, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_battery, -10);
    lv_obj_set_y(ui_battery, 7);
    lv_obj_set_align(ui_battery, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_3);
    lv_obj_clear_flag(ui_battery, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_battery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_battery, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_time = lv_label_create(ui_home);
    lv_obj_set_width(ui_time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_time, 0);
    lv_obj_set_y(ui_time, 7);
    lv_obj_set_align(ui_time, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_time, "12:12");
    lv_obj_clear_flag(ui_time, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_batteryp = lv_label_create(ui_home);
    lv_obj_set_width(ui_batteryp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_batteryp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_batteryp, -35);
    lv_obj_set_y(ui_batteryp, 7);
    lv_obj_set_align(ui_batteryp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_batteryp, "89%");
    lv_obj_clear_flag(ui_batteryp, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_color(ui_batteryp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_batteryp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menudown = lv_obj_create(ui_home);
    lv_obj_set_width(ui_menudown, 320);
    lv_obj_set_height(ui_menudown, 480);
    lv_obj_set_x(ui_menudown, 0);
    lv_obj_set_y(ui_menudown, -480);
    lv_obj_set_align(ui_menudown, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_menudown, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_menudown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_menudown, lv_color_hex(0x141414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menudown, 250, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menudown, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_menudown, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menudowntop = lv_obj_create(ui_menudown);
    lv_obj_set_width(ui_menudowntop, 280);
    lv_obj_set_height(ui_menudowntop, 70);
    lv_obj_set_x(ui_menudowntop, 0);
    lv_obj_set_y(ui_menudowntop, 80);
    lv_obj_set_align(ui_menudowntop, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_menudowntop, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_menudowntop, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menudowntop, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_menudowntop, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_wifibtn = lv_btn_create(ui_menudowntop);
    lv_obj_set_width(ui_wifibtn, 50);
    lv_obj_set_height(ui_wifibtn, 50);
    lv_obj_set_align(ui_wifibtn, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_wifibtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_wifibtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_scroll_dir(ui_wifibtn, LV_DIR_TOP);
    lv_obj_set_style_radius(ui_wifibtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_wifibtn, lv_color_hex(0xACACAC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_wifibtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_wifibtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_wifibtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_wifibtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_wifibtn, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_wifibtn, 50, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_wifibtn, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_wifibtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_wifibtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_wifilabel = lv_label_create(ui_wifibtn);
    lv_obj_set_width(ui_wifilabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_wifilabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_wifilabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_wifilabel, LV_SYMBOL_WIFI);

    ui_bluebtn = lv_btn_create(ui_menudowntop);
    lv_obj_set_width(ui_bluebtn, 50);
    lv_obj_set_height(ui_bluebtn, 50);
    lv_obj_set_x(ui_bluebtn, 68);
    lv_obj_set_y(ui_bluebtn, 0);
    lv_obj_set_align(ui_bluebtn, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_bluebtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bluebtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bluebtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bluebtn, lv_color_hex(0xACACAC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bluebtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bluebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_bluebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_bluebtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bluebtn, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_bluebtn, 50, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_bluebtn, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_bluebtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_bluebtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_bluelabel = lv_label_create(ui_bluebtn);
    lv_obj_set_width(ui_bluelabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bluelabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_bluelabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_bluelabel, LV_SYMBOL_BLUETOOTH_B);

    ui_bellbtn = lv_btn_create(ui_menudowntop);
    lv_obj_set_width(ui_bellbtn, 50);
    lv_obj_set_height(ui_bellbtn, 50);
    lv_obj_set_align(ui_bellbtn, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_bellbtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_bellbtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_bellbtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_bellbtn, lv_color_hex(0xACACAC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_bellbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_bellbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_bellbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_bellbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bellbtn, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_bellbtn, 50, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_bellbtn, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_bellbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_bellbtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_belllabel = lv_label_create(ui_bellbtn);
    lv_obj_set_width(ui_belllabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_belllabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_belllabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_belllabel, LV_SYMBOL_BELL);

    ui_lightbtn = lv_btn_create(ui_menudowntop);
    lv_obj_set_width(ui_lightbtn, 50);
    lv_obj_set_height(ui_lightbtn, 50);
    lv_obj_set_x(ui_lightbtn, -68);
    lv_obj_set_y(ui_lightbtn, 0);
    lv_obj_set_align(ui_lightbtn, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_lightbtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_lightbtn, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_lightbtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lightbtn, lv_color_hex(0xACACAC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lightbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_lightbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_lightbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_lightbtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lightbtn, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_lightbtn, 50, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_lightbtn, lv_color_hex(0x0078F5), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_lightbtn, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_lightbtn, 0, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_lightlabel = lv_label_create(ui_lightbtn);
    lv_obj_set_width(ui_lightlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lightlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lightlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lightlabel, LV_SYMBOL_FLASHLIGHT);

    ui_menudownlight = lv_obj_create(ui_menudown);
    lv_obj_set_width(ui_menudownlight, 280);
    lv_obj_set_height(ui_menudownlight, 30);
    lv_obj_set_x(ui_menudownlight, 0);
    lv_obj_set_y(ui_menudownlight, 160);
    lv_obj_set_align(ui_menudownlight, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_menudownlight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_menudownlight, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_menudownlight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menudownlight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menudownlight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lightslider = lv_slider_create(ui_menudownlight);
    lv_slider_set_value(ui_lightslider, 100, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_lightslider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_lightslider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_lightslider, 280);
    lv_obj_set_height(ui_lightslider, 30);
    lv_obj_set_align(ui_lightslider, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_lightslider, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lightslider, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lightslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_lightslider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_lightslider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lightslider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lightslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_lightslider, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_lightslider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_lightslider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_lighttext = lv_label_create(ui_lightslider);
    lv_obj_set_width(ui_lighttext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lighttext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lighttext, 10);
    lv_obj_set_y(ui_lighttext, 0);
    lv_obj_set_align(ui_lighttext, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_lighttext, LV_SYMBOL_BRIGHTNESS);
    lv_obj_set_style_text_color(ui_lighttext, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lighttext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lighttext, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menudownvolume = lv_obj_create(ui_menudown);
    lv_obj_set_width(ui_menudownvolume, 280);
    lv_obj_set_height(ui_menudownvolume, 30);
    lv_obj_set_x(ui_menudownvolume, 0);
    lv_obj_set_y(ui_menudownvolume, 200);
    lv_obj_set_align(ui_menudownvolume, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_menudownvolume, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_menudownvolume, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_menudownvolume, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menudownvolume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menudownvolume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_volumeslider = lv_slider_create(ui_menudownvolume);
    lv_slider_set_value(ui_volumeslider, 16, LV_ANIM_OFF);
    lv_slider_set_range(ui_volumeslider,10,46);
    if(lv_slider_get_mode(ui_volumeslider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_volumeslider, 0,
                                                                                                 LV_ANIM_OFF);
    lv_obj_set_width(ui_volumeslider, 280);
    lv_obj_set_height(ui_volumeslider, 30);
    lv_obj_set_align(ui_volumeslider, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_volumeslider, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_volumeslider, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_volumeslider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_volumeslider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_volumeslider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_volumeslider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_volumeslider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_volumeslider, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_volumeslider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_volumeslider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_volumetext = lv_label_create(ui_volumeslider);
    lv_obj_set_width(ui_volumetext, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_volumetext, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_volumetext, 10);
    lv_obj_set_y(ui_volumetext, 0);
    lv_obj_set_align(ui_volumetext, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_volumetext, LV_SYMBOL_VOLUME_MAX);
    lv_obj_set_style_text_color(ui_volumetext, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_volumetext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_volumetext, &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_menudownfoot = lv_obj_create(ui_menudown);
    lv_obj_set_width(ui_menudownfoot, 50);
    lv_obj_set_height(ui_menudownfoot, 3);
    lv_obj_set_x(ui_menudownfoot, 0);
    lv_obj_set_y(ui_menudownfoot, 240);
    lv_obj_set_align(ui_menudownfoot, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_menudownfoot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_menudownfoot, lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_menudownfoot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_menudownfoot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_header, ui_event_header, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_camera, ui_event_camera, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_clock, ui_event_clock, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_gallery, ui_event_gallery, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_music, ui_event_music, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_settings, ui_event_settings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_notes, ui_event_notes, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_weather, ui_event_weather, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_contacts, ui_event_contacts, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_caculator, ui_event_caculator, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_filemanager, ui_event_filemanager, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_video, ui_event_video, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_car, ui_event_car, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_jionet, ui_event_jionet, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_qrbarcode, ui_event_qrbarcode, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_bluetoothcontrl, ui_event_bluetoothcontrl, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_miremote, ui_event_miremote, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_colorlight, ui_event_colorlight, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_nes, ui_event_nes, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_phone, ui_event_phone, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_email, ui_event_email, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_browser, ui_event_browser, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_message, ui_event_message, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_wifibtn, ui_event_wifibtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_lightbtn, ui_event_lightbtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_lightslider, ui_event_lightslider, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_volumeslider, ui_event_volumeslider, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_menudown, ui_event_menudown, LV_EVENT_ALL, NULL);

}
