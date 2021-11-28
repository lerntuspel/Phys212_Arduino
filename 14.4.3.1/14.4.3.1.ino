// Listing 7-1
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // pins for RS, E, DB4, DB5, DB6, DB7
void setup()
{
 lcd.begin(16, 2);
 lcd.clear();
}
void loop()
{
 lcd.setCursor(5,0);
 lcd.print("Hello");
 lcd.setCursor(6,1);
 lcd.print("World!");
 delay(10000);
}
