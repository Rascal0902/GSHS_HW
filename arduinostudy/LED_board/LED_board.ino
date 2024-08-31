/*#define CUSTOM_SETTINGS
#define INCLUDE_CLOCK_SHIELD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<OneSheeld.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int hour,minute,second;
// set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  OneSheeld.begin();
  Clock.queryDateAndTime();
  lcd.begin();
}
void loop()
{
  Serial.begin(9600);
  hour=Clock.getHours();
  minute=Clock.getMinutes();
  second=Clock.getSeconds();
  lcd.setCursor(0, 0);
  lcd.print(0);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(second);
  if(second==59)
  {
    delay(100);
    lcd.setCursor(0,1);
    for(int i=0;i<16;i++)
    {
      lcd.print("");
    }
  }
}*/
#include <LiquidCrystal.h> 
LiquidCrystal lcd(4,5,8,9,10,11);
void setup() {
  lcd.begin(16,2);             
}

void loop() {
 lcd.setCursor(1,0);
 lcd.print("Hello");
 delay(1000);
 lcd.clear();
}
