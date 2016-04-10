/*
  Pms5003.h - Library for Nixietube 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */
/*
 * =========
 *        a
 *   f          b
 *        g
 *   e          c
 *        d 
 * =========
 *   L   a    f    C    R    b
 *   
 *   e   d    :    c    g    ?    
 *   
 *   L: left (VCC)
 *   R: Right (VCC)
 *   C: center (VCC)
 */
#ifndef NIXIETUBE_H
#define NIXIETUBE_H

#include <Arduino.h>

class Nixietube {
  public:
    Nixietube(int a, int b, int c, int d, int e, int f, int g,
                   int dp,
                   int left, int center, int right);
    void begin();
    void showNumber(int number);

  private:
    void setPinMode(int pin);
    void showDigit(int whichPin, int digit);
    void pickDigit(int whichPin);
    void clean();
    void lightAll();
    void dispDec();
    void clearLEDs();
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();

    int A;
    int B;
    int C;
    int D;
    int E;
    int F;
    int G;
    int DP;
    int LEFT;
    int CENTER;
    int RIGHT;

    static const int OFF = HIGH;
    static const int ON = LOW;
    static const int DIGITAL_ON = HIGH;
    static const int DIGITAL_OFF = LOW;

};
#endif
