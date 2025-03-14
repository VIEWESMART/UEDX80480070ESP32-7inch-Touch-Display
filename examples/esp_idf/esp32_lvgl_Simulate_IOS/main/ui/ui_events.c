#include "ui.h"
#include "esp_lcd_backlight.h"
#include <time.h>
#include <sys/time.h>
#include "esp_log.h"
#include "wifi.h"
#include "esp_sntp.h"
#include "sdcard.h"
#include "volume.h"
#include "mp3.h"
#include "rgbled.h"
#include "weather.h"
#include "nesgame.h"
#include "InfoNES_System.h"
// NES
extern DWORD dwPad1;
extern DWORD dwPad2;
extern DWORD dwSystem;
void backlight(lv_event_t *e)
{
	lv_obj_t *slider = lv_event_get_target(e);
	int32_t v = lv_slider_get_value(slider);
	const disp_backlight_config_t bckl_config = {
		.gpio_num = CONFIG_LV_DISP_PIN_BCKL,
#if defined CONFIG_LV_DISP_BACKLIGHT_PWM
		.pwm_control = true,
#else
		.pwm_control = false,
#endif
#if defined CONFIG_LV_BACKLIGHT_ACTIVE_LVL
		.output_invert = false, // 背光高
#else
		.output_invert = true, // 背光低
#endif
		.timer_idx = 0,
		.channel_idx = 0 // @todo this prevents us from having two PWM controlled displays
	};
	disp_backlight_h bckl_handle = disp_backlight_new(&bckl_config);
	disp_backlight_set(bckl_handle, v);
}

void volumesetting(lv_event_t *e)
{
	lv_obj_t *slider = lv_event_get_target(e);
	uint32_t t = lv_slider_get_value(slider);
	uint32_t s;
	if (t == 28)
	{
		ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, t));
		// 更新占空比以应用新值
		ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1));
		ESP_LOGI("MUSIC", "音量大小: %" PRIu32 "", t);
	}
	else if (t > 28)
	{
		s = 28 - (t - 28);
		ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, s));
		// 更新占空比以应用新值
		ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1));
		ESP_LOGI("MUSIC", "音量大小: %" PRIu32 "", t);
	}
	else if (t < 28)
	{
		s = 28 + (28 - t);
		ESP_ERROR_CHECK(ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1, s));
		// 更新占空比以应用新值
		ESP_ERROR_CHECK(ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_1));
		ESP_LOGI("MUSIC", "音量大小: %" PRIu32 "", t);
	}
}

void wifiscanf(lv_event_t *e)
{
	// lv_obj_invalidate(ui_wifilistpanel); // 刷新显示
	turnone_Animation(ui_wifirefresh, 0);
	lv_timer_t *wifi_time;
	xTaskCreate(wifi_scan, "wifiscan", 1024 * 4, NULL, 1, NULL);
	wifi_time = lv_timer_create(wifi_timer_cb, 4000, NULL); // 创建一个定时器
	lv_timer_set_repeat_count(wifi_time, 1);				// 设置该定时器重复执行1次
															// lv_timer_set_cb(wifi_time, wifi_timer_cb);             // 设置定时器回调函数为wifi_timer_cb
															// wifi_scan();
}

void wifistart(lv_event_t *e)
{
	lv_obj_clean(ui_wifilistpanel);
}

void wificlose(lv_event_t *e)
{
	// wifi_de_init();
	lv_obj_clean(ui_wifilistpanel);
}

void checkwlanswitch(lv_event_t *e)
{
	// Your code here
}

void connectwifi(lv_event_t *e)
{
	ESP_ERROR_CHECK(esp_wifi_disconnect());
	wifi_ssid = lv_label_get_text(ui_wifinamelabel);
	ESP_LOGI("SS", "%s", wifi_ssid);
	char password_buffer[64];
	strcpy(password_buffer, lv_textarea_get_text(ui_wifipassinput));
	wifi_pass = password_buffer;
	ESP_LOGI("SS", "%s", wifi_pass);
	wifi_config_t wifi_config = {
		.sta = {
			.ssid = "",
			.password = "",
		},
	};
	strcpy((char *)wifi_config.sta.ssid, wifi_ssid);
	strcpy((char *)wifi_config.sta.password, wifi_pass);
	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
	ESP_ERROR_CHECK(esp_wifi_connect());
	lv_textarea_set_text(ui_wifipassinput, "");
	if (!esp_sntp_enabled())
	{
		esp_sntp_setoperatingmode(ESP_SNTP_OPMODE_POLL);
		esp_sntp_setservername(0, "ntp.aliyun.com");
		esp_sntp_setservername(1, "ntp.ntsc.ac.cn");
		esp_sntp_setservername(2, "ntp7.aliyun.com");
		esp_sntp_init();
	}
}

void ampmsets(lv_event_t *e)
{
	// Your code here
}

void oktimebtndown(lv_event_t *e)
{
	// Your code here
}

void changetime(lv_event_t *e)
{
	// char strftime_buf[64];
	struct timeval tv;
	struct tm timeinfo;
	gettimeofday(&tv, NULL);

	localtime_r(&tv.tv_sec, &timeinfo);
	ESP_LOGI("时间", "%lld", tv.tv_sec);
	timeinfo.tm_hour = lv_roller_get_selected(ui_sethour);
	timeinfo.tm_min = lv_roller_get_selected(ui_setminute);
	timeinfo.tm_sec = 0;
	// 将 tm 结构体转换为 time_t 类型
	ESP_LOGI("时间", "%d年%d月%d日%d:%d:%d", timeinfo.tm_year, timeinfo.tm_mon, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
	tv.tv_sec = mktime(&timeinfo); // 将 struct tm 转换为 time_t 类型
	ESP_LOGI("时间", "%lld", tv.tv_sec);
	settimeofday(&tv, NULL);
}

void bluetoothscanf(lv_event_t *e)
{
	// Your code here
}

void bluetoothstart(lv_event_t *e)
{
	// Your code here
}

void bluetoothclose(lv_event_t *e)
{
	// Your code here
}

void bluetoothsanf(lv_event_t *e)
{
	// Your code here
}

void musicslidertime(lv_event_t *e)
{
	lv_obj_t *slider = lv_event_get_target(e);
	playsilder = lv_slider_get_value(slider);
	pcmfram = playsilder * sampleRate;
	seekpoint = true;
}

void musicleft(lv_event_t *e)
{
	char *name = lv_label_get_text(ui_musicnamelabel);
	ESP_LOGI("music", "开始切换任务");
	BaseType_t ret = xTaskCreate(switch_track, "switch_track", 4096, name, 20, NULL);
	assert(ret == pdPASS);
}

void musicright(lv_event_t *e)
{
	char *name = lv_label_get_text(ui_musicnamelabel);
	ESP_LOGI("music", "开始切换任务");
	BaseType_t ret = xTaskCreate(switch_track, "switch_track", 4096, name, 20, NULL);
	assert(ret == pdPASS);
}

void listsdcard(lv_event_t *e)
{

}

void musicplay(lv_event_t *e)
{
	char *name = lv_label_get_text(ui_musicnamelabel);
	if (strcmp(name, "请插入SD卡!") != 0)
	{
		BaseType_t ret = xTaskCreate(start_track, "start_task", 4096, name, 20, NULL);
		assert(ret == pdPASS);
	}
}
void musicstop(lv_event_t *e)
{
	char *name = lv_label_get_text(ui_musicnamelabel);
	if (strcmp(name, "请插入SD卡!") != 0)
	{
		musicpause();
	}
}
void musicchange(lv_event_t *e)
{
	lv_obj_t *listname = lv_event_get_target(e);
	lv_obj_t *labelname = lv_obj_get_child(listname, -1);
	char *name = lv_label_get_text(labelname);
	lv_label_set_text_fmt(ui_musicnamelabel, "%s", name);
	ESP_LOGI("music", "开始切换任务");
	BaseType_t ret = xTaskCreate(switch_track, "switch_track", 4096, name, 20, NULL);
	assert(ret == pdPASS);
}
void filemanagerflush(lv_event_t *e)
{

}

void opendirfile(lv_event_t *e)
{

}

void openphoto(lv_event_t *e)
{

}

void setcolor(lv_event_t *e)
{
	// lv_obj_t *color = lv_event_get_target(e);
	// lv_color_t selected_color = lv_colorwheel_get_rgb(color);
	lv_color_t selected_color = lv_colorwheel_get_rgb(ui_rgbcolorwheel);
	xTaskCreate(setcolortask, "setcolortask", 1024 * 4, &selected_color, 5, NULL);
}

void closecolor(lv_event_t *e)
{
	closergbled();
}
void weatherget(lv_event_t *e)
{
	const char *city = lv_textarea_get_text(ui_weathercityarea);
	weather_get_https(city);
}

void weatherchangecity(lv_event_t *e)
{
	const char *city = lv_textarea_get_text(ui_weathercityarea);
	weather_get_https(city);
}
void opennes(lv_event_t *e)
{
	lv_obj_t *neslistname = lv_event_get_target(e);
	char *name = lv_label_get_text(neslistname);
	nesstart(name);

}
void closenes(lv_event_t *e)
{
	stats = 0;

}
void neszoom(lv_event_t *e)
{
	lv_obj_t *neszoom = lv_event_get_target(e);
	uint16_t zoom = lv_img_get_zoom(ui_nesgamepanel);
	ESP_LOGI("NES事件", "zoom：%d", zoom);
	lv_coord_t zoomy = lv_obj_get_y(ui_nesgamepanel);
	ESP_LOGI("NES事件", "zoomy：%d", zoomy);
	if (neszoom == ui_neskeyzoomup)
	{
		zoom += 2;
		zoomy += 1;
		if (zoom > 512)
		{
			zoom = 256;
			zoomy= 0;
		}
	}
	if (neszoom == ui_neskeyzoomdown)
	{
		zoom -= 2;
		zoomy -= 1;
		if (zoom < 10)
		{
			zoom = 256;
			zoomy= 0;
		}
	}
	else if (neszoom == ui_neskeyquit)
	{
		lv_indev_wait_release(lv_indev_get_act());
		_ui_screen_change(&ui_nesscreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_nesscreen_screen_init);
		closenes(e);
	}
	lv_img_set_zoom(ui_nesgamepanel, zoom);
	lv_obj_set_y(ui_nesgamepanel, zoomy);
}
void neskey(lv_event_t *e)
{
	lv_obj_t *nesgamekey = lv_event_get_target(e);
	lv_event_code_t neskey_code = lv_event_get_code(e);
	if (neskey_code == LV_EVENT_PRESSED)
	{
		if (nesgamekey == ui_neskeya)
		{
			dwPad1 |= (1 << 0);
		}
		else if (nesgamekey == ui_neskeyb)
		{
			dwPad1 |= (1 << 1);
		}
		else if (nesgamekey == ui_neskeyselect)
		{
			dwPad1 |= (1 << 2);
		}
		else if (nesgamekey == ui_neskeystart)
		{
			dwPad1 |= (1 << 3);
		}
		else if (nesgamekey == ui_neskeyup)
		{
			dwPad1 |= (1 << 4);
		}
		else if (nesgamekey == ui_neskeydown)
		{
			dwPad1 |= (1 << 5);
		}
		else if (nesgamekey == ui_neskeyleft)
		{
			dwPad1 |= (1 << 6);
		}
		else if (nesgamekey == ui_neskeyright)
		{
			dwPad1 |= (1 << 7);
		}
	}
	if (neskey_code == LV_EVENT_RELEASED)
	{
		if (nesgamekey == ui_neskeya)
		{
			dwPad1 &= ~(1<<0);
		}
		else if (nesgamekey == ui_neskeyb)
		{
			dwPad1 &= ~(1<<1);
		}
		else if (nesgamekey == ui_neskeyselect)
		{
			dwPad1 &= ~(1<<2);
		}
		else if (nesgamekey == ui_neskeystart)
		{
			dwPad1 &= ~(1<<3);
		}
		else if (nesgamekey == ui_neskeyup)
		{
			dwPad1 &= ~(1<<4);
		}
		else if (nesgamekey == ui_neskeydown)
		{
			dwPad1 &= ~(1<<5);
		}
		else if (nesgamekey == ui_neskeyleft)
		{
			dwPad1 &= ~(1<<6);
		}
		else if (nesgamekey == ui_neskeyright)
		{
			dwPad1 &= ~(1<<7);
		}
	}
	
}