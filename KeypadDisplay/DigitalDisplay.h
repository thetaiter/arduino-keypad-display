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
    byte currentDigit;
    
    boolean validate(byte digitOnDisplay, char charToDisplay);
    boolean validate(char charToDisplay);
    byte getIndex(char c);
    void shiftDigits(boolean wrap);
  
  public:
    DigitalDisplay(byte pins[3][8]);
    
    void displayNumber(int number);
    boolean displayChar(byte digitOnDisplay, char charToDisplay);
    boolean displayChar(char charToDisplay);
    String getBuffer();
    void flash(int number, byte numTimes, unsigned int onTime, unsigned int offTime);
    void clearDisplay();
};

#endif
