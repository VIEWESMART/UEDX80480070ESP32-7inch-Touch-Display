/*
* Copyright © 2021 Sturnus Inc.

* Permission is hereby granted, free of charge, to any person obtaining a copy of this
* software and associated documentation files (the “Software”), to deal in the Software
* without restriction, including without limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
* to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
* PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
* FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <esp_log.h>
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include "gt911.h"

#include "lvgl_i2c/i2c_manager.h"

#define TAG "GT911"

gt911_status_t gt911_status;

// TODO: 处理多字节读取并重构为一个读取事务
esp_err_t gt911_i2c_read(uint8_t slave_addr, uint16_t register_addr, uint8_t *data_buf, uint8_t len)
{
    return lvgl_i2c_read(CONFIG_LV_I2C_TOUCH_PORT, slave_addr, register_addr, data_buf, len);
}

/**
 * @brief  初始化通过 I2C 进行 GT911 通信
 * @param  dev_addr: 通信总线上的设备地址（GT911的I2C从地址）.
 * @retval None
 */
void gt911_init(uint8_t dev_addr)
{
    if (!gt911_status.inited)
    {
        gt911_status.i2c_dev_addr = dev_addr;
        uint8_t data_buf;
        esp_err_t ret;

        ESP_LOGI(TAG, "检查GT911触摸控制器");
        if ((ret = gt911_i2c_read(dev_addr, GT911_PRODUCT_ID1, &data_buf, 1) != ESP_OK))
        {
            ESP_LOGE(TAG, "从设备读取时出错: %s",
                     esp_err_to_name(ret)); // Only show error the first time
            return;
        }
        gt911_status.inited = true;
    }
}

/**
 * @brief  获取触摸屏 X 和 Y 位置值。忽略多点触控
 * @param  drv:
 * @param  data: 在此处存储数据
 * @retval Always false
 */
bool gt911_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    uint8_t touch_pnt_cnt;     // 检测到的触摸点数量
    static int16_t last_x = 0; // 12 位像素值
    static int16_t last_y = 0; // 12 位像素值
    uint8_t status_reg[15];
    gt911_i2c_read(gt911_status.i2c_dev_addr, GT911_STATUS_REG, &status_reg[0], 15);
    //    ESP_LOGI(TAG, "\tstatus: 0x%02x", status_reg);
    touch_pnt_cnt = status_reg[2];

    if (touch_pnt_cnt !=1)
    { // 忽略无触摸和多点触控
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
        return false;
    }
    last_x = (uint16_t)(((status_reg[3] & 0x0F) << 8) + status_reg[4]);
    last_y = (uint16_t)(((status_reg[5] & 0x0F) << 8) + status_reg[6]);
#if CONFIG_LV_GT911_INVERT_X
    last_x = gt911_status.max_x_coord - last_x;
#endif
#if CONFIG_LV_GT911_INVERT_Y
    last_y = gt911_status.max_y_coord - last_y;
#endif
#if CONFIG_LV_GT911_SWAPXY
    int16_t swap_buf = last_x;
    last_x = last_y;
    last_y = swap_buf;
#endif
    data->point.x = last_x;
    data->point.y = last_y;
    data->state = LV_INDEV_STATE_PR;
    ESP_LOGI(TAG, "X=%u Y=%u", data->point.x, data->point.y);
    ESP_LOGV(TAG, "X=%u Y=%u", data->point.x, data->point.y); 
return false;
}
