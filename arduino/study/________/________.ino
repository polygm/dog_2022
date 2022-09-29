const int BEEP = 5;
void setup() {
  pinMode(BEEP,OUTPUT);

}

void loop() {
   tone(BEEP,262); // 도
  delay(500);
  
  tone(BEEP,294); // 레
  delay(500);

  tone(BEEP,330); // 미
  delay(500);

  tone(BEEP,350); // 파
  delay(500);
  
  tone(BEEP,392); // 솔
  delay(500);
  
  tone(BEEP,440); // 라
  delay(500);

  tone(BEEP,492); // 시
  delay(500);

  tone(BEEP,523); // 도
  delay(500);

  noTone(BEEP);

}
