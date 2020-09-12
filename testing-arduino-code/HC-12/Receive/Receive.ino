/*    Arduino Long Range Wireless Communication using HC-12
                      Example 01
*/
#include <SoftwareSerial.h>
SoftwareSerial HC12(63, 47); // HC-12 TX Pin (63 = A9), HC-12 RX Pin
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);// Serial port to HC12
}
void loop() {
  while (HC12.available()) {        // If HC-12 has data
  Serial.write(HC12.read());      // Send the data to Serial monitor
  }
  while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12
  }
}
