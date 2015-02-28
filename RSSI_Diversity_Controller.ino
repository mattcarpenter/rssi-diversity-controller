/**
 * Copyright (c) 2015 by Matt Carpenter <mattcarpenter@gmail.com>
 * RSSI Diversity Controller
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

#include <U8glib.h>
#include "display.h"

#define RSSI_CH0_PIN 14
#define RSSI_CH1_PIN 15
#define RSSI_CH2_PIN 16

#define CONTROL_PIN_0 2
#define CONTROL_PIN_1 3
#define CONTROL_PIN_2 4

#define RSSI_LOW 493
#define RSSI_HIGH 940

// If RSSI drops below threshold, assume not connected or no signal
#define RSSI_LOW_THRESHOLD 300

Display display;
int rawRssi[3] = {};
int rssiPct[3] = {};

void setup () {
  pinMode(CONTROL_PIN_0, OUTPUT);
  pinMode(CONTROL_PIN_1, OUTPUT);
  pinMode(CONTROL_PIN_2, OUTPUT);
  
  Serial.begin(9600);
}

/**
 * Sets the active video channel
 */
void setVideoOut(uint8_t activeChannel) {
  uint8_t control0val;
  uint8_t control1val;
  uint8_t control2val;
  
  switch (activeChannel) {
    case 0:
      control0val = LOW;
      control1val = HIGH;
      control2val = HIGH;
      break;
    case 1:
      control0val = HIGH;
      control1val = HIGH;
      control2val = LOW;
      break;
    case 2:
      control0val = HIGH;
      control1val = LOW;
      control2val = HIGH;
      break;
  }

  digitalWrite(CONTROL_PIN_0, control0val);
  digitalWrite(CONTROL_PIN_1, control1val);
  digitalWrite(CONTROL_PIN_2, control2val);
}


/**
 * Diversity control and display loop
 */
void loop(void) {
  int maxPct = 0;
  int activeChannel = 0;
  
  rawRssi[0] = analogRead(RSSI_CH0_PIN);
  rawRssi[1] = analogRead(RSSI_CH1_PIN);
  rawRssi[2] = analogRead(RSSI_CH2_PIN);
  //Serial.println(rawRssi[0]);
  
  // RSSI Channel 0
  if (rawRssi[0] < RSSI_LOW_THRESHOLD) {
    rssiPct[0] = 0;
  } else {
    rssiPct[0] = 100 - ((float)(rawRssi[0] - RSSI_LOW) / (float)(RSSI_HIGH - RSSI_LOW) * 100);
    
    // Constrain to 0-100
    rssiPct[0] = rssiPct[0] < 0 ? 0 : rssiPct[0];
    rssiPct[0] = rssiPct[0] > 100 ? 100 : rssiPct[0];
    
    maxPct = rssiPct[0];
  }
  
  // RSSI Channel 1
  if (rawRssi[1] < RSSI_LOW_THRESHOLD) {
    rssiPct[1] = 0;
  } else {
    rssiPct[1] = 100 - ((float)(rawRssi[1] - RSSI_LOW) / (float)(RSSI_HIGH - RSSI_LOW) * 100);
    //Serial.println("raw rssi");
    //Serial.println(rawRssi[1]);
    //Serial.println("pct:");
    //Serial.println(rssiPct[1]); 
    // Constrain to 0-100
    rssiPct[1] = rssiPct[1] < 0 ? 0 : rssiPct[1];
    rssiPct[1] = rssiPct[1] > 100 ? 100 : rssiPct[1];
    
    if (rssiPct[1] > maxPct) {
      maxPct = rssiPct[1];
      activeChannel = 1; 
    }
  }
  
  // RSSI Channel 2
  if (rawRssi[2] < RSSI_LOW_THRESHOLD) {
    rssiPct[2] = 0;
  } else {
    rssiPct[2] = 100 - ((float)(rawRssi[2] - RSSI_LOW) / (float)(RSSI_HIGH - RSSI_LOW) * 100);
    
    // Constrain to 0-100
    rssiPct[2] = rssiPct[2] < 0 ? 0 : rssiPct[2];
    rssiPct[2] = rssiPct[2] > 100 ? 100 : rssiPct[2];
    
    if (rssiPct[2] > maxPct) {
      activeChannel = 2;
    }
  }
  display.updateChannel(0, rssiPct[0], (activeChannel == 0 ? true : false));
  display.updateChannel(1, rssiPct[1], (activeChannel == 1 ? true : false));
  display.updateChannel(2, rssiPct[2], (activeChannel == 2 ? true : false));
  
  display.drawCycle();
  setVideoOut(activeChannel);

}

