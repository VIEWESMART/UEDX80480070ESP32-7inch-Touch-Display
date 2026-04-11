#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"
#include "esphome/core/defines.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "driver/gpio.h"

namespace esphome {
namespace viewe_display {

// Display dimensions
static const uint16_t DISPLAY_WIDTH = 800;
static const uint16_t DISPLAY_HEIGHT = 480;
static const uint8_t BITS_PER_PIXEL = 16;  // RGB565

class VieweDisplay : public display::DisplayBuffer {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void update() override;
  float get_setup_priority() const override { return setup_priority::HARDWARE; }
  
  void set_backlight_pin(uint8_t pin) { this->backlight_pin_ = pin; }
  void set_brightness(float brightness);
  
  display::DisplayType get_display_type() override { return display::DisplayType::DISPLAY_TYPE_COLOR; }

 protected:
  void draw_absolute_pixel_internal(int x, int y, Color color) override;
  int get_height_internal() override { return DISPLAY_HEIGHT; }
  int get_width_internal() override { return DISPLAY_WIDTH; }
  size_t get_buffer_length_() { return DISPLAY_WIDTH * DISPLAY_HEIGHT * (BITS_PER_PIXEL / 8); }
  
  void init_lcd_panel_();
  void update_display_();
  
  esp_lcd_panel_handle_t lcd_panel_ = nullptr;
  uint8_t backlight_pin_ = GPIO_NUM_NC;  // Default to no pin configured
  float brightness_ = 1.0f;
  
  // Pin definitions matching the hardware
  static constexpr uint8_t LCD_GPIO_VSYNC = GPIO_NUM_41;
  static constexpr uint8_t LCD_GPIO_HSYNC = GPIO_NUM_39;
  static constexpr uint8_t LCD_GPIO_DE = GPIO_NUM_40;
  static constexpr uint8_t LCD_GPIO_PCLK = GPIO_NUM_42;
  
  // Data pins
  static constexpr uint8_t LCD_GPIO_DATA0 = GPIO_NUM_8;
  static constexpr uint8_t LCD_GPIO_DATA1 = GPIO_NUM_3;
  static constexpr uint8_t LCD_GPIO_DATA2 = GPIO_NUM_46;
  static constexpr uint8_t LCD_GPIO_DATA3 = GPIO_NUM_9;
  static constexpr uint8_t LCD_GPIO_DATA4 = GPIO_NUM_1;
  static constexpr uint8_t LCD_GPIO_DATA5 = GPIO_NUM_5;
  static constexpr uint8_t LCD_GPIO_DATA6 = GPIO_NUM_6;
  static constexpr uint8_t LCD_GPIO_DATA7 = GPIO_NUM_7;
  static constexpr uint8_t LCD_GPIO_DATA8 = GPIO_NUM_15;
  static constexpr uint8_t LCD_GPIO_DATA9 = GPIO_NUM_16;
  static constexpr uint8_t LCD_GPIO_DATA10 = GPIO_NUM_4;
  static constexpr uint8_t LCD_GPIO_DATA11 = GPIO_NUM_45;
  static constexpr uint8_t LCD_GPIO_DATA12 = GPIO_NUM_48;
  static constexpr uint8_t LCD_GPIO_DATA13 = GPIO_NUM_47;
  static constexpr uint8_t LCD_GPIO_DATA14 = GPIO_NUM_21;
  static constexpr uint8_t LCD_GPIO_DATA15 = GPIO_NUM_14;
};

}  // namespace viewe_display
}  // namespace esphome