#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bluetooth.begin(9600);
Serial.println("START");
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

char val = bluetooth.read();

if(bluetooth.available()){
Serial.write(bluetooth.read());
}

if(val=='a'){
  digitalWrite(3,HIGH);
  }

if(val=='b'){
  digitalWrite(5,HIGH);
  
}

if(val=='c'){
  digitalWrite(5,LOW);
  digitalWrite(3,LOW);
  
}



}
