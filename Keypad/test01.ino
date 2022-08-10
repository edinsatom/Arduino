#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'#', '0', '*', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {2, 3, 4, 5};
byte count;
char password[5];
char validPass[5] = "0620";

Keypad keypad1 = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad1.getKey();

  if (key != NO_KEY) {
    password[count] = key;
    Serial.print(key);
    count++;
  }

  if (count == 4) {
    if (!strcmp(password, validPass))
      Serial.println(" Correcta!");
    else
      Serial.println(" Incorrecta!");
    count = 0;
  }
}