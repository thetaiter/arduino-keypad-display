#include "DigitalDisplay.h"
#include "Keypad.h"

char keys[4][3] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte keypadPins[4][3] = {
  { 10, 6, 2 },
  { 11, 7, 3 },
  { 12, 8, 4 },
  { 13, 9, 5 }
};

byte displayPins[3][8] = {
  { 25, 26, 49, 50, 51, 24, 23, 48 },  //Digit 1
  { 29, 30, 45, 46, 47, 27, 28, 44 },  //Digit 2
  { 32, 33, 40, 42, 43, 31, 41, 39 }   //Digit 3
};

Keypad keypad(keys, keypadPins, INPUT_PULLUP, HIGH);
DigitalDisplay disp(displayPins);
int motorPosition = 0;

void setup() {
  disp.flash(888, 3, 200, 150);
  
  Serial.begin(115200);
  Serial.println("Ready for input...");
}

void loop() {
  Key key = keypad.scanKeys();
  
  if (key.getChar()) {
    if (key.getChar() == '*') {
      disp.clearDisplay();
    } else if (key.getChar() == '#') {
      Serial.println(disp.getBuffer());
    } else {
      disp.displayChar(key.getChar());
    }
  }
}
