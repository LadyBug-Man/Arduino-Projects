#define RELAY_ON 0
#define RELAY_OFF 1

#define Relay_1  8


#define trigPin 13
#define echoPin 12

void setup() {
  digitalWrite(Relay_1, RELAY_OFF);
  Serial.begin (9600);
  pinMode(Relay_1, OUTPUT); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 25) {  // This is where the LED On/Off happens
    digitalWrite(Relay_1, RELAY_ON);
}
  else {
     digitalWrite(Relay_1, RELAY_OFF);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
