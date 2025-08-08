
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



void setup()
{
  Serial.begin(9600);
  lcd.begin(20,4);
  //lcd.backlight();  
  
  
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("PIR-Ce");
  lcd.setCursor(1,1);
  lcd.print("Need Anything?");
}


void loop()
{

}

