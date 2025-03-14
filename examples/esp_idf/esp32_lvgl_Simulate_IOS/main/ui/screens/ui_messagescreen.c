#include "../ui.h"

void ui_messagescreen_screen_init(void)
{
    ui_messagescreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_messagescreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_messagescreen, ui_event_messagescreen, LV_EVENT_ALL, NULL);

}
