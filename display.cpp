#include "display.h"

Display::Display() {
  u8g = new U8GLIB_ST7920_128X64_4X(10);
}

Display::~Display() {
  if (NULL != u8g) {
    delete u8g;
    u8g = NULL;
  }
}

void Display::drawCycle() {
  u8g->firstPage();
  do {
    draw();
  } while (u8g->nextPage());
}

void Display::draw() {
  
}
