void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(115200);
Serial.println("RGB ?");
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  int rv = Serial.parseInt();
  int gv = Serial.parseInt();
  int bv = Serial.parseInt();

  analogWrite(9, (255-rv));
  analogWrite(10, (255-gv));
  analogWrite(11, (255-bv));

  Serial.println(rv);
  Serial.println(gv);
  Serial.println(bv);
  
}
}
