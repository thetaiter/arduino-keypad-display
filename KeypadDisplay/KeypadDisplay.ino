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

Keypad keypad(keys, keypadPins, INPUT_PULLUP, 10);
DigitalDisplay disp(displayPins);
byte currentDigit = 3;
byte digit[3] = {0, 0, 0};
byte buttonStates[4][3];
byte lastButtonStates[4][3];

void setup() {
  Serial.begin(115200);
  
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      lastButtonStates[i][j] = HIGH;
    }
  }
  
  disp.flash(888, 3, 500, 250);
  
  Serial.println("Ready for input...");
}

byte hello;

void loop() {
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 3; j++) {
      Key key = keypad.checkKey(keys[i][j]);
      
      buttonStates[i][j] = digitalRead(key.getPin());
      
      if (buttonStates[i][j] != lastButtonStates[i][j]) {
        if (buttonStates[i][j] == LOW) {
          disp.displayChar(3, key.getChar());
        }
      }
      
      lastButtonStates[i][j] = buttonStates[i][j];
    }
  }
}
