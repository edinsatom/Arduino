#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

int SENSOR = 6;
int TEMPERATURA = 0;
int lastTemp = 0;
int HUMEDAD = 0;
int lastHum = 0;

DHT dht(SENSOR, DHT11);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hola Jackecita");
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  if(lastTemp != TEMPERATURA || lastHum != HUMEDAD){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura: ");
    lcd.print(TEMPERATURA);
    lcd.setCursor(0, 1);
    lcd.print("Humedad: ");
    lcd.print(HUMEDAD);
    
    lastTemp = TEMPERATURA;
    lastHum = HUMEDAD;
  }

  
  /*
   * if(Serial.available()){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Serial.readString());
  }
  */
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}