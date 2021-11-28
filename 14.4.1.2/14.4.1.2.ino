#include <Keypad.h>

#include "Keypad.h"
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS]=
  { {'1','2','3'},
    {'4','5','6' },
    {'7','8','9'},
    {'*','0','#'}};
byte rowPins[ROWS] = {3, 2, 1, 0};
byte colPins[COLS] = {6, 5, 4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char PIN[6]={'1','2','3','4','5','6'}; // our secret number
int attempt[6]={0,0,0,0,0,0};
int z=0;

void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT); //green 
  pinMode(12, OUTPUT); //red
}

void correctPIN() // do this if the correct PIN is entered
{
  digitalWrite(11, HIGH);
  Serial.println("Correct PIN entered...");
  delay(1000);
  digitalWrite(11, LOW);
}

void incorrectPIN() // do this if an incorrect PIN is entered
{
  digitalWrite(12, HIGH);
  Serial.println("Incorrect PIN entered!");
  delay(100);
  digitalWrite(12, LOW);
}

void checkPIN()
{
  int correct=0;
  int i;
  for ( i = 0; i < 6 ; i++ )
  {
    if (attempt[i]==PIN[i])
    {
    correct++;
    }
  }
  if (correct==6)
  {
    correctPIN();
  } 
  else
  {
    incorrectPIN();
  }
  for (int zz=0; zz<6; zz++) // remove previously entered
  {
    attempt[zz]=0;
  }
}

void readKeypad()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    switch(key)
    {
      case '*':
        z=0;
        break;
      case '#':
        delay(100); // removes the possibility of switch bounce
        checkPIN();
        break;
      default:
        attempt[z]=key;
        z++;
    }
  }
}

void loop()
{
  readKeypad();
}
