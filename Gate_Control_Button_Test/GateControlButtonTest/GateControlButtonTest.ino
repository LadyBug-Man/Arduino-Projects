#include <Servo.h>
#include "pitches.h"

// Set digital pin numbers:
const int servoPin = 7; 
const int buttonPin = 9;

int buttonState = 0; 
int directionState = 1;
 
Servo myservo;   
int pos = 0;
 
void setup() {
  myservo.attach(7);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (directionState == 0){
    if (buttonState = HIGH) {
      directionState = 1;
      for(pos = 0; pos < 90; pos=pos+1)
      {
        myservo.write(pos);
        ThemeMusic();
        delay(15);
      }
    }
  } else if (directionState == 1) {
    if (buttonState = HIGH) {
      directionState = 0;
      for(pos = 90; pos>=1; pos=pos-1)
      {
        myservo.write(pos);
        delay(15);
      }
    }
  }  
}

int melody[] = {
  NOTE_C4, NOTE_B3, NOTE_C4, 0, 
  NOTE_C4, NOTE_B3, NOTE_C4, 0, 
  NOTE_C4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_F4, 0,
  NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3, NOTE_G3, 0,
  NOTE_E4, NOTE_C4, NOTE_D4, 0,
  NOTE_E4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, 0,
  NOTE_C4, NOTE_B3, NOTE_C4, NOTE_G3, NOTE_F3,
  NOTE_C4, NOTE_B3, NOTE_C4, NOTE_G3, NOTE_F3,
  NOTE_C4, NOTE_B3, NOTE_B3, NOTE_C4, NOTE_G3,
  NOTE_G3, NOTE_C4, NOTE_B3, NOTE_E4
};

int noteDurations[] = {
  4, 4, 4, 2, 
  4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2,
  4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 2, 2, 2,
  4, 4, 2, 2, 2,
  4, 4, 3, 2, 2,
  2, 1, 2, 2,
};

void ThemeMusic() {
    for (int thisNote = 0; thisNote < 53; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(8);
  }
}
