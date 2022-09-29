// C++ code
//
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

const int tringPin = 11;
const int echoPin = 12;
const int activeB = 4;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(115200);
  
  pinMode(tringPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(activeB, OUTPUT);

lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("ultrasonic waves");
}


void loop()
{
  digitalWrite(tringPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tringPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(tringPin, LOW);
  
  
  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("cm");
  
  if(distance < 30) {
    digitalWrite(activeB, HIGH);
    delay(distance*10);
    digitalWrite(activeB, LOW);
    delay(distance*10);
  }

  lcd.setCursor(0,1);
  lcd.print("   ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  
}
