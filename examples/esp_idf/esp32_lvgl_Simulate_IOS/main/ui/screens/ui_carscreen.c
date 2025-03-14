#include "../ui.h"

void ui_carscreen_screen_init(void)
{
    ui_carscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_carscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_carscreen, ui_event_carscreen, LV_EVENT_ALL, NULL);

}
