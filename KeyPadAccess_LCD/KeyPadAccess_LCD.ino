#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//set our code
char* ourCode = "5D6C";
int currentPosition = 0;

//define the keypad
const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {8,7,6,9};
byte colPins[cols] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.begin(20,4);
  lcd.backlight();
  displayCodeEntryScreen();
  
}

void loop()
{
  int l;
  char key = keypad.getKey();
  if (int(key) != 0) {
    lcd.setCursor(14,3);
    lcd.print("    ");
    lcd.setCursor(14,3);
    for (l=0; l<=currentPosition; ++l)
    {
      lcd.print("*");
    }
    if (key == ourCode[currentPosition])
      {
        ++currentPosition;
        if (currentPosition == 4)
        {
          unlockDoor();
          currentPosition = 0;
        }
      } else {
        invalidCode();
        currentPosition = 0;
      }
  }
}

void invalidCode()
{
  clearScreen();
  lcd.setCursor(1,0);
  lcd.print("ACCESS DENIED!");
  lcd.setCursor(2,1);
  lcd.print("INVALID CODE");

  delay(5000);
  displayCodeEntryScreen();
}

void unlockDoor()
{
  clearScreen();
  lcd.setCursor(1,0);
  lcd.print("ACCESS GRANTED");
  lcd.setCursor(4,1);
  lcd.print("WELCOME!");
  
  //add any code to unlock the door here
  delay(5000);
  displayCodeEntryScreen();
}

void displayCodeEntryScreen()
{
  clearScreen();
  lcd.setCursor(1,0);
  lcd.print("Enter The Code");
  lcd.setCursor(0,1);
  lcd.print("So You May Enter");
}

void clearScreen()
{
  lcd.setCursor(0,0);
  lcd.print("                    ");
  lcd.setCursor(0,1);
  lcd.print("                    ");
  lcd.setCursor(0,2);
  lcd.print("                    ");
  lcd.setCursor(0,3);
  lcd.print("                    ");
}
