#ifndef _MP3GUI_UI_H
#define _MP3GUI_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

    void moveleft_Animation(lv_obj_t *TargetObject, int delay);
    void moveright_Animation(lv_obj_t *TargetObject, int delay);
    void moveup_Animation(lv_obj_t *TargetObject, int delay);
    void movedown_Animation(lv_obj_t *TargetObject, int delay);
    void turn_Animation(lv_obj_t *TargetObject, int delay);
    void turnoff_Animation(lv_obj_t *TargetObject, int delay);
    void turnone_Animation(lv_obj_t *TargetObject, int delay);
    // SCREEN: ui_home
    void ui_home_screen_init(void);
    extern lv_obj_t *ui_home;
    void ui_event_header(lv_event_t *e);
    extern lv_obj_t *ui_header;
    extern lv_obj_t *ui_body;
    extern lv_obj_t *ui_home1;
    void ui_event_camera(lv_event_t *e);
    extern lv_obj_t *ui_camera;
    extern lv_obj_t *ui_cameratext;
    void ui_event_clock(lv_event_t *e);
    extern lv_obj_t *ui_clock;
    extern lv_obj_t *ui_clocktext;
    void ui_event_gallery(lv_event_t *e);
    extern lv_obj_t *ui_gallery;
    extern lv_obj_t *ui_gallerytext;
    void ui_event_music(lv_event_t *e);
    extern lv_obj_t *ui_music;
    extern lv_obj_t *ui_musictext;
    void ui_event_settings(lv_event_t *e);
    extern lv_obj_t *ui_settings;
    extern lv_obj_t *ui_settingstext;
    void ui_event_notes(lv_event_t *e);
    extern lv_obj_t *ui_notes;
    extern lv_obj_t *ui_notestext;
    void ui_event_weather(lv_event_t *e);
    extern lv_obj_t *ui_weather;
    extern lv_obj_t *ui_weathertext;
    void ui_event_contacts(lv_event_t *e);
    extern lv_obj_t *ui_contacts;
    extern lv_obj_t *ui_contactstext;
    void ui_event_caculator(lv_event_t *e);
    extern lv_obj_t *ui_caculator;
    extern lv_obj_t *ui_caculatortext;
    void ui_event_filemanager(lv_event_t *e);
    extern lv_obj_t *ui_filemanager;
    extern lv_obj_t *ui_filemanagertext;
    void ui_event_video(lv_event_t *e);
    extern lv_obj_t *ui_video;
    extern lv_obj_t *ui_videotext;
    void ui_event_car(lv_event_t *e);
    extern lv_obj_t *ui_car;
    extern lv_obj_t *ui_cartext;
    extern lv_obj_t *ui_home2;
    void ui_event_jionet(lv_event_t *e);
    extern lv_obj_t *ui_jionet;
    extern lv_obj_t *ui_jionettext;
    void ui_event_qrbarcode(lv_event_t *e);
    extern lv_obj_t *ui_qrbarcode;
    extern lv_obj_t *ui_qrbarcodetext;
    void ui_event_bluetoothcontrl(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothcontrl;
    extern lv_obj_t *ui_bluetoothcontrltext;
    void ui_event_miremote(lv_event_t *e);
    extern lv_obj_t *ui_miremote;
    extern lv_obj_t *ui_miremotetext;
    void ui_event_colorlight(lv_event_t *e);
    extern lv_obj_t *ui_colorlight;
    extern lv_obj_t *ui_colorlighttext;
    void ui_event_nes(lv_event_t *e);
    extern lv_obj_t *ui_nes;
    extern lv_obj_t *ui_nestext;
    extern lv_obj_t *ui_footer;
    void ui_event_phone(lv_event_t *e);
    extern lv_obj_t *ui_phone;
    extern lv_obj_t *ui_phonet;
    void ui_event_email(lv_event_t *e);
    extern lv_obj_t *ui_email;
    extern lv_obj_t *ui_emailt;
    void ui_event_browser(lv_event_t *e);
    extern lv_obj_t *ui_browser;
    extern lv_obj_t *ui_browsert;
    void ui_event_message(lv_event_t *e);
    extern lv_obj_t *ui_message;
    extern lv_obj_t *ui_messages;
    extern lv_obj_t *ui_mobile;
    extern lv_obj_t *ui_wifi;
    extern lv_obj_t *ui_battery;
    extern lv_obj_t *ui_time;
    extern lv_obj_t *ui_batteryp;
    void ui_event_menudown(lv_event_t *e);
    extern lv_obj_t *ui_menudown;
    extern lv_obj_t *ui_menudowntop;
    void ui_event_wifibtn(lv_event_t *e);
    extern lv_obj_t *ui_wifibtn;
    extern lv_obj_t *ui_wifilabel;
    extern lv_obj_t *ui_bluebtn;
    extern lv_obj_t *ui_bluelabel;
    extern lv_obj_t *ui_bellbtn;
    extern lv_obj_t *ui_belllabel;
    void ui_event_lightbtn(lv_event_t *e);
    extern lv_obj_t *ui_lightbtn;
    extern lv_obj_t *ui_lightlabel;
    extern lv_obj_t *ui_menudownlight;
    void ui_event_lightslider(lv_event_t *e);
    extern lv_obj_t *ui_lightslider;
    extern lv_obj_t *ui_lighttext;
    extern lv_obj_t *ui_menudownvolume;
    void ui_event_volumeslider(lv_event_t *e);
    extern lv_obj_t *ui_volumeslider;
    extern lv_obj_t *ui_volumetext;
    extern lv_obj_t *ui_menudownfoot;
    // SCREEN: ui_setting
    void ui_setting_screen_init(void);
    void ui_event_setting(lv_event_t *e);
    extern lv_obj_t *ui_setting;
    extern lv_obj_t *ui_settingheader;
    extern lv_obj_t *ui_settingmobile;
    extern lv_obj_t *ui_settingwifi;
    extern lv_obj_t *ui_settingbattery;
    extern lv_obj_t *ui_settingtime;
    extern lv_obj_t *ui_settingbatteryp;
    extern lv_obj_t *ui_settingtext;
    extern lv_obj_t *ui_setpannel;
    void ui_event_aboutpannel(lv_event_t *e);
    extern lv_obj_t *ui_aboutpannel;
    extern lv_obj_t *ui_aboutlabel;
    extern lv_obj_t *ui_aboutlabel1;
    extern lv_obj_t *ui_aboutlabel2;
    void ui_event_datetimepannel(lv_event_t *e);
    extern lv_obj_t *ui_datetimepannel;
    extern lv_obj_t *ui_datetimelabel;
    extern lv_obj_t *ui_datetimelabel2;
    void ui_event_wifipanel(lv_event_t *e);
    extern lv_obj_t *ui_wifipanel;
    extern lv_obj_t *ui_wifitext;
    extern lv_obj_t *ui_wifionlabel;
    extern lv_obj_t *ui_wifionlabel1;
    void ui_event_wifipanel1(lv_event_t *e);
    extern lv_obj_t *ui_wifipanel1;
    extern lv_obj_t *ui_wifitext1;
    extern lv_obj_t *ui_wifionlabel2;
    extern lv_obj_t *ui_wifionlabel3;
    // SCREEN: ui_wifiset
    void ui_wifiset_screen_init(void);
    void ui_event_wifiset(lv_event_t *e);
    extern lv_obj_t *ui_wifiset;
    extern lv_obj_t *ui_wlanheader;
    extern lv_obj_t *ui_wlanmobile;
    extern lv_obj_t *ui_wlanwifi;
    extern lv_obj_t *ui_wlanbattery;
    extern lv_obj_t *ui_wlantime;
    extern lv_obj_t *ui_wlanbatteryp;
    extern lv_obj_t *ui_wlantitle;
    void ui_event_headerbackico(lv_event_t *e);
    extern lv_obj_t *ui_headerbackico;
    extern lv_obj_t *ui_wlansetpannel;
    extern lv_obj_t *ui_wlanswitchpanel;
    extern lv_obj_t *ui_wlansetlabel;
    void ui_event_wlanswitch(lv_event_t *e);
    extern lv_obj_t *ui_wlanswitch;
    extern lv_obj_t *ui_wificonnect;
    extern lv_obj_t *ui_wifisymbol;
    extern lv_obj_t *ui_wifiname;
    extern lv_obj_t *ui_wifistats;
    extern lv_obj_t *ui_wificlock;
    extern lv_obj_t *ui_wificonright;
    extern lv_obj_t *ui_wifiscan;
    extern lv_obj_t *ui_wifiselecttitle;
    void ui_event_wifirefresh(lv_event_t *e);
    extern lv_obj_t *ui_wifirefresh;
    extern lv_obj_t *ui_wifilistpanel;
    void ui_event_wifilistname(lv_event_t *e);

    extern lv_obj_t *ui_enterwifipass;
    extern lv_obj_t *ui_passpannel;
    extern lv_obj_t *ui_wifinamelabel;
    void ui_event_wifipassinput(lv_event_t *e);
    extern lv_obj_t *ui_wifipassinput;
    void ui_event_connectbtn(lv_event_t *e);
    extern lv_obj_t *ui_connectbtn;
    extern lv_obj_t *ui_connecttext;
    void ui_event_canceltbtn(lv_event_t *e);
    extern lv_obj_t *ui_canceltbtn;
    extern lv_obj_t *ui_canceltext;
    extern lv_obj_t *ui_keypannel;
    extern lv_obj_t *ui_Keyboard;
    // SCREEN: ui_aboutui
    void ui_aboutui_screen_init(void);
    void ui_event_aboutui(lv_event_t *e);
    extern lv_obj_t *ui_aboutui;
    extern lv_obj_t *ui_aboutheader;
    extern lv_obj_t *ui_aboutmobile;
    extern lv_obj_t *ui_aboutwifi;
    extern lv_obj_t *ui_aboutbattery;
    extern lv_obj_t *ui_abouttime;
    extern lv_obj_t *ui_aboutbatteryp;
    extern lv_obj_t *ui_abouttitle;
    extern lv_obj_t *ui_aboutbody;
    extern lv_obj_t *ui_aboutpanelname;
    extern lv_obj_t *ui_aboutnamelabel;
    extern lv_obj_t *ui_aboutnamelabel1;
    extern lv_obj_t *ui_aboutpanelversion;
    extern lv_obj_t *ui_aboutversionlabel;
    extern lv_obj_t *ui_aboutversion1;
    extern lv_obj_t *ui_aboutpanelmodel;
    extern lv_obj_t *ui_aboutmodellabel;
    extern lv_obj_t *ui_aboutmodellabel1;
    extern lv_obj_t *ui_aboutpanelcore;
    extern lv_obj_t *ui_aboutcorelabel;
    extern lv_obj_t *ui_aboutcorelabel1;
    extern lv_obj_t *ui_aboutpanelreversion;
    extern lv_obj_t *ui_aboutreversionlabel;
    extern lv_obj_t *ui_aboutreversionlabel1;
    extern lv_obj_t *ui_aboutpaneflash;
    extern lv_obj_t *ui_aboutflashlabel;
    extern lv_obj_t *ui_aboutflashlabel1;
    extern lv_obj_t *ui_aboutscreenpanel;
    extern lv_obj_t *ui_aboutscreenlabel;
    extern lv_obj_t *ui_aboutscreenlabel1;
    extern lv_obj_t *ui_aboutpanelmac;
    extern lv_obj_t *ui_aboutmaclabel;
    extern lv_obj_t *ui_aboutmaclabel1;
    // SCREEN: ui_datetimeui
    void ui_datetimeui_screen_init(void);
    void ui_event_datetimeui(lv_event_t *e);
    extern lv_obj_t *ui_datetimeui;
    extern lv_obj_t *ui_datetimeheader;
    extern lv_obj_t *ui_datetimemobile;
    extern lv_obj_t *ui_datetimewifi;
    extern lv_obj_t *ui_datetimebattery;
    extern lv_obj_t *ui_datetimetime;
    extern lv_obj_t *ui_datetimebatteryp;
    extern lv_obj_t *ui_datetimetitle;
    extern lv_obj_t *ui_datetimebody;
    extern lv_obj_t *ui_datetimepanel;
    extern lv_obj_t *ui_autodatetimelabel1;
    void ui_event_autodatetimeswitch1(lv_event_t *e);
    extern lv_obj_t *ui_autodatetimeswitch1;
    extern lv_obj_t *ui_datetimepanel1;
    extern lv_obj_t *ui_autodatetimelabel;
    void ui_event_autodatetimeswitch(lv_event_t *e);
    extern lv_obj_t *ui_autodatetimeswitch;
    void ui_event_setdate(lv_event_t *e);
    extern lv_obj_t *ui_setdate;
    extern lv_obj_t *ui_date;
    extern lv_obj_t *ui_dateright;
    void ui_event_settime(lv_event_t *e);
    extern lv_obj_t *ui_settime;
    extern lv_obj_t *ui_time1;
    extern lv_obj_t *ui_timeright;
    extern lv_obj_t *ui_datetimecountry;
    extern lv_obj_t *ui_datetimecountrylabel;
    extern lv_obj_t *ui_datetimelabel1;
    void ui_event_setdateing(lv_event_t *e);
    extern lv_obj_t *ui_setdateing;
    void ui_event_calendar(lv_event_t *e);
    extern lv_obj_t *ui_calendar;
    void ui_event_settimeing(lv_event_t *e);
    extern lv_obj_t *ui_settimeing;
    extern lv_obj_t *ui_settimes;
    extern lv_obj_t *ui_settimelabel;
    extern lv_obj_t *ui_settimetext;
    extern lv_obj_t *ui_settimepanel;
    extern lv_obj_t *ui_sethour;
    extern lv_obj_t *ui_hourtext;
    extern lv_obj_t *ui_setminute;
    extern lv_obj_t *ui_minutetext;
    extern lv_obj_t *ui_settimeokpanel;
    void ui_event_cenceltimebtn(lv_event_t *e);
    extern lv_obj_t *ui_cenceltimebtn;
    extern lv_obj_t *ui_cenceltimetext;
    void ui_event_oktimebtn(lv_event_t *e);
    extern lv_obj_t *ui_oktimebtn;
    extern lv_obj_t *ui_oktimetext;
    // SCREEN: ui_bluetoothset
    void ui_bluetoothset_screen_init(void);
    void ui_event_bluetoothset(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothset;
    extern lv_obj_t *ui_bluetoothheader;
    extern lv_obj_t *ui_bluetoothmobile;
    extern lv_obj_t *ui_bluetoothwifi;
    extern lv_obj_t *ui_bluetoothbattery;
    extern lv_obj_t *ui_bluetoothtime;
    extern lv_obj_t *ui_bluetoothbatteryp;
    extern lv_obj_t *ui_bluetoothtitle;
    void ui_event_bluetoothbackico(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothbackico;
    extern lv_obj_t *ui_bluetoothpannel;
    extern lv_obj_t *ui_bluetoothwitchpanel;
    extern lv_obj_t *ui_bluetoothsetlabel;
    void ui_event_bluetoothswitch(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothswitch;
    extern lv_obj_t *ui_bluetoothconnect;
    extern lv_obj_t *ui_bluetoothsymbol;
    extern lv_obj_t *ui_bluetoothname;
    extern lv_obj_t *ui_bluetoothstats;
    extern lv_obj_t *ui_bluetoothconright;
    extern lv_obj_t *ui_bluetoothscan;
    extern lv_obj_t *ui_bluetoothselecttitle;
    void ui_event_bluetoohtrefresh(lv_event_t *e);
    extern lv_obj_t *ui_bluetoohtrefresh;
    void ui_event_bluetoothlist(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothlist;
    extern lv_obj_t *ui_bluetoothsymbol1;
    void ui_event_bluetoothlistname(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothlistname;
    extern lv_obj_t *ui_bluetoothlistright;
    extern lv_obj_t *ui_blacklistpanel;
    extern lv_obj_t *ui_bluetoothblacklist;
    extern lv_obj_t *ui_blacklistright;
    extern lv_obj_t *ui_enterbluetooth;
    extern lv_obj_t *ui_enterbluetooth1;
    extern lv_obj_t *ui_bluetoothnamelabel;
    void ui_event_blacklist(lv_event_t *e);
    extern lv_obj_t *ui_blacklist;
    extern lv_obj_t *ui_blacklisttext;
    void ui_event_canceltbtn1(lv_event_t *e);
    extern lv_obj_t *ui_canceltbtn1;
    extern lv_obj_t *ui_canceltext1;
    void ui_event_connectbtn1(lv_event_t *e);
    extern lv_obj_t *ui_connectbtn1;
    extern lv_obj_t *ui_connecttext1;
    extern lv_obj_t *ui_keypannel1;
    extern lv_obj_t *ui_Keyboard1;
    // SCREEN: ui_clockscreen
    void ui_clockscreen_screen_init(void);
    void ui_event_clockscreen(lv_event_t *e);
    extern lv_obj_t *ui_clockscreen;
    extern lv_obj_t *ui_clockbg;
    extern lv_obj_t *ui_clockhour;
    extern lv_obj_t *ui_clockmin;
    extern lv_obj_t *ui_clocksec;
    // SCREEN: ui_musicscreen
    void ui_musicscreen_screen_init(void);
    void ui_event_musicscreen(lv_event_t *e);
    extern lv_obj_t *ui_musicscreen;
    extern lv_obj_t *ui_musicheader;
    extern lv_obj_t *ui_musicheadpanel;
    void ui_event_musicback(lv_event_t *e);
    extern lv_obj_t *ui_musicback;
    extern lv_obj_t *ui_musicbacklabel;
    void ui_event_musiclistbtn(lv_event_t *e);
    extern lv_obj_t *ui_musiclistbtn;
    extern lv_obj_t *ui_musiclistlabel;
    extern lv_obj_t *ui_musicbody;
    extern lv_obj_t *ui_musicpicbgpanel;
    void ui_event_musicpicbg(lv_event_t *e);
    extern lv_obj_t *ui_musicpicbg;
    extern lv_obj_t *ui_musicbg;
    extern lv_obj_t *ui_musicname;
    extern lv_obj_t *ui_musicnamelabel;
    extern lv_obj_t *ui_musicart;
    void ui_event_musiclyrics(lv_event_t *e);
    extern lv_obj_t *ui_musiclyrics;
    void ui_event_musiclyricslabel(lv_event_t *e);
    extern lv_obj_t *ui_musiclyricslabel;
    void ui_event_musicbarpanel(lv_event_t *e);
    extern lv_obj_t *ui_musicbarpanel;
    extern lv_obj_t *ui_musictimelabel;
    void ui_event_musicslider(lv_event_t *e);
    extern lv_obj_t *ui_musicslider;
    extern lv_obj_t *ui_musicendtimelabel;
    extern lv_obj_t *ui_musiccontrl;
    void ui_event_musicleft(lv_event_t *e);
    extern lv_obj_t *ui_musicleft;
    extern lv_obj_t *ui_musicleftlabel;
    extern lv_obj_t *ui_musicplay;
    void ui_event_musicplaybtn(lv_event_t *e);
    extern lv_obj_t *ui_musicplaybtn;
    extern lv_obj_t *ui_musicplaylabel;
    void ui_event_musicright(lv_event_t *e);
    extern lv_obj_t *ui_musicright;
    extern lv_obj_t *ui_musicrightlabel;
    void ui_event_musiclistpanel(lv_event_t *e);
    extern lv_obj_t *ui_musiclistpanel;
    extern lv_obj_t *ui_musiclists;
    extern lv_obj_t *ui_musiclist;
    extern lv_obj_t *ui_musiclisttitle;
    extern lv_obj_t *ui_musiclisttitletop;
    void ui_event_musiclistname(lv_event_t *e);
    void ui_weatherscreen_screen_init(void);
    void ui_event_weatherscreen(lv_event_t *e);
    extern lv_obj_t *ui_weatherscreen;
    extern lv_obj_t *ui_weatherbody;
    extern lv_obj_t *ui_weatherheader;
    void ui_event_weatherset(lv_event_t *e);
    extern lv_obj_t *ui_weatherset;
    extern lv_obj_t *ui_weathercity;
    extern lv_obj_t *ui_weatherprovincelabel;
    extern lv_obj_t *ui_weathercitylabel;
    extern lv_obj_t *ui_weathertemperature;
    extern lv_obj_t *ui_weathertemperaturelabel;
    extern lv_obj_t *ui_weatherpanel;
    extern lv_obj_t *ui_weatherlabel1;
    extern lv_obj_t *ui_weatherabel2;
    extern lv_obj_t *ui_weatherabel3;
    extern lv_obj_t *ui_weatherabel4;
    extern lv_obj_t *ui_weatherpanel1;
    extern lv_obj_t *ui_weatherabel5;
    extern lv_obj_t *ui_weatherabel6;
    extern lv_obj_t *ui_weatherfoot;
    extern lv_obj_t *ui_weatherfuture;
    extern lv_obj_t *ui_Label10;
    extern lv_obj_t *ui_Label13;
    extern lv_obj_t *ui_Label14;
    extern lv_obj_t *ui_Label15;
    extern lv_obj_t *ui_weatherfuture1;
    extern lv_obj_t *ui_Label2;
    extern lv_obj_t *ui_Label16;
    extern lv_obj_t *ui_Label17;
    extern lv_obj_t *ui_Label18;
    extern lv_obj_t *ui_weatherfuture2;
    extern lv_obj_t *ui_Label3;
    extern lv_obj_t *ui_Label19;
    extern lv_obj_t *ui_Label20;
    extern lv_obj_t *ui_Label21;
    extern lv_obj_t *ui_weathercitypanel;
    extern lv_obj_t *ui_weathercityarea;
    void ui_event_weatherbutton(lv_event_t *e);
    extern lv_obj_t *ui_weatherbutton;
    extern lv_obj_t *ui_weatherbuttontext;
    extern lv_obj_t *ui_weatherkey;
    extern lv_obj_t *ui_Keyboard2;
    // SCREEN: ui_phonescreen
    void ui_phonescreen_screen_init(void);
    void ui_event_phonescreen(lv_event_t *e);
    extern lv_obj_t *ui_phonescreen;
    // SCREEN: ui_rgbledscreen
    void ui_rgbledscreen_screen_init(void);
    void ui_event_rgbledscreen(lv_event_t *e);
    extern lv_obj_t *ui_rgbledscreen;
    extern lv_obj_t *ui_rgbledheader;
    extern lv_obj_t *ui_rgblabel;
    void ui_event_rgbswitch(lv_event_t *e);
    extern lv_obj_t *ui_rgbswitch;
    extern lv_obj_t *ui_rgbledbody;
    void ui_event_rgbcolorwheel(lv_event_t *e);
    extern lv_obj_t *ui_rgbcolorwheel;
    // SCREEN: ui_nesscreen
    void ui_nesscreen_screen_init(void);
    void ui_event_nesscreen(lv_event_t *e);
    extern lv_obj_t *ui_nesscreen;
    extern lv_obj_t *ui_nesheader;
    extern lv_obj_t *ui_nesheaderleft;

    extern lv_obj_t *ui_nesheaderright;
    extern lv_obj_t *ui_nesbody;
    void ui_event_neslistlabel(lv_event_t *e);
    // SCREEN: ui_nesgamescreen
    void ui_nesgamescreen_screen_init(void);
    void ui_event_nesgamescreen(lv_event_t *e);
    extern lv_timer_t *nes_time;
    extern lv_obj_t *ui_nesgamescreen;
    extern lv_obj_t *ui_nesgamebody;
    extern lv_obj_t *ui_nesgamepanel;
    extern lv_img_dsc_t *nesimg;
    extern lv_obj_t *ui_neskeyup;
    extern lv_obj_t *ui_neskeydown;
    extern lv_obj_t *ui_neskeyleft;
    extern lv_obj_t *ui_neskeyright;
    extern lv_obj_t *ui_neskeystart;
    extern lv_obj_t *ui_neskeyselect;
    extern lv_obj_t *ui_neskeya;
    extern lv_obj_t *ui_neskeyb;
    extern lv_obj_t *ui_neskeyzoomup;
    extern lv_obj_t *ui_neskeyzoomdown;
    extern lv_obj_t *ui_neskeyuplabel;
    extern lv_obj_t *ui_neskeydownlabel;
    extern lv_obj_t *ui_neskeyleftlabel;
    extern lv_obj_t *ui_neskeyrightlabel;
    extern lv_obj_t *ui_neskeystartlabel;
    extern lv_obj_t *ui_neskeyselectlabel;
    extern lv_obj_t *ui_neskeyalabel;
    extern lv_obj_t *ui_neskeyblabel;
    extern lv_obj_t *ui_neskeyzoomuplabel;
    extern lv_obj_t *ui_neskeyzoomdownlabel;
    extern lv_obj_t *ui_neskeyquit;
    extern lv_obj_t *ui_neskeyquitlabel;
    void ui_event_neskey(lv_event_t *e);
    // SCREEN: ui_filemanagerscreen
    void ui_filemanagerscreen_screen_init(void);
    void ui_event_filemanagerscreen(lv_event_t *e);
    extern lv_obj_t *ui_filemanagerscreen;
    extern lv_obj_t *ui_filemanagerheader;
    extern lv_obj_t *ui_filemanagerheaderleft;
    void ui_event_filemanagerheaderright(lv_event_t *e);
    extern lv_obj_t *ui_filemanagerheaderright;
    extern lv_obj_t *ui_filemanagerbody;
    extern lv_obj_t *ui_filelist;
    extern lv_obj_t *ui_filelisticon;
    void ui_event_filelistlabel(lv_event_t *e);
    extern lv_obj_t *ui_filelistlabel;
    extern lv_obj_t *ui_filelistright;
    extern lv_obj_t *ui_filelist2;
    extern lv_obj_t *ui_filelisticon2;
    extern lv_obj_t *ui_filelistlabel2;
    extern lv_obj_t *ui_filelistright2;
    // SCREEN: ui_camerascreen
    void ui_camerascreen_screen_init(void);
    void ui_event_camerascreen(lv_event_t *e);
    extern lv_obj_t *ui_camerascreen;
    // SCREEN: ui_galleryscreen
    void ui_galleryscreen_screen_init(void);
    void ui_event_galleryscreen(lv_event_t *e);
    extern lv_obj_t *ui_galleryscreen;
    extern lv_obj_t *ui_galleryheader;
    extern lv_obj_t *ui_galleryheaderlabel;
    extern lv_obj_t *ui_gallerybody;
    extern lv_obj_t *ui_picpanel;
    void ui_event_pic(lv_event_t *e);
    extern lv_obj_t *ui_pic;
    extern lv_obj_t *ui_picpanel1;
    void ui_event_pic1(lv_event_t *e);
    extern lv_obj_t *ui_pic1;
    extern lv_obj_t *ui_picpanel2;
    void ui_event_pic2(lv_event_t *e);
    extern lv_obj_t *ui_pic2;
    extern lv_obj_t *ui_picpanel3;
    void ui_event_pic3(lv_event_t *e);
    extern lv_obj_t *ui_pic3;
    extern lv_obj_t *ui_picpanel4;
    void ui_event_pic4(lv_event_t *e);
    extern lv_obj_t *ui_pic4;
    // SCREEN: ui_notesscreen
    void ui_notesscreen_screen_init(void);
    void ui_event_notesscreen(lv_event_t *e);
    extern lv_obj_t *ui_notesscreen;
    // SCREEN: ui_contactsscreen
    void ui_contactsscreen_screen_init(void);
    void ui_event_contactsscreen(lv_event_t *e);
    extern lv_obj_t *ui_contactsscreen;
    // SCREEN: ui_caculatorscreen
    void ui_caculatorscreen_screen_init(void);
    void ui_event_caculatorscreen(lv_event_t *e);
    extern lv_obj_t *ui_caculatorscreen;
    // SCREEN: ui_videoscreen
    void ui_videoscreen_screen_init(void);
    void ui_event_videoscreen(lv_event_t *e);
    extern lv_obj_t *ui_videoscreen;
    // SCREEN: ui_carscreen
    void ui_carscreen_screen_init(void);
    void ui_event_carscreen(lv_event_t *e);
    extern lv_obj_t *ui_carscreen;
    // SCREEN: ui_jionetscreen
    void ui_jionetscreen_screen_init(void);
    void ui_event_jionetscreen(lv_event_t *e);
    extern lv_obj_t *ui_jionetscreen;
    // SCREEN: ui_qrbarcodescreen
    void ui_qrbarcodescreen_screen_init(void);
    void ui_event_qrbarcodescreen(lv_event_t *e);
    extern lv_obj_t *ui_qrbarcodescreen;
    // SCREEN: ui_bluetoothcontrlscreen
    void ui_bluetoothcontrlscreen_screen_init(void);
    void ui_event_bluetoothcontrlscreen(lv_event_t *e);
    extern lv_obj_t *ui_bluetoothcontrlscreen;
    // SCREEN: ui_miremotescreen
    void ui_miremotescreen_screen_init(void);
    void ui_event_miremotescreen(lv_event_t *e);
    extern lv_obj_t *ui_miremotescreen;
    // SCREEN: ui_emailscreen
    void ui_emailscreen_screen_init(void);
    void ui_event_emailscreen(lv_event_t *e);
    extern lv_obj_t *ui_emailscreen;
    // SCREEN: ui_browserscreen
    void ui_browserscreen_screen_init(void);
    void ui_event_browserscreen(lv_event_t *e);
    extern lv_obj_t *ui_browserscreen;
    // SCREEN: ui_messagescreen
    void ui_messagescreen_screen_init(void);
    void ui_event_messagescreen(lv_event_t *e);
    extern lv_obj_t *ui_messagescreen;
    extern lv_obj_t *ui____initial_actions0;

    LV_IMG_DECLARE(ui_img_bg_png);              // assets/bg.png
    LV_IMG_DECLARE(ui_img_camera_png);          // assets/camera.png
    LV_IMG_DECLARE(ui_img_clock_png);           // assets/clock.png
    LV_IMG_DECLARE(ui_img_gallery_png);         // assets/gallery.png
    LV_IMG_DECLARE(ui_img_music_png);           // assets/music.png
    LV_IMG_DECLARE(ui_img_settings_png);        // assets/settings.png
    LV_IMG_DECLARE(ui_img_notes_png);           // assets/notes.png
    LV_IMG_DECLARE(ui_img_weather_png);         // assets/weather.png
    LV_IMG_DECLARE(ui_img_contacts_png);        // assets/contacts.png
    LV_IMG_DECLARE(ui_img_calculator_png);      // assets/calculator.png
    LV_IMG_DECLARE(ui_img_filemanager_png);     // assets/filemanager.png
    LV_IMG_DECLARE(ui_img_videos_png);          // assets/videos.png
    LV_IMG_DECLARE(ui_img_car_png);             // assets/car.png
    LV_IMG_DECLARE(ui_img_jionet_png);          // assets/jionet.png
    LV_IMG_DECLARE(ui_img_qrbarcode_png);       // assets/qrbarcode.png
    LV_IMG_DECLARE(ui_img_bluetoothcontrl_png); // assets/bluetoothcontrl.png
    LV_IMG_DECLARE(ui_img_mi_remote_png);       // assets/mi_remote.png
    LV_IMG_DECLARE(ui_img_tips_png);            // assets/tips.png
    LV_IMG_DECLARE(ui_img_nes_png);             // assets/nes.png
    LV_IMG_DECLARE(ui_img_phone_png);           // assets/phone.png
    LV_IMG_DECLARE(ui_img_email_png);           // assets/email.png
    LV_IMG_DECLARE(ui_img_browser_png);         // assets/browser.png
    LV_IMG_DECLARE(ui_img_messaging_png);       // assets/messaging.png
    LV_IMG_DECLARE(ui_img_refresh_png);         // assets/refresh.png
    LV_IMG_DECLARE(ui_img_bigclock_png);        // assets/bigclock.png
    LV_IMG_DECLARE(ui_img_clockhour_png);       // assets/clockhour.png
    LV_IMG_DECLARE(ui_img_clockminute_png);     // assets/clockminute.png
    LV_IMG_DECLARE(ui_img_clocksecond_png);     // assets/clocksecond.png
    LV_IMG_DECLARE(ui_img_musicbg_png);         // assets/musicbg.png
    LV_IMG_DECLARE(ui_img_weatherbg_png);       // assets/weatherbg.png
    LV_IMG_DECLARE(ui_img_qq_png);              // assets/qq.png

    // LV_FONT_DECLARE(ui_font_misans16);
    LV_FONT_DECLARE(ui_font_misans96);
    // LV_FONT_DECLARE(ui_font_misansbold20);
    // LV_FONT_DECLARE(ui_font_symbols16);

    void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
