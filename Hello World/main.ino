#include <LovyanGFX.hpp>

#define LGFX_USE_V1

// Define the LGFX class inline (was previously in LGFX_WT32_SC01_PLUS.hpp)
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_Parallel8 _bus_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance;

public:
  LGFX(void) {
    { // Bus configuration
      auto cfg = _bus_instance.config();
      cfg.freq_write = 40000000;
      cfg.pin_wr = 47;
      cfg.pin_rd = -1;
      cfg.pin_rs = 0;
      cfg.pin_d0 = 9;
      cfg.pin_d1 = 46;
      cfg.pin_d2 = 3;
      cfg.pin_d3 = 8;
      cfg.pin_d4 = 18;
      cfg.pin_d5 = 17;
      cfg.pin_d6 = 16;
      cfg.pin_d7 = 15;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }
    { // Panel configuration
      auto cfg = _panel_instance.config();
      cfg.pin_cs = -1;
      cfg.pin_rst = 4;
      cfg.pin_busy = -1;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.invert = true;
      _panel_instance.config(cfg);
    }
    { // Backlight configuration
      auto cfg = _light_instance.config();
      cfg.pin_bl = 45;
      cfg.invert = false;
      cfg.freq = 44100;
      cfg.pwm_channel = 7;
      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }
    { // Touch screen configuration
      auto cfg = _touch_instance.config();
      cfg.x_min = 0;
      cfg.x_max = 319;
      cfg.y_min = 0;
      cfg.y_max = 479;
      cfg.pin_int = 7;
      cfg.bus_shared = true;
      cfg.offset_rotation = 0;
      cfg.i2c_port = 1;
      cfg.i2c_addr = 0x38;
      cfg.pin_sda = 6;
      cfg.pin_scl = 5;
      cfg.freq = 400000;
      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }
    setPanel(&_panel_instance);
  }
};

// Global instance
static LGFX lcd;

void setup() {
  // Initialize the display
  lcd.init();
  
  // Set display rotation (0: portrait, 1: landscape)
  lcd.setRotation(1);

  // Clear the screen to black
  lcd.fillScreen(TFT_BLACK);

  // Set text properties
  lcd.setTextSize(3);
  lcd.setTextColor(TFT_WHITE);
  lcd.setTextDatum(textdatum_t::middle_center);

  // Display "Hello, World!" centered
  lcd.drawString("Hello World!", lcd.width() / 2, lcd.height() / 2);
}

void loop() {
  // Nothing to do in the loop
}