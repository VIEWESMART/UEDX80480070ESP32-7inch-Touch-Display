#include "ui.h"
#include "ui_helpers.h"
#include <time.h>
#include <sys/time.h>
#include "sdcard.h"
#include "mp3.h"
///////////////////// VARIABLES ////////////////////
void moveleft_Animation(lv_obj_t *TargetObject, int delay);
void moveright_Animation(lv_obj_t *TargetObject, int delay);
void moveup_Animation(lv_obj_t *TargetObject, int delay);
void movedown_Animation(lv_obj_t *TargetObject, int delay);
void turn_Animation(lv_obj_t *TargetObject, int delay);
void turnoff_Animation(lv_obj_t *TargetObject, int delay);
void turnone_Animation(lv_obj_t *TargetObject, int delay);

// SCREEN: ui_home
void ui_home_screen_init(void);
lv_obj_t *ui_home;
void ui_event_header(lv_event_t *e);
lv_obj_t *ui_header;
lv_obj_t *ui_body;
lv_obj_t *ui_home1;
void ui_event_camera(lv_event_t *e);
lv_obj_t *ui_camera;
lv_obj_t *ui_cameratext;
void ui_event_clock(lv_event_t *e);
lv_obj_t *ui_clock;
lv_obj_t *ui_clocktext;
void ui_event_gallery(lv_event_t *e);
lv_obj_t *ui_gallery;
lv_obj_t *ui_gallerytext;
void ui_event_music(lv_event_t *e);
lv_obj_t *ui_music;
lv_obj_t *ui_musictext;
void ui_event_settings(lv_event_t *e);
lv_obj_t *ui_settings;
lv_obj_t *ui_settingstext;
void ui_event_notes(lv_event_t *e);
lv_obj_t *ui_notes;
lv_obj_t *ui_notestext;
void ui_event_weather(lv_event_t *e);
lv_obj_t *ui_weather;
lv_obj_t *ui_weathertext;
void ui_event_contacts(lv_event_t *e);
lv_obj_t *ui_contacts;
lv_obj_t *ui_contactstext;
void ui_event_caculator(lv_event_t *e);
lv_obj_t *ui_caculator;
lv_obj_t *ui_caculatortext;
void ui_event_filemanager(lv_event_t *e);
lv_obj_t *ui_filemanager;
lv_obj_t *ui_filemanagertext;
void ui_event_video(lv_event_t *e);
lv_obj_t *ui_video;
lv_obj_t *ui_videotext;
void ui_event_car(lv_event_t *e);
lv_obj_t *ui_car;
lv_obj_t *ui_cartext;
lv_obj_t *ui_home2;
void ui_event_jionet(lv_event_t *e);
lv_obj_t *ui_jionet;
lv_obj_t *ui_jionettext;
void ui_event_qrbarcode(lv_event_t *e);
lv_obj_t *ui_qrbarcode;
lv_obj_t *ui_qrbarcodetext;
void ui_event_bluetoothcontrl(lv_event_t *e);
lv_obj_t *ui_bluetoothcontrl;
lv_obj_t *ui_bluetoothcontrltext;
void ui_event_miremote(lv_event_t *e);
lv_obj_t *ui_miremote;
lv_obj_t *ui_miremotetext;
void ui_event_colorlight(lv_event_t *e);
lv_obj_t *ui_colorlight;
lv_obj_t *ui_colorlighttext;
void ui_event_nes(lv_event_t *e);
lv_obj_t *ui_nes;
lv_obj_t *ui_nestext;
lv_obj_t *ui_footer;
void ui_event_phone(lv_event_t *e);
lv_obj_t *ui_phone;
lv_obj_t *ui_phonet;
void ui_event_email(lv_event_t *e);
lv_obj_t *ui_email;
lv_obj_t *ui_emailt;
void ui_event_browser(lv_event_t *e);
lv_obj_t *ui_browser;
lv_obj_t *ui_browsert;
void ui_event_message(lv_event_t *e);
lv_obj_t *ui_message;
lv_obj_t *ui_messages;
lv_obj_t *ui_mobile;
lv_obj_t *ui_wifi;
lv_obj_t *ui_battery;
lv_obj_t *ui_time;
lv_obj_t *ui_batteryp;
void ui_event_menudown(lv_event_t *e);
lv_obj_t *ui_menudown;
lv_obj_t *ui_menudowntop;
void ui_event_wifibtn(lv_event_t *e);
lv_obj_t *ui_wifibtn;
lv_obj_t *ui_wifilabel;
lv_obj_t *ui_bluebtn;
lv_obj_t *ui_bluelabel;
lv_obj_t *ui_bellbtn;
lv_obj_t *ui_belllabel;
void ui_event_lightbtn(lv_event_t *e);
lv_obj_t *ui_lightbtn;
lv_obj_t *ui_lightlabel;
lv_obj_t *ui_menudownlight;
void ui_event_lightslider(lv_event_t *e);
lv_obj_t *ui_lightslider;
lv_obj_t *ui_lighttext;
lv_obj_t *ui_menudownvolume;
void ui_event_volumeslider(lv_event_t *e);
lv_obj_t *ui_volumeslider;
lv_obj_t *ui_volumetext;
lv_obj_t *ui_menudownfoot;

// SCREEN: ui_setting
void ui_setting_screen_init(void);
void ui_event_setting(lv_event_t *e);
lv_obj_t *ui_setting;
lv_obj_t *ui_settingheader;
lv_obj_t *ui_settingmobile;
lv_obj_t *ui_settingwifi;
lv_obj_t *ui_settingbattery;
lv_obj_t *ui_settingtime;
lv_obj_t *ui_settingbatteryp;
lv_obj_t *ui_settingtext;
lv_obj_t *ui_setpannel;
void ui_event_aboutpannel(lv_event_t *e);
lv_obj_t *ui_aboutpannel;
lv_obj_t *ui_aboutlabel;
lv_obj_t *ui_aboutlabel1;
lv_obj_t *ui_aboutlabel2;
void ui_event_datetimepannel(lv_event_t *e);
lv_obj_t *ui_datetimepannel;
lv_obj_t *ui_datetimelabel;
lv_obj_t *ui_datetimelabel2;
void ui_event_wifipanel(lv_event_t *e);
lv_obj_t *ui_wifipanel;
lv_obj_t *ui_wifitext;
lv_obj_t *ui_wifionlabel;
lv_obj_t *ui_wifionlabel1;
void ui_event_wifipanel1(lv_event_t *e);
lv_obj_t *ui_wifipanel1;
lv_obj_t *ui_wifitext1;
lv_obj_t *ui_wifionlabel2;
lv_obj_t *ui_wifionlabel3;

// SCREEN: ui_wifiset
void ui_wifiset_screen_init(void);
void ui_event_wifiset(lv_event_t *e);
lv_obj_t *ui_wifiset;
lv_obj_t *ui_wlanheader;
lv_obj_t *ui_wlanmobile;
lv_obj_t *ui_wlanwifi;
lv_obj_t *ui_wlanbattery;
lv_obj_t *ui_wlantime;
lv_obj_t *ui_wlanbatteryp;
lv_obj_t *ui_wlantitle;
void ui_event_headerbackico(lv_event_t *e);
lv_obj_t *ui_headerbackico;
lv_obj_t *ui_wlansetpannel;
lv_obj_t *ui_wlanswitchpanel;
lv_obj_t *ui_wlansetlabel;
void ui_event_wlanswitch(lv_event_t *e);
lv_obj_t *ui_wlanswitch;
lv_obj_t *ui_wificonnect;
lv_obj_t *ui_wifisymbol;
lv_obj_t *ui_wifiname;
lv_obj_t *ui_wifistats;
lv_obj_t *ui_wificlock;
lv_obj_t *ui_wificonright;
lv_obj_t *ui_wifiscan;
lv_obj_t *ui_wifiselecttitle;
void ui_event_wifirefresh(lv_event_t *e);
lv_obj_t *ui_wifirefresh;
lv_obj_t *ui_wifilistpanel;
// lv_obj_t * ui_wifilist;
// lv_obj_t * ui_wifisymbol1;
void ui_event_wifilistname(lv_event_t *e);
// lv_obj_t * ui_wifilistname;
// lv_obj_t * ui_wifilock;
// lv_obj_t * ui_wifilistright;
lv_obj_t *ui_enterwifipass;
lv_obj_t *ui_passpannel;
lv_obj_t *ui_wifinamelabel;
void ui_event_wifipassinput(lv_event_t *e);
lv_obj_t *ui_wifipassinput;
void ui_event_connectbtn(lv_event_t *e);
lv_obj_t *ui_connectbtn;
lv_obj_t *ui_connecttext;
void ui_event_canceltbtn(lv_event_t *e);
lv_obj_t *ui_canceltbtn;
lv_obj_t *ui_canceltext;
lv_obj_t *ui_keypannel;
lv_obj_t *ui_Keyboard;

// SCREEN: ui_aboutui
void ui_aboutui_screen_init(void);
void ui_event_aboutui(lv_event_t *e);
lv_obj_t *ui_aboutui;
lv_obj_t *ui_aboutheader;
lv_obj_t *ui_aboutmobile;
lv_obj_t *ui_aboutwifi;
lv_obj_t *ui_aboutbattery;
lv_obj_t *ui_abouttime;
lv_obj_t *ui_aboutbatteryp;
lv_obj_t *ui_abouttitle;
lv_obj_t *ui_aboutbody;
lv_obj_t *ui_aboutpanelname;
lv_obj_t *ui_aboutnamelabel;
lv_obj_t *ui_aboutnamelabel1;
lv_obj_t *ui_aboutpanelversion;
lv_obj_t *ui_aboutversionlabel;
lv_obj_t *ui_aboutversion1;
lv_obj_t *ui_aboutpanelmodel;
lv_obj_t *ui_aboutmodellabel;
lv_obj_t *ui_aboutmodellabel1;
lv_obj_t *ui_aboutpanelcore;
lv_obj_t *ui_aboutcorelabel;
lv_obj_t *ui_aboutcorelabel1;
lv_obj_t *ui_aboutpanelreversion;
lv_obj_t *ui_aboutreversionlabel;
lv_obj_t *ui_aboutreversionlabel1;
lv_obj_t *ui_aboutpaneflash;
lv_obj_t *ui_aboutflashlabel;
lv_obj_t *ui_aboutflashlabel1;
lv_obj_t *ui_aboutscreenpanel;
lv_obj_t *ui_aboutscreenlabel;
lv_obj_t *ui_aboutscreenlabel1;
lv_obj_t *ui_aboutpanelmac;
lv_obj_t *ui_aboutmaclabel;
lv_obj_t *ui_aboutmaclabel1;

// SCREEN: ui_datetimeui
void ui_datetimeui_screen_init(void);
void ui_event_datetimeui(lv_event_t *e);
lv_obj_t *ui_datetimeui;
lv_obj_t *ui_datetimeheader;
lv_obj_t *ui_datetimemobile;
lv_obj_t *ui_datetimewifi;
lv_obj_t *ui_datetimebattery;
lv_obj_t *ui_datetimetime;
lv_obj_t *ui_datetimebatteryp;
lv_obj_t *ui_datetimetitle;
lv_obj_t *ui_datetimebody;
lv_obj_t *ui_datetimepanel;
lv_obj_t *ui_autodatetimelabel1;
void ui_event_autodatetimeswitch1(lv_event_t *e);
lv_obj_t *ui_autodatetimeswitch1;
lv_obj_t *ui_datetimepanel1;
lv_obj_t *ui_autodatetimelabel;
void ui_event_autodatetimeswitch(lv_event_t *e);
lv_obj_t *ui_autodatetimeswitch;
void ui_event_setdate(lv_event_t *e);
lv_obj_t *ui_setdate;
lv_obj_t *ui_date;
lv_obj_t *ui_dateright;
void ui_event_settime(lv_event_t *e);
lv_obj_t *ui_settime;
lv_obj_t *ui_time1;
lv_obj_t *ui_timeright;
lv_obj_t *ui_datetimecountry;
lv_obj_t *ui_datetimecountrylabel;
lv_obj_t *ui_datetimelabel1;
void ui_event_setdateing(lv_event_t *e);
lv_obj_t *ui_setdateing;
void ui_event_calendar(lv_event_t *e);
lv_obj_t *ui_calendar;
void ui_event_settimeing(lv_event_t *e);
lv_obj_t *ui_settimeing;
lv_obj_t *ui_settimes;
lv_obj_t *ui_settimelabel;
lv_obj_t *ui_settimetext;
lv_obj_t *ui_settimepanel;
lv_obj_t *ui_sethour;
lv_obj_t *ui_hourtext;
lv_obj_t *ui_setminute;
lv_obj_t *ui_minutetext;
lv_obj_t *ui_settimeokpanel;
void ui_event_cenceltimebtn(lv_event_t *e);
lv_obj_t *ui_cenceltimebtn;
lv_obj_t *ui_cenceltimetext;
void ui_event_oktimebtn(lv_event_t *e);
lv_obj_t *ui_oktimebtn;
lv_obj_t *ui_oktimetext;

// SCREEN: ui_bluetoothset
void ui_bluetoothset_screen_init(void);
void ui_event_bluetoothset(lv_event_t *e);
lv_obj_t *ui_bluetoothset;
lv_obj_t *ui_bluetoothheader;
lv_obj_t *ui_bluetoothmobile;
lv_obj_t *ui_bluetoothwifi;
lv_obj_t *ui_bluetoothbattery;
lv_obj_t *ui_bluetoothtime;
lv_obj_t *ui_bluetoothbatteryp;
lv_obj_t *ui_bluetoothtitle;
void ui_event_bluetoothbackico(lv_event_t *e);
lv_obj_t *ui_bluetoothbackico;
lv_obj_t *ui_bluetoothpannel;
lv_obj_t *ui_bluetoothwitchpanel;
lv_obj_t *ui_bluetoothsetlabel;
void ui_event_bluetoothswitch(lv_event_t *e);
lv_obj_t *ui_bluetoothswitch;
lv_obj_t *ui_bluetoothconnect;
lv_obj_t *ui_bluetoothsymbol;
lv_obj_t *ui_bluetoothname;
lv_obj_t *ui_bluetoothstats;
lv_obj_t *ui_bluetoothconright;
lv_obj_t *ui_bluetoothscan;
lv_obj_t *ui_bluetoothselecttitle;
void ui_event_bluetoohtrefresh(lv_event_t *e);
lv_obj_t *ui_bluetoohtrefresh;
void ui_event_bluetoothlist(lv_event_t *e);
lv_obj_t *ui_bluetoothlist;
lv_obj_t *ui_bluetoothsymbol1;
void ui_event_bluetoothlistname(lv_event_t *e);
lv_obj_t *ui_bluetoothlistname;
lv_obj_t *ui_bluetoothlistright;
lv_obj_t *ui_blacklistpanel;
lv_obj_t *ui_bluetoothblacklist;
lv_obj_t *ui_blacklistright;
lv_obj_t *ui_enterbluetooth;
lv_obj_t *ui_enterbluetooth1;
lv_obj_t *ui_bluetoothnamelabel;
void ui_event_blacklist(lv_event_t *e);
lv_obj_t *ui_blacklist;
lv_obj_t *ui_blacklisttext;
void ui_event_canceltbtn1(lv_event_t *e);
lv_obj_t *ui_canceltbtn1;
lv_obj_t *ui_canceltext1;
void ui_event_connectbtn1(lv_event_t *e);
lv_obj_t *ui_connectbtn1;
lv_obj_t *ui_connecttext1;
lv_obj_t *ui_keypannel1;
lv_obj_t *ui_Keyboard1;

// SCREEN: ui_clockscreen
void ui_clockscreen_screen_init(void);
void ui_event_clockscreen(lv_event_t *e);
lv_obj_t *ui_clockscreen;
lv_obj_t *meter;
lv_obj_t *ui_clockbg;
lv_obj_t *ui_clockhour;
lv_obj_t *ui_clockmin;
lv_obj_t *ui_clocksec;

// SCREEN: ui_musicscreen
void ui_musicscreen_screen_init(void);
void ui_event_musicscreen(lv_event_t *e);
lv_obj_t *ui_musicscreen;
lv_obj_t *ui_musicheader;
lv_obj_t *ui_musicheadpanel;
void ui_event_musicback(lv_event_t *e);
lv_obj_t *ui_musicback;
lv_obj_t *ui_musicbacklabel;
void ui_event_musiclistbtn(lv_event_t *e);
lv_obj_t *ui_musiclistbtn;
lv_obj_t *ui_musiclistlabel;
lv_obj_t *ui_musicbody;
lv_obj_t *ui_musicpicbgpanel;
void ui_event_musicpicbg(lv_event_t *e);
lv_obj_t *ui_musicpicbg;
lv_obj_t *ui_musicbg;
lv_obj_t *ui_musicname;
lv_obj_t *ui_musicnamelabel;
lv_obj_t *ui_musicart;
void ui_event_musiclyrics(lv_event_t *e);
lv_obj_t *ui_musiclyrics;
void ui_event_musiclyricslabel(lv_event_t *e);
lv_obj_t *ui_musiclyricslabel;
void ui_event_musicbarpanel(lv_event_t *e);
lv_obj_t *ui_musicbarpanel;
lv_obj_t *ui_musictimelabel;
void ui_event_musicslider(lv_event_t *e);
lv_obj_t *ui_musicslider;
lv_obj_t *ui_musicendtimelabel;
lv_obj_t *ui_musiccontrl;
void ui_event_musicleft(lv_event_t *e);
lv_obj_t *ui_musicleft;
lv_obj_t *ui_musicleftlabel;
lv_obj_t *ui_musicplay;
void ui_event_musicplaybtn(lv_event_t *e);
lv_obj_t *ui_musicplaybtn;
lv_obj_t *ui_musicplaylabel;
void ui_event_musicright(lv_event_t *e);
lv_obj_t *ui_musicright;
lv_obj_t *ui_musicrightlabel;
void ui_event_musiclistpanel(lv_event_t *e);
lv_obj_t *ui_musiclistpanel;
lv_obj_t *ui_musiclists;
lv_obj_t *ui_musiclist;
lv_obj_t *ui_musiclisttitle;
lv_obj_t *ui_musiclisttitletop;
void ui_event_musiclistname(lv_event_t *e);
// lv_obj_t * ui_musiclistname;
// lv_obj_t * ui_musicnames;
// void ui_event_musiclistname1(lv_event_t * e);
// lv_obj_t * ui_musiclistname1;
// lv_obj_t * ui_musicnames1;

// SCREEN: ui_weatherscreen
void ui_weatherscreen_screen_init(void);
void ui_event_weatherscreen(lv_event_t *e);
lv_obj_t *ui_weatherscreen;
lv_obj_t *ui_weatherbody;
lv_obj_t *ui_weatherheader;
void ui_event_weatherset(lv_event_t *e);
lv_obj_t *ui_weatherset;
lv_obj_t *ui_weathercity;
lv_obj_t *ui_weatherprovincelabel;
lv_obj_t *ui_weathercitylabel;
lv_obj_t *ui_weathertemperature;
lv_obj_t *ui_weathertemperaturelabel;
lv_obj_t *ui_weatherpanel;
lv_obj_t *ui_weatherlabel1;
lv_obj_t *ui_weatherabel2;
lv_obj_t *ui_weatherabel3;
lv_obj_t *ui_weatherabel4;
lv_obj_t *ui_weatherpanel1;
lv_obj_t *ui_weatherabel5;
lv_obj_t *ui_weatherabel6;
lv_obj_t *ui_weatherfoot;
lv_obj_t *ui_weatherfuture;
lv_obj_t *ui_Label10;
lv_obj_t *ui_Label13;
lv_obj_t *ui_Label14;
lv_obj_t *ui_Label15;
lv_obj_t *ui_weatherfuture1;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Label16;
lv_obj_t *ui_Label17;
lv_obj_t *ui_Label18;
lv_obj_t *ui_weatherfuture2;
lv_obj_t *ui_Label3;
lv_obj_t *ui_Label19;
lv_obj_t *ui_Label20;
lv_obj_t *ui_Label21;
lv_obj_t *ui_weathercitypanel;
lv_obj_t *ui_weathercityarea;
void ui_event_weatherbutton(lv_event_t *e);
lv_obj_t *ui_weatherbutton;
lv_obj_t *ui_weatherbuttontext;
lv_obj_t *ui_weatherkey;
lv_obj_t *ui_Keyboard2;

// SCREEN: ui_phonescreen
void ui_phonescreen_screen_init(void);
void ui_event_phonescreen(lv_event_t *e);
lv_obj_t *ui_phonescreen;

// SCREEN: ui_rgbledscreen
void ui_rgbledscreen_screen_init(void);
void ui_event_rgbledscreen(lv_event_t *e);
lv_obj_t *ui_rgbledscreen;
lv_obj_t *ui_rgbledheader;
lv_obj_t *ui_rgblabel;
void ui_event_rgbswitch(lv_event_t *e);
lv_obj_t *ui_rgbswitch;
lv_obj_t *ui_rgbledbody;
lv_obj_t *ui_rgbcolorwheel;

// SCREEN: ui_nesscreen
void ui_nesscreen_screen_init(void);
void ui_event_nesscreen(lv_event_t *e);
lv_timer_t *nes_time;
lv_obj_t *ui_nesscreen;
lv_obj_t *ui_nesheader;
lv_obj_t *ui_nesheaderleft;
lv_obj_t *ui_nesheaderright;
lv_obj_t *ui_nesbody;
void ui_event_neslistlabel(lv_event_t *e);
// SCREEN: ui_nesgamescreen
void ui_nesgamescreen_screen_init(void);
void ui_event_nesgamescreen(lv_event_t *e);
lv_obj_t *ui_nesgamescreen;
lv_obj_t *ui_nesgamebody;
lv_obj_t *ui_nesgamepanel;
lv_img_dsc_t *nesimg;
lv_obj_t *ui_neskeyup;
lv_obj_t *ui_neskeydown;
lv_obj_t *ui_neskeyleft;
lv_obj_t *ui_neskeyright;
lv_obj_t *ui_neskeystart;
lv_obj_t *ui_neskeyselect;
lv_obj_t *ui_neskeya;
lv_obj_t *ui_neskeyb;
lv_obj_t *ui_neskeyzoomup;
lv_obj_t *ui_neskeyzoomdown;
lv_obj_t *ui_neskeyuplabel;
lv_obj_t *ui_neskeydownlabel;
lv_obj_t *ui_neskeyleftlabel;
lv_obj_t *ui_neskeyrightlabel;
lv_obj_t *ui_neskeystartlabel;
lv_obj_t *ui_neskeyselectlabel;
lv_obj_t *ui_neskeyalabel;
lv_obj_t *ui_neskeyblabel;
lv_obj_t *ui_neskeyzoomuplabel;
lv_obj_t *ui_neskeyzoomdownlabel;
lv_obj_t *ui_neskeyquit;
lv_obj_t *ui_neskeyquitlabel;
void ui_event_neskey(lv_event_t *e);
// SCREEN: ui_filemanagerscreen
void ui_filemanagerscreen_screen_init(void);
void ui_event_filemanagerscreen(lv_event_t *e);
lv_obj_t *ui_filemanagerscreen;
lv_obj_t *ui_filemanagerheader;
lv_obj_t *ui_filemanagerheaderleft;
void ui_event_filemanagerheaderright(lv_event_t *e);
lv_obj_t *ui_filemanagerheaderright;
lv_obj_t *ui_filemanagerbody;
lv_obj_t *ui_filelist;
lv_obj_t *ui_filelisticon;
void ui_event_filelistlabel(lv_event_t *e);
lv_obj_t *ui_filelistlabel;
lv_obj_t *ui_filelistright;
lv_obj_t *ui_filelist2;
lv_obj_t *ui_filelisticon2;
lv_obj_t *ui_filelistlabel2;
lv_obj_t *ui_filelistright2;

// SCREEN: ui_camerascreen
void ui_camerascreen_screen_init(void);
void ui_event_camerascreen(lv_event_t *e);
lv_obj_t *ui_camerascreen;

// SCREEN: ui_galleryscreen
void ui_galleryscreen_screen_init(void);
void ui_event_galleryscreen(lv_event_t *e);
lv_obj_t *ui_galleryscreen;
lv_obj_t *ui_galleryheader;
lv_obj_t *ui_galleryheaderlabel;
lv_obj_t *ui_gallerybody;
lv_obj_t *ui_picpanel;
void ui_event_pic(lv_event_t *e);
lv_obj_t *ui_pic;
lv_obj_t *ui_picpanel1;
void ui_event_pic1(lv_event_t *e);
lv_obj_t *ui_pic1;
lv_obj_t *ui_picpanel2;
void ui_event_pic2(lv_event_t *e);
lv_obj_t *ui_pic2;
lv_obj_t *ui_picpanel3;
void ui_event_pic3(lv_event_t *e);
lv_obj_t *ui_pic3;
lv_obj_t *ui_picpanel4;
void ui_event_pic4(lv_event_t *e);
lv_obj_t *ui_pic4;

// SCREEN: ui_notesscreen
void ui_notesscreen_screen_init(void);
void ui_event_notesscreen(lv_event_t *e);
lv_obj_t *ui_notesscreen;

// SCREEN: ui_contactsscreen
void ui_contactsscreen_screen_init(void);
void ui_event_contactsscreen(lv_event_t *e);
lv_obj_t *ui_contactsscreen;

// SCREEN: ui_caculatorscreen
void ui_caculatorscreen_screen_init(void);
void ui_event_caculatorscreen(lv_event_t *e);
lv_obj_t *ui_caculatorscreen;

// SCREEN: ui_videoscreen
void ui_videoscreen_screen_init(void);
void ui_event_videoscreen(lv_event_t *e);
lv_obj_t *ui_videoscreen;

// SCREEN: ui_carscreen
void ui_carscreen_screen_init(void);
void ui_event_carscreen(lv_event_t *e);
lv_obj_t *ui_carscreen;

// SCREEN: ui_jionetscreen
void ui_jionetscreen_screen_init(void);
void ui_event_jionetscreen(lv_event_t *e);
lv_obj_t *ui_jionetscreen;

// SCREEN: ui_qrbarcodescreen
void ui_qrbarcodescreen_screen_init(void);
void ui_event_qrbarcodescreen(lv_event_t *e);
lv_obj_t *ui_qrbarcodescreen;

// SCREEN: ui_bluetoothcontrlscreen
void ui_bluetoothcontrlscreen_screen_init(void);
void ui_event_bluetoothcontrlscreen(lv_event_t *e);
lv_obj_t *ui_bluetoothcontrlscreen;

// SCREEN: ui_miremotescreen
void ui_miremotescreen_screen_init(void);
void ui_event_miremotescreen(lv_event_t *e);
lv_obj_t *ui_miremotescreen;

// SCREEN: ui_emailscreen
void ui_emailscreen_screen_init(void);
void ui_event_emailscreen(lv_event_t *e);
lv_obj_t *ui_emailscreen;

// SCREEN: ui_browserscreen
void ui_browserscreen_screen_init(void);
void ui_event_browserscreen(lv_event_t *e);
lv_obj_t *ui_browserscreen;

// SCREEN: ui_messagescreen
void ui_messagescreen_screen_init(void);
void ui_event_messagescreen(lv_event_t *e);
lv_obj_t *ui_messagescreen;
lv_obj_t *ui____initial_actions0;

///////////////////// ANIMATIONS ////////////////////
void moveleft_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -320);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);
}
void moveright_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, 320);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);
}
void moveup_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -480);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
}
void movedown_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 480);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
}
void turn_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 10000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE); // LV_ANIM_REPEAT_INFINITE无限循环，默认0。
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);
}
void turnoff_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 0);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);
}
void turnone_Animation(lv_obj_t *TargetObject, int delay)
{
    ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 4);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);
}

///////////////////// FUNCTIONS ////////////////////
void ui_event_header(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM)
    {
        lv_indev_wait_release(lv_indev_get_act());
        movedown_Animation(ui_menudown, 0);
    }
}
void ui_event_camera(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_camerascreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_camerascreen_screen_init);
    }
}
void ui_event_clock(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_clockscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_clockscreen_screen_init);
        lv_obj_invalidate(ui_clockscreen);
    }
}
void ui_event_gallery(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_galleryscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_galleryscreen_screen_init);
    }
}
void ui_event_music(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_musicscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_musicscreen_screen_init);
    }
}
void ui_event_settings(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_setting_screen_init);
    }
}
void ui_event_notes(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_notesscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_notesscreen_screen_init);
    }
}
void ui_event_weather(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_weatherscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_weatherscreen_screen_init);
    }
}
void ui_event_contacts(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_contactsscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_contactsscreen_screen_init);
    }
}
void ui_event_caculator(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_caculatorscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_caculatorscreen_screen_init);
    }
}
void ui_event_filemanager(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_filemanagerscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_filemanagerscreen_screen_init);
    }
}
void ui_event_video(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_videoscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_videoscreen_screen_init);
    }
}
void ui_event_car(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_carscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_carscreen_screen_init);
    }
}
void ui_event_jionet(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_jionetscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_jionetscreen_screen_init);
    }
}
void ui_event_qrbarcode(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_qrbarcodescreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_qrbarcodescreen_screen_init);
    }
}
void ui_event_bluetoothcontrl(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_bluetoothcontrlscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_bluetoothcontrlscreen_screen_init);
    }
}
void ui_event_miremote(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_miremotescreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_miremotescreen_screen_init);
    }
}
void ui_event_colorlight(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_rgbledscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_rgbledscreen_screen_init);
    }
}
void ui_event_nes(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_nesscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_nesscreen_screen_init);
    }
}
void ui_event_phone(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_phonescreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_phonescreen_screen_init);
    }
}
void ui_event_email(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_emailscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_emailscreen_screen_init);
    }
}
void ui_event_browser(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_browserscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_browserscreen_screen_init);
    }
}
void ui_event_message(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_messagescreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_messagescreen_screen_init);
    }
}
void ui_event_menudown(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP)
    {
        lv_indev_wait_release(lv_indev_get_act());
        moveup_Animation(ui_menudown, 0);
    }
}
void ui_event_wifibtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_LONG_PRESSED)
    {
        _ui_screen_change(&ui_wifiset, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_wifiset_screen_init);
        moveup_Animation(ui_menudown, 0);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_flag_modify(ui_wifiscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_wifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_settingwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_wlanwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_aboutwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_datetimewifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_bluetoothwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_state_modify(ui_wlanswitch, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
        _ui_checked_set_text_value(ui_wifionlabel, target, "Opened", "");
        _ui_flag_modify(ui_wifilistpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        wificlose(e);
        _ui_flag_modify(ui_wificonnect, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wifiscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wlanwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_settingwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_aboutwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_datetimewifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_bluetoothwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_wlanswitch, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_checked_set_text_value(ui_wifionlabel, target, "", "Closed");
        _ui_flag_modify(ui_wifilistpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_lightbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_state_modify(ui_rgbswitch, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
        _ui_flag_modify(ui_rgbcolorwheel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        setcolor(e);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_state_modify(ui_rgbswitch, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_flag_modify(ui_rgbcolorwheel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        closecolor(e);
    }
}
void ui_event_lightslider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        backlight(e);
    }
}
void ui_event_volumeslider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        volumesetting(e);
    }
}
void ui_event_setting(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_aboutpannel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_aboutui, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, &ui_aboutui_screen_init);
    }
}
void ui_event_datetimepannel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_datetimeui, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, &ui_datetimeui_screen_init);
    }
}
void ui_event_wifipanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_wifiset, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, &ui_wifiset_screen_init);
    }
}
void ui_event_wifipanel1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_bluetoothset, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, &ui_bluetoothset_screen_init);
    }
}
void ui_event_wifiset(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_setting_screen_init);
    }
    if (event_code == LV_EVENT_SCREEN_LOADED && lv_obj_has_state(ui_wlanswitch, LV_STATE_CHECKED))
    {
        wifiscanf(e);
    }
}
void ui_event_headerbackico(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0, &ui_setting_screen_init);
    }
}
void ui_event_wlanswitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        wifistart(e);
        // _ui_flag_modify(ui_wificonnect, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_wifiscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_wifilistpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_settingwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_state_modify(ui_wifibtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
        _ui_flag_modify(ui_wifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_wlanwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_aboutwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_datetimewifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_bluetoothwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_checked_set_text_value(ui_wifionlabel, target, "Opened", "");
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        wificlose(e);
        _ui_flag_modify(ui_wificonnect, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wifiscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wifilistpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_settingwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_wifibtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        _ui_flag_modify(ui_wifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_wlanwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_aboutwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_datetimewifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_bluetoothwifi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_checked_set_text_value(ui_wifionlabel, target, "", "Closed");
    }
}
void ui_event_wifirefresh(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED && lv_obj_has_state(ui_wlanswitch, LV_STATE_CHECKED))
    {
        wifiscanf(e);
        // turnone_Animation(ui_wifirefresh, 0);
    }
}
void ui_event_wifilistname(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lv_label_set_text(ui_wifinamelabel, lv_label_get_text(target));
        moveup_Animation(ui_enterwifipass, 0);
        _ui_keyboard_set_target(ui_Keyboard, ui_wifipassinput);
    }
}

void ui_event_wifipassinput(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_DEFOCUSED)
    {
        movedown_Animation(ui_enterwifipass, 0);
    }
}
void ui_event_connectbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        connectwifi(e);
        movedown_Animation(ui_enterwifipass, 0);
    }
}
void ui_event_canceltbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        lv_textarea_set_text(ui_wifipassinput, "");
        movedown_Animation(ui_enterwifipass, 0);
    }
}
void ui_event_aboutui(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_setting_screen_init);
    }
}
void ui_event_datetimeui(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_setting_screen_init);
    }
}
void ui_event_autodatetimeswitch1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        ampmsets(e);
    }
}
void ui_event_autodatetimeswitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_flag_modify(ui_setdate, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_settime, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_flag_modify(ui_setdate, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_settime, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_setdate(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        moveup_Animation(ui_setdateing, 0);
    }
}
void ui_event_settime(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        moveup_Animation(ui_settimeing, 0);
    }
}
void ui_event_setdateing(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_setdateing, 0);
    }
}
void ui_event_calendar(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_current_target(e);
    char buf[_UI_TEMPORARY_STRING_BUFFER_SIZE];
    // time_t now;
    struct timeval tv;
    // char strftime_buf[64];
    struct tm timeinfo;
    gettimeofday(&tv, NULL);
    localtime_r(&tv.tv_sec, &timeinfo);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        lv_calendar_date_t date;
        if (lv_calendar_get_pressed_date(target, &date))
        {
            timeinfo.tm_year = date.year - 1900;
            timeinfo.tm_mon = date.month - 1;
            timeinfo.tm_mday = date.day;

            tv.tv_sec = mktime(&timeinfo); // 将 struct tm 转换为 time_t 类型timeval
            settimeofday(&tv, NULL);
            lv_snprintf(buf, sizeof(buf), "date  %dyear%02dmonth%02dday", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
            lv_calendar_set_today_date(ui_calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
            lv_calendar_set_showed_date(ui_calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1);
        }
        _ui_checked_set_text_value(ui_date, target, "", buf);
    }
}
void ui_event_settimeing(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_settimeing, 0);
    }
}
void ui_event_cenceltimebtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_settimeing, 0);
    }
}
void ui_event_oktimebtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        oktimebtndown(e);
        movedown_Animation(ui_settimeing, 0);
        changetime(e);
    }
}
void ui_event_bluetoothset(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_setting_screen_init);
    }
    if (event_code == LV_EVENT_SCREEN_LOADED)
    {
        bluetoothscanf(e);
    }
}
void ui_event_bluetoothbackico(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(&ui_setting, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0, &ui_setting_screen_init);
    }
}
void ui_event_bluetoothswitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        bluetoothstart(e);
        _ui_flag_modify(ui_bluetoothconnect, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_bluetoothscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_bluetoothlist, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        bluetoothclose(e);
        _ui_flag_modify(ui_bluetoothconnect, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_bluetoothscan, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_bluetoothlist, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_bluetoohtrefresh(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        bluetoothsanf(e);
    }
}
void ui_event_bluetoothlist(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        moveup_Animation(ui_enterbluetooth, 0);
    }
}
void ui_event_bluetoothlistname(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        connectwifi(e);
        moveup_Animation(ui_enterbluetooth, 0);
    }
}
void ui_event_blacklist(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_enterbluetooth, 0);
    }
}
void ui_event_canceltbtn1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_enterbluetooth, 0);
    }
}
void ui_event_connectbtn1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        connectwifi(e);
    }
}
void ui_event_clockscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_musicscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_musicback(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        stop_track();
        _ui_state_modify(ui_musicplaybtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);          // 改变按钮为停止状态
        _ui_checked_set_text_value(ui_musicplaylabel, ui_musicplaybtn, LV_SYMBOL_PLAY, ""); // 改变按钮显示暂停字符
        playsilder = 0;
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_musiclistbtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        moveup_Animation(ui_musiclistpanel, 0);
        listsdcard(e);
    }
}
void ui_event_musicpicbg(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_musicpicbgpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_musicname, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_musiclyrics, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_musiclyrics(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_musiclyrics, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_musicpicbgpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_musicname, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}
void ui_event_musiclyricslabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_musicname, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_musicpicbgpanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_musiclyrics, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
void ui_event_musicbarpanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        musicslidertime(e);
    }
}
void ui_event_musicslider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    int32_t v = lv_slider_get_value(target);
    char str[6];
    lv_snprintf(str, sizeof(str), "%02ld:%02ld", v / 60, v % 60);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        _ui_checked_set_text_value(ui_musictimelabel, target, "", str);
        musicslidertime(e);
    }
}
void ui_event_musicleft(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t *musiclr = NULL;
    uint32_t i;
    uint32_t p = lv_obj_get_child_cnt(ui_musiclist);
    char *name = NULL;
    if (event_code == LV_EVENT_CLICKED)
    {
        if (p > 0)
        {
            for (i = 0; i < p; i++)
            {
                lv_obj_t *child = lv_obj_get_child(ui_musiclist, i);
                if (lv_obj_get_state(child) == LV_STATE_CHECKED)
                {
                    if (i == 0)
                    {
                        musiclr = lv_obj_get_child(ui_musiclist, p - 1);
                    }
                    else
                    {
                        musiclr = lv_obj_get_child(ui_musiclist, i - 1);
                    }
                    name = lv_label_get_text(lv_obj_get_child(musiclr, 0));
                    lv_label_set_text(ui_musicnamelabel, name);
                }
                _ui_state_modify(child, LV_STATE_CHECKED, _UI_MODIFY_FLAG_REMOVE);
            }
            _ui_state_modify(musiclr, LV_STATE_CHECKED, _UI_MODIFY_FLAG_ADD);
            musicright(e);
        }
    }
}
void ui_event_musicplaybtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_checked_set_text_value(ui_musicplaylabel, target, LV_SYMBOL_PAUSE, "");
        lv_label_get_text(ui_musicnamelabel);
        musicplay(e);
        // turn_Animation(ui_musicbg, 0);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_checked_set_text_value(ui_musicplaylabel, target, "", LV_SYMBOL_PLAY);
        musicstop(e);
        // turnoff_Animation(ui_musicbg, 0);
    }
}
void ui_event_musicright(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t *musiclr = NULL;
    uint32_t i;
    uint32_t p = lv_obj_get_child_cnt(ui_musiclist);
    char *name = NULL;
    if (event_code == LV_EVENT_CLICKED)
    {
        if (p > 0)
        {
            for (i = 0; i < p; i++)
            {
                lv_obj_t *child = lv_obj_get_child(ui_musiclist, i);
                if (lv_obj_get_state(child) == LV_STATE_CHECKED)
                {
                    if (i + 1 == p)
                    {
                        musiclr = lv_obj_get_child(ui_musiclist, 0);
                    }
                    else
                    {
                        musiclr = lv_obj_get_child(ui_musiclist, i + 1);
                    }
                    name = lv_label_get_text(lv_obj_get_child(musiclr, 0));
                    lv_label_set_text(ui_musicnamelabel, name);
                }
                _ui_state_modify(child, LV_STATE_CHECKED, _UI_MODIFY_FLAG_REMOVE);
            }
            _ui_state_modify(musiclr, LV_STATE_CHECKED, _UI_MODIFY_FLAG_ADD);
            musicright(e);
        }
    }
}
void ui_event_musiclistpanel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        movedown_Animation(ui_musiclistpanel, 0);
    }
}
void ui_event_musiclistname(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    uint32_t i;
    if (event_code == LV_EVENT_CLICKED)
    {
        for (i = 0; i < lv_obj_get_child_cnt(ui_musiclist); i++)
        {
            lv_obj_t *child = lv_obj_get_child(ui_musiclist, i);
            _ui_state_modify(child, LV_STATE_CHECKED, _UI_MODIFY_FLAG_REMOVE);
        }
        musicchange(e);
        _ui_state_modify(target, LV_STATE_CHECKED, _UI_MODIFY_FLAG_ADD);
    }
}

void ui_event_weatherscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
    if (event_code == LV_EVENT_SCREEN_LOADED)
    {
        weatherget(e);
    }
}
void ui_event_weatherset(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_weathercitypanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        moveup_Animation(ui_weatherkey, 0);
        _ui_keyboard_set_target(ui_Keyboard2, ui_weathercityarea);
    }
}
void ui_event_weatherbutton(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_flag_modify(ui_weathercitypanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        movedown_Animation(ui_weatherkey, 0);
        weatherchangecity(e);
    }
}
void ui_event_phonescreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_rgbledscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_rgbswitch(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED && !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_flag_modify(ui_rgbcolorwheel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_lightbtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        closecolor(e);
    }
    if (event_code == LV_EVENT_VALUE_CHANGED && lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        _ui_flag_modify(ui_rgbcolorwheel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_state_modify(ui_lightbtn, LV_STATE_CHECKED, _UI_MODIFY_STATE_ADD);
        setcolor(e);
    }
}
void ui_event_rgbcolorwheel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        setcolor(e);
    }
}
void ui_event_nesscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}

void ui_event_neslistlabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        opennes(e);
        _ui_screen_change(&ui_nesgamescreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_nesgamescreen_screen_init);
    }
}
void ui_event_neskey(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    //lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        neszoom(e);
    }
    if (event_code == LV_EVENT_PRESSED || LV_EVENT_RELEASED)
    {
        neskey(e);
    }
}
void ui_event_nesgamescreen(lv_event_t *e)
{
}

void ui_event_filemanagerscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_filemanagerheaderright(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        filemanagerflush(e);
    }
}
void ui_event_filelistlabel(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        opendirfile(e);
    }
}
void ui_event_camerascreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_galleryscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_pic(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        openphoto(e);
    }
}
void ui_event_pic1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        openphoto(e);
    }
}
void ui_event_pic2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        openphoto(e);
    }
}
void ui_event_pic3(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        openphoto(e);
    }
}
void ui_event_pic4(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        openphoto(e);
    }
}
void ui_event_notesscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_contactsscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_caculatorscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_videoscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_carscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_jionetscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_qrbarcodescreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_bluetoothcontrlscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_miremotescreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_emailscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_browserscreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}
void ui_event_messagescreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
    {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_home_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_home_screen_init();
    ui_setting_screen_init();
    ui_wifiset_screen_init();
    ui_aboutui_screen_init();
    ui_datetimeui_screen_init();
    ui_bluetoothset_screen_init();
    ui_clockscreen_screen_init();
    ui_musicscreen_screen_init();
    ui_weatherscreen_screen_init();
    ui_phonescreen_screen_init();
    ui_rgbledscreen_screen_init();
    ui_nesscreen_screen_init();
    ui_nesgamescreen_screen_init();
    ui_filemanagerscreen_screen_init();
    ui_camerascreen_screen_init();
    ui_galleryscreen_screen_init();
    ui_notesscreen_screen_init();
    ui_contactsscreen_screen_init();
    ui_caculatorscreen_screen_init();
    ui_videoscreen_screen_init();
    ui_carscreen_screen_init();
    ui_jionetscreen_screen_init();
    ui_qrbarcodescreen_screen_init();
    ui_bluetoothcontrlscreen_screen_init();
    ui_miremotescreen_screen_init();
    ui_emailscreen_screen_init();
    ui_browserscreen_screen_init();
    ui_messagescreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_home);
}
