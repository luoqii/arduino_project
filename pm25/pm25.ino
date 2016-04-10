#include <SoftwareSerial.h>
#include "Nixietube.h"
#include "Pms5003.h"
#define BAD_DATA_LENGTH 20
/**
    BT VCC  <==> UNO VCC 5v
    BT GND <==> UNO GND
    BT RXD <==> UNO d9
    BT TXD <==> UNO d8

    PM VCC <==> UNO VCC
    PM DND <==> UNO GND
    PM TXD <==> d11
*/

int pm25;
Nixietube n( 2, 3, 4, 5, 6, 7, 8,  -1, 9, 10, 11);
#define BT_RXD 12
#define BT_TXD 13

SoftwareSerial bt(BT_RXD, BT_TXD);
Pms5003 pm(14, 15);; // RX, TX

#define BAUD 9600
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
    n.begin();
}

void loopA() { 
  n.showNumber(123);
}
void loop() { // run over and over
  pm.listen();
  pm.loop();
  //https://www.arduino.cc/en/Tutorial/TwoPortReceive
  if (pm.available() 
 //   && false
    ) {
    //   byte* data = pm.getData();
    //   int size = sizeof(data)/ sizeof(byte);
    //   Serial.print("size:");
    //   Serial.println(size);
    pm.printData();

    bt.listen();
    //Serial.println("send by bt");
    bt.write(pm.readData(), PM_DATA_LENTH);
    //Serial.println("send by bt done.");
    //delay(5000);
    pm25 = pm.getPm2_5();
    //pm25 = 888;
  } else {
    //Serial.println("pm is not available.");
  }

    long time = millis();
//    while (pm25 > 0 && millis() - time < 1 * 1000) {
//      //Serial.print("pm25:");
//      //Serial.println(pm25);
//      n.showNumber(pm25);
//      delay(100);
//    }
      n.showNumber(pm25);
}



