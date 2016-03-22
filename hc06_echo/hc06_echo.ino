#include <SoftwareSerial.h>

/*
 * ARDUINO UNO R3               hc06
 * d8                         <==>    TXD
 * d9                        <==>     RXD
 * VCC                     <==>     3.3v
 * GND                    <==>      GND
 */
#define BT_RXD 8
#define BT_TXD 9
#define BAUD 9600

SoftwareSerial BT(BT_RXD, BT_TXD);
char val;

void setup() {
    Serial.begin(BAUD);
    Serial.println("Serial is ready.");

    BT.begin(BAUD);
}

void loop() {
  if (BT.available()) {
    val = BT.read();
    Serial.print("read:");
    Serial.println(val);
  }

  for (int i = 0 ; i < 255 ; i++) {
    Serial.print("write:");
    Serial.println(i);
    BT.write("abcdefjhijklmn");
//    delay(100);
  }
}

