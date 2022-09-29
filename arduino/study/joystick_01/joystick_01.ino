
const int Yin=A1;
const int Xin=A2;

void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int xVal = analogRead(Xin);
int yVal = analogRead(Yin);

Serial.print("X= ");
Serial.print(xVal, DEC);

Serial.print(", y= ");
Serial.println(yVal, DEC);


delay(100);

}
