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
morse_a();
morse_n();
morse_t();
morse_a();
morse_e();
morse_h();
morse_u();
morse_n();
delay(300);
}

void morse_a()
{
  dot();
  bar();
}

void morse_n()
{
  bar();
  dot();
}

void morse_t()
{
  bar();
}

void morse_e()
{
  dot();
}

void morse_h()
{
  dot();
  dot();
  dot();
  dot();
}

void morse_u()
{
  dot();
  dot();
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
