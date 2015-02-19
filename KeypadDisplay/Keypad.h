#ifndef Keypad_h
#define Keypad_h

#include "Arduino.h"
#include "Key.h"

class Keypad {
  private:
    Key _keys[4][3];
  
  public:
    Keypad(char keys[4][3], byte pins[4][3], byte buttonResistorPull, byte lastButtonState);
    Key& scanKeys();
};

#endif
