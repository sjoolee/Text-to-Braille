#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int degree= 40;

const int startButtonPin = 25;

void setup() {
  // Initialize the serial communication
  Serial.begin(115200);

  // Attach the servos to corresponding pins
  servo1.attach(21); 
  servo2.attach(22); 
  servo3.attach(19);
  servo4.attach(23);
  servo5.attach(18);
  servo6.attach(5);
  
  pinMode(25, INPUT_PULLUP); // START TRANSLATION
}

char command;

void loop() {
    /*if(digitalRead(26)==LOW){  //if button 6 is pressed...
     Serial.print("I'm Pressed!"); //print the message on a new line
  }*/
  if (Serial.available() > 0) {
    //sprintf(command, "%c", Serial.read()); 
    command = char(Serial.read());
    
  } 
   if(digitalRead(startButtonPin) == LOW) { 

    // Perform actions based on the received command
      if(command == '0') {
          servo2.write(degree);  
          servo4.write(degree);  
          servo5.write(degree);  
          delay(1000);       
          servo2.write(-degree);
          servo4.write(-degree);
          servo5.write(-degree); 
      }
      else if(command == '1') {
        servo1.write(degree);  
        delay(1000);       
        servo1.write(-degree);  
      }
      else if(command == '2') {
          servo1.write(degree);
          servo2.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo2.write(-degree);
      }
  
      else if(command == '3') {
          servo1.write(degree);
          servo4.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo4.write(-degree);
      }
      else if(command == '4') {
          servo1.write(degree);
          servo4.write(degree);
          servo5.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo4.write(-degree);
          servo5.write(-degree);
      }
      else if(command == '5') {
          servo1.write(degree);
          servo5.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo5.write(-degree);
      }
      else if(command == '6') {
          servo1.write(degree);
          servo4.write(degree);
          servo2.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo4.write(-degree);
          servo2.write(-degree);
      }
      else if(command == '7') {
          servo1.write(degree);
          servo2.write(degree);
          servo4.write(degree);
          servo5.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo2.write(-degree);
          servo4.write(-degree);
          servo5.write(-degree);
      }
      else if(command == '8') {
          servo1.write(degree);
          servo5.write(degree);
          servo2.write(degree);
          delay(1000);
          servo1.write(-degree);
          servo5.write(-degree);
          servo2.write(-degree);
      }
      else if(command == '9') {
          servo4.write(degree);
          servo2.write(degree);
          delay(1000);
          servo4.write(-degree);
          servo2.write(-degree);
      }   
      else {
          // Turn off all servos or perform other actions for default case
      }
    }
}
