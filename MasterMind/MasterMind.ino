#include <Keypad.h>
#include <LiquidCrystal.h>
#include "Keypad.h"

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // pins for RS, E, DB4, DB5, DB6, DB7

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
int z=0;


//code and its buffer
int code[4];
int codeBuffer[4];

//input and its buffer
int input[4] = {0,0,0,0};
int guess[4];

int turns = 10;
int wp = 0;
int bp = 0;
bool solved = false;

//The most difficult thing was discovering the fact that there were no such thing as local variables
//It took me about 2 days to figure out that was the reason most of my stuff was still untestable




void setup()
{
  int code[4];
  int codeBuffer[4];

//input and its buffer
  int input[4] = {0,0,0,0};
  int guess[4];

  int turns = 10;
  int wp = 0;
  int bp = 0;
  bool solved = false;
  Serial.begin(9600);
  lcd.begin(16, 2);
  randomSeed(analogRead(0));

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Welcome to");
  lcd.setCursor(3,1);
  lcd.print("Mastermind!");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Black is correct");
  lcd.setCursor(3,1);
  lcd.print("number");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("White is correct");
  lcd.setCursor(3,1);
  lcd.print("num and position");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("* to reset guess");
  lcd.setCursor(0,1);
  lcd.print("# to enter guess");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter only Nums in");
  lcd.setCursor(0,1);
  lcd.print("1 thru 6");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("10 Guesses total");
  lcd.setCursor(0,1);
  lcd.print("Have Fun!");
  delay(2000);
  
  generateCode();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Code generated.");
  lcd.setCursor(0,1);
  lcd.print("Enter Guesses");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
}

void generateCode()
{ 
  for (int i = 0; i < 4; i = i + 1)
  {
    code[i] = random(1,7);
    Serial.print(code[i]);
  }
}

void clue()
{
  wp = 0;
  bp = 0;
  //creates the buffers
  for (int i = 0; i < 4; i = i + 1)
  {
    //for whatever reason, 48 is the correction number
    guess[i] = input[i]-48;
    codeBuffer[i] = code[i];
  }
  for (int i = 0; i < 4; i = i + 1)
  {
    if (codeBuffer[i]==guess[i])
    {
      wp = wp + 1;
      guess[i] = 0;
      codeBuffer[i] = -1;
    }
  }
  
  for (int i = 0; i < 4; i = i + 1)
  {
    for (int j = 0; j < 4; j = j + 1)
    {
      if (codeBuffer[i]==guess[j])
      {
        bp = bp + 1;
        guess[j] = 0;
        codeBuffer[i] = -1;
      }
    }
  }
  //Print last guess undeneith and cleans up old space
  lcd.setCursor(0,1);
  for (int i = 0; i < 4; i = i + 1)
  {
    lcd.print(input[i]-48);
  }
  lcd.setCursor(0,0);
  for (int i = 0; i < 4; i = i + 1)
  {
    lcd.print(' ');
  }
  
  lcd.setCursor(7,0);
  lcd.print(wp);
  lcd.print(" White");
  
  lcd.setCursor(7,1);
  lcd.print(bp);
  lcd.print(" Black");

  if (wp==4)
  {
    solved = true;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("SOLVED");
  }
  
  lcd.setCursor(0,0);
}

void readKeypad()
{
  delay(100);
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    switch(key)
    {
      case '*':
        lcd.clear();

        lcd.setCursor(0,1);
        for (int i = 0; i < 4; i = i + 1)
        {
          lcd.print(input[i]-48);
        }
        
        lcd.setCursor(0,0);
        for (int i = 0; i < 4; i = i + 1)
        {
          lcd.print(' ');
        }
  
        lcd.setCursor(7,0);
        lcd.print(wp);
        lcd.print(" White");
  
        lcd.setCursor(7,1);
        lcd.print(bp);
        lcd.print(" Black");
        lcd.setCursor(0,0);
        z=0;
        break;
      case '#':
        delay(100); // removes the possibility of switch bounce
        clue();
        z=0;
        turns = turns-1;
        break;
      default:
        if (z<4)
        {
          input[z]=key;
          lcd.print(input[z]-48);
          z++;
        }
    }
  }
}

void loop()
{
  while ((not solved) and (turns != 0))
  {
    readKeypad();
  }
  if (not solved)
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("FAILED");
    lcd.setCursor(0,1);
    lcd.print("Hit UNO reset Button");
  }
  //No other clean way to end, for some reason, stuff would seriously mess up if I tried a loop to do the setup and play again.
  delay(10000000);
}
