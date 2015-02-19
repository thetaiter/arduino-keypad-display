#ifndef Key_h
#define Key_h

#include "Arduino.h"

class Key {
  private:
    char _keyChar;
    byte _pin;
    byte _currentState;
    byte _lastState;
  
  public:
    Key();
    Key(char keyChar, byte pin, byte lastState);
    
    char getChar();
    byte getPin();
    byte getCurrentState();
    byte getLastState();
    
    void setCurrentState(byte state);
    void setLastState(byte state);
};

#endif
