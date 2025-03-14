#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "string.h"
#include "driver/gpio.h"
#include "uart.h"
char uart_data[32];
char uart_vo[5];
char uart_vol;
void inttostr(char value, char *buffer)
{
    static const char digits[] = "0123456789";
    // 特殊处理100%的情况
    if (value == 100)
    {
        buffer[0] = '1';
        buffer[1] = '0';
        buffer[2] = '0';
        buffer[3] = '%';
    }
    else if (9 < value && value < 100)
    {
        // 将数字从低位到高位填入缓冲区
        buffer[0] = digits[value / 10 % 10];
        buffer[1] = digits[value % 10];
        // 数字后面留出位置放置百分号
        buffer[2] = '%';
        buffer[3] = '\0';
    }
    else
    {
        buffer[0] = digits[value % 10];
        buffer[1] = '%';
        buffer[2] = '\0';
        buffer[3] = 0;
    }
    // 添加字符串结束符
}
void uart_init(void)
{
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

int sendData(const char *logName, const char *data)
{
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(UART_NUM_1, data, len);
    ESP_LOGI(logName, "发送 %d 字节", txBytes);
    return txBytes;
}
void showbat(void)
{
    uart_read_bytes(UART_NUM_1, uart_data, 1, 1 / portTICK_PERIOD_MS);
    uart_vol = uart_data[0];  
    inttostr(uart_vol, uart_vo);             // 转换电压百分比
    lv_label_set_text(ui_batteryp, uart_vo); // 显示电量
    lv_label_set_text(ui_aboutbatteryp, uart_vo);
    lv_label_set_text(ui_bluetoothbatteryp, uart_vo);
    lv_label_set_text(ui_datetimebatteryp, uart_vo);
    lv_label_set_text(ui_settingbatteryp, uart_vo);
    lv_label_set_text(ui_wlanbatteryp, uart_vo);
    if (uart_vol < 20)
    {
        lv_obj_set_style_text_color(ui_battery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_aboutbattery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_bluetoothbattery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_datetimebattery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_settingbattery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_wlanbattery, lv_color_hex(0xcc0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_EMPTY);
        lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_EMPTY);
        lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_EMPTY);
        lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_EMPTY);
        lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_EMPTY);
        lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_EMPTY);
    }
    else if (uart_vol < 40)
    {
        lv_obj_set_style_text_color(ui_battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_aboutbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_bluetoothbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_datetimebattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_settingbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_wlanbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_1);
        lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_1);
        lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_1);
        lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_1);
        lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_1);
        lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_1);
    }
    else if (uart_vol < 60)
    {
        lv_obj_set_style_text_color(ui_battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_aboutbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_bluetoothbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_datetimebattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_settingbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_wlanbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_2);
        lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_2);
        lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_2);
        lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_2);
        lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_2);
        lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_2);
    }
    else if (uart_vol < 80)
    {
        lv_obj_set_style_text_color(ui_battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_aboutbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_bluetoothbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_datetimebattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_settingbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_wlanbattery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_3);
        lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_3);
        lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_3);
        lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_3);
        lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_3);
        lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_3);
    }
    else if (uart_vol < 101)
    {
        lv_obj_set_style_text_color(ui_battery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_aboutbattery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_bluetoothbattery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_datetimebattery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_settingbattery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_wlanbattery, lv_color_hex(0x00d200), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_battery, LV_SYMBOL_BATTERY_FULL);
        lv_label_set_text(ui_aboutbattery, LV_SYMBOL_BATTERY_FULL);
        lv_label_set_text(ui_bluetoothbattery, LV_SYMBOL_BATTERY_FULL);
        lv_label_set_text(ui_datetimebattery, LV_SYMBOL_BATTERY_FULL);
        lv_label_set_text(ui_settingbattery, LV_SYMBOL_BATTERY_FULL);
        lv_label_set_text(ui_wlanbattery, LV_SYMBOL_BATTERY_FULL);
    }
}
