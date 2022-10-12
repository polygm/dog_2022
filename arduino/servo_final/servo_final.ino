/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

// called this way, it uses the default address 0x40
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
//#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
//#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define BT_RXD 8
#define BT_TXD 7

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

// our servo # counter
uint8_t servo_fl_1 = 0;
uint8_t servo_fl_2 = 1;
uint8_t servo_fl_3 = 2;
uint8_t servo_fr_1 = 4;
uint8_t servo_fr_2 = 5;
uint8_t servo_fr_3 = 6;
uint8_t servo_bl_1 = 8;
uint8_t servo_bl_2 = 9;
uint8_t servo_bl_3 = 10;
uint8_t servo_br_1 = 12;
uint8_t servo_br_2 = 13;
uint8_t servo_br_3 = 14;

void setup() {
  
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  bluetooth.begin(9600);

  

  pwm.begin();
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  int angle1;
  int angle2;
  int angle3;
  int angle4;
  int angle5;
  int angle6;
  int angle7;
  int angle8;
  int angle9;
  int pulse1;
  int pulse2;
  int pulse3;
  int pulse4;
  int pulse5;
  int pulse6;
  int pulse7;
  int pulse8;
  int pulse9;
  int pulse10;
      
  angle1 = 0;
  pulse1 = map(angle1 -5 , 0, 180, USMIN, USMAX);
  pulse2 = map(angle1 + 160, 0, 180, USMIN, USMAX);
  pulse3 = map(angle1 + 160, 0, 180, USMIN, USMAX);
  pulse4 = map(angle1 -5, 0, 180, USMIN, USMAX);
  pwm.writeMicroseconds(servo_fl_1, pulse1);
  pwm.writeMicroseconds(servo_fr_1, pulse2);
  pwm.writeMicroseconds(servo_bl_1, pulse3);
  pwm.writeMicroseconds(servo_br_1, pulse4);
   
  angle2 = 130;
  angle3 = 90;
  angle4 = 30;
  angle5 = 70;
  angle6 = 130;
  angle7 = 90;
  angle8 = 30;
  angle9 = 70;
  
  pulse2 = map(angle2, 0, 180, USMIN, USMAX);
  pulse3 = map(angle3, 0, 180, USMIN, USMAX);
  pulse5 = map(angle4, 0, 180, USMIN, USMAX);
  pulse6 = map(angle5, 0, 180, USMIN, USMAX);
  pulse7 = map(angle6, 0, 180, USMIN, USMAX);
  pulse8 = map(angle7, 0, 180, USMIN, USMAX);
  pulse9 = map(angle8, 0, 180, USMIN, USMAX);
  pulse10 = map(angle9, 0, 180, USMIN, USMAX);
  
  pwm.writeMicroseconds(servo_fl_2, pulse2);
  pwm.writeMicroseconds(servo_fl_3, pulse3);
  pwm.writeMicroseconds(servo_fr_2, pulse9);
  pwm.writeMicroseconds(servo_fr_3, pulse10);
  pwm.writeMicroseconds(servo_bl_2, pulse7);
  pwm.writeMicroseconds(servo_bl_3, pulse8);
  pwm.writeMicroseconds(servo_br_2, pulse5);
  pwm.writeMicroseconds(servo_br_3, pulse6);


  delay(10);
}

// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

char tmp = 'i';
int flag = 0;

void loop() {
  
  int angle1;
  int angle2;
  int angle3;
  int angle4;
  int angle5;
  int angle6;
  int angle7;
  int angle8;
  int angle9;
  int pulse1;
  int pulse2;
  int pulse3;
  int pulse4;
  int pulse5;
  int pulse6;
  int pulse7;
  int pulse8;
  int pulse9;
  int pulse10;
  int walk_cnt;

  char val;

/*
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
      pwm.setPWM(servo_fl_1, 0, pulselen);
  }

  delay(500);
  
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm.setPWM(servo_fl_1, 0, pulselen);
  }

  delay(500);
*/


  // Drive each servo one at a time using writeMicroseconds(), it's not precise due to calculation rounding!
  // The writeMicroseconds() function is used to mimic the Arduino Servo library writeMicroseconds() behavior. 
/*
  for (angle2 = 100, angle3 = 130; angle2 < 150, angle3 > 30; angle2++, angle3 -= 2) {
    pulse2 = map(angle2, 0, 180, USMIN, USMAX);
    pulse3 = map(angle3, 0, 180, USMIN, USMAX);
    pwm.writeMicroseconds(servo_fl_2, pulse2);
    pwm.writeMicroseconds(servo_fl_3, pulse3);
    delay(10);
  }
  delay(500);

  for (angle2 = 150, angle3 = 30; angle2 > 100, angle3 < 130; angle2--, angle3 += 2) {
    pulse2 = map(angle2, 0, 180, USMIN, USMAX);
    pulse3 = map(angle3, 0, 180, USMIN, USMAX);
    pwm.writeMicroseconds(servo_fl_2, pulse2);
    pwm.writeMicroseconds(servo_fl_3, pulse3);
    delay(10);
  }
  delay(500);
*/

  if (bluetooth.available()) 
  {

    val = bluetooth.read();
    

      angle1 = 0;
      pulse1 = map(angle1 -5, 0, 180, USMIN, USMAX);
      pulse2 = map(angle1 +160, 0, 180, USMIN, USMAX);
      pulse3 = map(angle1 +160, 0, 180, USMIN, USMAX);
      pulse4 = map(angle1 -5 , 0, 180, USMIN, USMAX);
      pwm.writeMicroseconds(servo_fl_1, pulse1);
      pwm.writeMicroseconds(servo_fr_1, pulse2);
      pwm.writeMicroseconds(servo_bl_1, pulse3);
      pwm.writeMicroseconds(servo_br_1, pulse4);


  
    if (val == 'g' && tmp != 'd') {  // front
      walk_cnt = 0;
  angle2 = 130;
  angle3 = 90;
  angle4 = 30;
  angle5 = 70;
  angle6 = 130;
  angle7 = 90;
  angle8 = 30;
  angle9 = 70;
      
      while (angle2 >= 110) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);

        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2--;
        angle4++;
        angle6++;
        angle8--;
        if (walk_cnt % 2 == 0)
          angle3--;
          angle5++;
          angle7++;
          angle9--;
      }
      while (angle2 <= 150) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);
        
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2++;
        angle4--;
        angle6--;
        angle8++;
        if (walk_cnt % 2 == 0)
          angle3++;
          angle5--;
          angle7--;
          angle9++;
      }
      while (angle2 >= 130) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);
        
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2--;
        angle4++;
        angle6++;
        angle8--;
        if (walk_cnt % 2 == 0)
          angle3--;
          angle5++;
          angle7++;
          angle9--;
      }
    }
    
    if (val == 'b' && tmp != 'd') {  // back
      walk_cnt = 0;
  angle2 = 130;
  angle3 = 90;
  angle4 = 30;
  angle5 = 70;
  angle6 = 130;
  angle7 = 90;
  angle8 = 30;
  angle9 = 70;
      
      while (angle2 >= 110) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);

        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2--;
        angle4++;
        angle6++;
        angle8--;
        if (walk_cnt % 2 == 0)
          angle3++;
          angle5--;
          angle7--;
          angle9++;
      }
      while (angle2 <= 150) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);
        
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2++;
        angle4--;
        angle6--;
        angle8++;
        if (walk_cnt % 2 == 0)
          angle3--;
          angle5++;
          angle7++;
          angle9--;
      }
      while (angle2 >= 130) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);
        
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(5);
        walk_cnt++;
        angle2--;
        angle4++;
        angle6++;
        angle8--;
        if (walk_cnt % 2 == 0)
          angle3++;
          angle5--;
          angle7--;
          angle9++;
      }
    }

    if (val == 'd' && tmp != 'd') {       // down
      angle2 = 130;
      angle3 = 90;
      
        while (angle2 <= 150) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(160 - angle2, 0, 180, USMIN, USMAX);
        pulse6 = map(160 - angle3, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse5);
        pwm.writeMicroseconds(servo_fr_3, pulse6);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(10);
        angle2++;
        angle3 -= 3;

      }
    }

    if (val == 'u' && tmp == 'd') {  // up
      angle2 = 150;
      angle3 = 30;
      
      while  (angle2 >= 130) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(160 - angle2, 0, 180, USMIN, USMAX);
        pulse6 = map(160 - angle3, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse5);
        pwm.writeMicroseconds(servo_fr_3, pulse6);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(10);
        angle2--;
        angle3 += 3;
      }
    }
    
    if (val == 'l' && tmp != 'd') {       // left
      angle2 = 130;
      angle3 = 90;

      pulse5 = map(160 - angle2, 0, 180, USMIN, USMAX);
      pulse6 = map(160 - angle3, 0, 180, USMIN, USMAX);
      pwm.writeMicroseconds(servo_fr_2, pulse5);
      pwm.writeMicroseconds(servo_fr_3, pulse6);
      pwm.writeMicroseconds(servo_br_2, pulse5);
      pwm.writeMicroseconds(servo_br_3, pulse6);
      
      while (angle2 <= 160) {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);       
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        
        delay(10);
        angle2++;
        angle3 -= 2;
      }
        delay(500);
      
      while (angle2 >= 130)  {
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        delay(10);
        angle2--;
        angle3 += 2;
      }
    }
    if (val == 'r' && tmp != 'd') {       // right
      angle2 = 130;
      angle3 = 90;

      pulse2 = map(angle2, 0, 180, USMIN, USMAX);
      pulse3 = map(angle3, 0, 180, USMIN, USMAX);
      pwm.writeMicroseconds(servo_fl_2, pulse2);
      pwm.writeMicroseconds(servo_fl_3, pulse3);
      pwm.writeMicroseconds(servo_bl_2, pulse2);
      pwm.writeMicroseconds(servo_bl_3, pulse3);
      
      while (angle2 <= 160) {
        pulse5 = map(160 - angle2, 0, 180, USMIN, USMAX);
        pulse6 = map(160 - angle3, 0, 180, USMIN, USMAX);       
        pwm.writeMicroseconds(servo_fr_2, pulse5);
        pwm.writeMicroseconds(servo_fr_3, pulse6);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        
        delay(10);
        angle2++;
        angle3 -= 2;
      }
        delay(500);
      
      while (angle2 >= 130)  {
        pulse5 = map(160 - angle2, 0, 180, USMIN, USMAX);
        pulse6 = map(160 - angle3, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_fr_2, pulse5);
        pwm.writeMicroseconds(servo_fr_3, pulse6);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
        delay(10);
        angle2--;
        angle3 += 2;
      }
    }
    
    if (val == 's' && tmp != 'd') {   // sorry
  angle2 = 130;
  angle3 = 90;
  angle4 = 30;
  angle5 = 70;
  angle6 = 130;
  angle7 = 90;
  angle8 = 30;
  angle9 = 70;
      
      pulse2 = map(angle2, 0, 180, USMIN, USMAX);
      pulse3 = map(angle3, 0, 180, USMIN, USMAX);
      pulse5 = map(angle4, 0, 180, USMIN, USMAX);
      pulse6 = map(angle5, 0, 180, USMIN, USMAX);
      pulse7 = map(angle6, 0, 180, USMIN, USMAX);
      pulse8 = map(angle7, 0, 180, USMIN, USMAX);
      pulse9 = map(angle8, 0, 180, USMIN, USMAX);
      pulse10 = map(angle9, 0, 180, USMIN, USMAX);

      pwm.writeMicroseconds(servo_fl_2, pulse2);
      pwm.writeMicroseconds(servo_fl_3, pulse3);
      pwm.writeMicroseconds(servo_fr_2, pulse9);
      pwm.writeMicroseconds(servo_fr_3, pulse10);
      pwm.writeMicroseconds(servo_bl_2, pulse7);
      pwm.writeMicroseconds(servo_bl_3, pulse8);
      pwm.writeMicroseconds(servo_br_2, pulse5);
      pwm.writeMicroseconds(servo_br_3, pulse6);

      int elbow = 0;
      while (elbow < 90) {
        pulse4 = map(angle1 + elbow, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_br_1, pulse4);
        
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);       
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        
        delay(10);

        if (elbow % 2 == 0) {
          angle2++;
          angle3 -= 2;
        }
        elbow++;
      }
      delay(1000);

      while (elbow >= 0) {
        pulse4 = map(angle1 + elbow, 0, 180, USMIN, USMAX);
        pwm.writeMicroseconds(servo_br_1, pulse4);
        
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);       
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_bl_2, pulse2);
        pwm.writeMicroseconds(servo_bl_3, pulse3);
        
        delay(10);

        if (elbow % 2    == 0) {
          angle2-- ;
          angle3 += 2;
        }
        elbow--;
      }
      
      
    }

    if(val == 'i') {

  angle2 = 130;
  angle3 = 90;
  angle4 = 30;
  angle5 = 70;
  angle6 = 130;
  angle7 = 90;
  angle8 = 30;
  angle9 = 70;
        
        pulse2 = map(angle2, 0, 180, USMIN, USMAX);
        pulse3 = map(angle3, 0, 180, USMIN, USMAX);
        pulse5 = map(angle4, 0, 180, USMIN, USMAX);
        pulse6 = map(angle5, 0, 180, USMIN, USMAX);
        pulse7 = map(angle6, 0, 180, USMIN, USMAX);
        pulse8 = map(angle7, 0, 180, USMIN, USMAX);
        pulse9 = map(angle8, 0, 180, USMIN, USMAX);
        pulse10 = map(angle9, 0, 180, USMIN, USMAX);
        
        pwm.writeMicroseconds(servo_fl_2, pulse2);
        pwm.writeMicroseconds(servo_fl_3, pulse3);
        pwm.writeMicroseconds(servo_fr_2, pulse9);
        pwm.writeMicroseconds(servo_fr_3, pulse10);
        pwm.writeMicroseconds(servo_bl_2, pulse7);
        pwm.writeMicroseconds(servo_bl_3, pulse8);
        pwm.writeMicroseconds(servo_br_2, pulse5);
        pwm.writeMicroseconds(servo_br_3, pulse6);
    }
    
  }

  if (tmp == 'd' && val != 'i' && val != 'u')
    tmp == 'd';
  else if (val == 'u' && tmp != 'd')
    tmp == 'u';
  else
    tmp = val;
    

  delay(500);
  
//  servonum++;
//  if (servonum > 7) servonum = 0; // Testing the first 8 servo channels
}
