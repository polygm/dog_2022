const int time = 100;
const int wating = 100;

void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
morse_s();
morse_o();
morse_s();
delay(300);
}

void morse_s()
{
  dot();
  dot();
  dot();
}

void morse_o()
{
  bar();
  bar();
  bar();
}

void dot()
{
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
  delay(time);
  digitalWrite(4,LOW);
  digitalWrite(6,LOW);

  delay(wating);
}

void bar()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  delay(3*time);
  
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);

  delay(wating);
}
