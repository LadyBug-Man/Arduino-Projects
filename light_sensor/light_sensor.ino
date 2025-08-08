int led = 11;
int lightLevel;

void setup()
{
  Serial.begin(38400);
  pinMode(led, OUTPUT);
}

void loop() 
{
  lightLevel = analogRead(A0);
  Serial.print("Light level: ");
  Serial.println(lightLevel, DEC);
  digitalWrite(led, HIGH);
  delay(lightLevel);
  digitalWrite(led, LOW);
  delay(lightLevel);
}
