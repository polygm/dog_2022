// L298N motor driver
//
#define ENB 6
#define IN3 9
#define IN4 10

#define ENCODER_B_A 2
#define ENCODER_B_B A0

byte encoderBLast;
bool encoderBDir = true;
int encoderBCount = 0;

void ISR_encoderB() {
  byte encoderBA = digitalRead(ENCODER_B_A);
  if (encoderBLast == LOW && encoderBA == HIGH) {
    byte encoderBB = digitalRead(ENCODER_B_B);
    if (encoderBB == LOW) {
      encoderBDir = true;
    } else if (encoderBB == HIGH) {
      encoderBDir = false;
    }
  }
  encoderBLast = encoderBA;
  if (encoderBDir) {
    encoderBCount++;
  } else {
    encoderBCount--;
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ENB, OUTPUT);
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
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 125);
      logging = true;
    } if (cmd == 'b') {
      Serial.println("backward");
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 125);
      logging = true;
    } else if (cmd == 's') {
      Serial.println("stop");
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 0);
      logging = false;
    } 
  }

  unsigned long currTime = millis();
  if (logging && (currTime - lastTime > 100)) {
    Serial.print("encoderB = ");
    Serial.print(encoderBCount);
    Serial.println();
    lastTime = currTime;
  }
}
