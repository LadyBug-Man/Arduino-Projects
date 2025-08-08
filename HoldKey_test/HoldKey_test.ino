#include <Keypad.h>
#include "Keyboard.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char holdKey;
unsigned long t_hold;

void setup(){
  Serial.begin(9600);
  Keyboard.begin();
}
 
void loop(){
  char key = keypad.getKey();
 
   if (key){
     holdKey = key;
     //Serial.println(key);
   }
 
   if (keypad.getState() == HOLD) {
      if ((millis() - t_hold) > 100 ) {
          switch (holdKey) {
              case '1':
                  Keyboard.press('/');
                  break;
              case '2':
                  Serial.println("Move Up");
                  break;
              case '5':
                  Serial.println("Move Right");
          }
          t_hold = millis();
          Keyboard.releaseAll();
      }
   }
}
