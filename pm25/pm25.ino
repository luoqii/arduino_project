#include <SoftwareSerial.h>

/**
 * 
 */
SoftwareSerial pm(11, 12); // RX, TX
#define BAUD 9600

#define BT_RXD 8
#define BT_TXD 9
#define BAUD 9600

SoftwareSerial bt(BT_RXD, BT_TXD);

// keep sync with rawData's length
int DATA_LENGTH = 2 + 2 + 13 * 2 + 2;
byte rawData[32];

boolean HAS_42 = false;
boolean HAS_4d = false;
byte C_0X42 = 4 * 16 + 2 * 1;
byte C_0X4D = 4 * 16 + 13 * 1;
byte index = -1;
char currentData;
char lastData;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(BAUD);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  pm.begin(BAUD);
  pm.println("Hello, world?");

  rawData[0] = C_0X42;
  rawData[1] = C_0X4D;

      Serial.println("bt begin");
      bt.begin(BAUD);
      Serial.println("bt begin finish.");
}

void loop() { // run over and over
  pm.listen();
  //https://www.arduino.cc/en/Tutorial/TwoPortReceive
  if (pm.available()) {
    lastData = currentData;
    currentData = pm.read();

    if (lastData == C_0X42 && currentData == C_0X4D) {
      //    Serial.print("new data avaiable.");
      index = 1;
    }

    if (index > -1 && index < DATA_LENGTH) {
      rawData[index] = currentData;
    } else if (index == DATA_LENGTH) {
      showData();
    }

    index++;
    //    Serial.print(c,HEX);
    //    Serial.write(mySerial.read());


  } else {
    //Serial.println("pm is not available.");
  }

}

void showData() {
  //    Serial.print("data: ");
  //    for (int i = 0 ; i < DATA_LENGTH ; i++) {
  //      if (i == 2
  //          || (i > 2 && i < 32 && i % 2 == 0)
  //        ) {
  //        Serial.print("\t");
  //      }
  //      Serial.print(rawData[i], 16);
  //    }
  //    Serial.println("");

  //        Serial.print("data: ");
  //    for (int i = 0 ; i < DATA_LENGTH ; i++) {
  //      if (i == 2
  //          || (i > 2 && i < 32 && i % 2 == 0)
  //        ) {
  //        Serial.print("\t");
  //      }
  //      Serial.print(rawData[i]);
  //    }
  //    Serial.println("");

  Serial.print("data: ");
  Serial.print("S-Flag");

  Serial.print("\tL=");
  Serial.print(getData(2));

  {
    Serial.print("\t[.1=");
    Serial.print(getData(4));

    Serial.print("\t2.5=");
    Serial.print(getData(6));

    Serial.print("\t10=");
    Serial.print(getData(8));
    Serial.print("]");
  }

  {
    Serial.print("\t[.1=");
    Serial.print(getData(10));

    Serial.print("\t2.5=");
    Serial.print(getData(12));

    Serial.print("\t10=");
    Serial.print(getData(14));
    Serial.print("]");
  }

  {
    Serial.print("\t[.3=");
    Serial.print(getData(16));

    Serial.print("\t.5=");
    Serial.print(getData(18));

    Serial.print("\t1.=");
    Serial.print(getData(20));

    Serial.print("\t2.5=");
    Serial.print(getData(22));

    Serial.print("\t5.=");
    Serial.print(getData(24));

    Serial.print("\t10=");
    Serial.print(getData(24));
    Serial.print("]");
  }

  Serial.println("");

  bt.listen();
  Serial.println("sent to bt:");
//  String data = "";
//  for (int i = 0 ; i < 24 ; i++){
//   // bt.write(rawData[i]);
//    data = data + String(rawData[i], HEX);
//    Serial.print(rawData[i], HEX);
//  }
    bt.write(rawData, DATA_LENGTH);
//  Serial.println("");
//  Serial.print("data:");
//  Serial.println(data);
//  bt.print(data);
  delay(1000);
}

int getData(int startIndex) {
  int data = -1;
  byte h = String(rawData[startIndex]).toInt();
  byte l = String(rawData[startIndex + 1]).toInt();
  data = h * 256 + l;
  return data;
}

int getData_X(int startIndex) {
  int data = -1;
  data = rawData[startIndex] * 256 + rawData[startIndex + 1];
  return data;
}


