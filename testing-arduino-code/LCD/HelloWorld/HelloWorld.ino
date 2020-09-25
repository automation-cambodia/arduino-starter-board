//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int i = 0;
int j = 0;
int k = 0;
int delayTime2 = 200; // Delay between shifts

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void scrollInFromRight (int line, char str1[]) {
// Written by R. Jordan Kreindler June 2016
i = strlen(str1);
for (j = 16; j >= 0; j--) {
lcd.setCursor(0, line);
for (k = 0; k <= 15; k++) {
lcd.print(" "); // Clear line
}
lcd.setCursor(j, line);
lcd.print(str1);
delay(delayTime2);
}
}

void scrollInFromLeft (int line, char str1[]) {
// Written by R. Jordan Kreindler June 2016
i = 40 - strlen(str1);
line = line - 1;
for (j = i; j <= i + 16; j++) {
for (k = 0; k <= 15; k++) {
lcd.print(" "); // Clear line
}
lcd.setCursor(j, line);
lcd.print(str1);
delay(delayTime2);
}
}

void setup()
{
 Serial.begin(9600);
Serial.println("Starting test ...");
lcd.begin();
lcd.clear();
lcd.print("Test Only");

lcd.init();                      // initialize the lcd 
lcd.init();
  // Print a message to the LCD.
lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("Hello, world!");
//  lcd.setCursor(0,1);
//  lcd.print("ARDUINO_STARTER");
//  lcd.setCursor(0,2);
//  lcd.print("Arduino 2020");
//   lcd.setCursor(2,3);
//  lcd.print("Automation");
}


void loop()
{
lcd.clear();
scrollInFromRight(0, "Arduino Starter");
scrollInFromRight(1, "Kit");
lcd.clear();
scrollInFromLeft(0, "Automation   ");
scrollInFromLeft(1, "Cambodia");
lcd.clear();
scrollInFromRight(0, "Thank You !-!");
scrollInFromLeft(1, "For Testing !!!");
lcd.clear();
}
