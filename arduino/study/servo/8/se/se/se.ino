/**
 * SG90
 */
// 라이브러리 사용
#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7
#include <Servo.h>

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

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

  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("START");
 
  myservo1.attach(servoPin1, minPulse, maxPulse);
  myservo2.attach(servoPin2, minPulse, maxPulse);
  myservo3.attach(servoPin3, minPulse, maxPulse);


  
}

void loop() {

char val = bluetooth.read();

if(bluetooth.available()){
Serial.write(bluetooth.read());
}
  
  int speed = 1;





if(val=='a'){
  for(int k=90; k<=91; k++){
  myservo3.write(k);
  delay(10);
}
for(int i=180,j=25;i>110,j<=165;i--,j+=2){
  myservo2.write(i);

  myservo1.write(j);
  delay(50);
}
}

if(val=='b'){
  for(int k=91; k>90; k--){
  myservo3.write(k);
  delay(10);
}
  for(int i=110,j=165;i<=180,j>25;i++,j-=2){
  myservo2.write(i);
  myservo1.write(j);
  delay(50);
}
}



}
