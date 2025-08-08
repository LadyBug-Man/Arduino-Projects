int led = 11;
int brightness = 0;
int delayTime = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(brightness < 255)
  {
    analogWrite(led, brightness);
    delay(delayTime);
    brightness = brightness + 1;
  }
  while(brightness > 0)
  {
    analogWrite(led, brightness);
    delay(delayTime);
    brightness = brightness - 1;
  }

}
