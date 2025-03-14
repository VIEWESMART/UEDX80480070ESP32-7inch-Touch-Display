#include "weather.h"
#include "cJSON.h"
#include "esp_tls.h"
#include "esp_crt_bundle.h"
#include "esp_http_client.h"
#define MAX_HTTP_OUTPUT_BUFFER 2048
static const char *TAG = "天气";

// 定义一个结构体，用于存储未来几日天气预报信息
typedef struct
{
    char city[64];         // 城市名称
    char province[64];     // 省份名称
    char week[16];         // 星期
    char date[32];         // 日期
    char dayweather[32];   // 白天天气
    char nightweather[32]; // 夜晚天气
    char daytemp[32];      // 白天温度
    char nighttemp[32];    // 夜晚温度
    char daywind[32];      // 白天风向
    // char nightwind[32]; // 夜晚风向
    char daypower[32]; // 白天风力
    // char nightpower[32]; // 夜晚风力
} WeatherForecast;
// 定义一个结构体，用于存储当前实时天气预报信息
typedef struct
{
    char weather[32];     // 实时天气
    char temperature[32]; // 实时气温
    char humidity[32];    // 湿度
} weatherlives;
// 全局变量，用于存储解析后的天气预报数据
WeatherForecast daily_forecasts[4]; // 假设最多存储4天的天气预报数据
weatherlives daily_weatherlives;
// 解析天气预报 JSON 数据函数
void parse_weather_forecast_json(const char *json_string)
{
    cJSON *root = cJSON_Parse(json_string); // 使用 cJSON_Parse 函数解析 JSON 字符串，获取 JSON 根节点
    if (root == NULL)
    {
        ESP_LOGE(TAG, "Error before: [%s]", cJSON_GetErrorPtr()); // 如果解析失败，打印错误信息并返回
        return;
    }
    cJSON *weatherlives_array = cJSON_GetObjectItem(root, "lives"); // 从 JSON 根节点获取 "forecasts" 数组对象
    if (cJSON_IsArray(weatherlives_array) && cJSON_GetArraySize(weatherlives_array) > 0)
    {
        cJSON *weatherlives_obj = cJSON_GetArrayItem(weatherlives_array, 0); // 获取 "forecasts" 数组中的第一个预报对象
        // 解析实时天气、温度和湿度，并将其存储到 daily_weatherlives 中
        cJSON *weather = cJSON_GetObjectItem(weatherlives_obj, "weather");
        cJSON *temperature = cJSON_GetObjectItem(weatherlives_obj, "temperature");
        cJSON *humidity = cJSON_GetObjectItem(weatherlives_obj, "humidity");
        if (weather && cJSON_IsString(weather) && temperature && cJSON_IsString(temperature) && humidity && cJSON_IsString(humidity))
        {
            strcpy(daily_weatherlives.weather, cJSON_GetStringValue(weather));
            strcpy(daily_weatherlives.temperature, cJSON_GetStringValue(temperature));
            strcpy(daily_weatherlives.humidity, cJSON_GetStringValue(humidity));
        }
    }

    cJSON *forecasts_array = cJSON_GetObjectItem(root, "forecasts"); // 从 JSON 根节点获取 "forecasts" 数组对象
    if (cJSON_IsArray(forecasts_array) && cJSON_GetArraySize(forecasts_array) > 0)
    {
        cJSON *forecast_obj = cJSON_GetArrayItem(forecasts_array, 0); // 获取 "forecasts" 数组中的第一个预报对象

        // 解析城市、省份和报告时间，并将其存储到 daily_forecasts[0] 中
        cJSON *city = cJSON_GetObjectItem(forecast_obj, "city");
        cJSON *province = cJSON_GetObjectItem(forecast_obj, "province");
        if (city && cJSON_IsString(city) && province && cJSON_IsString(province))
        {
            strcpy(daily_forecasts[0].city, cJSON_GetStringValue(city));
            strcpy(daily_forecasts[0].province, cJSON_GetStringValue(province));
        }

        // 开始遍历casts数组，处理每一天的天气预报数据
        cJSON *casts_array = cJSON_GetObjectItem(forecast_obj, "casts");
        if (cJSON_IsArray(casts_array))
        {
            for (int i = 0; i < cJSON_GetArraySize(casts_array); i++)
            {                                                         // 遍历 casts 数组的前4个元素
                cJSON *cast_obj = cJSON_GetArrayItem(casts_array, i); // 获取casts数组中的第i个预报项对象

                // 解析每一天的天气预报数据，并将其存储到 daily_forecasts[i+1] 中
                cJSON *week = cJSON_GetObjectItem(cast_obj, "week");
                cJSON *date = cJSON_GetObjectItem(cast_obj, "date");
                cJSON *dayweather = cJSON_GetObjectItem(cast_obj, "dayweather");
                cJSON *nightweather = cJSON_GetObjectItem(cast_obj, "nightweather");
                cJSON *daytemp = cJSON_GetObjectItem(cast_obj, "daytemp");
                cJSON *nighttemp = cJSON_GetObjectItem(cast_obj, "nighttemp");
                cJSON *daywind = cJSON_GetObjectItem(cast_obj, "daywind");
                // cJSON *nightwind = cJSON_GetObjectItem(cast_obj, "nightwind");
                cJSON *daypower = cJSON_GetObjectItem(cast_obj, "daypower");
                // cJSON *nightpower = cJSON_GetObjectItem(cast_obj, "nightpower");

                // 检查这些字段是否都存在且为字符串类型，若是则复制到 daily_forecasts[i+1] 中
                if (week && cJSON_IsString(week) && date && cJSON_IsString(date) &&
                    dayweather && cJSON_IsString(dayweather) && nightweather && cJSON_IsString(nightweather) &&
                    daytemp && cJSON_IsString(daytemp) && nighttemp && cJSON_IsString(nighttemp) &&
                    daywind && cJSON_IsString(daywind) && daypower && cJSON_IsString(daypower))
                {

                    strcpy(daily_forecasts[i].week, cJSON_GetStringValue(week));
                    strcpy(daily_forecasts[i].date, cJSON_GetStringValue(date));
                    strcpy(daily_forecasts[i].dayweather, cJSON_GetStringValue(dayweather));
                    strcpy(daily_forecasts[i].nightweather, cJSON_GetStringValue(nightweather));
                    strcpy(daily_forecasts[i].daytemp, cJSON_GetStringValue(daytemp));
                    strcpy(daily_forecasts[i].nighttemp, cJSON_GetStringValue(nighttemp));
                    strcpy(daily_forecasts[i].daywind, cJSON_GetStringValue(daywind));
                    // strcpy(daily_forecasts[i].nightwind, cJSON_GetStringValue(nightwind));
                    strcpy(daily_forecasts[i].daypower, cJSON_GetStringValue(daypower));
                    // strcpy(daily_forecasts[i].nightpower, cJSON_GetStringValue(nightpower));
                }
            }
        }
    }
    // 在解析完成后，清理 cJSON 根节点以释放内存
    ESP_LOGI(TAG, "气温: %s°", daily_forecasts[0].daytemp);
    lv_label_set_text(ui_weatherprovincelabel, daily_forecasts[0].province);                  // 省份
    lv_label_set_text(ui_weathercitylabel, daily_forecasts[0].city);                          // 城市
    lv_label_set_text_fmt(ui_weathertemperaturelabel, "%s°", daily_weatherlives.temperature); // 实时温度

    lv_label_set_text(ui_weatherlabel1, daily_weatherlives.weather);                 // 实时天气
    lv_label_set_text_fmt(ui_weatherabel2, "Max%s°", daily_forecasts[0].daytemp);   // 白天气温
    lv_label_set_text_fmt(ui_weatherabel3, "%s°", daily_forecasts[0].nighttemp); // 夜间气温
    lv_label_set_text_fmt(ui_weatherabel4, "Humidity%s%%", daily_weatherlives.humidity); // 实时湿度
    lv_label_set_text_fmt(ui_weatherabel5, "%swind", daily_forecasts[0].daywind);      // 白天风向
    lv_label_set_text_fmt(ui_weatherabel6, "%slevel", daily_forecasts[0].daypower);     // 白天风力

    lv_label_set_text(ui_Label13, daily_forecasts[1].dayweather);           // 明天天气
    lv_label_set_text_fmt(ui_Label14, "%s°", daily_forecasts[1].nighttemp); // 明天夜间气温
    lv_label_set_text_fmt(ui_Label15, "%s°", daily_forecasts[1].daytemp);   // 明天白天气温

    lv_label_set_text(ui_Label16, daily_forecasts[2].dayweather);
    lv_label_set_text_fmt(ui_Label17, "%s°", daily_forecasts[2].nighttemp);
    lv_label_set_text_fmt(ui_Label18, "%s°", daily_forecasts[2].daytemp);
    // 定义星期数组
    const char *weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    int weekday_num = daily_forecasts[3].week[0] - '0'; // 使用首字符进行转换
    if ((weekday_num >= 1) && (weekday_num <= 7))       // 注意这里是字符'1'到'7'
    {
        lv_label_set_text(ui_Label3, weekdays[weekday_num - 1]);
    }
    else
    {
        lv_label_set_text(ui_Label3, "invalid");
    }
    lv_label_set_text(ui_Label19, daily_forecasts[3].dayweather);
    lv_label_set_text_fmt(ui_Label20, "%s°", daily_forecasts[3].nighttemp);
    lv_label_set_text_fmt(ui_Label21, "%s°", daily_forecasts[3].daytemp);
    cJSON_Delete(root);
}

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer; // Buffer to store response of http request from event handler
    static int output_len;      // Stores number of bytes read
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        /*
         *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
         *  However, event handler can also be used in case chunked encoding is used.
         */
        if (!esp_http_client_is_chunked_response(evt->client))
        {
            // If user_data buffer is configured, copy the response into the buffer
            if (evt->user_data)
            {
                memcpy(evt->user_data + output_len, evt->data, evt->data_len);
            }
            else
            {
                if (output_buffer == NULL)
                {
                    output_buffer = (char *)malloc(esp_http_client_get_content_length(evt->client));
                    output_len = 0;
                    if (output_buffer == NULL)
                    {
                        ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                        return ESP_FAIL;
                    }
                }
                memcpy(output_buffer + output_len, evt->data, evt->data_len);
            }
            output_len += evt->data_len;
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        if (output_buffer != NULL)
        {
            // Response is accumulated in output_buffer. Uncomment the below line to print the accumulated response
            // ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        int mbedtls_err = 0;
        esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
        if (err != 0)
        {
            ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
            ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
        }
        if (output_buffer != NULL)
        {
            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_REDIRECT:
        ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
        esp_http_client_set_header(evt->client, "From", "user@example.com");
        esp_http_client_set_header(evt->client, "Accept", "text/html");
        esp_http_client_set_redirection(evt->client);
        break;
    }
    return ESP_OK;
}
void weather_get_task(void *arg)
{
    char local_response_buffer[MAX_HTTP_OUTPUT_BUFFER] = {0};
    /*本例程使用高德开放平台天气API，请根据自己申请的KEY填入相应的KEY值。*/
    char *city_code = (char *)arg;
    char *key = "07bd81f5cd7728014fcdc6fc80d159df";
    char *extensions = "all";
    char query[128]; // 假设128足够容纳查询字符串
    snprintf(query, sizeof(query), "city=%s&key=%s&extensions=%s", city_code, key, extensions);
    esp_http_client_config_t config = {
        .host = "restapi.amap.com",
        .path = "/v3/weather/weatherInfo",
        .query = query,
        .event_handler = _http_event_handler,
        .user_data = local_response_buffer, // Pass address of local buffer to get response
        .disable_auto_redirect = true,
        .crt_bundle_attach = esp_crt_bundle_attach,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    // GET
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET 状态 = %d, 内容长度 = %lld",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET 请求失败: %s", esp_err_to_name(err));
    }
    // ESP_LOG_BUFFER_CHAR(TAG, local_response_buffer, strlen(local_response_buffer));
    parse_weather_forecast_json(local_response_buffer);
    extensions = "base";
    snprintf(query, sizeof(query), "city=%s&key=%s&extensions=%s", city_code, key, extensions);
    config.query = query;
    client = esp_http_client_init(&config);
    // GET
    err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP GET 状态 = %d, 内容长度 = %lld",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP GET 请求失败: %s", esp_err_to_name(err));
    }
    parse_weather_forecast_json(local_response_buffer);

    esp_http_client_cleanup(client);
    vTaskDeleteWithCaps(NULL);
}
void weather_get_https(const void *arg)
{
    char *city = (char *)arg;
    xTaskCreateWithCaps(weather_get_task, "weather_get_task", 1024 * 8, city, 5, NULL, MALLOC_CAP_SPIRAM);
}