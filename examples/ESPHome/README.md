# ESPHome Custom Component for VIEWE 7-inch Display

This is a custom ESPHome component for the VIEWE UEDX80480070E-WB-A 7-inch 800x480 RGB display with ESP32-S3. I tried using  RPI_DPI_RGB configuration which worked except I couldn't get it to display more than 16 colours

Also maintained here https://github.com/jtbnz/esphome_UEDX80480070ESP32

## Features

- Native RGB565 display driver for 800x480 resolution
- Hardware-accelerated rendering using ESP32-S3 LCD peripheral
- PSRAM framebuffer support for smooth graphics
- Backlight control
- Compatible with ESPHome's display API for drawing shapes, text, and images
- Touch support through ESPHome's existing GT911 component
- Claude code assisted development

## Installation

### Option 1: Use from GitHub (Recommended)

Add this to your ESPHome configuration:

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/jtbnz/esphome_UEDX80480070ESP32
      ref: main
    components: [viewe_display]
```

### Option 2: Local Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/jtbnz/esphome_UEDX80480070ESP32.git
   ```

2. Copy the components folder to your ESPHome configuration:
   ```bash
   cp -r esphome_UEDX80480070ESP32/components/viewe_display /config/esphome/custom_components/
   ```

3. Reference it locally in your YAML:
   ```yaml
   external_components:
     - source:
         type: local
         path: custom_components
       components: [viewe_display]
   ```

## Hardware Specifications

- **MCU**: ESP32-S3-N16R8 (16MB Flash, 8MB PSRAM)
- **Display**: 7-inch IPS, 800x480 pixels, RGB interface
- **Touch**: GT911 capacitive touch controller (I2C)
- **Backlight**: GPIO2

## Pin Configuration (Hardcoded in Component)

### Display Pins
- **VSYNC**: GPIO41
- **HSYNC**: GPIO39
- **DE**: GPIO40
- **PCLK**: GPIO42
- **Data pins**: GPIO8,3,46,9,1,5,6,7,15,16,4,45,48,47,21,14 (R0-R4, G0-G5, B0-B4)
- **Backlight**: GPIO2 (configurable)

### Touch Pins (Configure in YAML)
- **SDA**: GPIO19
- **SCL**: GPIO20
- **INT**: GPIO18
- **RST**: GPIO38

## Basic Usage

```yaml
# Include the custom component from GitHub
external_components:
  - source:
      type: git
      url: https://github.com/jtbnz/esphome_UEDX80480070ESP32
      ref: main
    components: [viewe_display]

# Configure the display
display:
  - platform: viewe_display
    id: my_display
    backlight_pin: GPIO2
    brightness: 100%
    update_interval: 16ms
    lambda: |-
      // Draw on the display
      it.fill(Color(255, 255, 255));  // White background
      it.rectangle(50, 50, 200, 100, Color(255, 0, 0));  // Red rectangle
```

## API Reference

The component inherits from ESPHome's `DisplayBuffer` class, providing access to all standard drawing functions:

- `fill(color)` - Fill entire screen
- `rectangle(x, y, width, height, color)` - Draw rectangle
- `filled_rectangle(x, y, width, height, color)` - Draw filled rectangle
- `circle(x, y, radius, color)` - Draw circle
- `filled_circle(x, y, radius, color)` - Draw filled circle
- `line(x1, y1, x2, y2, color)` - Draw line
- `print(x, y, font, text)` - Draw text (requires font configuration)
- `image(x, y, image_id)` - Draw image (requires image configuration)

## Advanced Features

### Multi-Page Support
```yaml
display:
  - platform: viewe_display
    id: my_display
    pages:
      - id: page1
        lambda: |-
          it.fill(Color(255, 255, 255));
          // Page 1 content
      - id: page2
        lambda: |-
          it.fill(Color(200, 200, 200));
          // Page 2 content
```

### Touch Integration
```yaml
touchscreen:
  platform: gt911
  id: my_touchscreen
  i2c_id: touch_i2c

display:
  - platform: viewe_display
    lambda: |-
      if (id(my_touchscreen).touched) {
        auto touch = id(my_touchscreen).touches[0];
        it.filled_circle(touch.x, touch.y, 20, Color(255, 0, 255));
      }
```

### Backlight Control
```yaml
light:
  - platform: monochromatic
    name: "Display Backlight"
    output: backlight_output

output:
  - platform: ledc
    pin: GPIO2
    id: backlight_output
```

## Performance Considerations

1. **PSRAM Usage**: The framebuffer is allocated in PSRAM for better performance
2. **Update Interval**: Default 16ms (60 FPS), adjust based on needs
3. **Bounce Buffer**: Configured for 10 lines to optimize DMA transfers
4. **Color Format**: RGB565 (16-bit) for memory efficiency

## Troubleshooting

1. **Display not working**: 
   - Check ESP-IDF version (requires 5.1+)
   - Verify PSRAM is enabled in sdkconfig
   - Check power supply (needs stable 5V/1A)

2. **Touch not responding**:
   - Verify I2C connections
   - Check pull-up resistors on SDA/SCL
   - Try reducing I2C frequency

3. **Graphics artifacts**:
   - Ensure proper timing parameters
   - Check PSRAM configuration
   - Reduce update frequency if needed

## Limitations

- Pin configuration is hardcoded (matches VIEWE hardware)
- RGB565 color format only
- No rotation support in current version


## Future Improvements

- [ ] Add rotation support
- [ ] Dynamic pin configuration
- [ ] DMA optimization
- [ ] Power management features

## License

This component is provided as-is for use with VIEWE display hardware.