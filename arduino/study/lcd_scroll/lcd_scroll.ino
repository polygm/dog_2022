#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(16,1);
lcd.autoscroll();
for(int i=0; i<10; i++){
  lcd.print(i);
  delay(500);
}

lcd.noAutoscroll();
lcd.clear();

}
