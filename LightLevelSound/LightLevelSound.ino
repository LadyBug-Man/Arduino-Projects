int lightLevel;
int piezo = 8;
int duration = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(piezo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(A0);
  tone(piezo, lightLevel, duration);
  delay(duration);
}
