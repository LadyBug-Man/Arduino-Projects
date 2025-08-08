
#include <Servo.h> 
 
int buttonPin = 2; 
 
Servo myservo;
Servo baseServo;                 // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
//int pos = 0;    // variable to store the servo position 
//int buttonState = 0;
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  baseServo.attach(8);
  pinMode(buttonPin, INPUT);
  
  myservo.write(5);
  baseServo.write(180);
} 
 
void loop() 
{ 
  //buttonState = digitalRead(buttonPin);
  
  while(digitalRead(buttonPin) == HIGH){
    baseServo.write(0);
    delay(1000);
    myservo.write(50);
  }
  while(digitalRead(buttonPin) == LOW){ 
    myservo.write(5);
    delay(1000);
    baseServo.write(180);
  }
}

