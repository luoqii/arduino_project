#include "Pms5003.h"

Pms5003 pm(11, 12);

void setup() {
 Serial.begin(9600);
  pm.setup();
 pm.begin(9600);
}

void loop() {
pm.loop();
if (pm.available()) {
  byte* data = pm.getData();
//  Serial.print("data:0x");  
//  for (int i = 0 ; i < 24; i++) {
//    Serial.print(data[i], HEX);
//    Serial.print(" ");
//  }
}
}
