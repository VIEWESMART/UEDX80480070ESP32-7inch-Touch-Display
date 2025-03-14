#include "../ui.h"

void ui_bluetoothcontrlscreen_screen_init(void)
{
    ui_bluetoothcontrlscreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_bluetoothcontrlscreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_bluetoothcontrlscreen, ui_event_bluetoothcontrlscreen, LV_EVENT_ALL, NULL);

}
