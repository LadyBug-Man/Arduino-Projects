int led = 11;
int lightLevel;
int ledLevel;

void setup() {
  Serial.begin(38400);
  pinMode(led, OUTPUT);
}

void loop() {
  lightLevel = analogRead(A0);
  ledLevel = 4/lightLevel;
  Serial.print ("Light Level: ");
  Serial.println(lightLevel, DEC);
  analogWrite(led, ledLevel);
  delay(10);
}
