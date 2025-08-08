#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define RELAY_ON 0
#define RELAY_OFF 1

#define Relay_1 7
#define Relay_2 6
#define Relay_3 5
#define Relay_4 4

int piezo = 2;
int duration = 250;
int notes[] = {587, 659, 698, 783, 880};

int msg[1];
RF24 radio(9,10);//check your pin number on RF24 github check you have the right
//pin number for the arduino you're using. this pin is diffrent for diffrent arduino models.

const uint64_t pipe = 0xF0F0F0F0D2L;
int relayONE_LED = A0;
int relayTWO_LED = A1;
int relayTHREE_LED = A2;
int relayFOUR_LED = A3;

boolean circuitActive = false;

void setup(void)
{
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
  digitalWrite(Relay_1, RELAY_OFF);
  digitalWrite(Relay_2, RELAY_OFF);
  digitalWrite(Relay_3, RELAY_OFF);
  digitalWrite(Relay_4, RELAY_OFF);
  
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  pinMode(relayONE_LED, OUTPUT);
  pinMode(relayTWO_LED, OUTPUT);
  pinMode(relayTHREE_LED, OUTPUT);
  pinMode(relayFOUR_LED, OUTPUT);
  relayTest();
}

void loop(void)
{
  if(circuitActive == true)
  {
  if(radio.available()){
    bool done = false;
    while (!done) {
      done = radio.read(msg, 1);
      Serial.println(msg[0]);
      if (msg[0] == 10) {
      digitalWrite(Relay_1, RELAY_ON);
      digitalWrite(relayONE_LED, HIGH);
      }else if(msg[0] == 11){
        digitalWrite(Relay_1, RELAY_OFF);
        digitalWrite(relayONE_LED, LOW);
      }else if(msg[0] == 12){
        digitalWrite(Relay_2, RELAY_ON);
        digitalWrite(relayTWO_LED, HIGH);
      }else if(msg[0] == 13){
        digitalWrite(Relay_2, RELAY_OFF);
        digitalWrite(relayTWO_LED, LOW);
      }else if(msg[0] == 14){
        digitalWrite(Relay_3, RELAY_ON);
        digitalWrite(relayTHREE_LED, HIGH);
      }else if(msg[0] == 15){
        digitalWrite(Relay_3, RELAY_OFF);
        digitalWrite(relayTHREE_LED, LOW);
      }else if(msg[0] == 16){
        digitalWrite(Relay_4, RELAY_ON);
        digitalWrite(relayFOUR_LED, HIGH);
      }else if(msg[0] == 17){
        digitalWrite(Relay_4, RELAY_OFF);
        digitalWrite(relayFOUR_LED, LOW);
        }
      }
    }
  }
}

void relayTest(){
 //---( Turn all 4 relays ON in sequence)--//
  digitalWrite(Relay_1, RELAY_ON);
  digitalWrite(relayONE_LED, HIGH);
  delay(500);
  digitalWrite(Relay_2, RELAY_ON);
  digitalWrite(relayTWO_LED, HIGH);
  delay(500);
  digitalWrite(Relay_3, RELAY_ON);
  digitalWrite(relayTHREE_LED, HIGH);
  delay(500);
  digitalWrite(Relay_4, RELAY_ON);
  digitalWrite(relayFOUR_LED, HIGH);
  delay(500);
 //---( Turn all 4 relays OFF in sequence)--//
  digitalWrite(Relay_1, RELAY_OFF);
  digitalWrite(relayONE_LED, LOW);
  delay(500);
  digitalWrite(Relay_2, RELAY_OFF);
  digitalWrite(relayTWO_LED, LOW);
  delay(500);
  digitalWrite(Relay_3, RELAY_OFF);
  digitalWrite(relayTHREE_LED, LOW);
  delay(500);
  digitalWrite(Relay_4, RELAY_OFF);
  digitalWrite(relayFOUR_LED, LOW);
  delay(500);
//---( Turn all relays on)---//
  digitalWrite(Relay_1, RELAY_ON);
  digitalWrite(relayONE_LED, HIGH);
  digitalWrite(Relay_2, RELAY_ON);
  digitalWrite(relayTWO_LED, HIGH);
  digitalWrite(Relay_3, RELAY_ON);
  digitalWrite(relayTHREE_LED, HIGH);
  digitalWrite(Relay_4, RELAY_ON);
  digitalWrite(relayFOUR_LED, HIGH);
  delay(1000);
  digitalWrite(Relay_1, RELAY_OFF);
  digitalWrite(relayONE_LED, LOW);
  digitalWrite(Relay_2, RELAY_OFF);
  digitalWrite(relayTWO_LED, LOW);
  digitalWrite(Relay_3, RELAY_OFF);
  digitalWrite(relayTHREE_LED, LOW);
  digitalWrite(Relay_4, RELAY_OFF);
  digitalWrite(relayFOUR_LED, LOW);
  delay(1000);
  playTone();
}
 
 void playTone() { 
  for (int i=0; i <5; i++)
  {
    tone(piezo, notes[i], duration);
    delay(duration);
  }
  circuitActive = true;
}
