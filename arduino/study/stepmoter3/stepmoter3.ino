#define motorPin1 2 // IN1
#define motorPin2 3 // IN2
#define motorPin3 4 // IN3
#define motorPin4 5 // IN4

//1-2상 여자 방식은 Half Step 구동 방식으로 Full Step 구동 방식보다 1step 당 로터의 이동 각도가 1/2로, 스텝수는 2배입니다.
#define step 4096 // 1봐퀴 스텝수

// 모터 회전 Loop 문 구현을 간단하게 하기위해 핀 배열 선언
int pinArray[4] = { motorPin1, motorPin2, motorPin3, motorPin4 };

// CW 시계방향 데이터 전송
int CW[8] = {
                0b1000,
                0b1100,
                0b0100,
                0b0110,
                0b0010,
                0b0011,
                0b0001,
                0b1001
            };
 
int CCW[8] = {
                0b1000,
                0b1001,
                0b0001,
                0b0011,
                0b0010,
                0b0110,
                0b0100,
                0b1100
            };





void setup(){
  // 핀모드 설정
  // 스텝모터 드라이브 보드의 IN 연결핀 출력으로 설정
   for(int i = 0 ; i < 4 ; i++ ) {
    pinMode(pinArray[i], OUTPUT);
   }
}

void loop() {
  
  int temp;
    
  // CW방향 1바퀴 후
  for(int i = 0 ; i < step ; i++)
  {
        temp = i % 8;
        digitalWrite(pinArray[0], bitRead(CW[temp], 0));
        digitalWrite(pinArray[1], bitRead(CW[temp], 1));
        digitalWrite(pinArray[2], bitRead(CW[temp], 2));
        digitalWrite(pinArray[3], bitRead(CW[temp], 3));
        delay(1); // 각 스텝 간격이 최소 1ms 이상이어야 정상적으로 동작합니다.
  }
  delay(1000);

  // CCW 1바퀴 
  for(int i = 0 ; i < step ; i++)
  {
        temp = i % 8;
        digitalWrite(pinArray[0], bitRead(CCW[temp], 0));
        digitalWrite(pinArray[1], bitRead(CCW[temp], 1));
        digitalWrite(pinArray[2], bitRead(CCW[temp], 2));
        digitalWrite(pinArray[3], bitRead(CCW[temp], 3));
        delay(1); // 각 스텝 간격이 최소 1ms 이상이어야 정상적으로 동작합니다.
  }
  delay(1000);

}
