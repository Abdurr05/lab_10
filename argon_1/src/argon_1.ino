#include <Wire.h>
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
char value;

// setup() runs once, when the device is first turned on.6
void setup() {
  Serial.begin(9600);
  while (!Serial.isConnected());
  Serial.println("serial is connected");
  Wire.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // to read from serial and send it to the slave
  if(Serial.available()>0){
    value = Serial.read();
    Serial.println(value);
    Wire.beginTransmission(0x2A);
    Wire.write(value);
    Wire.endTransmission();
  }

  // request data from the slave if the user enters "?"
  if(value == '?'){
    Wire.requestFrom(0x2A, 1);
    while (Wire.available() == 0);
    int buttonValue = Wire.read();
    Serial.println(buttonValue);
    delay(1000);
    value = 'n';
  }
  
}