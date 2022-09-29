#include <Servo.h>

Servo myservo;

const int servoPin = 3;
int minPulse = 600;
int maxPulse = 2500;

void setup() {
  // put your setup code here, to run once:
myservo.attach(servoPin, minPulse, maxPulse);
}

void loop() {
  // put your main code here, to run repeatedly:
int speed = 1;

for(int i=0;i<=60;i++){
  myservo.write(i);
  delay(20);
}

for(int i=60;i<=120;i++){
  myservo.write(i);
  delay(50);
}


for(int i=120; i<=180;i++){
  myservo.write(i);
  delay(20);
}
}
