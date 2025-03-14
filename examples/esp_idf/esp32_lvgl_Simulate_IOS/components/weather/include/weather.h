#ifndef WEATHER_H
#define WEATHER_H

#ifdef __cplusplus
extern "C"
{
#endif
#include "wifi.h"
extern SemaphoreHandle_t lvglmutex;
void weather_get_https(const void *arg);


#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif