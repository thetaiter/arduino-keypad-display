#ifndef Key_h
#define Key_h

#include "Arduino.h"

class Key {
  private:
    char _keyChar;
    byte _pin;
    unsigned int _currentState;
    unsigned int _lastState;
  
  public:
    Key();
    Key(char keyChar, byte pin);
    char getChar();
    byte getPin();
    unsigned int getCurrentState();
    unsigned int getLastState();
    void setCurrentState(unsigned int state);
    void setLastState(unsigned int state);
};

#endif
