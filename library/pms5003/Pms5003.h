/*
  Pms5003.h - Library for pms5003 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */

#ifndef PMS5003_H
#define PSM5003_H

#include <SoftwareSerial.h>

#define byte uint8_t

#define PM_DATA_LENTH 28

class Pms5003
{
  public:
    // FIXME
    //static const int PM_DATA_LENGTH = 28;
    Pms5003(uint8_t receviePin, uint8_t sendPin);
    void begin(int speed);
    void setup();
    void loop();
    void listen();
    bool available();
    void printData();

    byte* getData();
    int getPm1Cf();
    int getPm2_5Cf();
    int getPm10Cf();
    int getPm1();
    int getPm2_5();
    int getPm10();
    int getPmValue0_3();
    int getPmValue0_5();
    int getPmValue1();
    int getPmValue2_5();
    int getPmValue5();
    int getPmValue10();

  private:
    int getData(int index);

    int recivePin;
    SoftwareSerial* pm;
    byte data[PM_DATA_LENTH];
    
    // sadlly, i must skip this memory on my Anduino uno(r3).
    static const int BAD_DATA_LENGTH = 20;
    byte badData[BAD_DATA_LENGTH];

    static const int FIRST_BYTE = 4 * 16 + 2 * 1;
    static const int SECOND_BYTE = 4 * 16 + 13 * 1;
    char currentByte;
    char lastByte;
    bool _available;
    byte index;

  // debug
    void loopX();
};

#endif
