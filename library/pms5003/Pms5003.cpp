/*
  Pms5003.h - Library for pms5003 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */

#include "Pms5003.h"

#include <Arduino.h>

Pms5003::Pms5003(uint8_t receviePin, uint8_t sendPin) {
   pm= new SoftwareSerial(receviePin, sendPin);
   
   data[0] = FIRST_BYTE;
   data[1] = SECOND_BYTE;
   index = -1;
}

void Pms5003::begin(int speed) {
   pm->begin(speed);
}

void Pms5003::setup() {}

void Pms5003::loop() {
  if (pm->available() && false) {
    currentByte = pm->read();
        Serial.print("currentByte:0x");
        Serial.println(currentByte, HEX);
  }
	
  Serial.println("before.");
  printData();
  for (int i = 0 ; i < DATA_LENGTH; i++) {
    data[i] = 4;
    delay(100);
  }
  printData();
  delay(1000);
}

void Pms5003::loopX() {
  if (pm->available()) {
        Serial.println("");
        Serial.print("before read:");
        printData();
  	lastByte = currentByte;
        currentByte = pm->read();

        Serial.print("lastByte:0x");
        Serial.println(lastByte, HEX);
        Serial.print("currentByte:0x");
        Serial.println(currentByte, HEX);

        if (lastByte == FIRST_BYTE && currentByte == SECOND_BYTE){
          index = 1;
        }
        Serial.print("index:");
        Serial.println(index);	
        if (index >= 1 && index < DATA_LENGTH) {
          // FIXME what different for this 2 line codes?
          //Serial.println("index:" + index);
          Serial.print("write new byte, index:");
          Serial.println(index);

          data[index] = currentByte;
          if (index == DATA_LENGTH - 1) {
            _available = true;
            index = -1;
            printData();
          }
          index++;
        }
         
        
        Serial.print("after read:");
        printData();
  }
}

byte* Pms5003::getData(){
  return data;
}

bool Pms5003::available() {
  return _available;
}

void Pms5003::printData(){
  Serial.print("data:0x");
  for (int i = 0 ; i < DATA_LENGTH; i++) {
    Serial.print(data[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");
}