#include "../ui.h"

void ui_camerascreen_screen_init(void)
{
    ui_camerascreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_camerascreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_camerascreen, ui_event_camerascreen, LV_EVENT_ALL, NULL);

}
