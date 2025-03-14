#ifndef RGBLED_H
#define RGBLED_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
// #include "ui.h"
void setcolortask(void *hsv);
void rgbledinit(void);
void closergbled(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif