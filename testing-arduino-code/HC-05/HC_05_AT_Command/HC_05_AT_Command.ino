#include <SoftwareSerial.h>

SoftwareSerial mySerial(64, 65); // RX, TX

void setup() {

Serial.begin(9600);

pinMode(13,OUTPUT); digitalWrite(13,HIGH);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{

if (mySerial.available())

Serial.write(mySerial.read());

if (Serial.available())

mySerial.write(Serial.read());

}
