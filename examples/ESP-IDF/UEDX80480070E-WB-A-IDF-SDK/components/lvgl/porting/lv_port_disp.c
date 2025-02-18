/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 0

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "../../lvgl.h"
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/
static const char *TAG = "lv_port_disp";
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/
// we use two semaphores to sync the VSYNC event and the LVGL task, to avoid potential tearing effect
#if CONFIG_EXAMPLE_AVOID_TEAR_EFFECT_WITH_SEM
SemaphoreHandle_t sem_vsync_end;
SemaphoreHandle_t sem_gui_ready;
#endif

/**********************
 *      MACROS
 **********************/
static bool rgb_on_vsync_event(esp_lcd_panel_handle_t panel, const esp_lcd_rgb_panel_event_data_t *event_data, void *user_data);
static void lvgl_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *color_map);


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    static lv_display_t *disp; // contains callback functions

#if CONFIG_EXAMPLE_AVOID_TEAR_EFFECT_WITH_SEM
    /* Create semaphores */
    sem_vsync_end = xSemaphoreCreateBinary();
    assert(sem_vsync_end);
    sem_gui_ready = xSemaphoreCreateBinary();
    assert(sem_gui_ready);
#endif

    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << GPIO_LCD_BL};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_LOGI(TAG, "Install RGB LCD panel driver");
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_rgb_panel_config_t panel_config = {
        .data_width = 16, // RGB565 in parallel mode, thus 16bit in width
        .psram_trans_align = 64,
#if CONFIG_EXAMPLE_USE_BOUNCE_BUFFER
        .bounce_buffer_size_px = 10 * LCD_WIDTH,
#endif
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .disp_gpio_num = GPIO_NUM_NC,
        .pclk_gpio_num = GPIO_LCD_PCLK,
        .vsync_gpio_num = GPIO_LCD_VSYNC,
        .hsync_gpio_num = GPIO_LCD_HSYNC,
        .de_gpio_num = GPIO_LCD_DE,
        .data_gpio_nums = {
            GPIO_LCD_B0,
            GPIO_LCD_B1,
            GPIO_LCD_B2,
            GPIO_LCD_B3,
            GPIO_LCD_B4,
            GPIO_LCD_G0,
            GPIO_LCD_G1,
            GPIO_LCD_G2,
            GPIO_LCD_G3,
            GPIO_LCD_G4,
            GPIO_LCD_G5,
            GPIO_LCD_R0,
            GPIO_LCD_R1,
            GPIO_LCD_R2,
            GPIO_LCD_R3,
            GPIO_LCD_R4,
        },
        .timings = {
            .h_res = LCD_WIDTH, .v_res = LCD_HEIGHT,
    // The following parameters should refer to LCD spec
            .pclk_hz = 15 * 1000 * 1000,
            .hsync_back_porch = 42,
            .hsync_front_porch = 20,
            .hsync_pulse_width = 1,
            .vsync_back_porch = 12,
            .vsync_front_porch = 4,
            .vsync_pulse_width = 10,

			.flags.pclk_active_neg = true,


        },
        .flags.fb_in_psram = true, // allocate frame buffer in PSRAM
#if CONFIG_EXAMPLE_DOUBLE_FB
        .flags.double_fb = true, // allocate double frame buffer
#endif                           // CONFIG_EXAMPLE_DOUBLE_FB
    };
    ESP_LOGI(TAG, "Before esp_lcd_new_rgb_panel");
    ESP_ERROR_CHECK(esp_lcd_new_rgb_panel(&panel_config, &panel_handle));
    ESP_LOGI(TAG, "After esp_lcd_new_rgb_panel");

    /* Register event callbacks */
    esp_lcd_rgb_panel_event_callbacks_t cbs = {
        .on_vsync = rgb_on_vsync_event,
    };
     ESP_ERROR_CHECK(esp_lcd_rgb_panel_register_event_callbacks(panel_handle, &cbs, disp));

    /* Initialize RGB LCD panel */
    ESP_LOGI(TAG, "Before esp_lcd_panel_reset");
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_LOGI(TAG, "After esp_lcd_panel_reset");

    ESP_LOGI(TAG, "Before esp_lcd_panel_init");
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_LOGI(TAG, "After esp_lcd_panel_init");
    ESP_LOGI(TAG, "LCD panel initialized successfully");

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(GPIO_LCD_BL, 1);
    ESP_LOGI(TAG, "LCD resolution: %dx%d", LCD_WIDTH, LCD_HEIGHT);

    /* Create and configure LVGL display */
    disp = lv_display_create(LCD_WIDTH, LCD_HEIGHT);
    ESP_LOGI(TAG, " create display");
    lv_display_set_flush_cb(disp, &lvgl_flush_cb);
    ESP_LOGI(TAG, "used lvgl_flush_cb");

    /* initialize LVGL draw buffers */
    // static lv_display_draw_buf_t disp_buf;
    // void *buf1 = NULL;
    // void *buf2 = NULL;
    static lv_color_t buf1[LCD_WIDTH*10];
    static lv_color_t buf2[LCD_HEIGHT*10];
    uint16_t fact = 120;
#if CONFIG_EXAMPLE_DOUBLE_FB
    ESP_LOGI(TAG, "Use frame buffers as LVGL draw buffers");
    ESP_ERROR_CHECK(esp_lcd_rgb_panel_get_frame_buffer(panel_handle, 2, &buf1, &buf2));
    ESP_LOGI(TAG, "get frame buffers successfully");
    // initialize LVGL draw buffers
    lv_display_set_buffers(disp, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_FULL);
    ESP_LOGI(TAG, "set buffers successfully");
    // lv_display_draw_buf_init(&disp_buf, buf1, buf2, LCD_WIDTH * LCD_HEIGHT);
#endif
    // ESP_LOGI(TAG, "set user data");
    // lv_display_set_user_data(disp, &panel_handle);
    // ESP_LOGI(TAG, "set data successfully");
// #else
    // ESP_LOGI(TAG, "Allocate separate LVGL draw buffers from PSRAM");
    // if (esp_psram_is_initialized()) {
    // ESP_LOGI(TAG, "PSRAM initialized successfully");
    // } else {
    //     ESP_LOGE(TAG, "PSRAM initialization failed");
    // }
    // buf1 = heap_caps_malloc(LCD_WIDTH * fact * sizeof(lv_color_t), MALLOC_CAP_SPIRAM); // MALLOC_CAP_SPIRAM
    // assert(buf1);
    // buf2 = heap_caps_malloc(LCD_WIDTH * fact * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    // assert(buf2);

    // if (buf1 == NULL || buf2 == NULL) {
    // ESP_LOGE(TAG, "Failed to allocate frame buffer in PSRAM");
    // return;
    // }
    // initialize LVGL draw buffers
    // lv_display_draw_buf_init(&disp_buf, buf1, buf2, LCD_WIDTH * fact);
    // lv_display_set_buffers(disp, buf1, buf2, LCD_WIDTH * fact * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_FULL);

    // lv_disp_draw_buf_init(&disp_buf, buf1, NULL, LCD_WIDTH * fact);

// #endif // CONFIG_EXAMPLE_DOUBLE_FB

    
    // lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    // lv_display_set_buffers(disp, buf1, buf2, LCD_WIDTH * fact * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_FULL);
//     lv_display_set_buffers(disp, buf1, buf2, LCD_WIDTH * LCD_HEIGHT,LV_DISPLAY_RENDER_MODE_FULL);
//     ESP_LOGI(TAG, "set buffers successfully");

//     ESP_LOGI(TAG, "display initialized successfully");

// #if CONFIG_EXAMPLE_DOUBLE_FB
//     lv_display_set_render_mode(disp, LV_DISPLAY_RENDER_MODE_FULL); // the full_refresh mode can maintain the synchronization between the two frame buffers
// #endif

    /*Finally register the driver*/
    // lv_display_drv_register(&disp);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static bool rgb_on_vsync_event(esp_lcd_panel_handle_t panel, const esp_lcd_rgb_panel_event_data_t *event_data, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;
#if CONFIG_EXAMPLE_AVOID_TEAR_EFFECT_WITH_SEM
    if (xSemaphoreTakeFromISR(sem_gui_ready, &high_task_awoken) == pdTRUE)
    {
        xSemaphoreGiveFromISR(sem_vsync_end, &high_task_awoken);
    }
#endif
    return high_task_awoken == pdTRUE;
}

static void lvgl_flush_cb(lv_display_t *drv, const lv_area_t *area, uint8_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)lv_display_get_user_data(drv);
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;

    // lv_draw_sw_rgb565_swap(color_map, lv_area_get_width(area) * lv_area_get_height(area));
#if CONFIG_EXAMPLE_AVOID_TEAR_EFFECT_WITH_SEM
    xSemaphoreGive(sem_gui_ready);
    xSemaphoreTake(sem_vsync_end, portMAX_DELAY);
#endif
    // pass the draw buffer to the driver
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
    ESP_LOGI("LVGL_DEBUG", "Flushing area: (%d, %d) to (%d, %d)", (int)area->x1, (int)area->y1, (int)area->x2, (int)area->y2);

    lv_display_flush_ready(drv);
   
}

/**
 * @brief Task to generate ticks for LVGL.
 *
 * @param pvParam Not used.
 */
static void lv_tick_inc_cb(void *data)
{
    uint32_t tick_inc_period_ms = *((uint32_t *)data);

    lv_tick_inc(tick_inc_period_ms);
}

/**
 * @brief Create tick task for LVGL.
 *
 * @return esp_err_t
 */
esp_err_t lv_port_tick_init(void)
{
    static const uint32_t tick_inc_period_ms = 2;
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = lv_tick_inc_cb,
        .arg = &tick_inc_period_ms,
        // .dispatch_method = ESP_TIMER_TASK,
        .name = "lvgl_tick", /* name is optional, but may help identify the timer when debugging */
                             // .skip_unhandled_events = true,
    };

    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    /* The timer has been created but is not running yet. Start the timer now */
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, tick_inc_period_ms * 1000));

    return ESP_OK;
}

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    if(disp_flush_enabled) {
        /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

        int32_t x;
        int32_t y;
        for(y = area->y1; y <= area->y2; y++) {
            for(x = area->x1; x <= area->x2; x++) {
                /*Put a pixel to the display. For example:*/
                /*put_px(x, y, *px_map)*/
                px_map++;
            }
        }
    }

    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_display_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
