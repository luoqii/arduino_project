//http://www.arduino.cn/thread-11019-1-1.html
#include <SoftwareSerial.h>
unsigned long lastTime;
SoftwareSerial WIFISerial(8, 9); // RX, TX
 
//---------------------------------------------------------------------
void setup()  
{
  pinMode(13,OUTPUT);
 
  Serial.begin(9600);
  WIFISerial.begin(9600);
 
  delay(300);
  WIFISerial.println("AT+RST");
   
  lastTime=millis();
}
//---------------------------------------------------------------------
void loop() {
 
 
 
unsigned long tmpTime=millis();
if (tmpTime-lastTime==5000) {
WIFISerial.println("AT+CIPSTART=\"TCP\",\"api.yeelink.net\",80");
digitalWrite(13,HIGH);
}
 
tmpTime=millis();
if (tmpTime-lastTime==8000) {
 
int a1val = analogRead(3);
Serial.print("VAL:");
Serial.println(a1val);
String hcontent = sendData(a1val,"你的yeelink api",设备id,传感器id);
postHTTP(hcontent); 
}
 
tmpTime=millis();
if (tmpTime-lastTime==10000) {
WIFISerial.println("AT+CIPCLOSE");
digitalWrite(13,LOW);
}
 
tmpTime=millis();
if (tmpTime-lastTime>=30000) {
lastTime=millis();
}
 
 
    
  if (WIFISerial.available())
    Serial.write(WIFISerial.read());
  if (Serial.available())
    WIFISerial.write(Serial.read());
}
 
 
 
//==========================================================
void postHTTP(String ptxt)
{
WIFISerial.print("AT+CIPSEND=");
WIFISerial.println(ptxt.length()+2);
WIFISerial.println(ptxt);
//delay(300);
 
}
 
//==========================================================
//完整模块
//用法：Serial.print(sendData(123,"APIKEY",DEVICEID,SENSORID));
 
String sendData(int SensorData , String APIKEY , int DEVICEID ,int SENSORID) {
  String pData="";
  pData+="POST /v1.0/device/";
  pData+=DEVICEID;
  pData+="/sensor/";
  pData+=SENSORID;
  pData+="/datapoints HTTP/1.1\r\nHost: api.yeelink.net\r\nAccept: */*\r\nU-ApiKey: ";
  pData+=APIKEY;
  pData+="\r\nContent-Length: ";
  int thisLength = 10 + getLength(SensorData);
  pData+=thisLength;
  pData+="\r\nContent-Type: application/x-www-form-urlencoded\r\nConnection: close\r\n\r\n";
  // PUT回复内容
  pData+="{\"value\":";
  pData+=SensorData;
  pData+="}\r\n\r\n";
  return pData;
}
 
int getLength(int someValue) {
  int digits = 1;
  int dividend = someValue /10;
  while (dividend > 0) {
    dividend = dividend /10;
    digits++;
  }
  return digits;
}
//完整模块结束
//==========================================================
