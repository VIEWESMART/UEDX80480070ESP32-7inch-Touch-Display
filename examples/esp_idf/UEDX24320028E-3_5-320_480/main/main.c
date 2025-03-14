/*
 *November 2024
 *Author: LiuLong
 *Shenzhen VIEWE TECHNOLOGY Co., LTD
 */

#include <stdio.h>
#include "lv_demos.h"
#include "board.h"

static const char *TAG = "EXAMPLE";

void app_main(void)
{
    /* LCD HW initialization */
    ESP_ERROR_CHECK(app_lcd_init());

    /* Touch initialization */
    ESP_ERROR_CHECK(app_touch_init());

    /* LVGL initialization */
    ESP_ERROR_CHECK(app_lvgl_init());

    /* Show LVGL objects */
    // app_main_display();
    lvgl_port_lock(0);
    // lv_demo_stress();
    lv_demo_widgets();

    lvgl_port_unlock();
    ESP_ERROR_CHECK(gpio_set_level(EXAMPLE_LCD_GPIO_BL, EXAMPLE_LCD_BL_ON_LEVEL));
}
