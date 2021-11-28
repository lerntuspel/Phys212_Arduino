#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); // pins for RS, E, DB4, DB5, DB6, DB7
float voltage = 0;
float celsius = 0;
float farenheit = 0;
float sensor = 0;

void setup()
{
 lcd.begin(16, 2);
 lcd.clear();
}

void loop()
{
  // read the temperature sensor and convert the result to degrees Celsius
  sensor = analogRead(0);
  voltage = (sensor*5000)/1024; // convert sensor value to mV
  celsius = voltage/10; // convert millivolts to Celsius
  farenheit = ((celsius*9)/5)+32;
  lcd.setCursor(5,0);
  lcd.print("C ");
  lcd.print(celsius);
  lcd.setCursor(5,1);
  lcd.print("F ");
  lcd.print(farenheit);
  delay(10000);
}
  
