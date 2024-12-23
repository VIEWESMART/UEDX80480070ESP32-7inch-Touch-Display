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

#define BOOT_BUTTON_NUM  (GPIO_NUM_0)  // 使用 IO0 作为 boot 键
#define BUTTON_ACTIVE_LEVEL     0

void create_touch_test_screen();
void return_to_main_screen();


#define MAX_LINES 1000 // 最大线条数量
static lv_point_t last_touch_point = {-1, -1}; // 用于存储上一个触摸点
static lv_obj_t *lines[MAX_LINES]; // 存储线条对象
static int line_count = 0; // 当前线条数量
static lv_timer_t *clear_timer = NULL; // 清除线条的定时器
static bool in_touch_test_screen = false; // 标记是否在触摸测试界面
static bool in_display_test_screen = false; // 标记是否在显示测试界面
static lv_obj_t *display_test_label = NULL; // 显示测试界面的标签
static int current_color = 0; // 当前颜色索引

void draw_line(int x1, int y1, int x2, int y2) {
    if (line_count >= MAX_LINES) return; // 超过最大线条数量

    lv_obj_t *line = lv_line_create(lv_scr_act());
    static lv_point_t points[2];
    points[0].x = x1;
    points[0].y = y1;
    points[1].x = x2;
    points[1].y = y2;
    lv_line_set_points(line, points, 2); // 设置线条的两个点
    lv_obj_set_style_line_color(line, lv_color_make(0, 0, 0), LV_PART_MAIN); // 设置线条颜色
    lv_obj_set_style_line_width(line, 2, LV_PART_MAIN); // 设置线条宽度

    lines[line_count++] = line; // 存储线条对象
}

void clear_lines() {
    for (int i = 0; i < line_count; i++) {
        lv_obj_del(lines[i]); // 删除线条对象
    }
    line_count = 0; // 重置线条计数
}

void display_coordinates(int x, int y) {
    // 显示触摸坐标
    static lv_obj_t *label = NULL;
    if (label == NULL) {
        label = lv_label_create(lv_scr_act());
        lv_obj_align(label, LV_ALIGN_BOTTOM_LEFT, 10, -10); // 设置标签位置
    }
    char buf[32];
    snprintf(buf, sizeof(buf), "Touch: (%d, %d)", x, y);
    lv_label_set_text(label, buf); // 更新标签文本
}

static void touch_event_handler(lv_event_t *e) {
    lv_indev_t *indev = lv_indev_get_act();
    lv_point_t touch_point;

    // 获取触摸点
    lv_indev_get_point(indev, &touch_point);
    
    if (touch_point.x >= 0 && touch_point.y >= 0) {
        // 如果上一个触摸点有效，绘制线条
        if (touch_point.x >= 0 && touch_point.y >= 0) {
             // 如果上一个触摸点有效，绘制线条
            if (last_touch_point.x >= 0 && last_touch_point.y >= 0) {
                draw_line(last_touch_point.x, last_touch_point.y, touch_point.x, touch_point.y); // 绘制线条
            }
            last_touch_point = touch_point;

            // 如果定时器存在，重置定时器
            if (clear_timer) {
                lv_timer_reset(clear_timer);
            } else {
                // 创建定时器，15秒后清除所有线条
                clear_timer = lv_timer_create((lv_timer_cb_t)clear_lines, 5000, NULL);
            }
        }

        // 绘制当前触摸点
        // draw_touch_point(touch_point.x, touch_point.y); // 绘制触摸点
        display_coordinates(touch_point.x, touch_point.y); // 显示坐标
    } else {
        // 如果触摸点无效，重置上一个触摸点
        last_touch_point.x = -1;
        last_touch_point.y = -1;
    }
}


// 创建触摸测试界面的函数
void create_touch_test_screen() {
    // 清除当前界面
    lv_obj_clean(lv_scr_act());

    // 创建触摸测试界面
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Touch the screen!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    // 设置字体为 24pt 的 Montserrat 字体
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_24, LV_PART_MAIN);

    // 注册触摸事件
    lv_obj_add_event_cb(lv_scr_act(), touch_event_handler, LV_EVENT_PRESSING, NULL);
    in_touch_test_screen = true; // 更新状态标记
}

/*返回主界面*/

// 返回主界面的函数
void return_to_main_screen() {
    lv_obj_clean(lv_scr_act()); // 清除当前界面
    lv_demo_widgets(); // 返回主界面
    in_touch_test_screen = false; // 更新状态标记
}

// 创建显示测试界面的函数
void create_display_test_screen() {
    lv_obj_clean(lv_scr_act()); // 清除当前界面

    // 创建标签
    display_test_label = lv_label_create(lv_scr_act());
    lv_label_set_text(display_test_label, "Display Test");
    lv_obj_align(display_test_label, LV_ALIGN_CENTER, 0, -20);

    // 设置初始背景颜色
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_make(255, 0, 0), LV_PART_MAIN); // 红色背景

    in_display_test_screen = true; // 更新状态标记
}
// 更新显示测试界面颜色
void update_display_test_screen() {
    if (!in_display_test_screen) return;

    current_color = (current_color + 1) % 3; // 循环切换颜色
    lv_color_t color;

    switch (current_color) {
        case 0:
            color = lv_color_make(255, 0, 0); // 红色
            break;
        case 1:
            color = lv_color_make(0, 255, 0); // 绿色
            break;
        case 2:
            color = lv_color_make(0, 0, 255); // 蓝色
            break;
    }

    lv_obj_set_style_bg_color(lv_scr_act(), color, LV_PART_MAIN); // 更新背景颜色
}

/*按键初始化及处理 */

const char *button_event_table[] = {
    "BUTTON_PRESS_DOWN",
    "BUTTON_PRESS_UP",
    "BUTTON_PRESS_REPEAT",
    "BUTTON_PRESS_REPEAT_DONE",
    "BUTTON_SINGLE_CLICK",
    "BUTTON_DOUBLE_CLICK",
    "BUTTON_MULTIPLE_CLICK",
    "BUTTON_LONG_PRESS_START",
    "BUTTON_LONG_PRESS_HOLD",
    "BUTTON_LONG_PRESS_UP",
    "BUTTON_PRESS_END",
};
// 按钮事件回调函数
static void button_event_cb(void *arg, void *data) {
    button_event_t event = (button_event_t)data;
    ESP_LOGI(TAG, "Button event: %s", button_event_table[event]);

    switch (event) {
        case BUTTON_SINGLE_CLICK:
            if (in_touch_test_screen) {
                // 如果在触摸测试界面，返回主界面
                return_to_main_screen();
            } else {
                // 切换到触摸测试界面
                create_touch_test_screen();
            }
            break;

        case BUTTON_DOUBLE_CLICK:
            
            break;

        case BUTTON_LONG_PRESS_START:
            if (in_display_test_screen) {
                // 如果在显示测试界面，返回主界面
                return_to_main_screen();
            } else {
                // 切换到显示测试界面
                create_display_test_screen();
                // 启动定时器以更新显示测试界面颜色
                lv_timer_create((lv_timer_cb_t)update_display_test_screen, 1000, NULL);
            }
            break;

        default:
            break;
    }
}

#if CONFIG_ENTER_LIGHT_SLEEP_MODE_MANUALLY
void button_enter_power_save(void *usr_data)
{
    ESP_LOGI(TAG, "Can enter power save now");
    esp_light_sleep_start();
}
#endif

void button_init(uint32_t button_num)
{
    button_config_t btn_cfg = {
        .type = BUTTON_TYPE_GPIO,
        .gpio_button_config = {
            .gpio_num = button_num,
            .active_level = BUTTON_ACTIVE_LEVEL,
#if CONFIG_GPIO_BUTTON_SUPPORT_POWER_SAVE
            .enable_power_save = true,
#endif
        },
    };
    button_handle_t btn = iot_button_create(&btn_cfg);
    assert(btn);
    esp_err_t err = iot_button_register_cb(btn, BUTTON_PRESS_DOWN, button_event_cb, (void *)BUTTON_PRESS_DOWN);
    err |= iot_button_register_cb(btn, BUTTON_PRESS_UP, button_event_cb, (void *)BUTTON_PRESS_UP);
    err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT, button_event_cb, (void *)BUTTON_PRESS_REPEAT);
    err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT_DONE, button_event_cb, (void *)BUTTON_PRESS_REPEAT_DONE);
    err |= iot_button_register_cb(btn, BUTTON_SINGLE_CLICK, button_event_cb, (void *)BUTTON_SINGLE_CLICK);
    err |= iot_button_register_cb(btn, BUTTON_DOUBLE_CLICK, button_event_cb, (void *)BUTTON_DOUBLE_CLICK);
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_START, button_event_cb, (void *)BUTTON_LONG_PRESS_START);
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_HOLD, button_event_cb, (void *)BUTTON_LONG_PRESS_HOLD);
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_UP, button_event_cb, (void *)BUTTON_LONG_PRESS_UP);
    err |= iot_button_register_cb(btn, BUTTON_PRESS_END, button_event_cb, (void *)BUTTON_PRESS_END);

#if CONFIG_ENTER_LIGHT_SLEEP_MODE_MANUALLY
    /*!< For enter Power Save */
    button_power_save_config_t config = {
        .enter_power_save_cb = button_enter_power_save,
    };
    err |= iot_button_register_power_save_cb(&config);
#endif

    ESP_ERROR_CHECK(err);
}

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
   
    button_init(BOOT_BUTTON_NUM);

    //lv_demo_music();
    // lv_demo_widgets();
    //lv_demo_benchmark();

	// // 切换到显示测试界面
    // create_display_test_screen();
    // // 启动定时器以更新显示测试界面颜色
    // lv_timer_create((lv_timer_cb_t)update_display_test_screen, 1000, NULL);
	// 创建一个屏幕对象
    lv_obj_t *screen = lv_obj_create(NULL);

    // 设置背景颜色为白色
    lv_obj_set_style_bg_color(screen, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);

    xTaskCreate(lv_tick_task, "lv_tick_task", 1024*10, NULL, 1, NULL);
}
