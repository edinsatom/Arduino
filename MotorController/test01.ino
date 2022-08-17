byte in1 = 2;
byte in2 = 3;
byte enA = 5;

byte in3 = 7;
byte in4 = 8;
byte enB = 9;

short velocity;

void setup(){
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(enB, OUTPUT);
}

void loop(){
    // digitalWrite(enA, HIGH);
    // digitalWrite(in1, LOW);
    // digitalWrite(in2, HIGH);

    // digitalWrite(enB, HIGH);
    // digitalWrite(in3, LOW);
    // digitalWrite(in4, HIGH);

    // delay(3000);

    // digitalWrite(enA, LOW);
    // digitalWrite(enB, LOW);
    // delay(2000);
    velocity = 100;

    run(velocity);
    delay(2000);

    stop();
    delay(800);

    runRight(velocity);
    delay(3000);
    
    stop();
    delay(800);
}

void run(short vel){
    runLeft(vel);
    runRight(vel);
}

void runLeft(short vel){
    analogWrite(enA, vel);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void runRight(short vel){
    analogWrite(enB, vel);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void stop(){
    analogWrite(enA, LOW);
    analogWrite(enB, LOW);
}