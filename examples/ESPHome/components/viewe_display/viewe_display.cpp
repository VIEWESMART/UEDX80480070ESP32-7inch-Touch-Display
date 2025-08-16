#include "viewe_display.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esp_heap_caps.h"
#include <cstring>

namespace esphome {
namespace viewe_display {

static const char *const TAG = "viewe_display";

void VieweDisplay::setup() {
  ESP_LOGCONFIG(TAG, "Setting up VIEWE Display...");
  
  // Initialize backlight pin if specified
  if (this->backlight_pin_ != GPIO_NUM_NC) {
    gpio_config_t bk_gpio_config = {
      .pin_bit_mask = 1ULL << this->backlight_pin_,
      .mode = GPIO_MODE_OUTPUT,
      .pull_up_en = GPIO_PULLUP_DISABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&bk_gpio_config);
  }
  
  // Initialize LCD panel
  this->init_lcd_panel_();
  
  // Allocate display buffer in PSRAM
  this->init_internal_(this->get_buffer_length_());
  
  if (this->buffer_ == nullptr) {
    ESP_LOGE(TAG, "Failed to allocate display buffer");
    this->mark_failed();
    return;
  }
  
  // Apply initial brightness setting
  this->set_brightness(this->brightness_);
  
  ESP_LOGCONFIG(TAG, "VIEWE Display setup complete");
}

void VieweDisplay::loop() {
  // Update display if needed
  this->do_update_();
}

void VieweDisplay::update() {
  // Called periodically by ESPHome
  this->update_display_();
}

void VieweDisplay::dump_config() {
  ESP_LOGCONFIG(TAG, "VIEWE Display:");
  ESP_LOGCONFIG(TAG, "  Width: %d", DISPLAY_WIDTH);
  ESP_LOGCONFIG(TAG, "  Height: %d", DISPLAY_HEIGHT);
  ESP_LOGCONFIG(TAG, "  Color Mode: RGB565");
  ESP_LOGCONFIG(TAG, "  Backlight Pin: %s", 
                this->backlight_pin_ != GPIO_NUM_NC ? std::to_string(this->backlight_pin_).c_str() : "None");
  ESP_LOGCONFIG(TAG, "  Brightness: %.0f%%", this->brightness_ * 100);
}

void VieweDisplay::init_lcd_panel_() {
  ESP_LOGD(TAG, "Initializing RGB LCD panel...");
  
  esp_lcd_rgb_panel_config_t panel_config = {};
  panel_config.clk_src = LCD_CLK_SRC_PLL160M;
  panel_config.psram_trans_align = 64;
  panel_config.data_width = 16;
  panel_config.bits_per_pixel = 16;
  panel_config.de_gpio_num = LCD_GPIO_DE;
  panel_config.pclk_gpio_num = LCD_GPIO_PCLK;
  panel_config.vsync_gpio_num = LCD_GPIO_VSYNC;
  panel_config.hsync_gpio_num = LCD_GPIO_HSYNC;
  panel_config.disp_gpio_num = GPIO_NUM_NC;
  
  panel_config.data_gpio_nums[0] = LCD_GPIO_DATA0;
  panel_config.data_gpio_nums[1] = LCD_GPIO_DATA1;
  panel_config.data_gpio_nums[2] = LCD_GPIO_DATA2;
  panel_config.data_gpio_nums[3] = LCD_GPIO_DATA3;
  panel_config.data_gpio_nums[4] = LCD_GPIO_DATA4;
  panel_config.data_gpio_nums[5] = LCD_GPIO_DATA5;
  panel_config.data_gpio_nums[6] = LCD_GPIO_DATA6;
  panel_config.data_gpio_nums[7] = LCD_GPIO_DATA7;
  panel_config.data_gpio_nums[8] = LCD_GPIO_DATA8;
  panel_config.data_gpio_nums[9] = LCD_GPIO_DATA9;
  panel_config.data_gpio_nums[10] = LCD_GPIO_DATA10;
  panel_config.data_gpio_nums[11] = LCD_GPIO_DATA11;
  panel_config.data_gpio_nums[12] = LCD_GPIO_DATA12;
  panel_config.data_gpio_nums[13] = LCD_GPIO_DATA13;
  panel_config.data_gpio_nums[14] = LCD_GPIO_DATA14;
  panel_config.data_gpio_nums[15] = LCD_GPIO_DATA15;
  
  // Timing parameters for 800x480 display
  panel_config.timings.pclk_hz = 15 * 1000 * 1000;  // 15MHz pixel clock
  panel_config.timings.h_res = DISPLAY_WIDTH;
  panel_config.timings.v_res = DISPLAY_HEIGHT;
  panel_config.timings.hsync_pulse_width = 48;
  panel_config.timings.hsync_back_porch = 40;
  panel_config.timings.hsync_front_porch = 88;
  panel_config.timings.vsync_pulse_width = 6;
  panel_config.timings.vsync_back_porch = 26;
  panel_config.timings.vsync_front_porch = 30;
  panel_config.timings.flags.pclk_active_neg = true;
  panel_config.timings.flags.de_idle_high = false;
  panel_config.timings.flags.pclk_idle_high = false;
  
  // Use PSRAM for framebuffer
  panel_config.flags.fb_in_psram = true;
  panel_config.flags.double_fb = false;
  panel_config.flags.no_fb = false;
  panel_config.flags.bb_invalidate_cache = false;
  
  // Configure bounce buffer for better performance
  panel_config.bounce_buffer_size_px = DISPLAY_WIDTH * 10;  // 10 lines bounce buffer
  
  esp_err_t ret = esp_lcd_new_rgb_panel(&panel_config, &this->lcd_panel_);
  if (ret != ESP_OK) {
    ESP_LOGE(TAG, "Failed to create RGB panel: %s", esp_err_to_name(ret));
    this->mark_failed();
    return;
  }
  
  ret = esp_lcd_panel_init(this->lcd_panel_);
  if (ret != ESP_OK) {
    ESP_LOGE(TAG, "Failed to initialize RGB panel: %s", esp_err_to_name(ret));
    this->mark_failed();
    return;
  }
  
  ESP_LOGD(TAG, "RGB LCD panel initialized successfully");
}

void VieweDisplay::draw_absolute_pixel_internal(int x, int y, Color color) {
  if (x < 0 || x >= this->get_width_internal() || y < 0 || y >= this->get_height_internal()) {
    return;
  }
  
  if (this->buffer_ == nullptr) {
    ESP_LOGE(TAG, "Buffer not initialized");
    return;
  }
  
  // Convert to RGB565
  uint16_t rgb565 = display::ColorUtil::color_to_565(color);
  
  // Calculate buffer position (RGB565 = 2 bytes per pixel)
  size_t pos = (y * this->get_width_internal() + x) * 2;
  
  // Write to buffer (little endian)
  this->buffer_[pos] = rgb565 & 0xFF;
  this->buffer_[pos + 1] = (rgb565 >> 8) & 0xFF;
}

void VieweDisplay::update_display_() {
  if (this->lcd_panel_ == nullptr || this->buffer_ == nullptr) {
    return;
  }
  
  // Draw the buffer to the LCD
  esp_err_t ret = esp_lcd_panel_draw_bitmap(
    this->lcd_panel_,
    0, 0,  // Start position
    this->get_width_internal(), this->get_height_internal(),  // End position
    this->buffer_
  );
  
  if (ret != ESP_OK) {
    ESP_LOGE(TAG, "Failed to draw bitmap: %s", esp_err_to_name(ret));
  }
}

void VieweDisplay::set_brightness(float brightness) {
  this->brightness_ = clamp(brightness, 0.0f, 1.0f);
  
  if (this->backlight_pin_ == GPIO_NUM_NC) {
    return;  // No backlight pin configured
  }
  
  if (this->brightness_ > 0) {
    gpio_set_level(static_cast<gpio_num_t>(this->backlight_pin_), 1);
    // TODO: Implement PWM brightness control for variable brightness
  } else {
    gpio_set_level(static_cast<gpio_num_t>(this->backlight_pin_), 0);
  }
}

}  // namespace viewe_display
}  // namespace esphome