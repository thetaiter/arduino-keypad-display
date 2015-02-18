#include "Arduino.h"
#include "Keypad.h"

Keypad::Keypad(char keys[4][3], byte pins[4][3], byte buttonResistorPull) {
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      _keys[i][j] = Key(keys[i][j], pins[i][j]);
      pinMode(_keys[i][j].getPin(), buttonResistorPull);
    }
  }
}

Key Keypad::getKey(char key) {
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      if (_keys[i][j].getChar() == key) {
        return _keys[i][j];
      }
    }
  }
  return Key(' ', -1);
}
