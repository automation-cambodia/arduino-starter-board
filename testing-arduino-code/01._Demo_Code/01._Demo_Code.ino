#include <Wire.h> 
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Adafruit_PN532.h>

#define USE_CARD 0 // Using RFID card, cannot use keypad

//RFID Scanner
#define PN532_SCK  (2)
#define PN532_MOSI (3)
#define PN532_SS   (4)
#define PN532_MISO (5)
// If using the breakout or shield with I2C, define just the pins connected
// to the IRQ and reset lines.  Use the values below (2, 3) for the shield!
#define PN532_IRQ   (15)
#define PN532_RESET (14)  // Not connected by default on the NFC Shield

//Keypad password
uint8_t card_id[]={0xA0, 0x58, 0x48, 0x32};
String psw_set = "457D";
String psw_user = "";
uint8_t psw_num = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {28, 27, 26, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {31, 30, 39, 29}; //connect to the column pinouts of the keypad

Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET); //RFID
LiquidCrystal_I2C lcd(0x27, 16, 2);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
   Serial.begin(9600);
   nfc.begin();
   uint32_t versiondata = nfc.getFirmwareVersion();
   if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
   }
   nfc.SAMConfig();
  
   lcd.begin();
   lcd.backlight();
   lcd_print("     LOCKED     ", "  PSW or CARD   ");
}
  
void loop(){
  LCD_KEYPAD_RFID();
}

void LCD_KEYPAD_RFID(){
  if(USE_CARD){
    uint8_t read_card;
    uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
    uint8_t uidLength;
    read_card = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
    if(read_card){
      bool access_card = true;
      for(int i=0; i<4; i++){
        if(uid[i] != card_id[i]) access_card=false;
      }
      if(access_card){
        lcd_print("    UNLOCKED    ", "   Using Card   ");
        delay(2000);
        lcd_print("     LOCKED     ", "  PSW or CARD   ");
      }else{
        lcd_print("     LOCKED     ", "  Unknow Card   ");
        delay(2000);
        lcd_print("     LOCKED     ", "  PSW or CARD   ");
      }
      psw_user="";
      psw_num=0;
    }
  }
  
  char key = keypad.getKey();
  if (key){
    if(key=='*'){
      if(psw_user == psw_set){
        lcd_print("    UNLOCKED    ", " Using Password ");
        delay(2000);
        lcd_print("     LOCKED     ", "  PSW or CARD   ");
      }else{
        lcd_print("     LOCKED     ", " Wrong Password ");
        delay(2000);
        lcd_print("     LOCKED     ", "  PSW or CARD   ");
      }
      psw_user="";
      psw_num=0;
    }else{
      psw_user += key;
      psw_num++;
      Serial.println(psw_user);
    }
  }

  if(psw_num != 0){
    String psw_star="                ";
    for(int i=0; i<psw_num; i++){
      psw_star[i]='*';
    }
    lcd_print("     LOCKED     ", psw_star);
  }
}

void lcd_print(String row0, String row1){
  lcd.setCursor(0, 0);
  lcd.print(row0);
  lcd.setCursor(0, 1);
  lcd.print(row1);
}
