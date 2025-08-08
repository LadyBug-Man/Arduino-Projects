#include <Servo.h> 

// Set digital pin numbers:
const int servoPin = 7; 
const int buttonPin = 9; 

int buttonState = 0; 
int directionState = 1; 

Servo myservo;   
int pos = 0;  

 void setup() {
   myservo.attach(7);  // attaches the servo on pin 8 to the servo object 
   pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input
 }

 void loop(){
   buttonState = digitalRead(buttonPin);
   if (directionState == 0){
     if (buttonState == HIGH) {
       directionState = 1; 
       for(pos = 0; pos < 90; pos=pos+1)
       {
         myservo.write(pos); 
         delay(15);    
       }
     }
   } else if (directionState == 1) {
     if (buttonState == HIGH) {
       directionState = 0;
       for(pos = 90; pos>=1; pos=pos-1)
       {  
         myservo.write(pos);
         delay(15); 
       }
     }
   }
 }
