

#define EAST 11 //define pin 12 as the EAST SENSOR pin
#define WEST 12 //define pin 13 as the WEST SENSOR pin
#define WG 2 //define pin 12 as the LED pin
#define WY 3 //define pin 12 as the LED pin
#define WR 4 //define pin 12 as the LED pin
#define EG 5 //define pin 12 as the LED pin
#define EY 6 //define pin 12 as the LED pin
#define ER 7 //define pin 12 as the LED pin
void setup() 
{
pinMode(WG, OUTPUT); //set pin 2 as an output
pinMode(WY, OUTPUT); //set pin 3 as an output
pinMode(WR, OUTPUT); //set pin 4 as an output
pinMode(EG, OUTPUT); //set pin 5 as an output
pinMode(EY, OUTPUT); //set pin 6 as an output
pinMode(ER, OUTPUT); //set pin 7 as an output
pinMode(WEST, INPUT); // set pin 12 as input
pinMode(EAST, INPUT); // set pin 13 as input
digitalWrite(WG, HIGH); //initially turn on West Green
digitalWrite(ER, HIGH); //turn on EAST RED
}

void loop() 
{
  if (digitalRead(WG) == HIGH)
  {
    if (digitalRead(EAST) == HIGH)
    {
      digitalWrite(WG, LOW); //turn of west green
      digitalWrite(WY, HIGH);
      delay(2000);
      digitalWrite(WY, LOW); //turn off west yellow
      digitalWrite(WR, HIGH);
      digitalWrite(EG, HIGH);
      digitalWrite(ER, LOW);
    }
  }
  if (digitalRead(WG) == LOW)
  {
    if (digitalRead(WEST) == HIGH)
    {
      digitalWrite(EG, LOW); //turn of west green
      digitalWrite(EY, HIGH);
      delay(2000);
      digitalWrite(EY, LOW); //turn off west yellow
      digitalWrite(ER, HIGH);
      digitalWrite(WG, HIGH);
      digitalWrite(WR, LOW);
    }
  }
}
