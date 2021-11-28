#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); // pins for RS, E, DB4, DB5, DB6, DB7
byte a[8] = { B00111,
              B00101,
              B01111,
              B01110,
              B01111,
              B11111,
              B11110,
              B00011 };
 
void setup()
{
 lcd.createChar(0, a);
 lcd.begin(16, 2);
}

void loop()
{
 lcd.write(byte(0)); // write the custom character 0 to the next cursor position
}
