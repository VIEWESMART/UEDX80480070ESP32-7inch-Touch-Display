#ifndef VOLUME_H
#define VOLUME_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "esp_log.h"
#include "driver/ledc.h"
#include "driver/i2s_std.h"

#define MP3_STD_BCLK_IO1 GPIO_NUM_5 // I2S bit clock io number
#define MP3_STD_WS_IO1 GPIO_NUM_6   // I2S word select io number
#define MP3_STD_DOUT_IO1 GPIO_NUM_7 // I2S data out io number
#define MP3_STD_DIN_IO1 GPIO_NUM_8  // I2S data in io number
extern i2s_chan_handle_t tx_chan; // I2S tx channel handler
extern i2s_std_config_t std_cfg;
void volume_ledc_init(void);
void i2s_init_std_duplex(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif