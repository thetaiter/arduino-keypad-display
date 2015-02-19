#include "Key.h"

Key::Key() {
  _keyChar = 0;
  _pin = -1;
  _lastState = LOW;
}

Key::Key(char keyChar, byte pin, byte lastState) {
  _keyChar = keyChar;
  _pin = pin;
  _lastState = lastState;
}

char Key::getChar() {
  return _keyChar;
}

byte Key::getPin() {
  return _pin;
}

byte Key::getCurrentState() {
  return _currentState;
}

byte Key::getLastState() {
  return _lastState;
}

void Key::setCurrentState(byte state) {
  _currentState = state;
}

void Key::setLastState(byte state) {
  _lastState = state;
}
