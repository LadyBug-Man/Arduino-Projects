#include <IRremote.h>

int RECV_PIN = 11;

int lights = 3;


IRrecv irrecv(RECV_PIN);
boolean LightOn;
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(lights, OUTPUT);      // sets the digital pin as output
}

void loop() {
  if (irrecv.decode(&results)) {

    long int decCode = results.value;
    Serial.println(decCode);
    switch (results.value) {
      case -2142322625:
        Serial.println("lights on");
        digitalWrite(lights, HIGH);   // sets the LED on
        break;
      case -2142340475:
        Serial.println("lights off");
        digitalWrite(lights, LOW);
        break;
      //case 1791365666:
        //Serial.println("Stop");
        //digitalWrite(forwardPin, LOW);   // sets the LED off
        //digitalWrite(reversePin, LOW);   // sets the LED off
        //digitalWrite(playPin, LOW);   // sets the LED off
        //digitalWrite(pausePin, LOW);   // sets the LED off
        //break;
      default:
        Serial.println("Waiting ...");
    }

    irrecv.resume(); // Receive the next value
  }
}
