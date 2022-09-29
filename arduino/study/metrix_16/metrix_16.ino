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

int n = 0 ;
int line = 0;

int led = 0;

for (int i=1; i<255; i*=2){
  led |= i;
  dot_matrix.setRow(n,line,led);
  dot_matrix.setRow(n,1,led);
  dot_matrix.setRow(n,2,led);
  dot_matrix.setRow(n,3,led);
  dot_matrix.setRow(n,4,led);
  dot_matrix.setRow(n,5,led);
  dot_matrix.setRow(n,6,led);
  dot_matrix.setRow(n,7,led);
  delay(100);
}
for (int i=1; i<255; i*=2){
  led &= (255-i);
  dot_matrix.setRow(n,line,led);
  dot_matrix.setRow(n,1,led);
  dot_matrix.setRow(n,2,led);
  dot_matrix.setRow(n,3,led);
  dot_matrix.setRow(n,4,led);
  dot_matrix.setRow(n,5,led);
  dot_matrix.setRow(n,6,led);
  dot_matrix.setRow(n,7,led);
  delay(100);
}
}
