#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

// values 
float w = 0;
float h = 0;
float t = 0;
float b = 0;

//int d = 0;
int cnt = 0;
int cnt2 = 0;
boolean done = false;

const int num_field = 4; // how many comma-separated fields we expect
int fieldIndex = 0;             // the current field being received
int values[num_field];   // array holding values for all the fields

void setup() {
  Serial.begin(57600);
  mySerial.begin(57600);
  Serial.println("Waiting");
}

void loop() {
  if(mySerial.available()) {
    int d = (int)mySerial.read(); 
    
    Serial.println(d);
////    Serial.println(d);
//    Serial.println(cnt);
//    
//    if(cnt = 0) { 
//      w == d; 
//    } else if(cnt == 1) { h == d; }
//    else if(cnt == 2) { t == d; }
//    else if(cnt == 3) { b == d; }
//    
//    cnt = cnt + 1;
////    done = true;
////    Serial.println(0);
////    
//    if(cnt == 4) {
////      Serial.println(1);
//      cnt = 0;
//    }
  }
  
  Serial.println(1);
  
//  cnt2 = cnt2 + 1;
//  
//  if(cnt2 > 3) {
//    cnt = 0;
//  }

//  if(done == true) Serial.println("---------------------------");
  
//  if(Serial.available()) {
////    char d2 = (char)Serial.read(); 
//    char d2 = (char)Serial.read(); // int or char
//    Serial.println(d2);
////    for(fieldIndex = 0; fieldIndex < 4; fieldIndex ++) {
////       values[fieldIndex] = Serial.parseInt(); // get a numeric value
////       Serial.println(values[fieldIndex]);
////     }
////     
////     fieldIndex = 0;
//  }
}
