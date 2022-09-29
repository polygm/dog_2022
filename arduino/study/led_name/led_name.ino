#include "LedControl.h" 

// step1 : 매트릭스 설정
const int DIN=7; // DIN 핀을 7번
const int CS=8;  // CS핀을 8번
const int CLK=9; // CLK 핀을 9번에 
const int MATRIX=4; // (DIN, CLK, CS, 연결할 도트 매트릭스의 개수)

// 도트 매트릭스 제어 객체 선언
LedControl dot_matrix=LedControl(DIN,CS,CLK, MATRIX); 

// step2
// 출력데이터 생성
// http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx 를 참조
int n_matrix = 4;

// 이진수 배열로 선언
byte mat4[8]={B01100010,B10010010,B10010011,B10010010,B01100010,B00000010,B01000000,B01111110};
byte mat3[8]={B01110101,B10000101,B10000101,B11110111,B10000101,B10000101,B10000101,B01110101};
byte mat2[8]={B00011000,B01111110,B00111100,B01100110,B00111100,B11111111,B01001000,B01111110};
byte mat1[8]={B01110010,B10001010,B10001010,B10001010,B01110010,B00000000,B01000000,B01111110};


void setup(){
 for(int i=0; i<n_matrix; i++) // 매트릭스 0번부터 3번까지 세팅
  {
   dot_matrix.shutdown(i,false); // 0~3번까지 매트릭스 절전모드 해제
   dot_matrix.setIntensity(i,8); // 매트릭스의 밝기 0-15 사이의 정수
   dot_matrix.clearDisplay(i); // 매트릭스를 초기화
  }
}


void loop() {
  // mat1, mat2, mat3, mat4를 도트 매트릭스에 출력
  turn_on_led(mat1, mat2, mat3, mat4, dot_matrix);  
  delay(1000);

  // 4개의 매트릭스 led 초기화
  for(int i=0; i<4; i++){ 
    dot_matrix.clearDisplay(i);
  }
  delay(1000);

}

// led를 켜는 함수
void turn_on_led(byte* mat1, byte* mat2, byte* mat3, byte* mat4, LedControl lc){ 
 for(int ii=0; ii<8; ii++)
 {
   lc.setRow(0, ii, mat1[ii]); // 0번째 매트릭스에 mat1 출력
   lc.setRow(1, ii, mat2[ii]); // 1번째 매트릭스에 mat2 출력
   lc.setRow(2, ii, mat3[ii]); // 2번째 매트릭스에 mat3 출력
   lc.setRow(3, ii, mat4[ii]); // 3번째 매트릭스에 mat4 출력
 }
}
