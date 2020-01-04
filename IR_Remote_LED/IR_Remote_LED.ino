/*
 * Modified by Rui Santos, http://randomnerdtutorialscom
 * based on IRremote Library - Ken Shirriff
*/
 
#include <IRremote.h>
 
int IR_Recv = 11;   //IR Receiver Pin 3
int redPin = 10;
int greenPin = 9;
int bluePin = 8;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
  pinMode(redPin, OUTPUT);      // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
  pinMode(bluePin, OUTPUT);      // sets the digital pin as output 

}
 
void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 16753245: //when you press the 1 button
        digitalWrite(redPin, LOW);
        Serial.println("Red On");
        break;   
      case 16720605: //when you press the 4 button
        digitalWrite(redPin, HIGH);
        Serial.println("Red Off");   
        break;
       case 16736925: //when you press the 2 button
        digitalWrite(greenPin, LOW);
        Serial.println("Green On");
        break;           
       case 16712445: //when you press the 5 button
        digitalWrite(greenPin, HIGH);
        Serial.println("Green Off");
        break;       
       case 16769565: //when you press the 3 button
        digitalWrite(bluePin, LOW);
        Serial.println("Blue On");
        break;       
       case 16761405: //when you press the 6 button
        digitalWrite(bluePin, HIGH);
        Serial.println("Blue Off");
        break;
       case 16726215: //when you press the 6 button
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, HIGH);
        Serial.println("All Off");
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}

