#include <SoftwareSerial.h>

// Motor Controller
byte in1 = 2;
byte in2 = 3;
byte enA = 5;

byte in3 = 7;
byte in4 = 8;
byte enB = 9;

// Bluetooth commands
byte rx = 13;
byte tx = 12;

char command;
char lastCommand;
short velocity;

SoftwareSerial roverBT(rx, tx);

void setup()
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);

    roverBT.begin(9600);
    velocity = 100;
    Serial.begin(115200);
}

void loop()
{
    if (roverBT.available())
    {
        stop();
        lastCommand = command;
        command = roverBT.read();
        if (command == 'A')
        {
            velocity = velocity + 25;
            if (velocity > 255)
            {
                velocity = 255;
            }
            Serial.println(velocity);
            command = lastCommand;
        }
        else if (command == 'D')
        {
            velocity -= 25;
            if (velocity < 75)
            {
                velocity = 75;
            }
            Serial.println(velocity);
            command = lastCommand;
        }
    }

    switch (command)
    {
    case 'U':
        run(velocity);
        break;
    case 'L':
        runLeft(velocity);
        break;
    case 'R':
        runRight(velocity);
        break;
    case 'B':
        back(velocity);
        break;
    default:
        stop();
        break;
    }
}

void back(byte vel)
{
    Serial.println("BACK");
    analogWrite(enA, vel);
    analogWrite(enB, vel);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void run(byte vel)
{
    Serial.println("RUN");
    analogWrite(enA, vel);
    analogWrite(enB, vel);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void runLeft(byte vel)
{
    Serial.println("LEFT");
    analogWrite(enA, vel);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void runRight(byte vel)
{
    Serial.println("RIGHT");
    analogWrite(enB, vel);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void stop()
{
    // Serial.println("STOP");
    analogWrite(enA, LOW);
    analogWrite(enB, LOW);
}