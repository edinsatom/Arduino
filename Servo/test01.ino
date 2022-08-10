#include <Servo.h>

Servo servo1;

byte pinServo = 3;

int pulsoMin = 500;
int pulsoMax = 2400;
int vDelay = 1200;

void setup()
{
    servo1.attach(pinServo, pulsoMin, pulsoMax);
    Serial.begin(115200);
}

void loop()
{

    byte angle = 0;

    for (angle = 0; angle < 180; angle += 45)
    {
        servo1.write(angle);
        // log("UP to: ", angle);
        delay(vDelay);
    }

    for (angle = 180; angle > 0; angle -= 45)
    {
        servo1.write(angle);
        // log("DOWN to: ", angle);
        delay(vDelay);
    }
}

void log(char message[], int value)
{
    Serial.print(message);
    Serial.println(value);
}
