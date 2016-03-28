//http://www.arduino.cn/thread-11019-1-1.html
/**
 * 
 AT+GMR

AT version;0.40.0.0(Aug  8 2015 14;45:58)
SDK version:1.1^hnd.1:
 */
#include <SoftwareSerial.h>
//#define SPEED 9600
#define SPEED 115200
SoftwareSerial WIFISerial(7, 8); // RX, TX
void setup()
{
  Serial.begin(SPEED);   
  WIFISerial.begin(SPEED);
}
 
void loop(){   
 if (WIFISerial.available()){
    Serial.write(WIFISerial.read());}
  if (Serial.available()){
    WIFISerial.write(Serial.read());
}   
}

