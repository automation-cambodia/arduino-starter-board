// Code for AT command Mode of HC-12
#include <SoftwareSerial.h>

SoftwareSerial mySerial(63, 47); // RX, TX (63 = A9)

void setup() {

Serial.begin(9600);

pinMode(62,OUTPUT); digitalWrite(62,LOW); // Select SET pin to GND for AT Command Mode (62 = A8)

Serial.println("Enter AT commands:");

mySerial.begin(9600);

}

void loop()

{

if (mySerial.available())

Serial.write(mySerial.read());

if (Serial.available())

mySerial.write(Serial.read());

}
