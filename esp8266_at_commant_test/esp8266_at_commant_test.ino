//http://www.arduino.cn/thread-11019-1-1.html
/**
 * 
 AT+GMR

AT version;0.40.0.0(Aug  8 2015 14;45:58)
SDK version:1.1^hnd.1:
 */
 #include "ESP8266.h"
#include <SoftwareSerial.h>

//#define SPEED 9600
#define SPEED 115200

SoftwareSerial WIFISerial(8, 9); // RX, TX
// we MUST give a new speed, otherwise this will bite you.
ESP8266 esp8266(WIFISerial, SPEED);

#define SSID "Tenda_098C40"
#define PASSWORD "bangyuan"

void setup()
{  
  Serial.println("try setup.");
  Serial.begin(SPEED); 
  Serial.println("begin done.");
   delay(3000);  
   setupESP8266();
   esp8266.kick();
   esp8266.restart();
}
 
void loop(){   
  //WIFISerial.listen();
  /*
 if (WIFISerial.available()){
    Serial.write(WIFISerial.read());}
  if (Serial.available()){
    WIFISerial.write(Serial.read());
}   */
}

void setupESP8266()
{
    while (1) {
        Serial.print("restaring esp8266...");
        if (esp8266.restart()) {
            Serial.print("ok\r\n");
            break;
        }
        else {
            Serial.print("not ok...\r\n");
            Serial.print("Trying to kick...");
            while (1) {
                if (esp8266.kick()) {
                    Serial.print("ok\r\n");
                    break;
                }
                else {
                    Serial.print("not ok... Wait 5 sec and retry...\r\n");
                    delay(5000);
                }
            }
        }
    }

    Serial.print("setup begin\r\n");
    Serial.print("FW Version:");
    Serial.println(esp8266.getVersion().c_str());

    while (1) {
        if (esp8266.setOprToStation()) {
            Serial.print("to station ok\r\n");
            break;
        }
        else {
            Serial.print("to station err\r\n");
            Serial.println("Wait 5 seconds and try again...");
            delay(5000);
        }
    }

    while (1) {
        if (esp8266.joinAP(SSID, PASSWORD)) {
            Serial.print("Join AP success\r\n");
            break;
        }
        else {
            Serial.print("Join AP failure\r\n");
            Serial.println("Wait 5 seconds and try again...");
            delay(5000);
        }
    }
    Serial.print("setup end\r\n");
}

