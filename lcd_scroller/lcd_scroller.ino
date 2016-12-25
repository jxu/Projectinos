/* 1602 LCD (HD44780 driver compatible) holiday experiment 
 * Based on https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 *
 *  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor: ends to +5V and ground
 * 1K resistor to LCD VO pin (pin 3)
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, 0);
}

void scroll(int loops)
{
  char MSG0[] = "   * Merry *   ";
  char MSG1[] = " * Christmas! *";
  int MSGLEN = sizeof(MSG1);

  
  // Setup text scrolling
  lcd.clear();
  //lcd.setCursor(0, 0);
  lcd.print(MSG0);
  lcd.setCursor(0, 1);
  lcd.print(MSG1);
  delay(1000);

  
  for (int scroll_count = 0; scroll_count < loops; scroll_count++)
  {
    // scroll (string length) to the left
    for (int i = 0; i < MSGLEN; i++) 
    {
      lcd.scrollDisplayLeft();
      delay(150);
    }
  
    // scroll (string length + display length) to the right
    for (int i = 0; i < MSGLEN + 16; i++) 
    {
      lcd.scrollDisplayRight();
      delay(150);
    }
  
    // scroll (display length) to the left
    for (int i = 0; i < 16; i++) {
      lcd.scrollDisplayLeft();
      delay(150);
    }
  
    delay(1000);
  }
}

void snow(int steps)
{
  char SNOW[] = {' ', '*', 0xEB, 0xDF, 0xA1};
  
  // Wintery scene with randomized snow
  lcd.clear();
  
  for (int snow_count = 0; snow_count < steps; snow_count++)
  {
    char to_write = SNOW[random(sizeof(SNOW))];

    lcd.setCursor(random(16), random(2));
    lcd.print(to_write);

    delay(200);
  }  
}

void fly_in()
{
  char MSG0[] = "-For Mom & Dad ";
  int MSGLEN = sizeof(MSG0);
  
  lcd.clear();

  for (int i = 0; i < MSGLEN; i++)
  {
    if (MSG0[i] != ' ')
    {
      for (int j = 15; j > i; j--)
      {
        lcd.setCursor(j, 0);
        lcd.print(MSG0[i]);
        lcd.setCursor(j+1, 0);
        lcd.print(' ');
      
        delay(100);
      }
    }
    delay(200);
  }
  delay(1000);
}

void loop() 
{
  scroll(0);
  fly_in();
}
