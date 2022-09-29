#include "LedControl.h" 

const int DIN=7;
const int CS=8; 
const int CLK=9;
const int MATRIX=4; 

LedControl dot_matrix = LedControl(DIN,CS,CLK, MATRIX);

void dot_metrix_init(int matrix) {
  for(int i=0; i<matrix; i++) {
    dot_matrix.shutdown(i,false);
    dot_matrix.setIntensity(i,0);
    dot_matrix.clearDisplay(i);
  }
}

void setup() {
  dot_metrix_init(MATRIX);
  
}

void loop() {

  int n = 0;
  int line = 0;
  
  
  dot_matrix.setRow(n,line, B10101010);
  dot_matrix.setRow(n,1, B01010101);
  dot_matrix.setRow(n,2, B10101010);
  dot_matrix.setRow(n,3, B01010101);
  dot_matrix.setRow(n,4, B10101010);
  dot_matrix.setRow(n,5, B01010101);
  dot_matrix.setRow(n,6, B10101010);
  dot_matrix.setRow(n,7, B01010101);
  dot_matrix.setRow(1,line, B10101010);
  dot_matrix.setRow(1,1, B01010101);
  dot_matrix.setRow(1,2, B10101010);
  dot_matrix.setRow(1,3, B01010101);
  dot_matrix.setRow(1,4, B10101010);
  dot_matrix.setRow(1,5, B01010101);
  dot_matrix.setRow(1,6, B10101010);
  dot_matrix.setRow(1,7, B01010101);
  dot_matrix.setRow(2,line, B10101010);
  dot_matrix.setRow(2,1, B01010101);
  dot_matrix.setRow(2,2, B10101010);
  dot_matrix.setRow(2,3, B01010101);
  dot_matrix.setRow(2,4, B10101010);
  dot_matrix.setRow(2,5, B01010101);
  dot_matrix.setRow(2,6, B10101010);
  dot_matrix.setRow(2,7, B01010101);
dot_matrix.setRow(3,line, B10101010);
  dot_matrix.setRow(3,1, B01010101);
  dot_matrix.setRow(3,2, B10101010);
  dot_matrix.setRow(3,3, B01010101);
  dot_matrix.setRow(3,4, B10101010);
  dot_matrix.setRow(3,5, B01010101);
  dot_matrix.setRow(3,6, B10101010);
  dot_matrix.setRow(3,7, B01010101);
  
  delay(100);

  dot_matrix.setRow(n,line, B01010101);
  dot_matrix.setRow(n,1, B10101010);
  dot_matrix.setRow(n,2, B01010101);
  dot_matrix.setRow(n,3, B10101010);
  dot_matrix.setRow(n,4, B01010101);
  dot_matrix.setRow(n,5, B10101010);
  dot_matrix.setRow(n,6, B01010101);
  dot_matrix.setRow(n,7, B10101010);
   dot_matrix.setRow(1,line, B01010101);
  dot_matrix.setRow(1,1, B10101010);
  dot_matrix.setRow(1,2, B01010101);
  dot_matrix.setRow(1,3, B10101010);
  dot_matrix.setRow(1,4, B01010101);
  dot_matrix.setRow(1,5, B10101010);
  dot_matrix.setRow(1,6, B01010101);
  dot_matrix.setRow(1,7, B10101010);
   dot_matrix.setRow(2,line, B01010101);
  dot_matrix.setRow(2,1, B10101010);
  dot_matrix.setRow(2,2, B01010101);
  dot_matrix.setRow(2,3, B10101010);
  dot_matrix.setRow(2,4, B01010101);
  dot_matrix.setRow(2,5, B10101010);
  dot_matrix.setRow(2,6, B01010101);
  dot_matrix.setRow(2,7, B10101010);
   dot_matrix.setRow(3,line, B01010101);
  dot_matrix.setRow(3,1, B10101010);
  dot_matrix.setRow(3,2, B01010101);
  dot_matrix.setRow(3,3, B10101010);
  dot_matrix.setRow(3,4, B01010101);
  dot_matrix.setRow(3,5, B10101010);
  dot_matrix.setRow(3,6, B01010101);
  dot_matrix.setRow(3,7, B10101010);
  

  delay(100);
  
}
