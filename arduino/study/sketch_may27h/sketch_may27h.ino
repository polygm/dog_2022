// C++ code
//
void setup()
{
  pinMode(6, OUTPUT);
}

void loop()
{
  for(int i=0; i<255; i+=10){
  analogWrite(6, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=255; i>0; i-=10){  
  analogWrite(6, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=0; i<255; i+=10){
  analogWrite(5, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=255; i>0; i-=10){  
  analogWrite(5, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=0; i<255; i+=10){
  analogWrite(9, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=255; i>0; i-=10){  
  analogWrite(9, i);
  delay(10); // Wait for 1000 millisecond(s)
  }

      for(int i=0; i<255; i+=10){
  analogWrite(5, i);
  delay(10); // Wait for 1000 millisecond(s)
    }
  
    for(int i=255; i>0; i-=10){  
  analogWrite(5, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
      for(int i=0; i<255; i+=10){
  analogWrite(6, i);
  delay(10); // Wait for 1000 millisecond(s)
  }

  for(int i=255; i>0; i-=10){  
  analogWrite(6, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  

  
  for(int i=0; i<255; i++){
    analogWrite(6, i);
    analogWrite(5, i);
    analogWrite(9, i);
    delay(10);
  }
  
  for(int i=255; i>0; i--){
    analogWrite(6, i);
    analogWrite(5, i);
    analogWrite(9, i);
    delay(10);
  }
  
  
  
  }
