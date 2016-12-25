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
  // Scroll message left and right
  
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
  // Wintery scene with randomized snow characters on screen
  char SNOW[] = {' ', '*', 0xEB, 0xDF, 0xA1};
  
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
  // Fly in text effect with bottom row decorative design
  char MSG0[] = " -To Mom & Dad- ";
  int MSGLEN = sizeof(MSG0);

  byte BELL[8] = {
    B00000,
    B00100,
    B01010,
    B01010,
    B01010,
    B11111,
    B00100,
  };

  byte RIBBON[8] = {
    B00000,
    B00000,
    B10001,
    B01110,
    B10001,
    B01110,
    B00000,
  };

  // Definitely not a currency sign!
  byte FLOWER[8] = {
    B00000,
    B10001,
    B01110,
    B01010,
    B01110,
    B10001,
    B00000,
  };

  byte WREATH[8] = {
    B10001,
    B01110,
    B11011,
    B10101,
    B11011,
    B01110,
    B10001,
  };

  lcd.createChar(0, BELL);
  lcd.createChar(1, RIBBON);
  lcd.createChar(2, FLOWER);
  lcd.createChar(3, WREATH);

  char PATTERN[17] = {1, 0, 1, 2, 1, 0, 1, 3, 1, 0, 1, 2, 1, 0, 1, 3};
  
  lcd.clear();

  for (int i = 0; i < MSGLEN; i++)
  {
    if (MSG0[i] != ' ')
    {
      for (int j = 15; j >= i; j--)
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
  delay(500);

  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i, 1);
    lcd.write(byte(PATTERN[i]));
    delay(50);
  }
  delay(5000);
}

void blink(int loops)
{
  // Blinking text
  lcd.clear();
  for (int i = 0; i < loops; i++)
  {
      lcd.setCursor(0, 0);
      lcd.print("  And a Happy");
      lcd.setCursor(0, 1);
      lcd.print("    New Year!");
      delay(1000);

      lcd.noDisplay();
      delay(1000);
      lcd.display();
  }
}

void loop() 
{
  scroll(2);
  fly_in();
  //blink(5);
}
