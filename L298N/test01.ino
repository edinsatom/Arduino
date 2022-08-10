const byte OUT1 = 2;
const byte ENA = 3;
const byte OUT2 = 4;
const byte ENB = 11;
const byte OUT3 = 12;
const byte OUT4 = 13;

short velocity;

void setup()
{
    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);
    pinMode(ENA, OUTPUT);

    pinMode(OUT3, OUTPUT);
    pinMode(OUT4, OUTPUT);
    pinMode(ENB, OUTPUT);
}

void loop()
{
    velocity = 100;
    foward(velocity);
    delay(3000);

    stop();
    delay(2000);

    back(velocity);
    delay(3000);
}

void foward(short vel)
{
    analogWrite(ENA, vel);
    analogWrite(ENB, vel);
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
}

void back(short vel)
{
    analogWrite(ENA, vel);
    analogWrite(ENB, vel);
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, HIGH);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, HIGH);
}

void stop(){
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}