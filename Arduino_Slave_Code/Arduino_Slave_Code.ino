// EXAMPLE USAGE

// Slave Reader running on Device No.2 (Use with corresponding Master Writer running on Device No.1)

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
#include <Wire.h>
#define RELAY_ON 0
#define RELAY_OFF 1
#define Relay_1 2
#define Relay_2 3
#define Relay_3 4
#define Relay_4 5

void setup()
{  
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);   // start serial for output
  
  digitalWrite(Relay_1, RELAY_OFF);
  digitalWrite(Relay_2, RELAY_OFF);
  digitalWrite(Relay_3, RELAY_OFF);
  digitalWrite(Relay_4, RELAY_OFF);
  
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  while(1 < Wire.available())   // loop through all but the last
  {
    char c = Wire.read();       // receive byte as a character
    Serial.print(c);            // print the character
  }
  int x = Wire.read();  // receive byte as an integer
  if(x == 0){
    
    digitalWrite(Relay_1, RELAY_OFF);
    digitalWrite(Relay_2, RELAY_OFF);
    digitalWrite(Relay_3, RELAY_OFF);
    digitalWrite(Relay_4, RELAY_OFF);
    
  }else if(x == 1){
    
    digitalWrite(Relay_1, RELAY_ON);
    
  }else if(x == 2){
    
    digitalWrite(Relay_2, RELAY_ON);
    
  }else if(x == 3){
    
    digitalWrite(Relay_3, RELAY_ON);
    
  }else if(x == 4){
    
    digitalWrite(Relay_4, RELAY_ON);
  
  }else if(x == 6){
    
    digitalWrite(Relay_1, RELAY_OFF);
    
  }else if(x == 7){
  
    digitalWrite(Relay_2, RELAY_OFF);
    
  }else if(x == 8){
    
    digitalWrite(Relay_3, RELAY_OFF);
    
  }else if(x == 9){
    
    digitalWrite(Relay_4, RELAY_OFF);
    
  }else if(x == 5){
    
    digitalWrite(Relay_1, RELAY_ON);
    digitalWrite(Relay_2, RELAY_ON);
    digitalWrite(Relay_3, RELAY_ON);
    digitalWrite(Relay_4, RELAY_ON);
    
  }
  
  Serial.println(x);  // print the integer
}
