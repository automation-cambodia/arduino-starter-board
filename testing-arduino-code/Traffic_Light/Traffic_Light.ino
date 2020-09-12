#define R_LED A3
#define Y_LED A4
#define G_LED A5
void setup() {
pinMode(R_LED, OUTPUT);
pinMode(Y_LED, OUTPUT);
pinMode(G_LED, OUTPUT);

}

void loop() {
digitalWrite(R_LED,HIGH);
digitalWrite(Y_LED,LOW);
digitalWrite(G_LED,LOW);
delay(5000);
digitalWrite(Y_LED,HIGH);
digitalWrite(R_LED,LOW);
digitalWrite(G_LED,LOW);
delay(5000);
digitalWrite(G_LED,HIGH);
digitalWrite(Y_LED,LOW);
digitalWrite(R_LED,LOW);
delay(5000);

}
