#include "pitches.h"


// notes in the melody:
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

// note durations: 4 = quarter note, 8 = eighth note, etc.:
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

void setup() {
  for (int thisNote = 0; thisNote < 53; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
