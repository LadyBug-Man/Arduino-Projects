/* HID KeyBoard Example
   by: Jim Lindblom
   date: 1/12/2012
   license: MIT License - Feel free to use this code for any purpose.
   No restrictions. Just keep this license if you go on to use this
   code in your future endeavors! Reuse and share.

   This is very simplistic code that allows you to send a 'z' with
   a momentary pushbutton.
*/

#include <Keyboard.h>
int buttonPin = 9;  // Set a button to any pin

void setup()
{
  pinMode(buttonPin, INPUT);  // Set the button as an input
  digitalWrite(buttonPin, HIGH);  // Pull the button high

  Keyboard.begin(); //Init keyboard emulation
}

void loop()
{
  if (digitalRead(buttonPin) == 0)  // if the button goes low
  {
    //Keyboard.print("Testing");  // send a 'z' to the computer via Keyboard HID
    //Keyboard.press(KEY_LEFT_GUI);
    //Keyboard.press(KEY_RIGHT_SHIFT);
    //Keyboard.press('3');
    Keyboard.press('/');
   // delay(1000);  // delay so there aren't a kajillion z's
   // Keyboard.releaseAll();
  }
  if (digitalRead(buttonPin) == 1)
  {
    //delay(1000);
    Keyboard.releaseAll();
  }
}
