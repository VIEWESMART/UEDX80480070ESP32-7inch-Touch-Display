#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "lvgl.h"
#include "ui.h"
#include "driver/uart.h"
static const int RX_BUF_SIZE = 128;
extern SemaphoreHandle_t lvglmutex;
extern char uart_data[32];
extern char uart_vo[5];
extern char uart_vol;
#define TXD_PIN (GPIO_NUM_43)
#define RXD_PIN (GPIO_NUM_44)
void uart_init(void);
void showbat(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif