void setup()
{
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  showSpectrum();
}

void showSpectrum()
{
  for(int x=0;x<256*3; x++){
    showRGB(x);
    delay(10);
  }
}

void showRGB(int color)
{
  int red, green, blue;
  if(color <=255) {
    red = 255 - color;
    green = color;
    blue = 0;
  } else if(color<= 511) {
    red =0;
    green = 255- (color-256);
    blue = (color-256);
  } else {
    red = color -512;
    green = 0;
    blue = 255 - (color-512);
  }

  analogWrite(9,red);
  analogWrite(10,green);
  analogWrite(11,blue);

}
