#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int degree = 40;
int startButtonState = 1; //not pressed
int lastStartButtonState = HIGH;
bool translationStarted = false;

const int startButtonPin = 26;
const int LedPin = 25;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Attach the servos to corresponding pins
  servo1.attach(21);
  servo2.attach(22);
  servo3.attach(19);
  servo4.attach(23);
  servo5.attach(18);
  //servo6.attach(5);

  pinMode(startButtonPin, INPUT); // START TRANSLATION
  pinMode(LedPin, OUTPUT); // LED
}


void processCommand(char command) {
  // Perform actions based on the received command
  switch (command) {
    case '0':
      servo2.write(degree);
      servo4.write(degree);
      servo5.write(degree);
      delay(1000);
      servo2.write(-degree);
      servo4.write(-degree);
      servo5.write(-degree);
      break;

    case '1':
      servo1.write(degree);
      delay(1000);
      servo1.write(-degree);
      break;

    case '2':
      servo1.write(degree);
      servo2.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo2.write(-degree);
      break;

    case '3':
      servo1.write(degree);
      servo4.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo4.write(-degree);
      break;

    case '4':
      servo1.write(degree);
      servo4.write(degree);
      servo5.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo4.write(-degree);
      servo5.write(-degree);
      break;

    case '5':
      servo1.write(degree);
      servo5.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo5.write(-degree);
      break;

    case '6':
      servo1.write(degree);
      servo4.write(degree);
      servo2.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo4.write(-degree);
      servo2.write(-degree);
      break;

    case '7':
      servo1.write(degree);
      servo2.write(degree);
      servo4.write(degree);
      servo5.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo2.write(-degree);
      servo4.write(-degree);
      servo5.write(-degree);
      break;

    case '8':
      servo1.write(degree);
      servo5.write(degree);
      servo2.write(degree);
      delay(1000);
      servo1.write(-degree);
      servo5.write(-degree);
      servo2.write(-degree);
      break;

    case '9':
      servo4.write(degree);
      servo2.write(degree);
      delay(1000);
      servo4.write(-degree);
      servo2.write(-degree);
      break; 
      

    // Turn LED on
    digitalWrite(LedPin, HIGH);
    default:
      // Turn off all servos or perform other actions for default case
      break;
  }
}

void loop() {
  startButtonState = digitalRead(startButtonPin);
  digitalWrite(LedPin, LOW);

  if(startButtonState==LOW) {
    translationStarted = true;
  }
  if(translationStarted) {
    if (Serial.available() > 0) {
      String command = Serial.readString();
      Serial.println(command);
      
      for(int i=0; i<command.length(); i++) {
        char currentChar = command.charAt(i); 
        processCommand(currentChar);
      }
    }
  }
}
