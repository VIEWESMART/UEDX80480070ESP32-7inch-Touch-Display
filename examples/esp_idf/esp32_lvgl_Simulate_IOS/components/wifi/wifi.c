#include "wifi.h"
#include "freertos/semphr.h"
char *wifi_ssid;
char *wifi_pass;
EventGroupHandle_t s_wifi_event_group;
static const char *TAG = "扫描";
esp_netif_t *sta_netif;
SemaphoreHandle_t lvglmutex;
static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_SCAN_DONE)
    {
        // esp_wifi_connect();
        xEventGroupSetBits(s_wifi_event_group, WIFI_SCAN);
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED)
    {

        ESP_LOGI(TAG, "WIFI已连接！");
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_label_set_text_fmt(ui_wifiname, "%s", wifi_ssid);
        lv_label_set_text(ui_wifistats, "已连接");
        lv_obj_clear_flag(ui_wificonnect, LV_OBJ_FLAG_HIDDEN);
        xSemaphoreGive(lvglmutex);
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        xSemaphoreTake(lvglmutex, portMAX_DELAY);
        lv_label_set_text(ui_wifistats, "已断开");
        xSemaphoreGive(lvglmutex);
        esp_wifi_connect();
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "获取IP:" IPSTR, IP2STR(&event->ip_info.ip));
    }
}

void wifi_timer_cb(lv_timer_t *timer)
{
    // 获取扫描结果，并添加到界面上
    lv_obj_clean(ui_wifilistpanel);
    uint16_t ap_num = 0;
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
    ESP_LOGI(TAG, "AP数量：%d", ap_num);

    uint16_t max_aps = 20;
    wifi_ap_record_t ap_records[max_aps];
    memset(ap_records, 0, sizeof(ap_records));
    uint16_t aps_count = max_aps;
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&aps_count, ap_records));
    ESP_LOGI(TAG, "已扫描到 %d 个 AP", aps_count);
    lv_obj_t *ui_wifilist[aps_count];
    lv_obj_t *ui_wifisymbols[aps_count];
    lv_obj_t *ui_wifilistname[aps_count];
    lv_obj_t *ui_wifilock[aps_count];
    lv_obj_t *ui_wifilistright[aps_count];

    for (int i = 0; i < aps_count; ++i)
    {
        ESP_LOGI(TAG, "%s", ap_records[i].ssid);
        ESP_LOGI(TAG, "%d", ap_records[i].rssi);
        ui_wifilist[i] = lv_obj_create(ui_wifilistpanel);
        lv_obj_set_width(ui_wifilist[i], 280);
        lv_obj_set_height(ui_wifilist[i], 40);
        lv_obj_set_align(ui_wifilist[i], LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_wifilist[i], LV_OBJ_FLAG_SCROLLABLE); /// Flags
        lv_obj_set_style_radius(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_wifilist[i], lv_color_hex(0xE6E6E6), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_wifilist[i], 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(ui_wifilist[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        ui_wifisymbols[i] = lv_label_create(ui_wifilist[i]);
        lv_obj_set_width(ui_wifisymbols[i], LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_wifisymbols[i], LV_SIZE_CONTENT); /// 1
        lv_obj_set_align(ui_wifisymbols[i], LV_ALIGN_LEFT_MID);
        if (ap_records[i].rssi >= -50)
        {
            lv_label_set_text(ui_wifisymbols[i], LV_SYMBOL_WIFI);
        }
        else if (ap_records[i].rssi < -50 && ap_records[i].rssi >= -70)
        {
            lv_label_set_text(ui_wifisymbols[i], LV_SYMBOL_WIFI_FAIR);
        }
        else if (ap_records[i].rssi < -70)
        {
            lv_label_set_text(ui_wifisymbols[i], LV_SYMBOL_WIFI_WEAK);
        }
        lv_obj_set_style_text_font(ui_wifisymbols[i], &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
        ui_wifilistname[i] = lv_label_create(ui_wifilist[i]); // 只需要在外面创建一次对象
        lv_obj_add_flag(ui_wifilistname[i], LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_CHECKABLE);
        lv_obj_set_size(ui_wifilistname[i], 200, LV_SIZE_CONTENT); // 只需要设置一次大小
        lv_obj_set_x(ui_wifilistname[i], 30);
        lv_obj_set_y(ui_wifilistname[i], 0);
        lv_obj_set_align(ui_wifilistname[i], LV_ALIGN_LEFT_MID);
        lv_label_set_long_mode(ui_wifilistname[i], LV_LABEL_LONG_DOT);
        lv_label_set_text_fmt(ui_wifilistname[i], "%s", ap_records[i].ssid);

        ui_wifilock[i] = lv_label_create(ui_wifilist[i]);
        lv_obj_set_width(ui_wifilock[i], LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_wifilock[i], LV_SIZE_CONTENT); /// 1
        lv_obj_set_x(ui_wifilock[i], -20);
        lv_obj_set_y(ui_wifilock[i], 0);
        lv_obj_set_align(ui_wifilock[i], LV_ALIGN_RIGHT_MID);
        if (ap_records[i].authmode == 0)
        {
            lv_label_set_text(ui_wifilock[i], LV_SYMBOL_UNLOCK);
        }
        else
        {
            lv_label_set_text(ui_wifilock[i], LV_SYMBOL_LOCK);
        }
        lv_obj_set_style_text_font(ui_wifilock[i], &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
        ui_wifilistright[i] = lv_label_create(ui_wifilist[i]);
        lv_obj_set_width(ui_wifilistright[i], LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_wifilistright[i], LV_SIZE_CONTENT); /// 1
        lv_obj_set_align(ui_wifilistright[i], LV_ALIGN_RIGHT_MID);
        lv_label_set_text(ui_wifilistright[i], LV_SYMBOL_RIGHT);
        lv_obj_set_style_text_font(ui_wifilistright[i], &misans16, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(ui_wifilistname[i], ui_event_wifilistname, LV_EVENT_ALL, NULL);
        lv_obj_invalidate(ui_wifiset);
    }
}
void wifi_init(void)
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    s_wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    
    sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));
    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    // Initialize default station as network interface instance (esp-netif)
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_APSTA));
    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_LOGI(TAG, "WIFI初始化完成！");
}
void wifi_de_init(void)
{
    ESP_ERROR_CHECK(esp_wifi_disconnect());
    ESP_ERROR_CHECK(esp_wifi_stop());
    ESP_ERROR_CHECK(esp_wifi_deinit());
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, event_handler));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, event_handler));
    ESP_ERROR_CHECK(esp_event_loop_delete_default());
    esp_netif_destroy(sta_netif);
    ESP_ERROR_CHECK(nvs_flash_deinit());
    ESP_LOGI(TAG, "WIFI卸载完成！");
}

void wifi_scan(void *pt)
{

    ESP_LOGI(TAG, "WIFI扫描开始！");
    wifi_country_t wifi_country_config = {
        .cc = "CN",
        .schan = 1,
        .nchan = 13,
    };
    ESP_ERROR_CHECK(esp_wifi_set_country(&wifi_country_config));
    wifi_scan_config_t wifi_scan_config = {
        .ssid=NULL,
        .bssid=NULL,
        .channel = 0,

        // .show_hidden = true, /* 显示隐藏wifi选项 */
    };
    ESP_LOGI("wifi", "WIFI准备扫描！");
    ESP_ERROR_CHECK(esp_wifi_scan_start(&wifi_scan_config, false));
    ESP_LOGI("wifi", "WIFI扫描结束！");
    xEventGroupWaitBits(s_wifi_event_group, WIFI_SCAN, pdTRUE, pdFALSE, portMAX_DELAY);
    ESP_LOGI("wifi", "WIFI扫描完成！");

    vTaskDelete(NULL);
}