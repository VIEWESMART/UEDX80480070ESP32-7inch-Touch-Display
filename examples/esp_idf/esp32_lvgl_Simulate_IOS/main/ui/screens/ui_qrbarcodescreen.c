#include "../ui.h"

void ui_qrbarcodescreen_screen_init(void)
{
    ui_qrbarcodescreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_qrbarcodescreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_qrbarcodescreen, ui_event_qrbarcodescreen, LV_EVENT_ALL, NULL);

}
