#include "../ui.h"

void ui_emailscreen_screen_init(void)
{
    ui_emailscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_emailscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_emailscreen, ui_event_emailscreen, LV_EVENT_ALL, NULL);

}
