#define B1 40
#define B2 41
#define Relay 42
#define D_LED 38
void setup() {
pinMode(B1,INPUT);
pinMode(B2,INPUT);
pinMode(Relay,OUTPUT);
pinMode(D_LED,OUTPUT);

}

void loop() {
if (digitalRead(B1) == 0){
  digitalWrite(Relay,HIGH);
  }
else{
  digitalWrite(Relay,LOW);
  }
if (digitalRead(B2) == 0){
  digitalWrite(D_LED,HIGH);
  }
else{
  digitalWrite(D_LED,LOW);
  } 
}
