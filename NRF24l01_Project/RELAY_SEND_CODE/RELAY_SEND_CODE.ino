#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
//RF24 library link https://github.com/maniacbug/RF24
//Pin Assingmenet http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
int msg[1];
RF24 radio(9,10);//check your pin number on RF24 github check you have the right
//pin for the arduino you're using. this pin number is diffrent for diffrent arduino models.

const uint64_t pipe = 0xF0F0F0F0D2L;
int buttonPin1 = 7;
int buttonPin2 = 6;
int buttonPin3 = 5;
int buttonPin4 = 4;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup(void)
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

void loop(void)
{
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  
  if (buttonState1 == HIGH)
  {
    msg[0] = 10;
    radio.write(msg, 1);
  }
  if(buttonState1 == LOW)
  {
    msg[0] = 11;
    radio.write(msg, 1);
  }
  if (buttonState2 == HIGH)
  {
    msg[0] = 12;
    radio.write(msg, 1);
  }
  if (buttonState2 == LOW)
  {
    msg[0] = 13;
    radio.write(msg, 1);
  }
  if (buttonState3 == HIGH)
  {
    msg[0] = 14;
    radio.write(msg, 1);
  } 
  if (buttonState3 == LOW)
  {
    msg[0] = 15;
    radio.write(msg, 1);
  }
  if (buttonState4 == HIGH)
  {
    msg[0] = 16;
    radio.write(msg, 1);
  }
  if(buttonState4 == LOW)
  {
    msg[0] = 17;
    radio.write(msg, 1);
  }  
}
