int knock = 0;

void setup() {
  Serial.begin(38400);

}

void loop() {
  knock = analogRead(0);
  Serial.println(knock);
}
