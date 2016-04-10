/*
  Pms5003.h - Library for Nixietube 
  Created by bangbang.song@gmail.com
  Released into the public domain.
 */

#include "Nixietube.h"


Nixietube::Nixietube(int a, int b, int c, int d, int e, int f, int g,
                   int dp,
                   int left, int center, int right){
  A = a;
  B = b;
  C = c;
  D = d;
  E = e;
  F = f;
  G = g;

  DP = dp;

  LEFT = left;
  CENTER = center;
  RIGHT = right;
}

void Nixietube::begin(){
  setPinMode(A);
  setPinMode(B);
  setPinMode(C);
  setPinMode(D);
  setPinMode(E);
  setPinMode(F);
  setPinMode(G);
  setPinMode(DP);
  setPinMode(LEFT);
  setPinMode(CENTER);
  setPinMode(RIGHT);
}

void Nixietube::setPinMode(int pin) {
  if (pin >= 0 ) {
    pinMode(pin, OUTPUT);
  }
}

void Nixietube::showNumber(int number){
 if (number > 999 || number <= 0) {
    Serial.println("invalie number");
  }

  int delay_ms = 10;

  int number1 = number / 100;
  int number2 = number % 100 / 10;
  int number3 = number % 100 % 10 ;

  showDigit(LEFT, number1);
  delay(delay_ms);
  
  showDigit(CENTER, number2);
  delay(delay_ms);

  showDigit(RIGHT, number3);
  delay(delay_ms);
}

void Nixietube::pickDigit(int whichPin){
   digitalWrite(LEFT,DIGITAL_OFF);
   digitalWrite(CENTER,DIGITAL_OFF);
   digitalWrite(RIGHT,DIGITAL_OFF);
   
   digitalWrite(whichPin,DIGITAL_ON);
}

void Nixietube::showDigit(int whichPin, int digit) {
  pickDigit(whichPin);
  if (digit == 0) {
    zero();
  }
  if (digit == 1) {
    one();
  }
  if (digit == 2) {
    two();
  }
  if (digit == 3) {
    three();
  }
  if (digit == 4) {
    four();
  }
  if (digit == 5) {
    five();
  }
  if (digit == 6) {
    six();
  }
  if (digit == 7) {
    seven();
  }
  if (digit == 8) {
    eight();
  }
  if (digit == 9) {
    nine();
  }
}

void Nixietube::clean () {
  digitalWrite(A,OFF);
}

void Nixietube::lightAll() {  
  digitalWrite(LEFT,DIGITAL_ON);
  digitalWrite(A,ON);
  digitalWrite(B,ON);
  digitalWrite(C,ON);
  digitalWrite(D,ON);
  digitalWrite(E,ON);
  digitalWrite(F,ON);
  digitalWrite(G,ON);
  digitalWrite(DP,ON);
  
  digitalWrite(CENTER,DIGITAL_ON);
  digitalWrite(A,ON);
  digitalWrite(B,ON);
  digitalWrite(C,ON);
  digitalWrite(D,ON);
  digitalWrite(E,ON);
  digitalWrite(F,ON);
  digitalWrite(G,ON);
  digitalWrite(DP,ON);
  
  digitalWrite(RIGHT,DIGITAL_ON);
  digitalWrite(A,ON);
  digitalWrite(B,ON);
  digitalWrite(C,ON);
  digitalWrite(D,ON);
  digitalWrite(E,ON);
  digitalWrite(F,ON);
  digitalWrite(G,ON);
  digitalWrite(DP,ON);
}

void Nixietube::dispDec()  //设定开启小数点
{
  digitalWrite(DP, ON);
}
 
void Nixietube::clearLEDs()  //清屏
{
  digitalWrite(A, OFF);
  digitalWrite(B, OFF);
  digitalWrite(C, OFF);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, OFF);
  digitalWrite(DP, OFF);
}
 
void Nixietube::zero()  //定义数字0时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, ON);
  digitalWrite(G, OFF);
}
 
void Nixietube::one()  //定义数字1时阴极那些管脚开关
{
  digitalWrite(A, OFF);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, OFF);
}
 
void Nixietube::two()  //定义数字2时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, OFF);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, OFF);
  digitalWrite(G, ON);
}
 
void Nixietube::three()  //定义数字3时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, ON);
}
 
void Nixietube::four()  //定义数字4时阴极那些管脚开关
{
  digitalWrite(A, OFF);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
}
 
void Nixietube::five()  //定义数字5时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, OFF);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, OFF);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
}
 
void Nixietube::six()  //定义数字6时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, OFF);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
}
 
void Nixietube::seven()  //定义数字7时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F, OFF);
  digitalWrite(G, OFF);
}
 
void Nixietube::eight()  //定义数字8时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, ON);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
}
 
void Nixietube::nine()  //定义数字9时阴极那些管脚开关
{
  digitalWrite(A, ON);
  digitalWrite(B, ON);
  digitalWrite(C, ON);
  digitalWrite(D, ON);
  digitalWrite(E, OFF);
  digitalWrite(F, ON);
  digitalWrite(G, ON);
}
