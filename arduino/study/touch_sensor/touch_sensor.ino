const int TOUCH_SENSOR = 7;



void setup() {
  // put your setup code here, to run once:
pinMode(TOUCH_SENSOR, INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int status = digitalRead(TOUCH_SENSOR);

if(status == LOW){
  Serial.println("Touch off");
}else{
  Serial.println("*** Touch on ***");
}

delay(1000);
}
