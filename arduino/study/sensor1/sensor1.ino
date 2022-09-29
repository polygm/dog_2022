// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ int readValue = analogRead(A0);
 Serial.println(readValue);
 if(readValue > 600){
   digitalWrite(13,HIGH);
 }else{
   digitalWrite(13,LOW);
 }
}
