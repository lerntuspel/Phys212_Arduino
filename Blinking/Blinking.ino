//Blinking
void setup()
{
pinMode(2, OUTPUT); //Set Pin 2 to an output
pinMode(3, OUTPUT); //Set Pin 3 to an output
pinMode(4, OUTPUT); //Set Pin 4 to an output
pinMode(5, OUTPUT); //Set Pin 5 to an output
pinMode(6, OUTPUT); //Set Pin 6 to an output}
}

void loop()
{
  for ( int a = 2; a < 7 ; a++ )
  {
    digitalWrite(a, HIGH);
    delay(500);
    digitalWrite(a, LOW);
    delay(500);
  }
}
