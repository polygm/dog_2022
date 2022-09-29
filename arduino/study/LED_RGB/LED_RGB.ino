// C++ code
//
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  for(int i=0; i<255; i++){
  analogWrite(9, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=255; i>0; i--){  
  analogWrite(9, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=0; i<255; i++){
  analogWrite(10, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
   for(int i=255; i>0; i--){  
  analogWrite(10, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  for(int i=0; i<255; i++){
  analogWrite(11, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
   for(int i=255; i>0; i--){  
  analogWrite(11, i);
  delay(10); // Wait for 1000 millisecond(s)
  }
  
  }
