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

/**
 * @destructor
 */
 
Display::~Display() {
  if (NULL != u8g) {
    delete u8g;
    u8g = NULL;
  }
}

/**
 * Updates a channel in the view model
 *
 * @param {uint8_t} channel  Channel number to update
 * @param {uint8_t} rawValue Raw RSSI value
 * @param {boolean} active   Indicates whether or not this is the active channel
 */
 
void Display::updateChannel(uint8_t channel, uint8_t rawValue, boolean active) {
  
}

/**
 * Draw cycle routine
 */
 
void Display::drawCycle() {
  u8g->firstPage();
  do {
    drawChrome();
    drawText();
    drawIndicators();
  } while (u8g->nextPage());
}

/**
 * Paints boxes and frames for segmenting information
 */
 
void Display::drawChrome() {
  u8g->setColorIndex(1);
  
  // Draw channel ID boxes
  u8g->drawBox(12, 0, 21, 17);
  u8g->drawBox(12, 18, 21, 17);
  u8g->drawBox(12, 36, 21, 17);
  
  // Draw RSSI bar frames
  u8g->drawFrame(34, 0, 94, 17);
  u8g->drawFrame(34, 18, 94, 17);
  u8g->drawFrame(34, 36, 94, 17);
}

/**
 * Paints channel indicator and RSSI value text
 */
 
void Display::drawText() {
  u8g->setColorIndex(0);
  
  // Channel numbers
  u8g->setFont(u8g_font_6x10);
  u8g->drawStr( 14, 12, "CH1");
  u8g->drawStr( 14, 30, "CH2");
  u8g->drawStr( 14, 48, "CH3");
  
  // RSSI %
  u8g->setFont(u8g_font_9x15);
  u8g->setColorIndex(1);
  u8g->drawStr( 36, 14, "100%");
  u8g->drawStr( 36, 32, "75%");
  u8g->drawStr( 36, 50, "20%");
  
  // Footer
  u8g->setFont(u8g_font_04b_03r);
  u8g->drawStr(14, 62, "RSSI Diversity Controller");
}

/**
 * Paints strength bar indicators and active channel decorator
 */
 
void Display::drawIndicators() {
  u8g->setColorIndex(1);
  u8g->drawTriangle(2,2, 10,8, 2,16);
}
