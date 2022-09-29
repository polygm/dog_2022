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
int n=0;
int line=0;
int led=0;
for(line=0; line<8; line++){



for(int led=B10000000; led>=1; led/=2){
  
    
  dot_matrix.setRow(n,line,led);

  
  delay(100);
}

  led=0;

  dot_matrix.clearDisplay(n);
}
}
