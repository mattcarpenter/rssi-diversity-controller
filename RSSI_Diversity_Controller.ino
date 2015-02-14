#include <U8glib.h>
#include "display.h"

//U8GLIB_ST7920_128X64_4X u8g(10);

void setup () {
  
}


/**
 * Diversity control and display loop
 */
void loop(void) {
  // picture loop
 // u8g.firstPage();
  
  //do {
  //  draw();
  //} while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);
}

/**
 * Draws to RSSI indicator display
 */
void draw(void) {
  /*
  u8g.setFontPosTop();
  u8g.setColorIndex(1);
  u8g.drawBox(0, 0, 128, 20);
  u8g.setColorIndex(0);
  u8g.setFont(u8g_font_04b_03b);
  u8g.drawStr(2, 6, "RSSI           RSSI           RSSI");
  u8g.setFont(u8g_font_6x10);
  u8g.setColorIndex(0);
  u8g.drawStr( 1, 15, "CH1      CH2      CH3");
  u8g.setColorIndex(1);
  u8g.drawLine(34, 0, 34, 40);
  u8g.drawLine(89, 0, 89, 40);
  u8g.drawLine(0, 40, 196, 40);
  u8g.drawStr( 1, 30, " 0%       0%      0%");
  u8g.setFont(u8g_font_6x10);
  */
}


