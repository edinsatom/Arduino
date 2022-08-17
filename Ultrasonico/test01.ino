const byte TRIG = 10;
const byte ECHO = 9;
const byte LED = 3;

const float HC_SR04_CONSTANT = 58.2;

int duration;
int distance;
int lastDistance = 0;

void setup()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    digitalWrite(TRIG, HIGH);
    delay(1);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    distance = duration / HC_SR04_CONSTANT;

    if (distance > 0 && distance != lastDistance)
    {
        Serial.println(distance);
        delay(200);
        lastDistance = distance;

        if (distance < 20)
        {
            digitalWrite(LED, HIGH);
            delay(distance * 10);
            digitalWrite(LED, LOW);
        }
    }
}