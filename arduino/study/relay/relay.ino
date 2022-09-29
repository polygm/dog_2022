const int RELAY = 10;

void setup() {
  // put your setup code here, to run once:
   pinMode(RELAY, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(RELAY, HIGH);
   delay(500);

   digitalWrite(RELAY, LOW);
   delay(500);
}
