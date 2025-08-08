#include <IRremote.h>
#define RELAY_ON 0
#define RELAY_OFF 1
#define Relay_1  8

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

boolean lightState = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  digitalWrite(Relay_1, RELAY_OFF);
  pinMode(Relay_1, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    long int deCode = results.value;
    Serial.println(deCode);
    switch(results.value) {
      //case -2142322625: Up button on TV remote
      case -2142370055: //Very bottom left corner button with no label
        if (lightState == false){
          digitalWrite(Relay_1, RELAY_ON);
          lightState = true;
          Serial.println("Lights on");
        }else if (lightState == true){
          digitalWrite(Relay_1, RELAY_OFF);
          lightState = false;
          Serial.println("Lights off");
        }
        break;
      //case -2142340475: Down button on TV remote
      // Serial.println("Lights off");
      //  digitalWrite(Relay_1, RELAY_OFF);
      //  break;
       default:
         Serial.println("Waiting...");
    }
    
    irrecv.resume();
  }
}


