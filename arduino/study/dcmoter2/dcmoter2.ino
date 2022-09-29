const int IN1 = 9;
const int IN2 = 10;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // 정방향 회전
  digitalWrite(IN1, LOW);

  for(int i=0;i<255;i++) {
    analogWrite(IN2,i);
    delay(50);
  }

  for(int i=255;i>50;i--) {
    analogWrite(IN2,i);
    delay(50);
  }
  
  digitalWrite(IN2, LOW);

  for(int i=0;i<255;i++) {
    analogWrite(IN1,i);
    delay(50);
  }

  for(int i=255;i>50;i--) {
    analogWrite(IN1,i);
    delay(50);
  }
  
}
