// Single 7-Segment Display
#define DATA 6
#define LATCH 8
#define CLOCK 10
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
void setup()
{
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
}
void loop()
{
int i;
for (i = 0; i< 10; i++)
{
digitalWrite(LATCH, LOW);
delay(250);
shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
digitalWrite(LATCH, HIGH);
delay(500);
}
}
