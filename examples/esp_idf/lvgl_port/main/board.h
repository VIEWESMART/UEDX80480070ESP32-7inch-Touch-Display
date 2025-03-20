#pragma once

#include <stdio.h>
#include <string.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "driver/i2c.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_lvgl_port.h"

#include "lvgl.h"
#include "lv_demos.h"
#include "esp_lcd_touch_ft5x06.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_lcd_touch_cst816s.h"

/* LCD size */
#define VIEWE_7_TP          (1)
#define EXAMPLE_LCD_H_RES   (800)
#define EXAMPLE_LCD_V_RES   (480)


/* LCD settings */
#define EXAMPLE_LCD_LVGL_FULL_REFRESH           (1)
#define EXAMPLE_LCD_LVGL_DIRECT_MODE            (0)
#define EXAMPLE_LCD_LVGL_AVOID_TEAR             (1)
#define EXAMPLE_LCD_RGB_BOUNCE_BUFFER_MODE      (1)
#define EXAMPLE_LCD_DRAW_BUFF_DOUBLE            (1)
#define EXAMPLE_LCD_DRAW_BUFF_HEIGHT            (100)
#define EXAMPLE_LCD_RGB_BUFFER_NUMS             (2)
#define EXAMPLE_LCD_RGB_BOUNCE_BUFFER_HEIGHT    (10)


#define BOOT_BUTTON_NUM  (GPIO_NUM_0)  // 使用 IO0 作为 boot 键
#define BUTTON_ACTIVE_LEVEL     0



/* LCD pins */
#define GPIO_LCD_BL                (GPIO_NUM_2)
#define EXAMPLE_LCD_GPIO_VSYNC     (GPIO_NUM_41)
#define EXAMPLE_LCD_GPIO_HSYNC     (GPIO_NUM_39)
#define EXAMPLE_LCD_GPIO_DE        (GPIO_NUM_40)
#define EXAMPLE_LCD_GPIO_PCLK      (GPIO_NUM_42)
#define EXAMPLE_LCD_GPIO_DISP      (GPIO_NUM_NC)

#define EXAMPLE_LCD_GPIO_DATA0     (GPIO_NUM_8)
#define EXAMPLE_LCD_GPIO_DATA1     (GPIO_NUM_3)
#define EXAMPLE_LCD_GPIO_DATA2     (GPIO_NUM_46)
#define EXAMPLE_LCD_GPIO_DATA3     (GPIO_NUM_9)
#define EXAMPLE_LCD_GPIO_DATA4     (GPIO_NUM_1)

#define EXAMPLE_LCD_GPIO_DATA5     (GPIO_NUM_5)
#define EXAMPLE_LCD_GPIO_DATA6     (GPIO_NUM_6)
#define EXAMPLE_LCD_GPIO_DATA7     (GPIO_NUM_7)
#define EXAMPLE_LCD_GPIO_DATA8     (GPIO_NUM_15)
#define EXAMPLE_LCD_GPIO_DATA9     (GPIO_NUM_16)
#define EXAMPLE_LCD_GPIO_DATA10    (GPIO_NUM_4)

#define EXAMPLE_LCD_GPIO_DATA11    (GPIO_NUM_45)
#define EXAMPLE_LCD_GPIO_DATA12    (GPIO_NUM_48)
#define EXAMPLE_LCD_GPIO_DATA13    (GPIO_NUM_47)
#define EXAMPLE_LCD_GPIO_DATA14    (GPIO_NUM_21)
#define EXAMPLE_LCD_GPIO_DATA15    (GPIO_NUM_14)

/* Touch settings */
#define EXAMPLE_TOUCH_I2C_NUM       (0)
#define EXAMPLE_TOUCH_I2C_CLK_HZ    (400000)

/* LCD touch pins */
#define EXAMPLE_TOUCH_I2C_SCL       (GPIO_NUM_20)
#define EXAMPLE_TOUCH_I2C_SDA       (GPIO_NUM_19)
#define GPIO_I2C_INT                (GPIO_NUM_18)
#define GPIO_I2C_RST                (GPIO_NUM_38)


#define EXAMPLE_LCD_PANEL_35HZ_RGB_TIMING()  \
    {                                               \
        .pclk_hz = 15 * 1000 * 1000,                \
        .h_res = EXAMPLE_LCD_H_RES,                 \
        .v_res = EXAMPLE_LCD_V_RES,                 \
        .hsync_pulse_width = 48,                     \
        .hsync_back_porch = 40,                     \
        .hsync_front_porch = 88,                    \
        .vsync_pulse_width = 6,                    \
        .vsync_back_porch = 26,                     \
        .vsync_front_porch = 30,                     \
        .flags.pclk_active_neg = true,              \
    }


esp_err_t app_lcd_init(void);
esp_err_t app_touch_init(void);
esp_err_t app_lvgl_init(void);

#ifdef __cplusplus
}
#endif