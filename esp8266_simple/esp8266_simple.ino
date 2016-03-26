//http://www.arduino.cn/thread-11019-1-1.html
/**
 * 
 AT+GMR

AT version;0.40.0.0(Aug  8 2015 14;45:58)
SDK version:1.1^hnd.1:
 */
#include <SoftwareSerial.h>
#define SPEED 9600
#define SPEED 115200
SoftwareSerial WIFISerial(8, 9); // RX, TX
void setup()
{

  {};
  Serial.begin(SPEED);
   
  WIFISerial.begin(SPEED);
  delay(2000);
  WIFISerial.println("AT+RST");
    Serial.println("AT+RST");
  delay(2000);
  WIFISerial.println("AT+CWMODE=3"); //ap+sta mode
    Serial.println("AT+CWMODE=3");
  delay(2000);
  WIFISerial.println("AT+CWJAP=\"Tenda_098C40\",\"bangyuan\""); //connect to router!
    Serial.println("AT+CWJAP=\"Tenda_098C40\",\"bangyuan\"");
  delay(3000);
}
 
void loop(){
 
   
 if (WIFISerial.available()){
    Serial.write(WIFISerial.read());}
  if (Serial.available()){
    WIFISerial.write(Serial.read());
}
   
}

void postData() {

}

