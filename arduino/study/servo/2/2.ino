/**
 * SG90
 */
// 라이브러리 사용
#include <Servo.h>

// 서보객체 생성
Servo myservo1;
Servo myservo2;
Servo myservo3;


// 서버 연결핀
const int servoPin1 = 3;
const int servoPin2 = 5;
const int servoPin3 = 6;
int minPulse = 600; // 60 micro seconds
int maxPulse = 2500; // 2500 micro second

void setup(){
  
  myservo3.attach(servoPin3, minPulse, maxPulse);
  myservo1.attach(servoPin1, minPulse, maxPulse);
  myservo2.attach(servoPin2, minPulse, maxPulse);
}

void loop() {
  int speed = 1;

for(int k=70;k<=110;k++){
  myservo3.write(k);
  delay(5);
}
  
  // 60deg 가속
  for(int i=30;i<=120;i++){
    myservo1.write(i);
    delay(5);
  }

for(int j=0;j<=60;j++){
  myservo2.write(j);
  delay(5);
}

for(int j=60;j>0;j--){
  myservo2.write(j);
  delay(5);
}

    // 역방향
  for(int i=120;i>30;i--){
    myservo1.write(i);
    delay(5);
  }
for(int k=110;k>70;k--){
    myservo3.write(k);
    delay(5);
  }

}
