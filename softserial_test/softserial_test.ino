#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(57600);
  mySerial.begin(57600);
  Serial.println("Waiting");
}

void loop() {
  if(mySerial.available()) {
    int d = (int)mySerial.read(); 
    
    Serial.println(d); // print value when serial available
  }
  
  Serial.println(1); // print 1 on every loop
}
