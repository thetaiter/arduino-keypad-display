#include "Arduino.h"
#include "Key.h"

Key::Key() {
  _keyChar = ' ';
  _pin = -1;
  _lastState = LOW;
}

Key::Key(char keyChar, byte pin) {
  _keyChar = keyChar;
  _pin = pin;
  _lastState = LOW;
}

char Key::getChar() {
  return _keyChar;
}

byte Key::getPin() {
  return _pin;
}

unsigned int Key::getCurrentState() {
  return _currentState;
}

unsigned int Key::getLastState() {
  return _lastState;
}

void Key::setCurrentState(unsigned int state) {
  _currentState = state;
}

void Key::setLastState(unsigned int state) {
  _lastState = state;
}
