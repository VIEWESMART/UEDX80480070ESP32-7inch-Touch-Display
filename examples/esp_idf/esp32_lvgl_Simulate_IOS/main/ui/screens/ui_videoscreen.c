#include "../ui.h"

void ui_videoscreen_screen_init(void)
{
    ui_videoscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_videoscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_videoscreen, ui_event_videoscreen, LV_EVENT_ALL, NULL);

}
