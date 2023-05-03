#include "U8glib.h"
#define i2c_Address 0x3C
U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE);

void page1(void){
  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0,30);
  oled.print("Test Message");
}

void page2(void){
  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0,40);
  oled.print("Test Message");
}
void setup(void) {
}

void loop(void){
  oled.firstPage();
  do {
    page1();
  } while (oled.nextPage());

  delay(3000);

  oled.firstPage();
  do {
    page1();
  } while (oled.nextPage());
 delay(3000);

}