//http://www.arduino.cn/thread-11019-1-1.html
/**

  AT+GMR
AT+CWMODE_CUR=1
AT+CWJAP_CUR="Tenda_098C40","bangyuan"
AT+CIPSTATUS
AT+CIPSTART="TCP","www.baidu.com",80


*/
#include <SoftwareSerial.h>

// XXX must use 2 different speed fuck.
#define SPEED_SERIAL 9600
//#define SPEED_SERIAL 115200
#define SPEED_ESP 115200
//#define SPEED_ESP 9600

SoftwareSerial wifi(8, 9); // RX, TX

void setup()
{
  Serial.begin(SPEED_SERIAL, SERIAL_8N1);
  wifi.begin(SPEED_ESP);

  delay(3000);
  execCmd("AT");
  //execCmd("AT+RST");
  delay(5000);
  execCmd("AT+GMR");  
  delay(1000);
  execCmd("AT+CWJAP_CUR=\"Tenda_098C40\",\"bangyuan\"");
  delay(1000);
  execCmd("AT+CIPSTATUS");
  delay(1000);
  execCmd("AT+CIPSTART=\"TCP\",\"www.baidu.com\",80");
  delay(1000);
  execCmd("AT+CIPSTATUS");
  delay(1000);
}

void loop() {
  dump();
}

void execCmd(String cmd) {  
  Serial.println("AT@CMD:" + cmd);
  wifi.println(cmd + "\r\n");
  //consumeWifiOutput();
}

void consumeWifiOutput(){
  int timeout = 3*1000;
  unsigned long start = millis();
  String out = "";
  while ( millis() - start < timeout) {
   while (wifi.available()) {
       char c = wifi.read();
        Serial.write(c);
        out += c;
   }
  }
  Serial.print("out:");
  Serial.println(out);
}

void dump(){
  
  if (wifi.available()) {
    Serial.write(wifi.read());
  }

  if (Serial.available()) {
    wifi.write(Serial.read());
  }
}


