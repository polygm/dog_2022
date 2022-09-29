/**
 * SG90
 */
// 라이브러리 사용
#include <Servo.h>

// 서버 연결핀
const int servoPin = 3;
Servo myservo;

void setup(){
  myservo.attach(servoPin);
  myservo.write(0);
  delay(1000);
}


void loop() {
  for(int i=0; i<180;i+=10){
    myservo.write(i);
    delay(1000);
  }  

  for(int i=180;i>0;i-=10){
    myservo.write(i);
    delay(1000);
  } 
}
