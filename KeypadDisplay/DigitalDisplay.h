#ifndef DigitalDisplay_h
#define DigitalDisplay_h

#include "Arduino.h"

const char charArray[36][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 1, 0, 1, 1, 1 },
  { 0, 0, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 0, 1 },
  { 1, 0, 0, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
  { 0, 1, 1, 0, 1, 1, 1 },
  { 0, 0, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 0, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 1, 0 },
  { 1, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 0 },
  { 1, 1, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 1, 1 },
  { 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 0, 0, 0, 1, 1, 1, 1 },
  { 0, 1, 1, 1, 1, 1, 0 },
  { 0, 0, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1, 1, 1 },
  { 0, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 1, 0, 1 }
};

class DigitalDisplay {
  private:
    byte _pins[3][8];
    char buffer[3]; 
    boolean validate(byte digitOnDisplay, char charToDisplay);
    byte getIndex(char c);
  
  public:
    DigitalDisplay(byte pins[3][8]);
    void displayNumber(int number);
    void displayChar(byte digitOnDisplay, char charToDisplay);
    void flash(int number, byte numTimes, unsigned int onTime, unsigned int offTime);
    void clearDisplay();
};

#endif
