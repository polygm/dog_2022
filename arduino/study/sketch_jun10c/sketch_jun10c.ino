#include < Wire.h>
#include < LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2)

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("hello, world2!");
lcd.setCursor(0,1)"
lcd.print("hellow, world2!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
