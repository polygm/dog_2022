#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bluetooth.begin(9600);
Serial.println("START");

}

void loop() {
  // put your main code here, to run repeatedly:
if(bluetooth.available()){
Serial.write(bluetooth.read());
}
if(Serial.available()){
  bluetooth.write(Serial.read());
}
}
