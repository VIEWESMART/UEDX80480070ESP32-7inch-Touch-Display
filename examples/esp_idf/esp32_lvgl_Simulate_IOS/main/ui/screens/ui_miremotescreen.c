#include "../ui.h"

void ui_miremotescreen_screen_init(void)
{
    ui_miremotescreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_miremotescreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_miremotescreen, ui_event_miremotescreen, LV_EVENT_ALL, NULL);

}
