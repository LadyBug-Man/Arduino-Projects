/* YourDuino Example: Relay Control 1.10
  Handles "Relay is active-low" to assure
  no relay activation from reset until
  application is ready.
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
/*-----( Declare Constants )-----*/
#define RELAY_ON 0
#define RELAY_OFF 1

#define Relay_1  8  // Arduino Digital I/O pin number

int micPin = A0;   
int gndPin = A1;
int powerPin = A2;
int micValue1 = 0;  
int micValue2 = 0;
boolean lightOn = false;


void setup()  
{

  digitalWrite(Relay_1, RELAY_OFF);
  pinMode(Relay_1, OUTPUT);      
  pinMode(powerPin, OUTPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(micPin, INPUT);
  digitalWrite(gndPin,LOW);
  delay(500);
  digitalWrite(powerPin,HIGH);
  Serial.begin(9600);
  //delay(4000); 

}


void loop()
{
 micValue1 = analogRead(micPin);  // read pin value
  Serial.println(micValue1);
  delay(1);
  micValue2 = analogRead(micPin);
  Serial.println(micValue2);
  
  if (micValue1-micValue2 > 2||micValue2-micValue1 > 2){
  delay(100);
  if(lightOn == true){
  digitalWrite(Relay_1, RELAY_ON);
  lightOn = false;
  }else if(lightOn == false){
     digitalWrite(Relay_1, RELAY_OFF);
     lightOn=true;
    }       
  }
}

 // digitalWrite(Relay_1, RELAY_ON);
 // delay(1000);              
            
  
 
  //digitalWrite(Relay_1, RELAY_OFF);
  //delay(1000);    

