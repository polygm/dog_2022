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
  
 
  myservo1.attach(servoPin1, minPulse, maxPulse);
  myservo2.attach(servoPin2, minPulse, maxPulse);
  myservo3.attach(servoPin3, minPulse, maxPulse);
  
}

void loop() {
  int speed = 1;

for(int k=90; k<=91; k++){
  myservo3.write(k);
  delay(10);
}
for(int k=91; k>90; k--){
  myservo3.write(k);
  delay(10);
}


for(int i=70,j=25;i>0,j<=165;i--,j+=2){
  myservo2.write(i);
  myservo1.write(j);
  delay(100);
}

for(int i=0,j=165;i<=70,j>25;i++,j-=2){
  myservo2.write(i);
  myservo1.write(j);
  delay(100);
}

}
