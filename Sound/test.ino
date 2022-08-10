
const byte LED = 13;
const byte SOUND_SENSOR_DIGITAL = 10;
const byte SOUND_SENSOR_ANALOG = A0;
const byte LED_OUTPUT = 2;

int vDelay = 500;
int valor;
int estado;
byte temp;

void setup()
{
	pinMode(LED, OUTPUT);

    pinMode(SOUND_SENSOR_DIGITAL, INPUT);
    pinMode(LED_OUTPUT, OUTPUT);

    // Serial.begin(115200);
}

void loop()
{
    temp = 0;
    if(digitalRead(SOUND_SENSOR_DIGITAL) == HIGH)
    {
	    digitalWrite(LED, HIGH);
        estado = digitalRead(LED_OUTPUT);
        digitalWrite(LED_OUTPUT, !estado);
        delay(500);
    }
    
	digitalWrite(LED, LOW);
}
