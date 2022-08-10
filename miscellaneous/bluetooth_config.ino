/*
  This project test is about Bluetooth module and allow send commands from Serial monitor
  some commands are:

  AT+NAME[name]
  AT+PIN[pin]
*/
#include <SoftwareSerial.h>

byte rx = 13;
byte tx = 12;


SoftwareSerial testBluetooth(rx, tx);


void setup(){
  testBluetooth.begin(9600);
  Serial.begin(9600);
}

void loop(){
  if(testBluetooth.available())
    Serial.write(testBluetooth.read());

  if(Serial.available())
    testBluetooth.write(Serial.read());
}