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
  int size = sizeof(data) / sizeof(byte);
  
//  Serial.print("pm:0x");  
//  for (int i = 0 ; i < 24; i++) {
//    Serial.print(data[i], HEX);
//    Serial.print(" ");
//  }
//  Serial.println("");

  //pm.printData();
  
 Serial.print("pm 1.0: ");
 Serial.print(pm.getPm1Cf());
 Serial.print(" 2.5: ");
 Serial.print(pm.getPm2_5Cf());
 Serial.print(" 10: ");
 Serial.print(pm.getPm10Cf());
 
 Serial.print("   1.0:");
 Serial.print(pm.getPm1());
 Serial.print(" 2.5:");
 Serial.print(pm.getPm2_5());
 Serial.print(" 10:");
 Serial.print(pm.getPm10());
 
 Serial.print("   0.3:");
 Serial.print(pm.getPmValue0_3());
 Serial.print(" 0.5:");
 Serial.print(pm.getPmValue0_5());
 Serial.print(" 1.0:");
 Serial.print(pm.getPmValue1());
 Serial.print(" 2.5:");
 Serial.print(pm.getPmValue2_5());
 Serial.print(" 5.0:");
 Serial.print(pm.getPmValue5());
 Serial.print(" 10:");
 Serial.print(pm.getPmValue10());
 Serial.println("");
  
  delay(1000);
}
}
