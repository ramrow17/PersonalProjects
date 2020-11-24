/* Basic Arduino example code for displaying text on 16x2, 20x4 etc. character LCDs. More info: www.makerguides.com */
// Include the library:
#include <LiquidCrystal.h>
// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
byte Heart[] = {0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00,0x00}; //This is a heart emoji



void setup() {
  // Specify the LCD's number of columns and rows. Change to (20, 4) for a 20x4 LCD:
  lcd.begin(20, 4);
  lcd.createChar(0, Heart);
  
}
void loop() {
  // Set the cursor on the third column and the first row, counting starts at 0:
  lcd.setCursor(2, 1); lcd.write(byte(0));
  // Print the string 'Hello World!':
  lcd.print("Goodnight Meli"); lcd.write(byte(0));
  // Set the cursor on the third column and the second row:
  lcd.setCursor(2, 2);
  lcd.write(byte(0));
  // Print the string 'LCD tutorial':
  lcd.print(" I can't wait ");lcd.write(byte(0));

  
  lcd.setCursor(2, 3); lcd.write(byte(0));
  lcd.print("  to see you! "); lcd.write(byte(0));
  
}
