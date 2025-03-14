#include "../ui.h"

void ui_caculatorscreen_screen_init(void)
{
    ui_caculatorscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_caculatorscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_caculatorscreen, ui_event_caculatorscreen, LV_EVENT_ALL, NULL);

}
