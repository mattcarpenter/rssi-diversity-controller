#ifndef DISPLAY_H
#define DISPLAY_H
 
#include <WProgram.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
#include <U8glib.h>

class Display {
  public:
    Display();
    ~Display();
    void drawCycle();
    void setRSSI(int channel, int rawValue);
  private:
    U8GLIB_ST7920_128X64_4X *u8g;
    void draw();
};

#endif
