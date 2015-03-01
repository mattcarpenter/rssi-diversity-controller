# RSSI Diversity Controller

The RSSI Diversity Controller is an Arduino-based video diversity controller capable of switching up to three channels of video based on the relative signal strength of each channel.

RSSI input is typically a 1-2 volt signal pulled from the AGC pin of each video receiver's demodulator chip. The diversity controller amplifies this signal into a useable 2-4 volt range for easy measurement from the Arduino's analog in pins. Switching is accomplished by feeding each video input into a NTE74HC4053 multiplexer chip controlled by the Arduino.

A 128x64 graphic LCD display connected to the Arduino via I<sup>2</sup>C provides a real-time indication of signal strength and the currently active channel.
