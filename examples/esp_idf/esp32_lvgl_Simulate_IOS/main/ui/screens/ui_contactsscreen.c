#include "../ui.h"

void ui_contactsscreen_screen_init(void)
{
    ui_contactsscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_contactsscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_contactsscreen, ui_event_contactsscreen, LV_EVENT_ALL, NULL);

}
