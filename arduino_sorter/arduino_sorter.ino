#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int servoPin = 5; // pin for the servo motor signal
int leftPin = 6; // pin for the left input
int rightPin = 7; // pin for the right input
int speed = 1; // the less this value, the faster the speed!

void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
}

void loop() {

  int leftVal = digitalRead(leftPin);
  int rightVal = digitalRead(rightPin);

  if (leftVal == HIGH){
    while(pos <= 180){
      myservo.write(pos);
      pos ++;
      delay(speed);
    }
  }
  else if (rightVal == HIGH ){
    while(pos >= 0){
      myservo.write(pos);
      pos --;
      delay(speed);
    }
  }
  else{
    if (pos > 90){
      while (pos > 90){
        myservo.write(pos);
        pos --;
        delay(speed);
      }
    }
    else{
      while(pos < 90){
        myservo.write(pos);
        pos ++;
        delay(speed);
      }
    }
  }
}
