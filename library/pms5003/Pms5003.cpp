/*
  Pms5003.h - Library for pms5003 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */

#include "Pms5003.h"

#include <Arduino.h>

Pms5003::Pms5003(uint8_t receviePin, uint8_t sendPin) {
   pm= new SoftwareSerial(receviePin, sendPin);
 
   for (int i = 0 ; i < BAD_DATA_LENGTH; i++) {
     badData[i] = i;
   }   

   data[0] = FIRST_BYTE;
   data[1] = SECOND_BYTE;
   index = -1;

   _available = false;
}

void Pms5003::begin(int speed) {
   pm->begin(speed);
}

void Pms5003::setup() {}

void Pms5003::listen() {
  pm->listen();
}

void Pms5003::loopX() {
  if (pm->available() && false) {
    currentByte = pm->read();
        Serial.print("currentByte:0x");
        Serial.println(currentByte, HEX);
  }
	
  Serial.println("before.");
  printData();
  for (int i = 0 ; i < PM_DATA_LENTH; i++) {
    data[i] = 4;
    delay(100);
  }
  printData();
  delay(1000);
}

void Pms5003::loop() {
  if (pm->available()) {
        //Serial.println("");
        //Serial.print("before read:");
        //printData();
  	lastByte = currentByte;
        currentByte = pm->read();
        DEBUG("rcv:");
        DEBUGLN(currentByte, HEX);      

        //Serial.print("lastByte:0x");
        //Serial.println(lastByte, HEX);
        //Serial.print("currentByte:0x");
        //Serial.println(currentByte, HEX);

        if (lastByte == FIRST_BYTE && currentByte == SECOND_BYTE){
          index = 1;
          _available = false;
        }
        //Serial.print("index:");
        //Serial.println(index);	
        if (index >= 1 && index < PM_DATA_LENTH) {
          // FIXME what different for this 2 line codes?
          //Serial.println("index:" + index);
          //Serial.print("write new byte, index:");
          //Serial.println(index);

          data[index] = currentByte;
          if (index == PM_DATA_LENTH - 1) {
            _available = true;
            index = -1;
            //printData();
          }
          index++;
        }         
        
        //Serial.print("after read:");
        //printData();
  }
}

byte* Pms5003::readData(){
  _available = false;
  return data;
}

bool Pms5003::available() {
  return _available;
}

int Pms5003::getPm1Cf() {
  return getData(4);
}

int Pms5003::getPm2_5Cf() {
  return getData(6);
}

int Pms5003::getPm10Cf() {
  return getData(8);
}

int Pms5003::getPm1() {
  return getData(10);
}

int Pms5003::getPm2_5() {
  return getData(12);
}

int Pms5003::getPm10() {
  return getData(14);
}

int Pms5003::getPmValue0_3() {
  return getData(16);
}
int Pms5003::getPmValue0_5() {
  return getData(18);
}
int Pms5003::getPmValue1() {
  return getData(20);
}
int Pms5003::getPmValue2_5() {
  return getData(22);
}
int Pms5003::getPmValue5() {
  return getData(24);
}
int Pms5003::getPmValue10() {
  return getData(26);
}

int Pms5003::getData(int startIndex) {
  int ret = -1;
  byte h = (data[startIndex]);
  byte l = (data[startIndex + 1]);
  //Serial.print("h:");
  //Serial.print(h);
  //Serial.print(" l:");
  //Serial.println(l);
  ret = h * 256 + l;
  //Serial.print(" ret:");
  //Serial.println(ret);
  //ret = data[startIndex] * 256 + data[startIndex + 1];
  return ret;
}

void Pms5003::printData(){
  if (!_available) {
    Serial.println("data is not available.");
  }
  Serial.print("data:0x");
  for (int i = 0 ; i < PM_DATA_LENTH; i++) {
    Serial.print(data[i], HEX);
    Serial.print(" ");
    if (i % 2 == 1) {
      Serial.print("    ");
    }
  }
  Serial.println("");

  Serial.print("cf[");
  Serial.print(getPm1Cf());
  Serial.print(",");
  Serial.print(getPm2_5Cf());
  Serial.print(",");
  Serial.print(getPm10Cf());

  Serial.print("],[");

  Serial.print(getPm1());
  Serial.print(",");
  Serial.print(getPm2_5());
  Serial.print(",");
  Serial.print(getPm10());

  Serial.print("],[");

  Serial.print(getPmValue0_3());
  Serial.print(",");
  Serial.print(getPmValue0_5());
  Serial.print(",");
  Serial.print(getPmValue1());
  Serial.print(",");
  Serial.print(getPmValue2_5());
  Serial.print(",");
  Serial.print(getPmValue5());
  Serial.print(",");
  Serial.print(getPmValue10());
  Serial.print("]");
  Serial.println("");
}
