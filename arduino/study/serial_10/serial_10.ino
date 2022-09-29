// C++ code
//
void setup()
{
 Serial.begin(9600);
  pinMode(8,OUTPUT);
}

void loop()
{
  if(Serial.available()){
    char data = Serial.read();
    if(data == '1') {
      digitalWrite(8,HIGH);
    }else{
      digitalWrite(8,LOW);
    }
  }
}
