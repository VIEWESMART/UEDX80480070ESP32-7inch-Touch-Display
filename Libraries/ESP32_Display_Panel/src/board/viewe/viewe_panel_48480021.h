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

/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

// *INDENT-OFF*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the LCD panel /////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 1 when using an LCD panel */
#define ESP_PANEL_USE_LCD           (1)     // 0/1

#if ESP_PANEL_USE_LCD
/**
 * LCD Controller Name
 */
#define ESP_PANEL_LCD_NAME          GC9503

/* LCD resolution in pixels */
#define ESP_PANEL_LCD_WIDTH         (480)
#define ESP_PANEL_LCD_HEIGHT        (480)

/* LCD Bus Settings */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 */
#define ESP_PANEL_LCD_BUS_SKIP_INIT_HOST    (0)     // 0/1
/**
 * LCD Bus Type.
 */
#define ESP_PANEL_LCD_BUS_TYPE      (ESP_PANEL_BUS_TYPE_RGB)
/**
 * LCD Bus Parameters.
 *
 * Please refer to https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/lcd.html and
 * https://docs.espressif.com/projects/esp-iot-solution/en/latest/display/lcd/index.html for more details.
 *
 */
#if ESP_PANEL_LCD_BUS_TYPE == ESP_PANEL_BUS_TYPE_RGB

    #define ESP_PANEL_LCD_RGB_CLK_HZ            (16 * 1000 * 1000)
    #define ESP_PANEL_LCD_RGB_HPW               (8)
    #define ESP_PANEL_LCD_RGB_HBP               (20)
    #define ESP_PANEL_LCD_RGB_HFP               (40)
    #define ESP_PANEL_LCD_RGB_VPW               (8)
    #define ESP_PANEL_LCD_RGB_VBP               (20)
    #define ESP_PANEL_LCD_RGB_VFP               (50)
    #define ESP_PANEL_LCD_RGB_PCLK_ACTIVE_NEG   (0)     // 0: rising edge, 1: falling edge
    #define ESP_PANEL_LCD_RGB_DATA_WIDTH        (16)    //  8 | 16
    #define ESP_PANEL_LCD_RGB_PIXEL_BITS        (16)    // 24 | 16
    #define ESP_PANEL_LCD_RGB_FRAME_BUF_NUM     (1)     // 1/2/3
    #define ESP_PANEL_LCD_RGB_BOUNCE_BUF_SIZE   (ESP_PANEL_LCD_WIDTH * 10)
                                                        // Bounce buffer size in bytes. This function is used to avoid screen drift.
                                                        // To enable the bounce buffer, set it to a non-zero value.
                                                        // Typically set to `ESP_PANEL_LCD_WIDTH * 10`
    #define ESP_PANEL_LCD_RGB_IO_HSYNC          (46)
    #define ESP_PANEL_LCD_RGB_IO_VSYNC          (3)
    #define ESP_PANEL_LCD_RGB_IO_DE             (17)   // -1 if not used
    #define ESP_PANEL_LCD_RGB_IO_PCLK           (9)
    #define ESP_PANEL_LCD_RGB_IO_DISP           (-1)    // -1 if not used
    #define ESP_PANEL_LCD_RGB_IO_DATA0          (10)
    #define ESP_PANEL_LCD_RGB_IO_DATA1          (11)
    #define ESP_PANEL_LCD_RGB_IO_DATA2          (12)
    #define ESP_PANEL_LCD_RGB_IO_DATA3          (13)
    #define ESP_PANEL_LCD_RGB_IO_DATA4          (14)
    #define ESP_PANEL_LCD_RGB_IO_DATA5          (21)
    #define ESP_PANEL_LCD_RGB_IO_DATA6          (47)
    #define ESP_PANEL_LCD_RGB_IO_DATA7          (48)
#if ESP_PANEL_LCD_RGB_DATA_WIDTH > 8
    #define ESP_PANEL_LCD_RGB_IO_DATA8          (45)
    #define ESP_PANEL_LCD_RGB_IO_DATA9          (38)
    #define ESP_PANEL_LCD_RGB_IO_DATA10         (39)
    #define ESP_PANEL_LCD_RGB_IO_DATA11         (40)
    #define ESP_PANEL_LCD_RGB_IO_DATA12         (41)
    #define ESP_PANEL_LCD_RGB_IO_DATA13         (42)
    #define ESP_PANEL_LCD_RGB_IO_DATA14         (2)
    #define ESP_PANEL_LCD_RGB_IO_DATA15         (1)
#endif
#if !ESP_PANEL_LCD_BUS_SKIP_INIT_HOST
    #define ESP_PANEL_LCD_3WIRE_SPI_IO_CS               (18)
    #define ESP_PANEL_LCD_3WIRE_SPI_IO_SCK              (13)
    #define ESP_PANEL_LCD_3WIRE_SPI_IO_SDA              (12)
    // #define ESP_PANEL_LCD_BTN_PRESS                     (0) //BTN
    // #define ESP_PANEL_LCD_ENCODER_A                     (6) //编码器
    // #define ESP_PANEL_LCD_ENCODER_B                     (5) //


    #define ESP_PANEL_LCD_3WIRE_SPI_CS_USE_EXPNADER     (0)     // 0/1
    #define ESP_PANEL_LCD_3WIRE_SPI_SCL_USE_EXPNADER    (0)     // 0/1
    #define ESP_PANEL_LCD_3WIRE_SPI_SDA_USE_EXPNADER    (0)     // 0/1
    #define ESP_PANEL_LCD_3WIRE_SPI_SCL_ACTIVE_EDGE     (0)     // 0: rising edge, 1: falling edge
    #define ESP_PANEL_LCD_FLAGS_AUTO_DEL_PANEL_IO       (1)     // Delete the panel IO instance automatically if set to 1.
                                                                // If the 3-wire SPI pins are sharing other pins of the RGB interface to save GPIOs,
                                                                // Please set it to 1 to release the panel IO and its pins (except CS signal).
    #define ESP_PANEL_LCD_FLAGS_MIRROR_BY_CMD           (!ESP_PANEL_LCD_FLAGS_AUTO_DEL_PANEL_IO)
                                                                // The `mirror()` function will be implemented by LCD command if set to 1.
#endif

#endif /* ESP_PANEL_LCD_BUS_TYPE */

/**
 * LCD Venbdor Initialization Commands.
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
#define ESP_PANEL_LCD_VENDOR_INIT_CMD() \
    { \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF0, {0x55, 0xAA, 0x52, 0x08, 0x00}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF6, {0x5A, 0x87}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC1, {0x3F}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCD, {0x25}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xCD, {0x00}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xC9, {0x10}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xF8, {0x8A}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xAC, {0x45}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA7, {0x47}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xA0, {0xDD}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x87, {0x04, 0x03, 0x66}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x86, {0x99, 0xa3, 0xa3, 0x51}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xFA, {0x08, 0x08, 0x08, 0x04}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9A, {0x8a}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x9B, {0x62}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x82, {0x48, 0x48}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xB1, {0x10}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7A, {0x13, 0x1A}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x7B, {0x13, 0x1A}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x6D, {0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x02, 0x0b, 0x01, 0x00, 0x1f, 0x1e, 0x09, 0x0f, 0x1e, 0x1e, 0x1e, 0x1e, 0x10, 0x0a, 0x1e, 0x1f, 0x00, 0x08, 0x0b, 0x02, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x64, {0x18, 0x07, 0x01, 0xE7, 0x03, 0x03, 0x18, 0x06, 0x01, 0xE6, 0x03, 0x03, 0x7a, 0x7a, 0x7a, 0x7a}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x65, {0x58, 0x26, 0x18, 0x2c, 0x03, 0x03, 0x58, 0x26, 0x18, 0x2c, 0x03, 0x03, 0x7a, 0x7a, 0x7a, 0x7a}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x66, {0x58, 0x26, 0x18, 0x2c, 0x03, 0x03, 0x58, 0x26, 0x18, 0x2c, 0x03, 0x03, 0x7a, 0x7a, 0x7a, 0x7a}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x67, {0x18, 0x05, 0x01, 0xE5, 0x03, 0x03, 0x18, 0x04, 0x01, 0xE4, 0x03, 0x03, 0x7a, 0x7a, 0x7a, 0x7a}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x60, {0x18, 0x09, 0x7A, 0x7A, 0x51, 0xF1, 0x7A, 0x7A}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0x63, {0x51, 0xF1, 0x7A, 0x7A, 0x18, 0x08, 0x7A, 0x7A}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD1, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD2, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD3, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD4, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD5, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_8BIT_PARAM(0, 0xD6, {0x00, 0x00, 0x00, 0x0E, 0x00, 0x31, 0x00, 0x4E, 0x00, 0x67, 0x00, 0x92, 0x00, 0xB5, 0x00, 0xED, 0x01, 0x1C, 0x01, 0x66, 0x01, 0xA4, 0x02, 0x04, 0x02, 0x53, 0x02, 0x56, 0x02, 0x9F, 0x02, 0xF3, 0x03, 0x29, 0x03, 0x73, 0x03, 0xA1, 0x03, 0xB9, 0x03, 0xC8, 0x03, 0xDB, 0x03, 0xE7, 0x03, 0xF4, 0x03, 0xFB, 0x03, 0XFF}), \
        ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(120, 0x11), \
        ESP_PANEL_LCD_CMD_WITH_NONE_PARAM(120, 0x29), \
    }

/* LCD Color Settings */
/* LCD color depth in bits */
#define ESP_PANEL_LCD_COLOR_BITS    (24)        // 8/16/18/24
/*
 * LCD RGB Element Order. Choose one of the following:
 *      - 0: RGB
 *      - 1: BGR
 */
#define ESP_PANEL_LCD_BGR_ORDER     (0)         // 0/1
#define ESP_PANEL_LCD_INEVRT_COLOR  (0)         // 0/1

/* LCD Transformation Flags */
#define ESP_PANEL_LCD_SWAP_XY       (0)         // 0/1
#define ESP_PANEL_LCD_MIRROR_X      (0)         // 0/1
#define ESP_PANEL_LCD_MIRROR_Y      (0)         // 0/1

/* LCD Other Settings */
/* IO num of RESET pin, set to -1 if not use */
#define ESP_PANEL_LCD_IO_RST        (8)
#define ESP_PANEL_LCD_RST_LEVEL     (0)         // 0: low level, 1: high level

#endif /* ESP_PANEL_USE_LCD */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Please update the following macros to configure the touch panel ///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 1 when using an touch panel */
#define ESP_PANEL_USE_TOUCH         (0)         // 0/1
#if ESP_PANEL_USE_TOUCH
/**
 * Touch controller name
 */
#define ESP_PANEL_TOUCH_NAME        GT911

/* Touch resolution in pixels */
#define ESP_PANEL_TOUCH_H_RES       (ESP_PANEL_LCD_WIDTH)   // Typically set to the same value as the width of LCD
#define ESP_PANEL_TOUCH_V_RES       (ESP_PANEL_LCD_HEIGHT)  // Typically set to the same value as the height of LCD

/* Touch Panel Bus Settings */
/**
 * If set to 1, the bus will skip to initialize the corresponding host. Users need to initialize the host in advance.
 * It is useful if other devices use the same host. Please ensure that the host is initialized only once.
 */
#define ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST      (0)     // 0/1
/**
 * Touch panel bus type
 */
#define ESP_PANEL_TOUCH_BUS_TYPE            (0)
/* Touch panel bus parameters */
#if ESP_PANEL_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_I2C

    #define ESP_PANEL_TOUCH_BUS_HOST_ID     (0)     // Typically set to 0
    #define ESP_PANEL_TOUCH_I2C_ADDRESS     (0)     // Typically set to 0 to use default address
#if !ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST
    #define ESP_PANEL_TOUCH_I2C_CLK_HZ      (400 * 1000)
                                                    // Typically set to 400K
    #define ESP_PANEL_TOUCH_I2C_SCL_PULLUP  (1)     // 0/1
    #define ESP_PANEL_TOUCH_I2C_SDA_PULLUP  (1)     // 0/1
    #define ESP_PANEL_TOUCH_I2C_IO_SCL      (45)
    #define ESP_PANEL_TOUCH_I2C_IO_SDA      (19)
#endif

#endif /* ESP_PANEL_TOUCH_BUS_TYPE */

/* Touch Transformation Flags */
#define ESP_PANEL_TOUCH_SWAP_XY         (0)         // 0/1
#define ESP_PANEL_TOUCH_MIRROR_X        (0)         // 0/1
#define ESP_PANEL_TOUCH_MIRROR_Y        (0)         // 0/1

/* Touch Other Settings */
/* IO num of RESET pin, set to -1 if not use */
#define ESP_PANEL_TOUCH_IO_RST          (-1)
#define ESP_PANEL_TOUCH_RST_LEVEL       (0)         // 0: low level, 1: high level
/* IO num of INT pin, set to -1 if not use */
#define ESP_PANEL_TOUCH_IO_INT          (-1)
#define ESP_PANEL_TOUCH_INT_LEVEL       (0)         // 0: low level, 1: high level

#endif /* ESP_PANEL_USE_TOUCH */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the backlight ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ESP_PANEL_USE_BACKLIGHT         (1)         // 0/1
#if ESP_PANEL_USE_BACKLIGHT
/* IO num of backlight pin */
#define ESP_PANEL_BACKLIGHT_IO          (7)
#define ESP_PANEL_BACKLIGHT_ON_LEVEL    (0)         // 0: low level, 1: high level

/* Set to 1 if turn off the backlight after initializing the panel; otherwise, set it to turn on */
#define ESP_PANEL_BACKLIGHT_IDLE_OFF    (0)         // 0: on, 1: off

/* Set to 1 if use PWM for brightness control */
#define ESP_PANEL_LCD_BL_USE_PWM        (0)         // 0/1
#endif /* ESP_PANEL_USE_BACKLIGHT */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Please update the following macros to configure the IO expander //////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Set to 0 if not using IO Expander */
#define ESP_PANEL_USE_EXPANDER          (0)         // 0/1

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
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_MINOR 1
#define ESP_PANEL_BOARD_CUSTOM_FILE_VERSION_PATCH 2

#endif /* ESP_PANEL_USE_CUSTOM_BOARD */

// *INDENT-OFF*
