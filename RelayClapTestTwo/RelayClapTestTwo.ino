
#define RELAY_ON 0
#define RELAY_OFF 1
#define Relay_1  8


int soundSensor = A0;
int gndPin = A1;
int powerPin = A2;
int claps = 0;
long detectionSpanInitial = 0;
long detectionSpan = 0;
boolean lightState = false;
int sensorState;
 
void setup() {
  digitalWrite(Relay_1, RELAY_OFF);
  pinMode(Relay_1, OUTPUT);
 
  pinMode(soundSensor, INPUT);
  pinMode(powerPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  digitalWrite(gndPin,LOW);
  delay(500);
  digitalWrite(powerPin,HIGH);
  Serial.begin(9600);
}
 
void loop() {
 
 sensorState = analogRead(soundSensor);
 
  if (sensorState == 0)
  {
    if (claps == 0)
    {
      detectionSpanInitial = detectionSpan = millis();
      claps++;
    }
    else if (claps > 0 && millis()-detectionSpan >= 50)
    {
      detectionSpan = millis();
      claps++;
    }
  }
 
  if (millis()-detectionSpanInitial >= 400)
  {
    if (claps == 2)
    {
      if (!lightState)
        {
          lightState = true;
          digitalWrite(Relay_1, RELAY_OFF);
        }
        else if (lightState)
        {
          lightState = false;
          digitalWrite(Relay_1, RELAY_ON);
        }
    }
    claps = 0;
  }
}
