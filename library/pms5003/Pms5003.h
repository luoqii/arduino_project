/*
  Pms5003.h - Library for pms5003 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */

#ifndef PMS5003_H
#define PSM5003_H

#include <SoftwareSerial.h>

#define byte uint8_t

class Pms5003
{
  public:
    Pms5003(uint8_t receviePin, uint8_t sendPin);
    void begin(int speed);
    void setup();
    void loop();
    bool available();

    byte* getData();
    int getPm2_5();
    int getPm1_0();
    int getPm10();

  private:
    void printData();

    int recivePin;
    SoftwareSerial* pm;
    static const int DATA_LENGTH = 50;
    byte data[];

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
