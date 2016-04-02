//http://www.arduino.cn/thread-11019-1-1.html
/**

  AT+GMR
  AT version:0.40.0.0(Aug  8 2014 14:45:58)
  SDK versioo:1.3-TCB.54
*/
#include <SoftwareSerial.h>
#define SPEED 9600
#define SPEED 115200

SoftwareSerial WIFISerial(8, 9); // RX, TX

void setup()
{
  Serial.begin(SPEED);
  WIFISerial.begin(SPEED);
}

// TODO
void loop() {
  if (WIFISerial.available()) {
    Serial.print("<<<");
    do {
      Serial.write(WIFISerial.read());
    }  while (WIFISerial.available());
  }

  if (Serial.available()) {
    Serial.print(">>>");
    do {
      WIFISerial.write(Serial.read());
    } while (Serial.available());
  }
}


