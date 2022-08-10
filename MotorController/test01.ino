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
    velocity = 100;

    run(velocity);
    delay(3000);

    stop();
    delay(2000);

    runRight(velocity);
    delay(3000);
    
    stop();
    delay(2000);
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
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}