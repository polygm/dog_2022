// C++ code
//
#include <Servo.h>

const int servoPin = 3;
Servo myservo;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  
  myservo.attach(servoPin);
  myservo.write(0);
  delay(1000);
  
}

void loop()
{
  int sw = digitalRead(2);
  if(sw == LOW) {
    digitalWrite(13, HIGH);
    myservo.write(180);
  } else {
    digitalWrite(13, LOW);
    myservo.write(0);
  }

  }
