

const byte LED = 13;

void setup()
{
	pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
	digitalWrite(LED, HIGH);
    delay(400);
    digitalWrite(LED, LOW);
    delay(500);
}
