//LED Binary Guessing Game
#define DATA 6
#define LATCH 8
#define CLOCK 10
int number = 0;
int answer = 0;
void setup()
{
pinMode(LATCH, OUTPUT);
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
Serial.begin(9600);
randomSeed(analogRead(0));
displayNumber(0);
}

void displayNumber(byte a)
{
digitalWrite(LATCH, LOW);
shiftOut(DATA, CLOCK, MSBFIRST, a);
digitalWrite(LATCH, HIGH);
}

void getAnswer() 
{
  int z = 0;
  Serial.flush();
  while (Serial.available() == 0)
    {
    }
  while (Serial.available() > 0)
  {
    answer = answer*10;
    z = Serial.read()-'0';
    answer = answer + z;
    delay(5);
  }
  Serial.print("You entered: ");
  Serial.print(answer);
}

void checkAnswer()
{
if(answer == number)
{
Serial.print("Correct! ");
Serial.print(answer, BIN);
Serial.print(" equals ");
Serial.println(number);
Serial.println();
}
else
{
Serial.print("Incorrect: ");
Serial.print(number, BIN);
Serial.print(" equals ");
Serial.println(number);
Serial.println();
}
answer = 0;
delay(10000); //
}

void loop()
{
number = random(256);
displayNumber(number);
Serial.println("What is the binary number in base-10? ");
getAnswer();
checkAnswer();
}
