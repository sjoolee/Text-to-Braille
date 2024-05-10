#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
string numString;
//servo 2 in row 1 column 2, servo 3 in row 2 column 1, etc. 

int initAngle = 90;
int degree;
int ms;

void setup() {
  //initialize serial
  Serial.begin(9600);
  //designate each servo to a pin
  servo1.attach(6); servo1.write(initAngle);
  servo2.attach(7); servo2.write(initAngle);
  servo3.attach(8); servo3.write(initAngle);
  servo4.attach(9); servo4.write(initAngle);
  servo5.attach(10); servo5.write(initAngle);
  servo6.attach(11); servo6.write(initAngle);
}

void displayBraille(currentNum){
  //actuate the correct servo motor based on the serial string
  if(currentNum) == 1){
    servo1.write(degrees);
    delay(ms);
    servo1.write(-degrees);
  }
  else if(currentNum) == 2){
    servo1.write(degrees);
    servo3.write(degrees);
    delay(ms);
    servo1.write(-degrees);
    servo3.write(-degrees);
  }
  else if(currentNum) == 3){
    servo1.write(degrees);
    servo2.write(degrees);
    delay(ms);
    servo1.write(-degrees);
    servo2.write(-degrees);    
  }
  else if(currentNum) == 4){
    servo1.write(degrees);
    servo2.write(degrees);
    servo4.write(degrees);
    delay(ms);
    servo1.write(-degrees);
    servo2.write(-degrees);  
    servo4.write(-degrees);    
  }
  else if(currentNum) == 5){
    servo1.write(degrees);
    servo4.write(degrees);
    delay(ms);
    servo1.write(-degrees); 
    servo4.write(-degrees);    
  }
  else if(currentNum) == 6){
    servo1.write(degrees);
    servo2.write(degrees);
    servo3.write(degrees);
    delay(ms);
    servo1.write(-degrees);
    servo2.write(-degrees);  
    servo3.write(-degrees);      
  }
  else if(currentNum) == 7){
    servo1.write(degrees);
    servo2.write(degrees);
    servo3.write(degrees);
    servo4.write(degrees);
    delay(ms);
    servo1.write(-degrees);
    servo2.write(-degrees);  
    servo3.write(-degrees); 
    servo4.write(-degrees);      
  }
  else if(currentNum) == 8){
    servo1.write(degrees);
    servo3.write(degrees);
    servo4.write(degrees);
    delay(ms);
    servo1.write(-degrees); 
    servo3.write(-degrees); 
    servo4.write(-degrees);    
  }
  else if(currentNum) == 9){
    servo2.write(degrees);
    servo3.write(degrees);
    delay(ms);
    servo2.write(-degrees);  
    servo3.write(-degrees);      
  }
  else if(currentNum) == 0){
    servo2.write(degrees);
    servo3.write(degrees);
    servo4.write(degrees);
    delay(ms);
    servo2.write(-degrees);  
    servo3.write(-degrees); 
    servo4.write(-degrees);    
  }
  else{
    Serial.print("Error");
  }
}

void loop() {
  //wait for serial input from computer
  while(Serial.available()){
    numString = Serial.readString();
  }

  //call function to display each 
  for(n=0; numString[n]!='\0'; n++){
    displayBraille(atoi(numString[n]));
  }



}
