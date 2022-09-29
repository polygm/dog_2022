#include "LedControl.h" 

// step1 : 매트릭스 설정
const int DIN=7; // DIN 핀을 7번
const int CS=8;  // CS핀을 8번
const int CLK=9; // CLK 핀을 9번에 
const int MATRIX=8; // (DIN, CLK, CS, 연결할 도트 매트릭스의 개수)

// 도트 매트릭스 제어 객체 선언
LedControl dot_matrix=LedControl(DIN,CS,CLK, MATRIX); 

int n_matrix = 4;

void setup(){
 for(int i=0; i<n_matrix; i++) // 매트릭스 0번부터 3번까지 세팅
  {
   dot_matrix.shutdown(i,false); // 0~3번까지 매트릭스 절전모드 해제
   dot_matrix.setIntensity(i,8); // 매트릭스의 밝기 0-15 사이의 정수
   dot_matrix.clearDisplay(i); // 매트릭스를 초기화
  }
}

void loop() {
  // 점점 채우기
  for(int k=0;k<n_matrix;k++){
    for(int i=0; i<8;i++){
      dot_matrix.setRow(k,i,B11111111);
      delay(100);
    }
     dot_matrix.clearDisplay(k);
  }

  for(int k=(n_matrix-1);k>0;k--){
    for(int i=8; i>0;i--){
      dot_matrix.setRow(k,i,B11111111);
      delay(100);
    }
     dot_matrix.clearDisplay(k);
  }

  for(int k=0;k<n_matrix;k++){
    for(int j=1;j<255;){
      // 세로줄
      for(int i=0; i<8;i++){
        dot_matrix.setRow(k,i,j);
      }
      j = j*2;
      delay(100);
      dot_matrix.clearDisplay(k);    
    }        
  }

  for(int k=(n_matrix-1);k>0;k--){
    for(int j=0x40;j>0;){
      // 세로줄
      for(int i=0; i<8;i++){
        dot_matrix.setRow(k,i,j);
      }
      j = j/2;
      delay(100);
      dot_matrix.clearDisplay(k);
    }
  }  

  // 데모3
  for(int k=0;k<n_matrix;k++){
    for(int i=0; i<8;i++){
      dot_matrix.setRow(k,i,B11111111);
      delay(100);
      dot_matrix.clearDisplay(k);
    }     
  }

  for(int k=(n_matrix-1);k>0;k--){
    for(int i=8; i>0;i--){
      dot_matrix.setRow(k,i,B11111111);
      delay(100);
      dot_matrix.clearDisplay(k);
    }     
  }
  
}
