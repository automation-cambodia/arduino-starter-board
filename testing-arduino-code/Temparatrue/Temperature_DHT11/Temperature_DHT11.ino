#include<dht.h>
dht DHT11;

#define DHT11_PIN 4

void setup() {

Serial.begin(9600);
Serial.println("DHT11 SFE Electronics"); 
}

void loop() { 

int chk = DHT11.read11(DHT11_PIN);

Serial.print(" Humidity " );
Serial.print(DHT11.humidity, 1);
Serial.print("      ");
Serial.print(" Temparature ");
Serial.println(DHT11.temperature, 1);
delay(2000);

}
