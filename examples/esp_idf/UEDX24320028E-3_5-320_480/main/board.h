/*
 *November 2024
 *Author: LiuLong
 *Shenzhen VIEWE TECHNOLOGY Co., LTD
 */

#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lvgl_port.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"

#include "esp_lcd_touch_cst816s.h"
#include "esp_lcd_gc9a01.h"
#include "esp_lcd_st7796.h"
#include "lvgl.h"
#include "lv_demos.h"

//*************************************************** */
#define GC 0   //2.4/2.8/3.5 low resolution set 1
#define ST 1   //3.5 3.5inch high resolution set 1

/*select board*/
#if GC
#define VIEWE_24_L35    0  //2.4inch Display and 3.5inch low resolution Display
#define VIEWE_28        1  //2.8inch Display
#elif ST
#define VIEWE_H35       1  //3.5inch high resolution Display(320*480)
#endif

#if ST
/* LCD size */
#define EXAMPLE_LCD_H_RES   (320)
#define EXAMPLE_LCD_V_RES   (480)

/* LCD settings */
#define EXAMPLE_LCD_SPI_NUM         (SPI3_HOST)
#define EXAMPLE_LCD_PIXEL_CLK_HZ    (80 * 1000 * 1000)
#define EXAMPLE_LCD_CMD_BITS        (8)
#define EXAMPLE_LCD_PARAM_BITS      (8)
#define EXAMPLE_LCD_COLOR_SPACE     (ESP_LCD_COLOR_SPACE_BGR)
#define EXAMPLE_LCD_BITS_PER_PIXEL  (16)
#define EXAMPLE_LCD_DRAW_BUFF_DOUBLE (0)
#define EXAMPLE_LCD_DRAW_BUFF_HEIGHT (80)
#define EXAMPLE_LCD_BL_ON_LEVEL      (1)

#elif GC
/* LCD size */
#define EXAMPLE_LCD_H_RES   (240)
#define EXAMPLE_LCD_V_RES   (320)

/* LCD settings */
#define EXAMPLE_LCD_SPI_NUM         (SPI3_HOST)
#define EXAMPLE_LCD_PIXEL_CLK_HZ    (80 * 1000 * 1000)
#define EXAMPLE_LCD_CMD_BITS        (8)
#define EXAMPLE_LCD_PARAM_BITS      (8)
#define EXAMPLE_LCD_COLOR_SPACE     (ESP_LCD_COLOR_SPACE_BGR)
#define EXAMPLE_LCD_BITS_PER_PIXEL  (16)
#define EXAMPLE_LCD_DRAW_BUFF_DOUBLE (0)
#define EXAMPLE_LCD_DRAW_BUFF_HEIGHT (80)
#define EXAMPLE_LCD_BL_ON_LEVEL      (1)
#endif

// The MCU interface mode select
#define EXAMPLE_PIN_NUM_IM0             (47)  
#define EXAMPLE_PIN_NUM_IM1             (48)  
#define EXAMPLE_PIN_NUM_IM_ON_LEVEL     (1)
#define EXAMPLE_PIN_NUM_IM_OFF_LEVEL    (0)


/* LCD pins */
#define EXAMPLE_LCD_GPIO_SCLK       (GPIO_NUM_40)
#define EXAMPLE_LCD_GPIO_MOSI       (GPIO_NUM_45)
#define EXAMPLE_LCD_GPIO_RST        (GPIO_NUM_NC)
#define EXAMPLE_LCD_GPIO_DC         (GPIO_NUM_41)
#define EXAMPLE_LCD_GPIO_CS         (GPIO_NUM_42)
#define EXAMPLE_LCD_GPIO_BL         (GPIO_NUM_13)

/* Touch settings */
#define EXAMPLE_TOUCH_I2C_NUM       (0)
#define EXAMPLE_TOUCH_I2C_CLK_HZ    (400000)

/* LCD touch pins */
#define EXAMPLE_TOUCH_I2C_SCL       (GPIO_NUM_3)
#define EXAMPLE_TOUCH_I2C_SDA       (GPIO_NUM_1)
#define EXAMPLE_TOUCH_GPIO_INT      (GPIO_NUM_4)

esp_err_t app_lcd_init(void);
esp_err_t app_touch_init(void);
esp_err_t app_lvgl_init(void);

#ifdef __cplusplus
}
#endif