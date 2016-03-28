#include <SoftwareSerial.h>
#include "Pms5003.h"
#define BAD_DATA_LENGTH 20
/**
 *  BT VCC  <==> UNO VCC 5v
 *  BT GND <==> UNO GND
 *  BT RXD <==> UNO d9
 *  BT TXD <==> UNO d8
 *  
 *  PM VCC <==> UNO VCC
 *  PM DND <==> UNO GND
 *  PM TXD <==> d11
 */

#define BT_RXD 8
#define BT_TXD 9
#define BAUD 9600

SoftwareSerial bt(BT_RXD, BT_TXD);
Pms5003 pm(11, 12);; // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(BAUD);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  pm.begin(BAUD);

  Serial.println("bt begin");
  bt.begin(BAUD);
  Serial.println("bt begin finish.");
}

void loop() { // run over and over
  pm.listen();
  pm.loop();
  //https://www.arduino.cc/en/Tutorial/TwoPortReceive
  if (pm.available()) {
//   byte* data = pm.getData();
//   int size = sizeof(data)/ sizeof(byte);
//   Serial.print("size:");
//   Serial.println(size);
  pm.printData();

   bt.listen();
   Serial.println("send by bt");
   bt.write(pm.getData(), PM_DATA_LENTH);
   Serial.println("send by bt done.");
   delay(4000);
  } else {
    //Serial.println("pm is not available.");
  }
}



