// VIEWE——lvgl控件例程
// https://www.display-wiki.com/smartdisplay/esp32_5_800_480
#include <stdio.h>
#include <string.h>
#include "board.h"

#include "lvgl.h"
#include "lv_demos.h"

static const char *TAG = "https://www.display-wiki.com/smartdisplay/esp32_5_800_480";


void app_main(void)
{
	/* LCD HW initialization */
    ESP_LOGI(TAG, "Starting LCD HW initialization...");
    ESP_ERROR_CHECK(app_lcd_init());

#if VIEWE_7_TP 
    /* Touch initialization */
    ESP_LOGI(TAG, "Starting Touch initialization...");
    ESP_ERROR_CHECK(app_touch_init());
#endif

    /* LVGL initialization */
    ESP_LOGI(TAG, "Starting LVGL initialization...");
    ESP_ERROR_CHECK(app_lvgl_init());
    
	ESP_LOGI(TAG, "Creating LVGL objects...");
	 /* Show LVGL objects */
    lvgl_port_lock(0);

    //lv_demo_music();
	lv_demo_widgets();
    //lv_demo_benchmark();
	lvgl_port_unlock();
}