#include <SPI.h>


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
digitalWrite(SS, HIGH);
SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop() {
  // put your main code here, to run repeatedly:
SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
digitalWrite(SS, LOW);

byte received = SPI.transfer(0);
digitalWrite(SS, HIGH);
SPI.endTransaction();

Serial.println(received);
delay(1000);
}
