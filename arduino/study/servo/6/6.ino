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

for(int k=80,i=30,j=0;k<=100,i<=130,j<=60;k++,i++,j++){
  myservo3.write(k);
  if(k%5){
  }else{
    i+=5;
  }
  if(k%3){
    
  }else{
    j+=3;
  }
  myservo2.write(j);
  myservo1.write(i);
  delay(50);
}

for(int k=100,i=130,j=60;k>80,i>30,j>0;k--,i--,j--){
  myservo3.write(k);
  if(k%5){
    
  }else{
    i-=5;
  }
  if(k%3){
    
  }else{
    j-=3;
  }
  myservo2.write(j);
  myservo1.write(i);
  delay(50);
}


}
