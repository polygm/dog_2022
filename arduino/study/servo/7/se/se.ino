/**
 * SG90
 */
// 라이브러리 사용
#include <Servo.h>

// 서보객체 생성
Servo myservo1;
Servo myservo2;

// 서버 연결핀
const int servoPin1 = 3;
const int servoPin2 = 5;
int minPulse = 600; // 60 micro seconds
int maxPulse = 2500; // 2500 micro second

void setup(){
  
 
  myservo1.attach(servoPin1, minPulse, maxPulse);
  myservo2.attach(servoPin2, minPulse, maxPulse);
  
}

void loop() {
  int speed = 1;

for(int i=180,j=25;i>110,j<=165;i--,j+=2){
  myservo2.write(i);

  myservo1.write(j);
  delay(50);
}

for(int i=110,j=165;i<=180,j>25;i++,j-=2){
  myservo2.write(i);
  myservo1.write(j);
  delay(50);
}

}
