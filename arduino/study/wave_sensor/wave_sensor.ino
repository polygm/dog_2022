const int SENSOR = A0;
const int LED = 8;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(SENSOR, INPUT);
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(SENSOR);

Serial.print("Gas= ");
Serial.println(value);

if(value<80){
  digitalWrite(LED,HIGH);
  delay(1000);
}else{
  digitalWrite(LED,LOW);
}
delay(100);
}
