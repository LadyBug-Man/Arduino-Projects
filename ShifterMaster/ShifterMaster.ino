#include <Shifter.h>

// THESE VARIABLES CHANGE.
// Set the number of leds your using and the number of shift registers used.
// The Shifter library assumes one register = 8 bits.  With this in mind,  
// NUM_LED can never be greater that NUM_REG x 8 bits.
const int NUM_LED = 8;      // number of leds
const int NUM_REG = 1;       // number of shift registers


// Set variables - Global variables, except for the Arduino
// pins, are CAPITALIZED.  This makes identification of local and 
// global variables easy to understand.  The compilier is case sensitive
// so it understands capitalized and lower case letters.

// These variables are too make things a little easier for humans to read.
// The "const" sets the variable so it cannot be changed
// later in the program (ie. make them constants).  The standard
// constants "true" and "false" function just as well as these.
const bool OFF = 0;
const bool ON = 1;


// Pin connected to RCLK, pin 12, of ALL the 74HC595s
//                                  ===
const int latchPin = 3;
// Pin connected to SRCLK, pin 11, of ALL the 74HC595s
//                                    ===
const int clockPin = 4;
// Pin connected to SER, pin 14, of the FIRST 74HC595s
//                                      =====
// All of the serial data will be going to this SER (data in)
// pin to all the register(s) you have connected.
const int dataPin = 2;

// Set up the shifter object used to send data to the registers.
Shifter shifter(dataPin, latchPin, clockPin, NUM_REG); 


// Set up the array of leds that is used throughout the program
bool LED[NUM_LED];        


/**************************************************************
Function: setup
Purpose:  set up Arduino
Args:     none
Returns:  nothing
Notes:    This function is required by the Arduino
***************************************************************/
void setup() {

  // Set up the output pins.  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  
  // Set up the shifter output
  shifter.clear();
  shifter.write();
  
  // turn off all the LEDS, just in case
  allOff();
  writeBytes();
 
  // This is needed for the randomLeds() function below,
  // along with any other code that uses a random number
  // and removed if random numbers are not used.  
  // Quoted from http://arduino.cc/en/Reference/random - 
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  //
  // In other words, set this to any analog pin that is
  // not used.
  randomSeed(analogRead(0));
  

}  // End of Arduino Setup 



/**************************************************************
Function: loop
Purpose:  loop funtion for Arduino
Args:     none
Returns:  nothing
Notes:    This function is required by the Arduino, and the 
          Arduino will loop through this function indefinately.
***************************************************************/
void loop() {


  crissCross(100, 5);

}  






/**************************************************************
Function: crissCross
Purpose:  Criss-Cross effect
Args:     int duration - how long an led is on 
          int count - how many times to cycle through effect
Returns:  nothing
Notes:    
***************************************************************/
void crissCross(int duration, int count)
{
  // Clear the array and turns off any leds still on 
  allOff();
  writeBytes();
  
  // Create variables
  int firstled;
  int lastled;
  
  for(int i = 0; i < count; i++)
  {
    for(int j = 0; j < NUM_LED; j++)
    {
      // if its the start of a loop through the leds,
      // reset the variables to their starting position.
      if(j == 0){
        firstled = 0;
        lastled = NUM_LED -1;
      }
      LED[firstled] = ON;
      LED[lastled] = ON;
      writeBytes();
      // Skip the delay if the center leds are crossing
      // or if the leds have reached the ends.
      // This code was changed to be human readable and 
      // is not the most effecient.
      if(lastled == (firstled +1)){}
        // do nothing - skip delay
      else if (lastled == 0){}
        // do nothing - skip delay
      else
        delay(duration);
      // Turn off the last leds we just turned on
      LED[firstled] = OFF;
      LED[lastled] = OFF;
      // increment variables
      firstled++;
      lastled--;
    }
  }
  
  // turn the last leds off
  delay(duration);
  allOff();
  writeBytes();
}


/**************************************************************
Function: sumArray
Purpose:  Take a binary representation of the array of ON and OFF
          positions, and generates an integer.
Args:     int array[]
Returns:  integer of the total
Notes:    See comments on bit shifting at the beginning
          of this file.
**************************************************************/  
int sumArray(bool array[])
{
   int total = 0;
   
   for (int i = 0; i < NUM_LED; i++)
   {
     if (array[i] == ON)
	 total = total + (1<<i);
   }
   
   return(total);
}

/**************************************************************
Function: setArray
Purpose:  Sets the primary array to the binary of the number
          given.
Args:     int num - number to put into array
Returns:  nothing
Notes:    See comments on bit shifting at the beginning
          of this file.  Since this is an integer, it must be
          between -32,768 and 32,767, HOWEVER, it should 
          always be a positive number (0 to 32,767).
**************************************************************/  
void setArray(int num)
{
  // Clear the array
  allOff();
  int i = 0;
  bool value;
  
   while (num > 0)
   {
     value = num & 1;
     if(value == true)
       LED[i] = ON;
     else
       LED[i] = OFF;
       
     num >>= 1;
     i++;
   }  
}

/**************************************************************
Function: evenOn
Purpose:  Turns ON even leds
Args:     none
Returns:  none
Notes:    
**************************************************************/  
void evenOn()
{
   for (int i = 1; i < NUM_LED; i += 2)
   {
     LED[i] = ON;
   }
}


/**************************************************************
Function: oddOn
Purpose:  Turns ON even leds
Args:     none
Returns:  none
Notes:    
**************************************************************/  
void oddOn()
{
   for (int i = 0; i < NUM_LED; i += 2)
   {
     LED[i] = ON;
   }
}


/**************************************************************
Function: allOn
Purpose:  Turns ON all leds
Args:     none
Returns:  none
Notes:    
**************************************************************/  
void allOn()
{
   for (int i = 0; i < NUM_LED; i++)
   {
     LED[i] = ON;
   }
}

/**************************************************************
Function: allOff
Purpose:  Turns OFF all leds
Args:     none
Returns:  none
Notes:    
**************************************************************/  
void allOff()
{
   for (int i = 0; i < NUM_LED; i++)
   {
     LED[i] = OFF;
   }
}



/**************************************************************
Function: writeBits
Purpose:  Write the array with Most Significant Bit first (MSFBFIRST)
Args:     none
Returns:  nothing
Notes:    This function is a wrapper function for outBytes()
***************************************************************/
void writeBytes()
{
  outBytes(MSBFIRST);
}


/**************************************************************
Function: writeBytesRev
Purpose:  Write the array with Least Significant Bit first (MSFBFIRST)
Args:     none
Returns:  nothing
Notes:    This function is a wrapper function for outBytes()
***************************************************************/
void writeBytesRev()
{
  outBytes(LSBFIRST);
}

/**************************************************************
Function: outBytes
Purpose:  Send array data to shift register
Args:     int dir - First or Least significant bit first
Returns:  nothing
Notes:    This is where data is actually sent out, but is not 
          intended to be used directly.  writeBytes() and
          writeBytesRev() should be used instead.
***************************************************************/
void outBytes(int dir)
{
   // set latch pin low so data can be sent 
   digitalWrite(latchPin, LOW);
   // Clears previous data
   shifter.clear();
   
   // Set each pin according to what LED[] currently has.
   
   // most significant bit first
   if(dir == MSBFIRST)
   {
     for(int i = 0; i < sizeof(LED);i++)
     {
        if(LED[i] == ON)
         shifter.setPin(i, HIGH);
       else
         shifter.setPin(i, LOW);
     } 
   }
   // least significant bit first - reverses what is in LED[]
   else if(dir == LSBFIRST)
   {
     int j = 0;
     for(int i = sizeof(LED) - 1; i > -1;i--)
     {
       if(LED[i] == ON){
         shifter.setPin(j, HIGH);
       }  
       else{
         shifter.setPin(j, LOW);
       }        
       j++;  
     } 
   }   
   
   // Write the data to the registers
   shifter.write();
   // set the latch high to turn on the output
   digitalWrite(latchPin, HIGH);

}

//  End of program
