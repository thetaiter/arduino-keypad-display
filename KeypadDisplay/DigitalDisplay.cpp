#include "DigitalDisplay.h"

DigitalDisplay::DigitalDisplay(byte pins[3][8]) {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 8; j++) {
      _pins[i][j] = pins[i][j];
      pinMode(_pins[i][j], OUTPUT);
      digitalWrite(_pins[i][j], LOW);
    }
  }
  
  currentDigit = 3;
  buffer[0] = '\0';
  buffer[1] = '\0';
  buffer[2] = '\0';
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
  } else if ((charToDisplay < '0' || (charToDisplay > '9' && charToDisplay < 'A') || (charToDisplay > 'Z' && charToDisplay < 'a') || charToDisplay > 'z') && charToDisplay != '\0') {
    Serial.print(charToDisplay);
    Serial.println(" is an invalid character to print. Allowed values are a-z, A-Z, or 0-9");
    return false;
  }
  
  return true;
}

boolean DigitalDisplay::validate(char charToDisplay) {
  if ((charToDisplay < '0' || (charToDisplay > '9' && charToDisplay < 'A') || (charToDisplay > 'Z' && charToDisplay < 'a') || charToDisplay > 'z') && charToDisplay != '\0') {
    Serial.print(charToDisplay);
    Serial.println(" is an invalid character to print. Allowed values are a-z, A-Z, or 0-9");
    return false;
  } else if (charToDisplay == '\0') {
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

boolean DigitalDisplay::displayChar(byte digitOnDisplay, char charToDisplay) {
  if (validate(digitOnDisplay, charToDisplay)) {
    byte charIndex = getIndex(charToDisplay);
      
    for (byte i = 0; i < 7; i++) {
      digitalWrite(_pins[digitOnDisplay-1][i], charArray[charIndex][i]);
    }
    
    buffer[digitOnDisplay-1] = charToDisplay;
    
    return true;
  }
  
  return false;
}

void DigitalDisplay::shiftDigits(boolean wrap) {
  if (wrap) {
    char temp = buffer[0];
    buffer[0] = buffer[1];
    buffer[1] = buffer[2];
    buffer[2] = temp;
  } else {
    buffer[0] = buffer[1];
    buffer[1] = buffer[2];
    buffer[2] = '\0';
  }
  
  if (buffer[0] != '\0') {
    displayChar(1, buffer[0]);
  }
  
  if (buffer[1] != '\0') {
    displayChar(2, buffer[1]);
  }
  
  if (buffer[2] != '\0') {
    displayChar(3, buffer[2]);
  }
}

boolean DigitalDisplay::displayChar(char charToDisplay) {
  if (validate(charToDisplay) && currentDigit > 0) {        
    shiftDigits(false);
    
    displayChar(3, charToDisplay);
    
    currentDigit--;
    
    return true;
  }
  
  return false;
}

String DigitalDisplay::getBuffer() {
  String str;
  
  if (buffer[0]) {
    str = String(buffer[0]);
    str = str + buffer[1];
    str = str + buffer[2];
  } else if (buffer[1]) {
    str = String(buffer[1]);
    str = str + buffer[2];
  } else if (buffer[2]) {
    str = String(buffer[2]);
  } else {
    str = "empty"; 
  }
  
  return str;
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

void DigitalDisplay::clearDisplay() {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 8; j++) {
      digitalWrite(_pins[i][j], LOW);
    }
  }
  
  currentDigit = 3;
  buffer[0] = '\0';
  buffer[1] = '\0';
  buffer[2] = '\0';
}
