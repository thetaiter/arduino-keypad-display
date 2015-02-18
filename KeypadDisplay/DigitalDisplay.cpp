#include "Arduino.h"
#include "DigitalDisplay.h"

DigitalDisplay::DigitalDisplay(byte pins[3][8]) {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 8; j++) {
      _pins[i][j] = pins[i][j];
      pinMode(_pins[i][j], OUTPUT);
      digitalWrite(_pins[i][j], LOW);
    }
  }
}

void DigitalDisplay::displayNumber(int number) {
  int ones, tens, hundreds;
  
  if (number >= 999) {
    ones = 9;
    tens = 9;
    hundreds = 9;
  } else {
    ones = number % 10;
    number = number / 10;
    
    tens = number % 10;
    number = number / 10;
    
    hundreds = number;
  }
  
  displayChar(1, hundreds + '0');
  displayChar(2, tens + '0');
  displayChar(3, ones + '0');
}

boolean DigitalDisplay::validate(byte digitOnDisplay, char charToDisplay) {
  if (digitOnDisplay < 1 || digitOnDisplay > 3) {
    Serial.println("Invalid digit to display on. Must be 1, 2, or 3.");
    return false;
  } else if (charToDisplay < '0' || (charToDisplay > '9' && charToDisplay < 'A') || (charToDisplay > 'Z' && charToDisplay < 'a') || charToDisplay > 'z') {
    Serial.println(charToDisplay);
    Serial.println("Invalid character to print. Allowed values are a-z, A-Z, or 0-9");
    return false;
  }
  
  return true;
}

byte DigitalDisplay::getIndex(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'z') {
    return c - 'a' + 10;
  } else {
    return c - 'A' + 10;
  }
}

void DigitalDisplay::displayChar(byte digitOnDisplay, char charToDisplay) {
  if (validate(digitOnDisplay, charToDisplay)) {
    byte charIndex = getIndex(charToDisplay);
      
    for (byte i = 0; i < 7; i++) {
      digitalWrite(_pins[digitOnDisplay-1][i], charArray[charIndex][i]);
    }
  }
}

void DigitalDisplay::clearDisplay() {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 8; j++) {
      digitalWrite(_pins[i][j], LOW);
    }
  }
}

void DigitalDisplay::flash(int number, byte numTimes, unsigned int onTime, unsigned int offTime) {
  if (number > 999) number = 999;
  
  for (byte i = 0; i < numTimes; i++) { 
    displayNumber(number);
    delay(onTime);
    clearDisplay();
    delay(offTime);
  }
}
