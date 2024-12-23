/**
 * @file gt911.c
 * @brief GT911 Capacitive Touch Panel Controller Driver
 * @version 0.1
 * @date 2021-01-13
 * 
 * @copyright Copyright 2021 Espressif Systems (Shanghai) Co. Ltd.
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0

 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#include "CST3240.h"

static const char *TAG = "CST3240";

uint8_t CST3240_ADDR = 0x5A;

static i2c_bus_device_handle_t CST3240_handle = NULL;

esp_err_t CST3240_read_bytes(uint16_t reg_addr, size_t data_len, uint8_t *data)
{
    return i2c_bus_read_reg16(CST3240_handle, reg_addr, data_len, data);
}

esp_err_t CST3240_write_bytes(uint16_t reg_addr, size_t data_len, uint8_t *data)
{
    return i2c_bus_write_reg16(CST3240_handle, reg_addr, data_len, data);
}

esp_err_t CST3240_init(void)
{
   esp_err_t ret=ESP_OK;
   
    if (NULL != CST3240_handle) {
        return ESP_FAIL;
    }

    uint8_t temp[5] = {0};

	bsp_i2c_add_device(&CST3240_handle, CST3240_ADDR);

	vTaskDelay(pdMS_TO_TICKS(100));
	
    CST3240_write_bytes(0xD101,4,temp);
	CST3240_read_bytes(CST_PID_REG,4,temp);//读取产品ID  读取到3240

	if((temp[3]==0x32)&&(temp[2]==0x40)) ret = ESP_OK;
	else                                 ret = ESP_FAIL;
		
    if(ret == ESP_OK) ESP_LOGI(TAG, "CST3240 init ok");
    else ESP_LOGI(TAG, "CST3240 init fail");
    return ret;
}

static esp_err_t CST3240_get_touch_points_num(uint8_t *touch_points_num)
{
    uint8_t temp = 0;
    CST3240_read_bytes(CST_GSTID_REG, 1, &temp);
    if((temp&0XF)&&((temp&0XF)<6)){
        *touch_points_num = temp=0XFF<<(temp&0XF);
        // ESP_LOGI(TAG, "reg=0x%X num=%d", temp, *touch_points_num);
        return ESP_OK;
    }
    else {
        *touch_points_num = 0;
        return ESP_FAIL;
    }
}

esp_err_t CST3240_read_pos(uint8_t *touch_points_num, uint16_t *x, uint16_t *y)
{
    static uint8_t data[4];

    if(ESP_OK == CST3240_get_touch_points_num(touch_points_num))
    {
        if (0 == *touch_points_num) {
        } else {
            CST3240_read_bytes(CST_TP1_REG, 4, data);
			if(1)	//竖屏
			{
				*x=((uint16_t)data[0]<<4)+(((uint16_t)data[2]>>4)&0x0F);
				*y=(((uint16_t)data[1]<<4)+((uint16_t)data[2]&0x0f));
			}else //横屏
			{
				*y=((uint16_t)data[0]<<4)+(((uint16_t)data[2]>>4)&0x0F);
				*x=(((uint16_t)data[3]<<8)+data[2]);
			}  
        }

        data[0] = 0;
        CST3240_write_bytes(CST_GSTID_REG,1,&data[0]);//清标志 	
    }

    return ESP_OK;
}



