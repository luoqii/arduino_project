//http://www.arduino.cn/thread-11019-1-1.html
/**
 * 
 AT+GMR

AT version;0.40.0.0(Aug  8 2015 14;45:58)
SDK version:1.1^hnd.1:
 */
 #include "ESP8266.h"
#include <SoftwareSerial.h>
#define SPEED 9600
#define SPEED 115200
SoftwareSerial WIFISerial(8, 9); // RX, TX
ESP8266 wifi(WIFISerial);
void setup()
{
  Serial.begin(SPEED);   
    wifi.restart();
}
 
void loop(){   
 
}

