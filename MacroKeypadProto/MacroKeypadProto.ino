
#include "Keyboard.h"

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'},
};

byte rowPins[ROWS] = {6, 5, 4, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}


void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
      //Pen_Pencil shortcut
        Keyboard.press('p');
        break;
      case '2':
      //Zoom shortcut
        Keyboard.press('/');
        break;
      case '3':
      //Brush shortcut
        Keyboard.press('b');
        break;
      case '4':
      //Eraser shortcut
        Keyboard.press('e');
        break;
      case '5':
      //Eyedropper tool shortcut
        Keyboard.press('i');
        break;
      case '6':
      //Redo shortcut
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press('y');
        break;
      case '7':
      //Undo shortcut
         Keyboard.press(KEY_LEFT_GUI);
         Keyboard.press('z');
        break;
      case '8':
      //Rotate shortcut
         Keyboard.press('r');
        break;
      case '9':
      //Hand tool shortcut
         Keyboard.press(' ');
        break;
      case '0':
       // Keyboard.press('');
        break;
      case '*':
       // Keyboard.press('');
        break;
      case '#':
       // Keyboard.press('');
        break;
      case 'A':
       // Keyboard.press('');
        break;
      case 'B':
       // Keyboard.press('');
        break;
      case 'C':
       // Keyboard.press('');
        break;
      case 'D':
       // Keyboard.press('');
        break;
    }
  }
  if( keypad.getState() == RELEASED) //replace HOLD with IDLE, PRESSED, RELEASED
          {
             //delay(100);
             Keyboard.releaseAll();
      }
}
