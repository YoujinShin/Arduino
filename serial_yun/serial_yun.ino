void setup() {
  // put your setup code here, to run once:
  Serial.println("HEY");
  
  Serial.begin(57600);
  Serial1.begin(57600);
  while (!Serial) {}
  
  Serial.println("Waiting");
}

void loop() {
//  Serial.println("loop");
  
  // put your main code here, to run repeatedly:
  if(Serial1.available()) {
    char c = (char)Serial1.read();
    Serial.write(c);
    
//    Serial.println("OKAY1");
  }
  
  if(Serial.available()) {
    char c1 = (char)Serial.read();
    Serial.println(c1);
  }
}
