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
  // put your main code here, to run repeatedly:
dot_matrix.setRow(0,0,B10000000);
delay(100);
dot_matrix.setRow(0,1,B10000000);
delay(100);
dot_matrix.setRow(0,0,B11000000);
delay(100);
dot_matrix.setRow(0,0,B11100000);
delay(100);
dot_matrix.setRow(0,1,B11000000);
delay(100);
dot_matrix.setRow(0,2,B10000000);
delay(100);
dot_matrix.setRow(0,3,B10000000);
delay(100);
dot_matrix.setRow(0,2,B11000000);
delay(100);
dot_matrix.setRow(0,1,B11100000);
delay(100);
dot_matrix.setRow(0,0,B11110000);
delay(100);
dot_matrix.setRow(0,0,B11111000);
delay(100);
dot_matrix.setRow(0,1,B11110000);
delay(100);
dot_matrix.setRow(0,2,B11100000);
delay(100);
dot_matrix.setRow(0,3,B11000000);
delay(100);
dot_matrix.setRow(0,4,B10000000);
delay(100);
dot_matrix.setRow(0,5,B10000000);
delay(100);
dot_matrix.setRow(0,4,B11000000);
delay(100);
dot_matrix.setRow(0,3,B11100000);
delay(100);
dot_matrix.setRow(0,2,B11110000);
delay(100);
dot_matrix.setRow(0,1,B11111000);
delay(100);
dot_matrix.setRow(0,0,B11111100);
delay(100);
dot_matrix.setRow(0,0,B11111110);
delay(100);
dot_matrix.setRow(0,1,B11111100);
delay(100);
dot_matrix.setRow(0,2,B11111000);
delay(100);
dot_matrix.setRow(0,3,B11110000);
delay(100);
dot_matrix.setRow(0,4,B11100000);
delay(100);
dot_matrix.setRow(0,5,B11000000);
delay(100);
dot_matrix.setRow(0,6,B10000000);
delay(100);
dot_matrix.setRow(0,7,B10000000);
delay(100);
dot_matrix.setRow(0,6,B11000000);
delay(100);
dot_matrix.setRow(0,5,B11100000);
delay(100);
dot_matrix.setRow(0,4,B11110000);
delay(100);
dot_matrix.setRow(0,3,B11111000);
delay(100);
dot_matrix.setRow(0,2,B11111100);
delay(100);
dot_matrix.setRow(0,1,B11111110);
delay(100);
dot_matrix.setRow(0,0,B11111111);
delay(100);
dot_matrix.setRow(0,1,B11111111);
delay(100);
dot_matrix.setRow(0,2,B11111110);
delay(100);
dot_matrix.setRow(0,3,B11111100);
delay(100);
dot_matrix.setRow(0,4,B11111000);
delay(100);
dot_matrix.setRow(0,5,B11110000);
delay(100);
dot_matrix.setRow(0,6,B11100000);
delay(100);
dot_matrix.setRow(0,7,B11000000);
delay(100);
dot_matrix.setRow(0,7,B11100000);
delay(100);
dot_matrix.setRow(0,6,B11110000);
delay(100);
dot_matrix.setRow(0,5,B11111000);
delay(100);
dot_matrix.setRow(0,4,B11111100);
delay(100);
dot_matrix.setRow(0,3,B11111110);
delay(100);
dot_matrix.setRow(0,2,B11111111);
delay(100);
dot_matrix.setRow(0,3,B11111111);
delay(100);
dot_matrix.setRow(0,4,B11111110);
delay(100);
dot_matrix.setRow(0,5,B11111100);
delay(100);
dot_matrix.setRow(0,6,B11111000);
delay(100);
dot_matrix.setRow(0,7,B11110000);
delay(100);
dot_matrix.setRow(0,7,B11111000);
delay(100);
dot_matrix.setRow(0,6,B11111100);
delay(100);
dot_matrix.setRow(0,5,B11111110);
delay(100);
dot_matrix.setRow(0,4,B11111111);
delay(100);
dot_matrix.setRow(0,5,B11111111);
delay(100);
dot_matrix.setRow(0,6,B11111110);
delay(100);
dot_matrix.setRow(0,7,B11111100);
delay(100);
dot_matrix.setRow(0,7,B11111110);
delay(100);
dot_matrix.setRow(0,6,B11111111);
delay(100);
dot_matrix.setRow(0,7,B11111111);
delay(100);




dot_matrix.clearDisplay(0);

}
