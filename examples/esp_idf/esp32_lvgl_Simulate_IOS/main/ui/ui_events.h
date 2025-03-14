#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void backlight(lv_event_t * e);
void volumesetting(lv_event_t * e);
void wifiscanf(lv_event_t * e);
void wifistart(lv_event_t * e);
void wificlose(lv_event_t * e);
void checkwlanswitch(lv_event_t * e);
void connectwifi(lv_event_t * e);
void ampmsets(lv_event_t * e);
void oktimebtndown(lv_event_t * e);
void changetime(lv_event_t * e);
void bluetoothscanf(lv_event_t * e);
void bluetoothstart(lv_event_t * e);
void bluetoothclose(lv_event_t * e);
void bluetoothsanf(lv_event_t * e);
void musicslidertime(lv_event_t * e);
void musicleft(lv_event_t * e);
void musicright(lv_event_t * e);
void musicplay(lv_event_t * e);
void weatherget(lv_event_t * e);
void weatherchangecity(lv_event_t * e);
void musicstop(lv_event_t * e);
void musicchange(lv_event_t * e);
void listsdcard(lv_event_t * e);
void closecolor(lv_event_t * e);
void setcolor(lv_event_t * e);
void filemanagerflush(lv_event_t * e);
void opendirfile(lv_event_t * e);
void openphoto(lv_event_t * e);
void opennes(lv_event_t * e);
void closenes(lv_event_t * e);
void neszoom(lv_event_t * e);
void neskey(lv_event_t *e);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
