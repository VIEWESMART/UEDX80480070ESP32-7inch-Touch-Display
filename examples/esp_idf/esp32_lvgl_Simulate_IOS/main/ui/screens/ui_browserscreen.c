#include "../ui.h"

void ui_browserscreen_screen_init(void)
{
    ui_browserscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_browserscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_browserscreen, ui_event_browserscreen, LV_EVENT_ALL, NULL);

}
