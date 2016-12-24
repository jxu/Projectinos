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

char MSG0[] = "   * Merry *   ";
char MSG1[] = " * Christmas! *";
byte MSGLEN = sizeof(MSG1);

void setup()
{
  lcd.begin(16, 2);
  lcd.print(MSG0);
  lcd.setCursor(0, 1);
  lcd.print(MSG1);
  delay(1000);
}

void loop() 
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

  // scroll (display length + string length) to the left
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }

  delay(1000);
}
