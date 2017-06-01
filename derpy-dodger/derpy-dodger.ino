/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button = 6;
int counter = 0;
char Str1[41] = ("====_==_=====^=====^===_===^====^=====^^^==_");
char Str0[41] = ("<  <  <       <  <  < < <  <   < <   <  <   ");

void setup() {
  pinMode (6, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print(Str1[21]);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  for (int x = 0; x<20; x++){
    lcd.setCursor(x,3);
    lcd.print(Str1[x+counter%20]);
    lcd.setCursor(x, 1);
    lcd.print(Str0[x+counter%20]);
   
  }
  if (digitalRead(button) == HIGH)
  {
    lcd.setCursor(2, 1);
    lcd.print(" ");
    lcd.setCursor(2, 2);
    lcd.print((char)62);
    lcd.setCursor(3, 2);
    lcd.print((char)126);
 }
  else
  {
    lcd.setCursor(2, 2);
    lcd.print(" ");
    lcd.setCursor(2, 1);
    lcd.print((char)252);
  }
  counter = counter +1;
  delay(1000 - 2 * counter);
}
