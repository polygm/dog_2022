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


const int Yin=A1;
const int Xin=A2;


int minPulse = 600; // 60 micro seconds
int maxPulse = 2500; // 2500 micro second

void setup(){
  
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);

  myservo1.attach(servoPin1, minPulse, maxPulse);
  myservo2.attach(servoPin2, minPulse, maxPulse);
  
}

void loop() {
  int speed = 1;
  int xVal = analogRead(Xin);
  int yVal = analogRead(Yin);

Serial.print("X= ");
Serial.print(xVal, DEC);

Serial.print(", y= ");
Serial.println(yVal, DEC);

delay(100);


if(xVal==0){
  

for(int i=0,j=165;i<=70,j>25;i++,j-=2){
  myservo2.write(i);

  myservo1.write(j);
  delay(50);
}
}

if(xVal==1023){
  

for(int i=70,j=25;i>0,j<=165;i--,j+=2){
  myservo2.write(i);
  myservo1.write(j);
  delay(50);
}
}
}
