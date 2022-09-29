/**
 * SG90
 */
// 라이브러리 사용
#include <Servo.h>

// 서버 연결핀
const int servoPin = 3;
Servo myservo;

void setup(){
  // 서버 초기화
  myservo.attach(servoPin);
  myservo.write(0); // 0deg 유지
  delay(1000);
}


void loop() {
    myservo.write(180);
    delay(1000);   
    myservo.write(0);
    delay(1000);
}
