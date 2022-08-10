#include <SoftwareSerial.h>

byte rx = 13;
byte tx = 12;

SoftwareSerial miBT(rx, tx);

const byte LED = 3;

char data = 0;
short bright = 0;

void setup()
{
  // put your setup code here, to run once:
  miBT.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (miBT.available())
  {
    data = miBT.read();

    if (data == '1')
    {
      bright += 10;
      if (bright > 255)
      {
        bright = 255;
      }
      Serial.println(bright);
      analogWrite(LED, bright);
    }
    else if (data == '0')
    {
      digitalWrite(LED, LOW);
      bright = 0;
    }
  }
}