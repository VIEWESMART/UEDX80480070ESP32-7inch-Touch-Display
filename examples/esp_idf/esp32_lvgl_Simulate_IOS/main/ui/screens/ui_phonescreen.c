#include "../ui.h"

void ui_phonescreen_screen_init(void)
{
    ui_phonescreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_phonescreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_phonescreen, ui_event_phonescreen, LV_EVENT_ALL, NULL);

}
