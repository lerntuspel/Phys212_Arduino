// Single 7-Segment Display
#define DATA 6
#define LATCH 8
#define CLOCK 10
#define BUTTON 4
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
int i;
void setup()
{
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
pinMode(BUTTON, INPUT);
}

void loop()
{
if (digitalRead(BUTTON)==HIGH)
  {
  i = random(1,7);
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
  digitalWrite(LATCH, HIGH);
  }
}
