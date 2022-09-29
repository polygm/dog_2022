const int FlexPin = A0;
const int led = 9;

void setup()
{
 Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop()
{
  int FlexVal;
  FlexVal = analogRead(FlexPin);
  
  Serial.print("sensor ");
  Serial.println(FlexVal);
  
  int lightValue = map(FlexVal, 0 , 400, 0, 255);
  analogWrite(led, lightValue);
                       delay(500);
  }
