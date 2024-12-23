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
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x13}, 5, 0},  \
        {0xEF, (uint8_t[]){0x08}, 1, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x10}, 5, 0}, \
        {0xC0, (uint8_t[]){0x3B, 0x00}, 2, 0},  \
        {0xC1, (uint8_t[]){0x0B, 0x02}, 2, 0},  \
        {0xC2, (uint8_t[]){0x07, 0x02}, 2, 0},  \
        {0xC7, (uint8_t[]){0x00}, 1, 0},  \
        {0xCC, (uint8_t[]){0x10}, 1, 0},  \
        {0xCD, (uint8_t[]){0x08}, 1, 0},  \
        {0xB0, (uint8_t[]){0x00, 0x11, 0x16, 0x0E, 0x11, 0x06, 0x05, 0x09, 0x08, 0x21, 0x06, 0x13, 0x10, 0x29, 0x31, 0x18}, 16, 0},  \
        {0xB1, (uint8_t[]){0x00, 0x11, 0x16, 0x0E, 0x11, 0x07, 0x05, 0x09, 0x09, 0x21, 0x05, 0x13, 0x11, 0x2A, 0x31, 0x18}, 16, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x11}, 5, 0},  \
        {0xB0, (uint8_t[]){0x6D}, 1, 0},  \
        {0xB1, (uint8_t[]){0x37}, 1, 0},  \
        {0xB2, (uint8_t[]){0x8B}, 1, 0},  \
        {0xB3, (uint8_t[]){0x80}, 1, 0},  \
        {0xB5, (uint8_t[]){0x43}, 1, 0},  \
        {0xB7, (uint8_t[]){0x85}, 1, 0},  \
        {0xB8, (uint8_t[]){0x20}, 1, 0},  \
        {0xC0, (uint8_t[]){0x09}, 1, 0},  \
        {0xC1, (uint8_t[]){0x78}, 1, 0},  \
        {0xC2, (uint8_t[]){0x78}, 1, 0},  \
        {0xD0, (uint8_t[]){0x88}, 1, 0},  \
        {0xE0, (uint8_t[]){0x00, 0x00, 0x02}, 3, 0},  \
        {0xE1, (uint8_t[]){0x03, 0xA0, 0x00, 0x00, 0x04, 0xA0, 0x00, 0x00, 0x00, 0x20, 0x20}, 11, 0},  \
        {0xE2, (uint8_t[]){0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 13, 0},  \
        {0xE3, (uint8_t[]){0x00, 0x00, 0x11, 0x00}, 4, 0},  \
        {0xE4, (uint8_t[]){0x22, 0x00}, 2, 0},  \
        {0xE5, (uint8_t[]){0x05, 0xEC, 0xF6, 0xCA, 0x07, 0xEE, 0xF6, 0xCA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 16, 0},  \
        {0xE6, (uint8_t[]){0x00, 0x00, 0x11, 0x00}, 4, 0},  \
        {0xE7, (uint8_t[]){0x22, 0x00}, 2, 0},  \
        {0xE8, (uint8_t[]){0x06, 0xED, 0xF6, 0xCA, 0x08, 0xEF, 0xF6, 0xCA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 16, 0},  \
        {0xE9, (uint8_t[]){0x36, 0x00}, 2, 0},  \
        {0xEB, (uint8_t[]){0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00}, 1, 0},  \
        {0xED, (uint8_t[]){0xFF, 0xFF, 0xFF, 0xBA, 0x0A, 0xFF, 0x45, 0xFF, 0xFF, 0x54, 0xFF, 0xA0, 0xAB, 0xFF, 0xFF, 0xFF}, 16, 0},  \
        {0xEF, (uint8_t[]){0x08, 0x08, 0x08, 0x45, 0x3F, 0x54}, 6, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x13}, 5, 0},  \
        {0xE8, (uint8_t[]){0x00, 0x0E}, 2, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x00}, 5, 0},  \
        {0x11, (uint8_t[]){0x00}, 1, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x13}, 5, 0},  \
        {0xE8, (uint8_t[]){0x00, 0x0C}, 2, 0},  \
        {0xE8, (uint8_t[]){0x00, 0x00}, 2, 0},  \
        {0xFF, (uint8_t[]){0x77, 0x01, 0x00, 0x00, 0x00}, 5, 0},  \
        {0x36, (uint8_t[]){0x00}, 1, 0},  \
        {0x3A, (uint8_t[]){0x66}, 1, 0},  \
        {0x29, (uint8_t[]){0x00}, 1, 0},\
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
#define ESP_PANEL_USE_TOUCH         (1)         // 0/1
#if ESP_PANEL_USE_TOUCH
/**
 * Touch controller name
 */
#define ESP_PANEL_TOUCH_NAME        CST816S

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
#define ESP_PANEL_TOUCH_BUS_TYPE            (ESP_PANEL_BUS_TYPE_I2C)
/* Touch panel bus parameters */
#if ESP_PANEL_TOUCH_BUS_TYPE == ESP_PANEL_BUS_TYPE_I2C

    #define ESP_PANEL_TOUCH_BUS_HOST_ID     (0)     // Typically set to 0
    #define ESP_PANEL_TOUCH_I2C_ADDRESS     (0)     // Typically set to 0 to use default address
#if !ESP_PANEL_TOUCH_BUS_SKIP_INIT_HOST
    #define ESP_PANEL_TOUCH_I2C_CLK_HZ      (400 * 1000)
                                                    // Typically set to 400K
    #define ESP_PANEL_TOUCH_I2C_SCL_PULLUP  (1)     // 0/1
    #define ESP_PANEL_TOUCH_I2C_SDA_PULLUP  (1)     // 0/1
    #define ESP_PANEL_TOUCH_I2C_IO_SCL      (15)
    #define ESP_PANEL_TOUCH_I2C_IO_SDA      (16)
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
