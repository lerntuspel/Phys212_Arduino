// Quick-Read Thermometer
// define the pins that the LEDs are connected to:
#define NORMAL 4
float voltage = 0;
float celsius = 0;
float sensor = 0;
void setup()
{
  pinMode(NORMAL, OUTPUT);
}

void blink()
{
  digitalWrite(NORMAL, HIGH);
  delay(200);
  digitalWrite(NORMAL, LOW);
  delay(200);
}
void loop()
{
  // read the temperature sensor and convert the result to degrees Celsius
  sensor = analogRead(0);
  voltage = (sensor*5000)/1024; // convert sensor value to mV
  celsius = voltage/10; // convert millivolts to Celsius
  
  // act on temperature range
  if ( celsius > 20 && celsius <= 26 )
  {
    if (celsius > 20)
    { 
      blink();
    }
    if (celsius > 21)
    {  
      blink();
    }
    if (celsius > 22)
    {  
      blink();
    }
    if (celsius > 23)
    {  
      blink();
    }
    if (celsius > 24)
    {  
      blink();
    }
    if (celsius > 25)
    {  
      blink();
    } 
  delay(2000);
  }
}
