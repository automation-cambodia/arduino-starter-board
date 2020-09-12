#define IR A2
#define LDR A0
void setup() {
pinMode(IR,INPUT);
pinMode(LDR,INPUT);
Serial.begin(9600);
}

void loop() {
Serial.print("IR");
Serial.print(" : ");
Serial.print(analogRead(IR));
Serial.print(",");
Serial.print(" LDR ");
Serial.print(" : ");
Serial.println(analogRead(LDR));

}
