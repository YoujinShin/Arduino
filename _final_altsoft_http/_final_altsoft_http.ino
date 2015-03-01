#include <AltSoftSerial.h> // rx: 13, tx: 5
#include <Bridge.h>
#include <HttpClient.h>

// serial
AltSoftSerial altSerial;
char c;

// http
float w = 0;
float h = 0;
float t = 0;
float b = 0;

const int field_num = 4;
int field_index = 0;
int values[field_num];
String url = "http://vitaldata.herokuapp.com/vitals?";

// input string
String inputString = "";
boolean stringComplete = false; 

// output string
String message = "";
int commaPosition;

void setup() {
  // http
  Bridge.begin();
  
  // serial
  Serial.begin(57600);
  while(!Serial);
  Serial.println("AltSoftSerial Test Begin");
  
  altSerial.begin(57600);
//  altSerial.println("Hello World");
  
  // input string
  //inputString.reserve(200);
}

void loop() {
  // input string
  if(stringComplete) {
    //Serial.println(inputString);

    //  output string
    message = inputString;
    
    // first data
    commaPosition = message.indexOf(',');
    w = message.substring(0, commaPosition).toInt();
    message = message.substring(commaPosition+1, message.length());
//    Serial.println(w);
    
    // second data
    commaPosition = message.indexOf(',');
    h = (int)message.substring(0, commaPosition).toInt();
    message = message.substring(commaPosition+1, message.length());
//    Serial.println(h);
    
    // third data
    commaPosition = message.indexOf(',');
    t = (int)message.substring(0, commaPosition).toInt();
    message = message.substring(commaPosition+1, message.length());
//    Serial.println(t);
    
    // fourth data
    commaPosition = message.indexOf(',');
    b = (int)message.substring(0, commaPosition).toInt();
    message = message.substring(commaPosition+1, message.length());
//    Serial.println(b);
    
    // http
    HttpClient client;
    client.get(url+"height="+h+"&weight="+w+"&bpm="+b+"&temp="+t); 
    
    
    // input string reset
    inputString = "";
    stringComplete = false;
    
  }// end of 'string complete
  
  // serial
  if(Serial.available()) {
    c = Serial.read();
    altSerial.print(c);
  }
  
  if(altSerial.available()) {
    c = altSerial.read();
//    Serial.print(c);
    
    inputString += c; 
    if(c == '\r') { // in can be '\r\n'
//    if(c == '\n') { 
      stringComplete = true;
    }

    // http
//    HttpClient client;
//    client.get(url+"height="+h+"&weight="+w+"&bpm="+b+"&temp="+t); 
    
    
  }
}
