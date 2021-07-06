/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Abdurrahman/Documents/labs/lab_10/argon_2/src/argon_2.ino"
#include <Wire.h>
void setup();
void receiveEvent(int howMany);
void requestEvent();
void loop();
#line 2 "c:/Users/Abdurrahman/Documents/labs/lab_10/argon_2/src/argon_2.ino"
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
void receiveEvent(int howMany) {
  x = Wire.read();       
}
void requestEvent() {
  Wire.write(digitalRead(D5));
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if(x == '1'){
    digitalWrite(D6,HIGH);
  }
  if(x == '0'){
    digitalWrite(D6,LOW);
  }

  // The core of your code will likely live here.

}