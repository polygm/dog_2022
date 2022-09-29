void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int readValue = analogRead(A3);
Serial.print("analog= ");
Serial.print(readValue);

int y = map(readValue, 0, 1023, 0, 255);
analogWrite(11,y);
Serial.print("LED= ");
Serial.println(y);
}
