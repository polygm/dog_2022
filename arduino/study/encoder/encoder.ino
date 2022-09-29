// L298N motor driver
//
#define IN3 9
#define IN4 10

#define ENCODER_B_A 2
#define ENCODER_B_B A0

byte encoderBLast;
bool encoderBDir = true;
int encoderBCount = 0;
bool active_A = false;

void ISR_encoderB() {
  byte encoderBA = digitalRead(ENCODER_B_A);

  // 방향체크
  if (encoderBLast == LOW && encoderBA == HIGH) {
    byte encoderBB = digitalRead(ENCODER_B_B);
    if (encoderBB == LOW) {
      encoderBDir = true;
    } else if (encoderBB == HIGH) {
      encoderBDir = false;
    }
  }
  encoderBLast = encoderBA;

  // 회전 카운트
  if (encoderBDir) {
    encoderBCount++;
  } else {
    encoderBCount--;
  }
}

void setup() {
  Serial.begin(115200);
  
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENCODER_B_A, INPUT);
  pinMode(ENCODER_B_B, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_A), ISR_encoderB, CHANGE);
}

unsigned long lastTime = 0;
bool logging = false;

void loop() {
  
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'f') {
      Serial.println("forward");
      dc_forward();
      logging = true;
    } if (cmd == 'b') {
      Serial.println("backward");
      dc_backward();
      logging = true;
    } else if (cmd == 's') {
      Serial.println("stop");
      dc_stop();
      logging = false;
    } 
  }

  unsigned long currTime = millis();
  if (logging && (currTime - lastTime > 100)) {
    Serial.print("speedB = ");
    Serial.print(currTime - lastTime);

    Serial.print(" encoderB = ");
    Serial.print(encoderBCount);
    
    Serial.println();
    lastTime = currTime;
  }
}

void dc_backward()
{
  //동작시작
  active_A = true;
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void dc_forward()
{
  if(!active_A) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  
  
    //동작시작
    active_A = true;
  }  
}

void dc_stop()
{
  if(active_A) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  

    //동작시작
    active_A = false;
  }
}
