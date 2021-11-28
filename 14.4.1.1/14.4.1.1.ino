
#include <Keypad.h>

#include "Keypad.h"
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS]=
  { {'1','2','3'},
    {'4','5','6' },
    {'7','8','9'},
    {'*','0','#'}};
byte rowPins[ROWS] = {3,2,1,0};
byte colPins[COLS] = {6,5,4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char PIN[6]={'1','2','3','4','5','6'}; // our secret number
char attempt[6]={0,0,0,0,0,0};
int z=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    Serial.print(key);
  }
}
