/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

// *INDENT-OFF*

/* Set to 1 if using a custom board */
#define ESP_PANEL_USE_CUSTOM_BOARD       (1)         // 0/1

#if ESP_PANEL_USE_CUSTOM_BOARD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the LCD panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 1 when using an LCD panel */
#define ESP_PANEL_USE_LCD           (1)     // 0/1

#if ESP_PANEL_USE_LCD
/**
 * LCD Controller Name. Choose one of the following:
 *      - EK9716B
 *      - GC9A01, GC9B71, GC9503
 *      - ILI9341
 *      - NV3022B
 *      - SH8601
 *      - SPD2010
 *      - ST7262, ST7701, ST7789, ST7796, ST77916, ST77922
 */
#define ESP_PANEL_LCD_NAME          GC9A01

/* LCD resolution in pixels */
#define ESP_PANEL_LCD_WIDTH         (240)
#define ESP_PANEL_LCD_HEIGHT        (240)

/* LCD Bus Settings */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 *
 * Set to 1 if only the RGB interface is used without the 3-wire SPI interface,
 */
#define ESP_PANEL_LCD_BUS_SKIP_INIT_HOST    (0)     // 0/1
/**
 * LCD Bus Type. Choose one of the following:
 *      - ESP_PANEL_BUS_TYPE_I2C (not ready)
 *      - ESP_PANEL_BUS_TYPE_SPI
 *      - ESP_PANEL_BUS_TYPE_QSPI
 *      - ESP_PANEL_BUS_TYPE_I80 (not ready)
 *      - ESP_PANEL_BUS_TYPE_RGB (only supported for ESP32-S3)
 */
#define ESP_PANEL_LCD_BUS_TYPE      (ESP_PANEL_BUS_TYPE_SPI)
/**
 * LCD Bus Parameters.
 *
 * Please refer to https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/lcd.html and
 * https://docs.espressif.com/projects/esp-iot-solution/en/latest/display/lcd/index.html for more details.
 *
 */
#if ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_SPI

    #define ESP_PANEL_LCD_BUS_HOST_ID           (1)     // Typically set to 1
    #define ESP_PANEL_LCD_SPI_IO_CS             (10)
#if !ESP_PANEL_LCD_BUS_SKIP_INIT_HOST
    #define ESP_PANEL_LCD_SPI_IO_SCK            (1)
    #define ESP_PANEL_LCD_SPI_IO_MOSI           (0)
    #define ESP_PANEL_LCD_SPI_IO_MISO           (-1)    // -1 if not used
#endif
    #define ESP_PANEL_LCD_SPI_IO_DC             (4)
    #define ESP_PANEL_LCD_SPI_MODE              (0)     // 0/1/2/3, typically set to 0
    #define ESP_PANEL_LCD_SPI_CLK_HZ            (80 * 1000 * 1000)
                                                        // Should be an integer divisor of 80M, typically set to 40M
    #define ESP_PANEL_LCD_SPI_TRANS_QUEUE_SZ    (10)    // Typically set to 10
    #define ESP_PANEL_LCD_SPI_CMD_BITS          (8)     // Typically set to 8
    #define ESP_PANEL_LCD_SPI_PARAM_BITS        (8)     // Typically set to 8
#else

#error "The function is not ready and will be implemented in the future."

#endif /* ESP_PANEL_LCD_BUS_TYPE */

/**
 * LCD Vendor Initialization Commands.
 *
 * Vendor specific initialization can be different between manufacturers, should consult the LCD supplier for
 * initialization sequence code. Please uncomment and change the following macro definitions. Otherwise, the LCD driver
 * will use the default initialization sequence code.
 *
 * There are two formats for the sequence code:
 *   1. Raw data: {command, (uint8_t []){ data0, data1, ... }, data_size, delay_ms}
 *   2. Formater: ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(delay_ms, command, { data0, data1, ... }) and
 *                ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(delay_ms, command)
 */
// #define ESP_PANEL_LCD_VENDOR_INIT_CMD()                                        \
//     {                                                                          \
//         {0xfe, (uint8_t []){0x00}, 0, 0}, \
//         {0xef, (uint8_t []){0x00}, 0, 0}, \
//         {0xeb, (uint8_t []){0x14}, 1, 0}, \
//         {0x84, (uint8_t []){0x60}, 1, 0}, \
//         {0x85, (uint8_t []){0xFF}, 1, 0}, \
//         {0x86, (uint8_t []){0xFF}, 1, 0}, \
//         {0x87, (uint8_t []){0xFF}, 1, 0}, \
//         {0x8e, (uint8_t []){0xFF}, 1, 0}, \
//         {0x8f, (uint8_t []){0xFF}, 1, 0}, \
//         {0x88, (uint8_t []){0x0A}, 1, 0}, \
//         {0x89, (uint8_t []){0x21}, 1, 0}, \
//         {0x8a, (uint8_t []){0x00}, 1, 0}, \
//         {0x8b, (uint8_t []){0x80}, 1, 0}, \
//         {0x8c, (uint8_t []){0x01}, 1, 0}, \
//         {0x8d, (uint8_t []){0x03}, 1, 0}, \
//         {0xb5, (uint8_t []){0x08, 0x09, 0x14, 0x08}, 4, 0}, \
//         {0xb6, (uint8_t []){0x00, 0x00}, 2, 0}, \
//         {0x36, (uint8_t []){0x48}, 1, 0}, \
//         {0x3a, (uint8_t []){0x05}, 1, 0}, \
//         {0x90, (uint8_t []){0x08, 0x08, 0x08, 0x08}, 4, 0}, \
//         {0xbd, (uint8_t []){0x06}, 1, 0}, \
//         {0xba, (uint8_t []){0x01}, 1, 0}, \
//         {0xbc, (uint8_t []){0x00}, 1, 0}, \
//         {0xff, (uint8_t []){0x60, 0x01, 0x04}, 3, 0}, \
//         {0xc3, (uint8_t []){0x13}, 1, 0}, \
//         {0xc4, (uint8_t []){0x13}, 1, 0}, \
//         {0xc9, (uint8_t []){0x25}, 1, 0}, \
//         {0xbe, (uint8_t []){0x11}, 1, 0}, \
//         {0xe1, (uint8_t []){0x10, 0x0e}, 2, 0}, \
//         {0xdf, (uint8_t []){0x21, 0x0c, 0x02}, 3, 0}, \
//         {0xf0, (uint8_t []){0x45, 0x09, 0x08, 0x08, 0x26, 0x2a}, 6, 0}, \
//         {0xf1, (uint8_t []){0x43, 0x70, 0x72, 0x36, 0x37, 0x6f}, 6, 0}, \
//         {0xf2, (uint8_t []){0x45, 0x09, 0x08, 0x08, 0x26, 0x2a}, 6, 0}, \
//         {0xf3, (uint8_t []){0x43, 0x70, 0x72, 0x36, 0x37, 0x6f}, 6, 0}, \
//         {0xed, (uint8_t []){0x1b, 0x0b}, 2, 0}, \
//         {0xae, (uint8_t []){0x77}, 1, 0}, \
//         {0xcd, (uint8_t []){0x63}, 1, 0}, \
//         {0x70, (uint8_t []){0x07, 0x07, 0x04, 0x0e, 0x0f, 0x09, 0x07, 0x08, 0x03}, 9, 0}, \
//         {0xe8, (uint8_t []){0x34}, 1, 0}, \
//         {0x62, (uint8_t []){0x18, 0x0d, 0x71, 0xed, 0x70, 0x70, 0x18, 0x0f, 0x71, 0xef, 0x70, 0x70}, 12, 0}, \
//         {0x63, (uint8_t []){0x18, 0x11, 0x71, 0xf1, 0x70, 0x70, 0x18, 0x13, 0x71, 0xf3, 0x70, 0x70}, 12, 0}, \
//         {0x64, (uint8_t []){0x28, 0x29, 0xf1, 0x01, 0xf1, 0x00, 0x07}, 7, 0}, \
//         {0x66, (uint8_t []){0x3c, 0x00, 0xcd, 0x67, 0x45, 0x45, 0x10, 0x00, 0x00, 0x00}, 10, 0}, \
//         {0x67, (uint8_t []){0x00, 0x3c, 0x00, 0x00, 0x00, 0x01, 0x54, 0x10, 0x32, 0x98}, 10, 0}, \
//         {0x74, (uint8_t []){0x10, 0x85, 0x80, 0x00, 0x00, 0x4e, 0x00}, 7, 0}, \
//         {0x98, (uint8_t []){0x3e, 0x07}, 2, 0}, \
//         {0x99, (uint8_t []){0x3e, 0x07}, 2, 0}, \
//         {0x35, (uint8_t []){0x00}, 1, 0}, \
//         {0x44, (uint8_t []){0x00, 0x4a}, 2, 0}, \
//         {0x21, (uint8_t []){0x00}, 0, 0}, \
//         {0x2a, (uint8_t []){0x00, 0x00, 0x00, 0xef}, 4, 0}, \
//         {0x2b, (uint8_t []){0x00, 0x00, 0x00, 0xef}, 4, 0}, \
//         {0x2c, (uint8_t []){0x00}, 0, 0}, \
//         {0x11, (uint8_t []){0x00}, 0, 120}, \
//         {0x29, (uint8_t []){0x00}, 0, 20}, \
//     }

/* LCD Color Settings */
/* LCD color depth in bits */
#define ESP_PANEL_LCD_COLOR_BITS    (16)        // 8/16/18/24
/*
 * LCD RGB Element Order. Choose one of the following:
 *      - 0: RGB
 *      - 1: BGR
 */
#define ESP_PANEL_LCD_BGR_ORDER     (0)         // 0/1
#define ESP_PANEL_LCD_INEVRT_COLOR  (0)         // 0/1

/* LCD Transformation Flags */
#define ESP_PANEL_LCD_SWAP_XY       (0)         // 0/1
#define ESP_PANEL_LCD_MIRROR_X      (1)         // 0/1
#define ESP_PANEL_LCD_MIRROR_Y      (0)         // 0/1

/* LCD Other Settings */
/* Reset pin */
#define ESP_PANEL_LCD_IO_RST          (-1)      // IO num of RESET pin, set to -1 if not use
#define ESP_PANEL_LCD_RST_LEVEL       (0)       // Active level. 0: low level, 1: high level

#endif /* ESP_PANEL_USE_LCD */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the backlight ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ESP_PANEL_USE_BACKLIGHT         (1)         // 0/1
#if ESP_PANEL_USE_BACKLIGHT
/* Backlight pin */
#define ESP_PANEL_BACKLIGHT_IO          (8)        // IO num of backlight pin
#define ESP_PANEL_BACKLIGHT_ON_LEVEL    (1)         // 0: low level, 1: high level

/* Set to 1 if you want to turn off the backlight after initializing the panel; otherwise, set it to turn on */
#define ESP_PANEL_BACKLIGHT_IDLE_OFF    (1)         // 0: on, 1: off

/* Set to 1 if use PWM for brightness control */
#define ESP_PANEL_LCD_BL_USE_PWM        (0)         // 0/1
#endif /* ESP_PANEL_USE_BACKLIGHT */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the IO expander //////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 0 if not using IO Expander */
#define ESP_PANEL_USE_EXPANDER          (0)         // 0/1
#if ESP_PANEL_USE_EXPANDER
/**
 * IO expander name. Choose one of the following:
 *      - CH422G
 *      - HT8574
 *      - TCA95xx_8bit
 *      - TCA95xx_16bit
 */
#define ESP_PANEL_EXPANDER_NAME         TCA95xx_8bit

/* IO expander Settings */
/**
 * If set to 1, the driver will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 */
#define ESP_PANEL_EXPANDER_SKIP_INIT_HOST       (0)     // 0/1
/* IO expander parameters */
#define ESP_PANEL_EXPANDER_HOST_ID              (0)     // Typically set to 0
#define ESP_PANEL_EXPANDER_I2C_ADDRESS          (0x20)  // The actual I2C address. Even for the same model of IC,
                                                        // the I2C address may be different, and confirmation based on
                                                        // the actual hardware connection is required
#if !ESP_PANEL_EXPANDER_SKIP_INIT_HOST
    #define ESP_PANEL_EXPANDER_I2C_CLK_HZ       (400 * 1000)
                                                        // Typically set to 400K
    #define ESP_PANEL_EXPANDER_I2C_SCL_PULLUP   (1)     // 0/1
    #define ESP_PANEL_EXPANDER_I2C_SDA_PULLUP   (1)     // 0/1
    #define ESP_PANEL_EXPANDER_I2C_IO_SCL       (18)
    #define ESP_PANEL_EXPANDER_I2C_IO_SDA       (8)
#endif
#endif /* ESP_PANEL_USE_EXPANDER */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please utilize the following macros to execute any additional code if required. //////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #define ESP_PANEL_BEGIN_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_EXPANDER_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_EXPANDER_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_LCD_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_LCD_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_TOUCH_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_TOUCH_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_BACKLIGHT_START_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_BACKLIGHT_END_FUNCTION( panel )
// #define ESP_PANEL_BEGIN_END_FUNCTION( panel )

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// File Version ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Do not change the following versions, they are used to check if the configurations in this file are compatible with
 * the current version of `ESP_Panel_Board_Custom.h` in the library. The detailed rules are as follows:
 *
 *   1. If the major version is not consistent, then the configurations in this file are incompatible with the library
 *      and must be replaced with the file from the library.
 *   2. If the minor version is not consistent, this file might be missing some new configurations, which will be set to
 *      default values. It is recommended to replace it with the file from the library.
 *   3. Even if the patch version is not consistent, it will not affect normal functionality.
 *
 */
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MAJOR 0
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MINOR 2
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_PATCH 2

#endif /* ESP_PANEL_USE_CUSTOM_BOARD */

// *INDENT-OFF*
