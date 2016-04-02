

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.println("start test memory.");
  testMemory();
  Serial.println("test memory done.");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void testMemory(){
   const int L = 200000;
   byte m[L];

  for (int i = 0 ; i < L ; i++) {
      for (int j = 0 ; j < 255; j++) {
        m[i] = j;
        if (j != m[i]) {
          unsigned char* add = &m[i];
          Serial.print("bad memory at:0X");
          Serial.println((int)add, HEX);
        }
      }    
  }
}

