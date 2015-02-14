/**
 * Copyright (c) 2015 by Matt Carpenter <mattcarpenter@gmail.com>
 * Display class for RSSI Diversity Controller
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#include "display.h"

/**
 * The Dispaly class is essentially a view model, binding RSSI state
 * information to a KS0108 chipset based LCD display.
 *
 * @constructor
 */
 
Display::Display() {
  u8g = new U8GLIB_ST7920_128X64_4X(10);
}

Display::~Display() {
  if (NULL != u8g) {
    delete u8g;
    u8g = NULL;
  }
}

void Display::setRSSI(int channel, int rawValue) {
  
}

void Display::drawCycle() {
  u8g->firstPage();
  do {
    draw();
  } while (u8g->nextPage());
}

void Display::draw() {
  u8g->setFontPosTop();
  u8g->setColorIndex(1);
  u8g->drawBox(0, 0, 128, 20);
  u8g->setColorIndex(0);
  u8g->setFont(u8g_font_04b_03b);
  u8g->drawStr(2, 6, "RSSI           RSSI           RSSI");
  u8g->setFont(u8g_font_6x10);
  u8g->setColorIndex(0);
  u8g->drawStr( 1, 15, "CH1      CH2      CH3");
  u8g->setColorIndex(1);
  u8g->drawLine(34, 0, 34, 40);
  u8g->drawLine(89, 0, 89, 40);
  u8g->drawLine(0, 40, 196, 40);
  u8g->drawStr( 1, 30, " 0%       0%      0%");
  u8g->setFont(u8g_font_6x10);
}
