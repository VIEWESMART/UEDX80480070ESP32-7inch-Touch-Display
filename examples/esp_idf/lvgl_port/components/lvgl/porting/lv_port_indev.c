/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 0

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "../../lvgl.h"
/*********************
 *      DEFINES
 *********************/
static const char *TAG = "lv_port_indev";

esp_err_t ctpfalg=-1;

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_t * indev, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(int32_t * x, int32_t * y);

static void mouse_init(void);
static void mouse_read(lv_indev_t * indev, lv_indev_data_t * data);
static bool mouse_is_pressed(void);
static void mouse_get_xy(int32_t * x, int32_t * y);

static void keypad_init(void);
static void keypad_read(lv_indev_t * indev, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);

static void encoder_init(void);
static void encoder_read(lv_indev_t * indev, lv_indev_data_t * data);
static void encoder_handler(void);

static void button_init(void);
static void button_read(lv_indev_t * indev, lv_indev_data_t * data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
lv_indev_t * indev_button;

static int32_t encoder_diff;
static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    touchpad_init();

    /*Register a touchpad input device*/
    indev_touchpad = lv_indev_create();
    lv_indev_set_type(indev_touchpad, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev_touchpad, touchpad_read);

#if 0
    /*------------------
     * Mouse
     * -----------------*/

    /*Initialize your mouse if you have*/
    mouse_init();

    /*Register a mouse input device*/
    indev_mouse = lv_indev_create();
    lv_indev_set_type(indev_mouse, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev_mouse, mouse_read);

    /*Set cursor. For simplicity set a HOME symbol now.*/
    lv_obj_t * mouse_cursor = lv_image_create(lv_screen_active());
    lv_image_set_src(mouse_cursor, LV_SYMBOL_HOME);
    lv_indev_set_cursor(indev_mouse, mouse_cursor);

    /*------------------
     * Keypad
     * -----------------*/

    /*Initialize your keypad or keyboard if you have*/
    keypad_init();

    /*Register a keypad input device*/
    indev_keypad = lv_indev_create();
    lv_indev_set_type(indev_keypad, LV_INDEV_TYPE_KEYPAD);
    lv_indev_set_read_cb(indev_keypad, keypad_read);

    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_keypad, group);`*/

    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    encoder_init();

    /*Register a encoder input device*/
    indev_encoder = lv_indev_create();
    lv_indev_set_type(indev_encoder, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(indev_touchpad, encoder_read);

    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_encoder, group);`*/

    /*------------------
     * Button
     * -----------------*/

    /*Initialize your button if you have*/
    button_init();

    /*Register a button input device*/
    indev_button = lv_indev_create();
    lv_indev_set_type(indev_button, LV_INDEV_TYPE_BUTTON);
    lv_indev_set_read_cb(indev_button, button_read);

    /*Assign buttons to points on the screen*/
    static const lv_point_t btn_points[2] = {
        {10, 10},   /*Button 0 -> x:10; y:10*/
        {40, 100},  /*Button 1 -> x:40; y:100*/
    };
    lv_indev_set_button_points(indev_button, btn_points);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
static void touchpad_init(void)
{
    /*Your code comes here*/
    if(gt911_init() == ESP_OK)
	{
		ctpfalg=GT911;
		
	}else if(CST3240_init() == ESP_OK)
	{
		ctpfalg=CST3240;

	}else if(FT62XX_init() == ESP_OK)
	{
       ctpfalg=FT62XX;
	}
}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static int32_t last_x = 0;
    static int32_t last_y = 0;

    /*Save the pressed coordinates and the state*/
    if(touchpad_is_pressed()) {
        touchpad_get_xy(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
    data->point.x = last_x;
    data->point.y = last_y;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/
    uint8_t temp = 0;

	if(ctpfalg==GT911)
	{
	    gt911_read_bytes(GT_GSTID_REG, 1, &temp);

		//////]ESP_LOGI(TAG, "temp=0x%X",temp);
		 
	    if (temp & 0x80) {
	        if(temp & 0x0F){
	            return true;            
	        }
	        temp = 0;
	        gt911_write_bytes(GT_GSTID_REG, 1, &temp);
	    }
	    return false;
	}
	else if(ctpfalg==FT62XX)
	{
	    FT62XX_read_bytes(FT_REG_NUM_FINGER, 1, &temp);
	    if ((temp&0XF)&&((temp&0XF)<6)) {
	        if(temp&0XF){
	            return true;            
	        }
	    }
         return false;
	}
	else if(ctpfalg==CST3240)
	{
		
		CST3240_read_bytes(CST_GSTID_REG, 1, &temp);
		//ESP_LOGI(TAG, "temp=0x%X",temp);
		
		if((temp&0XF)&&((temp&0XF)<6)) {
			if(temp&0XF){
				return true;			
			}
		}
		return false;
	}

    return false;
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/
    if(ctpfalg==GT911)
	{
	    uint8_t data[4];

	    gt911_read_bytes(GT_TP1_REG, 4, data);
	    *x = ((data[1] & 0x0f) << 8) + data[0];
	    *y = ((data[3] & 0x0f) << 8) + data[2];
	    //ESP_LOGI(TAG, "x=%d, y=%d",*x, *y);

	    data[0] = 0;
	    gt911_write_bytes(GT_GSTID_REG, 1, data);
	}
	else if(ctpfalg==FT62XX)
	{

	    uint8_t buf[4];
		uint16_t ctpx[5]; 		 
		uint16_t xtpy[5];

		//读取XY坐标值 
		FT62XX_read_bytes(0x03,1,&buf[0]);
		xtpy[0] = (int16_t)(buf[0] & 0x0F)<<8;
		FT62XX_read_bytes(0x04,1,&buf[1]);
		xtpy[0]|= (int16_t)buf[1];
		
		FT62XX_read_bytes(0x05,1,&buf[2]);
		ctpx[0] = (int16_t)(buf[2] & 0x0F)<<8;
		FT62XX_read_bytes(0x06,1,&buf[3]);
		ctpx[0]|= (int16_t)buf[3];
			
	    *y = ctpx[0];
	    *x = xtpy[0];
				
	    //ESP_LOGI(TAG, "x=0x%X, y=%d",*x, *y);
	}
	else if(ctpfalg==CST3240)
	{
	    static uint8_t data[4];

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

		//ESP_LOGI(TAG, "x=%d, y=%d",*x, *y);
		
		data[0] = 0;
	    CST3240_write_bytes(CST_GSTID_REG,1,data);//清标志 	
	}
}

/*------------------
 * Mouse
 * -----------------*/

/*Initialize your mouse*/
static void mouse_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the mouse*/
static void mouse_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    /*Get the current x and y coordinates*/
    mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the mouse button is pressed or released*/
    if(mouse_is_pressed()) {
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
}

/*Return true is the mouse button is pressed*/
static bool mouse_is_pressed(void)
{
    /*Your code comes here*/

    return false;
}

/*Get the x and y coordinates if the mouse is pressed*/
static void mouse_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/

    (*x) = 0;
    (*y) = 0;
}

/*------------------
 * Keypad
 * -----------------*/

/*Initialize your keypad*/
static void keypad_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get the current x and y coordinates*/
    mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
            case 1:
                act_key = LV_KEY_NEXT;
                break;
            case 2:
                act_key = LV_KEY_PREV;
                break;
            case 3:
                act_key = LV_KEY_LEFT;
                break;
            case 4:
                act_key = LV_KEY_RIGHT;
                break;
            case 5:
                act_key = LV_KEY_ENTER;
                break;
        }

        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/

    return 0;
}

/*------------------
 * Encoder
 * -----------------*/

/*Initialize your encoder*/
static void encoder_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{

    data->enc_diff = encoder_diff;
    data->state = encoder_state;
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    /*Your code comes here*/

    encoder_diff += 0;
    encoder_state = LV_INDEV_STATE_REL;
}

/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
static void button_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for(i = 0; i < 2; i++) {
        /*Return the pressed button's ID*/
        if(button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id)
{

    /*Your code comes here*/

    return false;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
