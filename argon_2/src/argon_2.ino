#include <Wire.h>
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
char x;
// setup() runs once, when the device is first turned on.
void setup() {
  Wire.begin(0x2A);
  Wire.onReceive(receiveEvent); // in setup
  Wire.onRequest(requestEvent);
  pinMode(D6,OUTPUT);
  pinMode(D5,INPUT);
  Serial.begin(9600);
  // Put initialization like pinMode and begin functions here.

}
// to recive data from master
void receiveEvent(int howMany) {
  x = Wire.read();       
}
//to send requested data to master
void requestEvent() {
  Wire.write(digitalRead(D5));
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  //if master enters 1 switch the led on
  if(x == '1'){
    digitalWrite(D6,HIGH);
  }
  //if master enters 0 switch the led off
  if(x == '0'){
    digitalWrite(D6,LOW);
  }

  // The core of your code will likely live here.

}