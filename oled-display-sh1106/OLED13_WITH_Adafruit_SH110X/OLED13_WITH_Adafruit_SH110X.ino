#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// #define OLED_RESET -1
// Adafruit_SH1106 display(OLED_RESET); /* Object of class Adafruit_SSD1306 */

void setup() {
  display.begin(i2c_Address, true); // Address 0x3C default
  display.clearDisplay(); /* Clear display */
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(2); /* Select font size of text. Increases with size of argument. */
  display.setCursor(25,30);
  display.println("Rashed");
  display.display();
  delay(500);
   
}

void loop() {
  
  
}
