
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

// U8g2 Contructor List (Frame Buffer)
U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


#include "CurieIMU.h"
int ax, ay, az;         // accelerometer values
int gx, gy, gz;         // gyrometer values


int calibrateOffsets = 1; // int to determine whether calibration takes place or not

void setup() {
  // Initialize OLED SH1106 128x64 Display 
  oled.begin();
  oled.setFontMode(0);				// write solid glyphs
  
  oled.setFont(u8g_font_profont12);
  oled.clearBuffer();					// clear the internal memory
  oled.sendBuffer();					// transfer internal memory to the display
  // oled.setFont(u8g_font_unifont);	// choose a suitable font
  // oled.setFont(u8g_font_courB08);
  // oled.setFont(u8g_font_profont12);
  
  // initialize device
  CurieIMU.begin();

  oled.drawStr(5,15,"Test IMU connections");
  oled.sendBuffer();	
  delay(2000);
  oled.clearBuffer();					// clear the internal memory
  oled.drawStr(5,15,"CurieIMU connection");
  if (CurieIMU.begin()) {			
    oled.drawStr(30,30,"Successful");
    oled.sendBuffer();	
  } else {
    oled.drawStr(30,30,"Failed !!!");
    oled.sendBuffer();	
  }
  delay(2000);
 oled.clearBuffer();
}

void loop() {
  // read raw accel/gyro measurements from device
  CurieIMU.readMotionSensor(ax, ay, az, gx, gy, gz);
  
  // these methods (and a few others) are also available

  //CurieIMU.readAcceleration(ax, ay, az);
  //CurieIMU.readRotation(gx, gy, gz);

  //ax = CurieIMU.readAccelerometer(X_AXIS);
  //ay = CurieIMU.readAccelerometer(Y_AXIS);
  //az = CurieIMU.readAccelerometer(Z_AXIS);
  //gx = CurieIMU.readGyro(X_AXIS);
  //gy = CurieIMU.readGyro(Y_AXIS);
  //gz = CurieIMU.readGyro(Z_AXIS);
  
  /* 
  // old method
  oled.clearBuffer();
  oled.setFontMode(0);				// write solid glyphs
  oled.setFont(u8g_font_profont12);
  oled.clearBuffer();
  oled.setCursor(5,15); oled.print("IMU Raw Data..."); 
  oled.setCursor(5,30);  oled.print("ax: "); oled.print(ax);
  oled.setCursor(65,30); oled.print("gx: "); oled.print(gx);
  oled.setCursor(5,40);  oled.print("ay: "); oled.print(ay);
  oled.setCursor(65,40);  oled.print("gy: "); oled.print(gy);
  oled.setCursor(5,50);  oled.print("az: "); oled.print(az);
  oled.setCursor(65,50);  oled.print("gz: "); oled.print(gz);
  oled.sendBuffer();

*/


  oled.firstPage();  
  do {
    oled.setFontMode(0);				// write solid glyphs
    oled.setFont(u8g_font_profont12);
    oled.clearBuffer();
    oled.setCursor(5,15); oled.print("IMU Raw Data..."); 
    oled.setCursor(5,30);  oled.print("ax: "); oled.print(ax);
    oled.setCursor(65,30); oled.print("gx: "); oled.print(gx);
    oled.setCursor(5,40);  oled.print("ay: "); oled.print(ay);
    oled.setCursor(65,40);  oled.print("gy: "); oled.print(gy);
    oled.setCursor(5,50);  oled.print("az: "); oled.print(az);
    oled.setCursor(65,50);  oled.print("gz: "); oled.print(gz);
    } while( oled.nextPage() );

  delay(500);




}
