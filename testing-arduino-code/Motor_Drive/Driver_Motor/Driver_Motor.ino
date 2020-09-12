#define IN1 16
#define IN2 17
#define IN3 12
#define IN4 44
#define EN1 46
#define EN2 45
void setup() {
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(EN1,OUTPUT);
pinMode(EN2,OUTPUT);
}

void loop() {
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
analogWrite(EN1,50);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
analogWrite(EN2,255);
}
