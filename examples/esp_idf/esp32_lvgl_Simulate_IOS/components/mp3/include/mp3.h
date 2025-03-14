#ifndef MP3_H
#define MP3_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "freertos/FreeRTOS.h"
#include "driver/i2s_std.h"
#include "sdcard.h"
#include "ui.h"
#include "lvgl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DR_MP3_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION
#define DR_FLAC_IMPLEMENTATION
extern volatile bool seekpoint;
extern uint64_t pcmfram;
extern uint16_t sampleRate;
extern SemaphoreHandle_t lvglmutex;
extern char musicplaytime[10];
extern volatile uint64_t playsilder;
void audio_write_task(void *args);
void switch_track(void *new_track);
void start_track(void *new_track);
void musicpause(void);
void musicstart(void);
void stop_track(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif