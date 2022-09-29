// C++ code
//
#include <Wire.h>

const int pinLED = 7;
int x= 0 ;


void setup()
{
Wire.begin(1);
  Wire.onReceive(receivedEvent);
  Serial.begin(115200);
  pinMode(pinLED, OUTPUT);
}

void loop()
{
  delay(100);
  
}

void receivedEvent(int howmany){
  x = Wire.read();
    if(x == HIGH) {
    digitalWrite(pinLED, LOW);
  } else {
    digitalWrite(pinLED, HIGH);
  }
}
