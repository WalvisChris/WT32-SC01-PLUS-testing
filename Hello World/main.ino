#include <LovyanGFX.hpp>
#include "LGFX_WT32_SC01_PLUS.hpp" // Make sure this file is in the same directory as your .ino file

static LGFX lcd;

void setup() {
  // Initialize the display
  lcd.init();
  
  // Set display rotation (0: portrait, 1: landscape)
  lcd.setRotation(1); 

  // Clear the screen to black
  lcd.fillScreen(TFT_BLACK);

  // Set text properties
  lcd.setTextSize(3);                // Set text size
  lcd.setTextColor(TFT_WHITE);       // Set text color to white
  lcd.setTextDatum(textdatum_t::middle_center); // Set text alignment to middle center

  // Display "Hello, World!"
  // The coordinates (width/2, height/2) position the text in the center of the screen
  lcd.drawString("Hello, World!", lcd.width() / 2, lcd.height() / 2);
}

void loop() {
  // Nothing to do in the loop for this example
  // The message stays on the screen until reset.
}