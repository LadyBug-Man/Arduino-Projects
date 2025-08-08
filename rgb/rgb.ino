int redLedPin = 11;
int greenLedPin = 10;
int blueLedPin = 9;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop()  {
  analogWrite(blueLedPin, random(0, 255));
  analogWrite(greenLedPin, random(0,255));
  analogWrite(redLedPin, random(0, 255));

  delay(500);
}
