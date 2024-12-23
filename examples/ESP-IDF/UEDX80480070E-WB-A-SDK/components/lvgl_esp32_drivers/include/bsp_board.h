 
#ifndef _BSP_BOARD_H_
#define _BSP_BOARD_H_

#include "driver/gpio.h"

#define FUNC_LCD_EN     (1)
 
#define LCD_4r3_480x272   0   // 4r3 inch 480-272
#define LCD_4r3_800x480   0   // 4r3 inch 800-480
#define LCD_5r0_800x480   0   // 5 inch   800-480
#define LCD_5r0_480x854   0   // 5 inch   480-854
#define LCD_7r0_800x480   0   // 7 inch   800-480
#define LCD_7r0_1024x600  0   // 7 inch   1024-600
#define LCD_4r0_480x480   0   // 4 inch   480-480
#define LCD_yysj_5_800x480   0   // 5 inch 800-480
#define LCD_yysj_7_800x480   1   // 5 inch 800-480
#define LCD_yysj_4R3_480x272 0  
 
extern esp_err_t ctpfalg; //指定触摸型号

//选择触摸驱动型号
#define GT911      3
#define FT62XX     2
#define CST3240    1


#if (LCD_4r3_480x272==1)
#define LCD_WIDTH       (480)
#define LCD_HEIGHT      (272)

#elif(LCD_5r0_800x480 ==1)   // 5 inch
#define LCD_WIDTH       (800)
#define LCD_HEIGHT      (480)

#elif(LCD_5r0_480x854 ==1)   // 5 inch 480*854
#define LCD_WIDTH       (480)
#define LCD_HEIGHT      (854)


#elif(LCD_7r0_800x480 ==1)   // 7 inch 800-480
#define LCD_WIDTH       (800)
#define LCD_HEIGHT      (480)


#elif(LCD_4r3_800x480 ==1)   // 4.3 inch 800-480
#define LCD_WIDTH       (800)
#define LCD_HEIGHT      (480)

#elif(LCD_7r0_1024x600 ==1)   // 7 inch
#define LCD_WIDTH       (1024)
#define LCD_HEIGHT      (600)

#elif(LCD_4r0_480x480 ==1)   // 4 inch
#define LCD_WIDTH       (480)
#define LCD_HEIGHT      (480)

#elif (LCD_yysj_4R3_480x272 ==1)
#define LCD_WIDTH       (480)
#define LCD_HEIGHT      (272)


#elif(LCD_yysj_5_800x480 ==1)   // 4.3 inch 480-272
#define LCD_WIDTH       (800)
#define LCD_HEIGHT      (480)

#elif(LCD_yysj_5_800x480 ==1)   // 5 inch 800-480
#define LCD_WIDTH       (480)
#define LCD_HEIGHT      (272)

#elif(LCD_yysj_7_800x480 ==1)   // 7 inch 800-480
#define LCD_WIDTH       (800)
#define LCD_HEIGHT      (480)


#endif

#if 0
#define GPIO_LCD_BL     (GPIO_NUM_42)
#define GPIO_LCD_RST    (GPIO_NUM_NC)

#define GPIO_LCD_DE     (GPIO_NUM_0)
#define GPIO_LCD_VSYNC  (GPIO_NUM_1)
#define GPIO_LCD_HSYNC  (GPIO_NUM_2)
#define GPIO_LCD_PCLK   (GPIO_NUM_3)

#define GPIO_LCD_R0    (GPIO_NUM_21)
#define GPIO_LCD_R1    (GPIO_NUM_18)
#define GPIO_LCD_R2    (GPIO_NUM_17)
#define GPIO_LCD_R3    (GPIO_NUM_16)
#define GPIO_LCD_R4    (GPIO_NUM_15)

#define GPIO_LCD_G0    (GPIO_NUM_14)
#define GPIO_LCD_G1    (GPIO_NUM_13)
#define GPIO_LCD_G2    (GPIO_NUM_12)
#define GPIO_LCD_G3    (GPIO_NUM_11)
#define GPIO_LCD_G4    (GPIO_NUM_10)
#define GPIO_LCD_G5    (GPIO_NUM_9)

#define GPIO_LCD_B0    (GPIO_NUM_8)
#define GPIO_LCD_B1    (GPIO_NUM_7)
#define GPIO_LCD_B2    (GPIO_NUM_6)
#define GPIO_LCD_B3    (GPIO_NUM_5)
#define GPIO_LCD_B4    (GPIO_NUM_4)


#define FUNC_I2C_EN     (1)
#define GPIO_I2C_SCL    (GPIO_NUM_45)
#define GPIO_I2C_SDA    (GPIO_NUM_47)


#define SDMMC_BUS_WIDTH (1)
#define GPIO_SDMMC_CLK  (GPIO_NUM_39)
#define GPIO_SDMMC_CMD  (GPIO_NUM_38)
#define GPIO_SDMMC_D0   (GPIO_NUM_40)
#define GPIO_SDMMC_D1   (GPIO_NUM_NC)
#define GPIO_SDMMC_D2   (GPIO_NUM_NC)
#define GPIO_SDMMC_D3   (GPIO_NUM_NC)
#define GPIO_SDMMC_DET  (GPIO_NUM_NC)

#elif((LCD_yysj_5_800x480 ==1) || (LCD_yysj_7_800x480 ==1)||(LCD_yysj_4R3_480x272 ==1))

#define GPIO_LCD_BL     (GPIO_NUM_2)
#define GPIO_LCD_RST    (GPIO_NUM_NC)

#define GPIO_LCD_DE     (GPIO_NUM_40)
#define GPIO_LCD_VSYNC  (GPIO_NUM_41)
#define GPIO_LCD_HSYNC  (GPIO_NUM_39)
#define GPIO_LCD_PCLK   (GPIO_NUM_42)

#define GPIO_LCD_R0    (GPIO_NUM_45)
#define GPIO_LCD_R1    (GPIO_NUM_48)
#define GPIO_LCD_R2    (GPIO_NUM_47)
#define GPIO_LCD_R3    (GPIO_NUM_21)
#define GPIO_LCD_R4    (GPIO_NUM_14)

#define GPIO_LCD_G0    (GPIO_NUM_5)
#define GPIO_LCD_G1    (GPIO_NUM_6)
#define GPIO_LCD_G2    (GPIO_NUM_7)
#define GPIO_LCD_G3    (GPIO_NUM_15)
#define GPIO_LCD_G4    (GPIO_NUM_16)
#define GPIO_LCD_G5    (GPIO_NUM_4)

#define GPIO_LCD_B0    (GPIO_NUM_8)
#define GPIO_LCD_B1    (GPIO_NUM_3)
#define GPIO_LCD_B2    (GPIO_NUM_46)
#define GPIO_LCD_B3    (GPIO_NUM_9)
#define GPIO_LCD_B4    (GPIO_NUM_1)

#define GPIO_I2C_SCL    (GPIO_NUM_20)
#define GPIO_I2C_SDA    (GPIO_NUM_19)

#define GPIO_I2C_INT    (GPIO_NUM_18)
//#define GPIO_I2C_SDA    (GPIO_NUM_38)
#define GPIO_I2C_RST    (GPIO_NUM_38)

#define SDMMC_BUS_WIDTH (1)
#define GPIO_SDMMC_CLK  (GPIO_NUM_NC)
#define GPIO_SDMMC_CMD  (GPIO_NUM_NC)
#define GPIO_SDMMC_D0   (GPIO_NUM_NC)
#define GPIO_SDMMC_D1   (GPIO_NUM_NC)
#define GPIO_SDMMC_D2   (GPIO_NUM_NC)
#define GPIO_SDMMC_D3   (GPIO_NUM_NC)
#define GPIO_SDMMC_DET  (GPIO_NUM_NC)

#else
#define GPIO_LCD_BL     (GPIO_NUM_1)
#define GPIO_LCD_RST    (GPIO_NUM_NC)

#define GPIO_LCD_DE     (GPIO_NUM_5)
#define GPIO_LCD_VSYNC  (GPIO_NUM_2)
#define GPIO_LCD_HSYNC  (GPIO_NUM_4)
#define GPIO_LCD_PCLK   (GPIO_NUM_6)

#if((LCD_4r0_480x480 ==1)||(LCD_7r0_800x480 ==1))

#define GPIO_LCD_R0    (GPIO_NUM_7)
#define GPIO_LCD_R1    (GPIO_NUM_15)
#define GPIO_LCD_R2    (GPIO_NUM_16)
#define GPIO_LCD_R3    (GPIO_NUM_8)
#define GPIO_LCD_R4    (GPIO_NUM_3)

#else 

#define GPIO_LCD_B0    (GPIO_NUM_7)
#define GPIO_LCD_B1    (GPIO_NUM_15)
#define GPIO_LCD_B2    (GPIO_NUM_16)
#define GPIO_LCD_B3    (GPIO_NUM_8)
#define GPIO_LCD_B4    (GPIO_NUM_3)

#endif


#define GPIO_LCD_G0    (GPIO_NUM_46)
#define GPIO_LCD_G1    (GPIO_NUM_9)
#define GPIO_LCD_G2    (GPIO_NUM_10)
#define GPIO_LCD_G3    (GPIO_NUM_11)
#define GPIO_LCD_G4    (GPIO_NUM_12)
#define GPIO_LCD_G5    (GPIO_NUM_13)

#if((LCD_4r0_480x480 ==1)||(LCD_7r0_800x480 ==1))

#define GPIO_LCD_B0    (GPIO_NUM_14)
#define GPIO_LCD_B1    (GPIO_NUM_21)
#define GPIO_LCD_B2    (GPIO_NUM_47)
#define GPIO_LCD_B3    (GPIO_NUM_48)
#define GPIO_LCD_B4    (GPIO_NUM_45)

#else

#define GPIO_LCD_R0    (GPIO_NUM_14)
#define GPIO_LCD_R1    (GPIO_NUM_21)
#define GPIO_LCD_R2    (GPIO_NUM_47)
#define GPIO_LCD_R3    (GPIO_NUM_48)
#define GPIO_LCD_R4    (GPIO_NUM_45)

#endif

#define FUNC_I2C_EN     (1)
#define GPIO_I2C_SCL    (GPIO_NUM_41)
#define GPIO_I2C_SDA    (GPIO_NUM_42)


#define SDMMC_BUS_WIDTH (1)
#define GPIO_SDMMC_CLK  (GPIO_NUM_NC)
#define GPIO_SDMMC_CMD  (GPIO_NUM_NC)
#define GPIO_SDMMC_D0   (GPIO_NUM_NC)
#define GPIO_SDMMC_D1   (GPIO_NUM_NC)
#define GPIO_SDMMC_D2   (GPIO_NUM_NC)
#define GPIO_SDMMC_D3   (GPIO_NUM_NC)
#define GPIO_SDMMC_DET  (GPIO_NUM_NC)
#endif




#endif 
