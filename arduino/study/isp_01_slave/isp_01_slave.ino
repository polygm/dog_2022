#include <SPI.h>

byte count;

void setup() {
  // put your setup code here, to run once:
pinMode(MISO, OUTPUT);
pinMode(MOSI, INPUT);
pinMode(SCK, INPUT);
pinMode(SS, INPUT);

SPCR |=bit(SPE);
SPI.attachInterrupt();

count = 0;
Serial.begin(9600);
Serial.println("slave");

}

ISR (SPI_STC_vect)
{
  SPDR = count ;
}

void loop() {
  // put your main code here, to run repeatedly:
count++;
delay(1000);

}
