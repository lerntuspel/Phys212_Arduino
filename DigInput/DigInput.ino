//Digital Input
#define LED 12 //define pin 12 as the LED pin
#define BUTTON 7 //define pin 7 as the BUTTON pin
void setup()
{
pinMode(LED, OUTPUT); //set pin 12 as an output
pinMode(BUTTON, INPUT); // set pin 7 as input
}
void loop()
{
  if ( digitalRead(BUTTON) == HIGH )
  {
    digitalWrite(LED, HIGH); //turn on LED
    delay(1000); //wait 1 second
    digitalWrite(LED, LOW); //turn off LED
  }
}
