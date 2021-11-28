//LED Binary Number Display
#define DATA 6 //Defines Pin 6 to be the data output
#define LATCH 8 //Defines Pin 8 to control the latch
#define CLOCK 10 //Defines Pin 10 to be the clock out

void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop()
{
  int i;
  for ( i = 0; i < 128; i++ )
  {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, i);
    digitalWrite(LATCH, HIGH);
    delay(200);
  }
}
