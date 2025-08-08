int dataPin = 2;
int latchPin = 3;
int clockPin = 4;

byte leds = 0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  leds = 0;
  updateShiftRegister();
  delay(500);
  for(int i = 0; i < 4; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
   }
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
