#include "../ui.h"

void ui_jionetscreen_screen_init(void)
{
    ui_jionetscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_jionetscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_jionetscreen, ui_event_jionetscreen, LV_EVENT_ALL, NULL);

}
