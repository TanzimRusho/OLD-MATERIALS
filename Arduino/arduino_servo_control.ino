/*
Possible string values:
a (to turn the LED on)
b (tor turn the LED off)
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


int pos = 0;    // variable to store the servo position
char junk;
String inputString="";

String users[4] = {"50","51","52","53"};

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


int from = 0;
int to = 120;
int rotspeed = 2;


void loop()
{
  if(Serial.available()){
    while(Serial.available()){
        char inChar = (char)Serial.read(); //read the input
        inputString += inChar;        //make a string of the characters coming on serial
      }
      Serial.println(inputString);
      
      while (Serial.available() > 0)  { junk = Serial.read() ; }      // clear the serial buffer

   for(int i = 0; i < 4; ++i){ 
   if(inputString == users[i]){  
    Serial.println("hello: " + users[i]);   
        if(inputString == "a"){         //in case of 'a' turn the LED on
          // open gate
          for (pos = from; pos <= to; pos += rotspeed) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(10);                       // waits 15ms for the servo to reach the position
          }
          
        }else if(inputString == "b"){   //incase of 'b' turn the LED off 
          // close gate      
          for (pos = to; pos >= from; pos -= rotspeed) { // goes from 180 degrees to 0 degrees
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(10);                       // waits 15ms for the servo to reach the position
          }
         }
        inputString = "";
    }
   }
    inputString = "";
  }
}
