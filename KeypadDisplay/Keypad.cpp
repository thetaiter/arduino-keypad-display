#include "Keypad.h"

Keypad::Keypad(char keys[4][3], byte pins[4][3], byte buttonResistorPull, byte lastButtonState) {
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      _keys[i][j] = Key(keys[i][j], pins[i][j], lastButtonState);
      pinMode(_keys[i][j].getPin(), buttonResistorPull);
    }
  }
}

Key& Keypad::scanKeys() {
  Key failKey = Key(0, -1, LOW);
  Key& key = failKey;
  
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      Key& k = _keys[i][j];
      
      k.setCurrentState(digitalRead(k.getPin()));
      
      if (k.getCurrentState() != k.getLastState()) {
        if (k.getCurrentState() == LOW) {
          key = k;
        }
      }
      
      k.setLastState(k.getCurrentState());
      
      delay(1);
    }
  }
  
  return key;
}
