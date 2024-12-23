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

#include "FT62XX.h"

static const char *TAG = "FT62XX";

uint8_t FT62XX_ADDR=0x38;

static i2c_bus_device_handle_t FT62XX_handle = NULL;

esp_err_t FT62XX_read_bytes(uint16_t reg_addr, size_t data_len, uint8_t *data)
{
    return i2c_bus_read_bytes(FT62XX_handle, reg_addr, data_len, data);
}

esp_err_t FT62XX_write_bytes(uint16_t reg_addr, size_t data_len, uint8_t *data)
{
    return i2c_bus_write_bytes(FT62XX_handle, reg_addr, data_len, data);
} 

esp_err_t FT62XX_init(void)
{

    if (NULL != FT62XX_handle) {
        return ESP_FAIL;
    }

    uint8_t temp[2] = {0};
	esp_err_t ret=ESP_OK;

    bsp_i2c_add_device(&FT62XX_handle, FT62XX_ADDR);

    temp[0]=0;
	FT62XX_write_bytes(FT_DEVIDE_MODE,1,temp);	//进入正常操作模式 
	FT62XX_write_bytes(FT_ID_G_MODE,1,temp);    //查询模式 
	temp[0]=22;								    //触摸有效值，22，越小越灵敏	
	FT62XX_write_bytes(FT_ID_G_THGROUP,1,temp);	//设置触摸有效值
	temp[0]=12;								    //激活周期，不能小于12，最大14
	FT62XX_write_bytes(FT_ID_G_PERIODACTIVE,1,temp); 
	//读取版本号，参考值：0x3003
	FT62XX_read_bytes(FT_ID_G_LIB_VERSION,2,&temp[0]);  

	ESP_LOGI(TAG, "FT62XX ID=%X",temp[0]);
	
    vTaskDelay(pdMS_TO_TICKS(10));

    if(ret == ESP_OK) ESP_LOGI(TAG, "FT62XX init ok");
    else ESP_LOGI(TAG, "FT62XX init fail");
    return ret;
}

static esp_err_t FT62XX_get_touch_points_num(uint8_t *touch_points_num)
{
    uint8_t temp = 0;
    FT62XX_read_bytes(FT_REG_NUM_FINGER, 1, &temp);
    if((temp&0XF)&&((temp&0XF)<6)) {
        *touch_points_num = 0XFF<<(temp&0XF);
         ESP_LOGI(TAG, "reg=0x%X num=%d", temp, *touch_points_num);
        return ESP_OK;
    }
    else {
        *touch_points_num = 0;
        return ESP_FAIL;
    }
}

esp_err_t FT62XX_read_pos(uint8_t *touch_points_num, uint16_t *x, uint16_t *y)
{
    static uint8_t buf[4];
	uint16_t ctpx[5]; 		 
	uint16_t xtpy[5];

    if(ESP_OK == FT62XX_get_touch_points_num(touch_points_num))
    {
        if (0 == *touch_points_num) {
        } else {
            //读取XY坐标值 
			FT62XX_read_bytes(0x03,1,&buf[0]);
			xtpy[0] = (int16_t)(buf[0] & 0x0F)<<8;
			FT62XX_read_bytes(0x04,1,&buf[1]);
			xtpy[0]|= (int16_t)buf[1];
			
			FT62XX_read_bytes(0x05,1,&buf[2]);
			ctpx[0] = (int16_t)(buf[2] & 0x0F)<<8;
			FT62XX_read_bytes(0x06,1,&buf[3]);
			ctpx[0]|= (int16_t)buf[3];
				
            *x = ctpx[0];
            *y = xtpy[0];
             ESP_LOGI(TAG, "x=0x%X, y=%d",*x, *y);
        }

       // buf[0] = 0;
       // FT62XX_write_bytes(GT_GSTID_REG, 1, data);
    }

    return ESP_OK;
}



