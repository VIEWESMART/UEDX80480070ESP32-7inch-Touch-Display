// VIEWE——lvgl控件例程
// https://www.display-wiki.com/smartdisplay/esp32_5_800_480
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "nvs_flash.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"
#include "lv_demos.h"
#include "iot_button.h"

static const char *TAG = "https://www.display-wiki.com/smartdisplay/esp32_5_800_480";

void lvgl_hardWare_init() // 外围硬件初始化
{
    ESP_ERROR_CHECK(bsp_i2c_init(I2C_NUM_0, 400000));
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    lv_port_tick_init();
}
void lv_tick_task(void *arg)// LVGL 时钟任务
{
    while (1)
    {
        vTaskDelay((20) / portTICK_PERIOD_MS);
        lv_task_handler();
    }
}


void Touch_IO_RST(void)
{

#if(GT911==1)
	//touch reset pin  低电平复位
//for yysj_5
//#define GPIO_I2C_INT    (GPIO_NUM_18)
//#define GPIO_I2C_RST    (GPIO_NUM_38)
	gpio_reset_pin(18); //INT
	gpio_reset_pin(38); //RST
	gpio_pullup_en(38);
	gpio_pullup_en(18);

	gpio_set_direction(18, GPIO_MODE_OUTPUT);
	gpio_set_direction(38, GPIO_MODE_OUTPUT);
	gpio_set_level(38, 1);
	gpio_set_level(18, 1);
	ESP_LOGI(TAG, "io18 set_high");
	vTaskDelay(pdMS_TO_TICKS(50));
	gpio_pulldown_en(18);
	gpio_pulldown_en(38);
	gpio_set_level(18, 0);
	gpio_set_level(38, 0);
	ESP_LOGI(TAG, "io18 set_low");

	vTaskDelay(pdMS_TO_TICKS(20));
	gpio_set_level(38, 1);
	vTaskDelay(pdMS_TO_TICKS(20));
	gpio_pulldown_en(18);
	gpio_set_level(18, 0);
	//gpio_reset_pin(39);
	//gpio_set_direction(39, GPIO_MODE_INPUT);//中断脚没有用上，这只是用来配置地址


	/*
	gpio_reset_pin(39);
	gpio_reset_pin(40);
	gpio_pullup_en(40);
	gpio_pullup_en(39);

	gpio_set_direction(39, GPIO_MODE_OUTPUT);
	gpio_set_direction(40, GPIO_MODE_OUTPUT);
	gpio_set_level(40, 1);
	gpio_set_level(39, 1);
	ESP_LOGI(TAG, "io39 set_high");
	vTaskDelay(pdMS_TO_TICKS(50));
	gpio_pulldown_en(39);
	gpio_pulldown_en(40);
	gpio_set_level(39, 0);
	gpio_set_level(40, 0);
	ESP_LOGI(TAG, "io39 set_low");

	vTaskDelay(pdMS_TO_TICKS(20));
	gpio_set_level(40, 1);
	vTaskDelay(pdMS_TO_TICKS(20));
	gpio_pulldown_en(39);
	gpio_set_level(39, 0);
	//gpio_reset_pin(39);
	//gpio_set_direction(39, GPIO_MODE_INPUT);//中断脚没有用上，这只是用来配置地址
	*/

#elif(CST3240==1)

    gpio_reset_pin(39);
	gpio_reset_pin(40);
	
	gpio_set_direction( GPIO_NUM_40, GPIO_MODE_OUTPUT);//RST SET PORT OUTPUT
	gpio_set_level(40, 0);        //RST RESET IO
	vTaskDelay(pdMS_TO_TICKS(50));//DELAY 50ms 
	gpio_set_level(40, 1);        //SET RESET IO
	vTaskDelay(pdMS_TO_TICKS(10));//DELAY 10ms 	
#endif

}
void app_main(void)
{
    Touch_IO_RST();
    lvgl_hardWare_init();       // 外围硬件初始化
    ESP_LOGI(TAG, "init ok");

    //lv_demo_music();
    lv_demo_widgets();
    //lv_demo_benchmark();
    xTaskCreate(lv_tick_task, "lv_tick_task", 1024*10, NULL, 1, NULL);
}
