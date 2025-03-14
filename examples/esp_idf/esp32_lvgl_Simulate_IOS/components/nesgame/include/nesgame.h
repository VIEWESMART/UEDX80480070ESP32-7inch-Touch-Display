#ifndef NESGAME_H
#define NESGAME_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "sdcard.h"
#include "InfoNES.h"
#include "lvgl.h"
void nesmain(void *args);
void nesstart(char *name);
void nes_timer_cb(lv_timer_t *timer);
void nes_flush(void);
extern uint8_t stats;
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif