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
  int slash = 0;
  int line = 0;
  int led = 0;
  int n = 0;


  for (slash = 0; slash < 8; slash++) {
    
    led = B10000000;

    if (slash % 2 == 0)
      for (line = slash; line >= 0; line--) {
  
          dot_matrix.setRow(n, line, led / pow(2, slash - line));
          delay(100);
          dot_matrix.clearDisplay(n);
            
      }
    else
      for (line = 0; line <= slash ; line++) {
  
          dot_matrix.setRow(n, line, led / pow(2, slash - line));
          delay(100);
          dot_matrix.clearDisplay(n);
            
      }
    
  }
  
  
  for (slash = 0; slash < 8; slash++) {
 
    led = B10000000;
     if (slash % 2 == 0)
       for (line = 7; line > slash; line--) {
      
         dot_matrix.setRow(n, line, led / pow(2, 8 - (line - slash)));
         delay(100);
         dot_matrix.clearDisplay(n);
          
       }
     else
       for(line = slash+1 ; line < 8; line++) {
    
         dot_matrix.setRow(n, line, led / pow(2, 8 - (line - slash)));
         delay(100);
         dot_matrix.clearDisplay(n);
          
       }
  }

}
