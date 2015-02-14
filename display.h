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

#ifndef DISPLAY_H
#define DISPLAY_H
 
#include <WProgram.h>
#include <Arduino.h>
#include <U8glib.h>

class Display {
  public:
    Display();
    ~Display();
    void drawCycle();
    void updateChannel(uint8_t channel, uint8_t rawValue, boolean active);
  private:
    U8GLIB_ST7920_128X64_4X *u8g;
    
    uint8_t _rawValues[3];
    uint8_t _activeChannel;
    
    void drawChrome();
    void drawText();
    void drawIndicators();
};

#endif
