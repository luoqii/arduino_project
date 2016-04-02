#include <SoftwareSerial.h>

#define BAUD 9600
#define BAUD 115200
SoftwareSerial esp8266(8, 9);

void setup() {
  Serial.begin(BAUD);
  Serial.println("Serial begin finish.");
  esp8266.begin(BAUD);
  Serial.println("esp8266 begin finish.");

  delay(300);
  esp8266.println("AT+RST");
}

void loop() {
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }

  if (Serial.available()) {
    esp8266.write(Serial.read());
    //Serial.write(Serial.read());
  }
}
