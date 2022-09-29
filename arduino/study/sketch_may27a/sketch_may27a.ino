void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println("문자를 입력해 주세요");
}

void loop() {
  // 문자형 변수 a 메모리에 만들어 주세요
char a;
if(Serial.available()){
  a = Serial.read();
  
}

}
