#include "../ui.h"

void ui_notesscreen_screen_init(void)
{
    ui_notesscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_notesscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_notesscreen, ui_event_notesscreen, LV_EVENT_ALL, NULL);

}
