#include <LiquidCrystal.h>
#include <String.h>
#include "custom_chars.h"

#define RS 11
#define EN 10
#define D4 6
#define D5 7
#define D6 8
#define D7 9

#define ROWS 2
#define COLS 16
/** Initializes the LCD
 */
LiquidCrystal initLCD() {
  LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
  lcd.begin(COLS,ROWS);
  return lcd;
}
/** Prints a string to the lcd
 */
void displayString(LiquidCrystal &lcd, String str) {
  lcd.print(str);
}
/** Displays the karate emoji
 */
void displayKarate(LiquidCrystal &lcd) {
  initKarate(lcd);
  
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.write(byte(KARATE_0));
  lcd.setCursor(8,0);
  lcd.write(byte(KARATE_1));
  lcd.setCursor(7,1);
  lcd.write(byte(KARATE_2));
  lcd.setCursor(8,1);
  lcd.write(byte(KARATE_3));
}
/** Displays the karate kick emoji
 */
void displayKarateKick(LiquidCrystal &lcd) {
  initKarate(lcd);
  
  lcd.clear();
  
  lcd.setCursor(1, 1);
  lcd.print("POW!");
  
  lcd.setCursor(7, 0);
  lcd.write(byte(KARATE_0));
  lcd.setCursor(8,0);
  lcd.write(byte(KARATE_1));
  lcd.setCursor(7,1);
  lcd.write(byte(KARATE_K_2));
  lcd.setCursor(8,1);
  lcd.write(byte(KARATE_K_3));

  lcd.setCursor(10, 0);
  lcd.print("KACHOW");
}
/** Displays the "up" version of the excited emoji
 */
void displayExcited_UP(LiquidCrystal &lcd) {
  initExcited(lcd);
  lcd.clear();

  lcd.setCursor(4, 0);
  lcd.write(byte(BACKSLASH));
  
  lcd.setCursor(7, 0);
  lcd.write(byte(EXCITED_01));
  lcd.write(byte(EXCITED_01));

  lcd.setCursor(11, 0);
  lcd.print("/");

  lcd.setCursor(7,1);
  lcd.write(byte(EXCITED_2));
  lcd.write(byte(EXCITED_3));  
}
/** Displays the "down" version of the excited emoji
 */
void displayExcited_DN(LiquidCrystal &lcd) {
  initExcited(lcd);
  lcd.clear();

  lcd.setCursor(4, 1);
  lcd.print("/");
  
  lcd.setCursor(7, 0);
  lcd.write(byte(EXCITED_01));
  lcd.write(byte(EXCITED_01));

  lcd.setCursor(11, 1);
  lcd.write(byte(BACKSLASH));

  lcd.setCursor(7,1);
  lcd.write(byte(EXCITED_2));
  lcd.write(byte(EXCITED_3));  
}
/** Displays the "left" verision of the flip emoji
 */
void displayFlip_L(LiquidCrystal &lcd) {
  lcd.clear();
  initFlip_L(lcd);

  lcd.setCursor(4,0);
  lcd.write(byte(FLIP_ARM));
  lcd.write(byte(FLIP_FACE_0));
  lcd.write(byte(FLIP_FACE_1));
  lcd.write(byte(FLIP_ARM));
  lcd.setCursor(5,1);
  lcd.write(byte(FLIP_FACE_2));
  lcd.write(byte(FLIP_FACE_3));

  lcd.setCursor(10,0);
  lcd.write(byte(TABLE_0));
  lcd.write(byte(TABLE_1));
  lcd.write(byte(TABLE_1));
  lcd.write(byte(TABLE_2));
}
/** Displays the "right" version of the flip emoji
 */
void displayFlip_R(LiquidCrystal &lcd) {
  lcd.clear();
  initFlip_R(lcd);

  lcd.setCursor(8,0);
  lcd.write(byte(FLIP_ARM_1));
  lcd.write(byte(FLIP_FACE_0));
  lcd.write(byte(FLIP_FACE_1));
  lcd.write(byte(FLIP_ARM_1));
  lcd.setCursor(9,1);
  lcd.write(byte(FLIP_FACE_2));
  lcd.write(byte(FLIP_FACE_3));

  lcd.setCursor(1,0);
  lcd.write(byte(TABLE_0));
  lcd.write(byte(TABLE_1));
  lcd.write(byte(TABLE_1));
  lcd.write(byte(TABLE_2));
}
/** Displays the "left" version of the look emoji
 */
void displayLook_L(LiquidCrystal &lcd) {
  lcd.clear();
  initLookLeft(lcd);

  lcd.setCursor(7,0);
  lcd.write(byte(LOOK_LEFT_0));
  lcd.write(byte(LOOK_LEFT_1));
  lcd.setCursor(7,1);
  lcd.write(byte(LOOK_LEFT_2));
  lcd.write(byte(LOOK_LEFT_3));  
}
/** Displays the "right" version of the look emoji
 */
void displayLook_R(LiquidCrystal &lcd) {
  lcd.clear();
  initLookRight(lcd);

  lcd.setCursor(7,0);
  lcd.write(byte(LOOK_RIGHT_0));
  lcd.write(byte(LOOK_RIGHT_1));
  lcd.setCursor(7,1);
  lcd.write(byte(LOOK_RIGHT_2));
  lcd.write(byte(LOOK_RIGHT_3));  
}
/** Displays the "left" version of the waggle emoji
 */
void displayWaggle_L(LiquidCrystal &lcd) {
  lcd.clear();
  initWaggle_L(lcd);

  lcd.setCursor(5,0);
  lcd.write(byte(FIRST_ARM_1));
  lcd.write(byte(FIRST_ARM_2));
  lcd.write(byte(LEFT_EYE));
  lcd.write(byte(RIGHT_EYE));
  lcd.write(byte(FIRST_ARM_1));
  lcd.write(byte(FIRST_ARM_2));
  lcd.setCursor(7,1);
  lcd.write(byte(LEFT_LIP));
  lcd.write(byte(RIGHT_LIP));
}
/** Displays the "right" version of the waggle emoji
 */
void displayWaggle_R(LiquidCrystal &lcd) {
  lcd.clear();
  initWaggle_R(lcd);

  lcd.setCursor(5,0);
  lcd.write(byte(FIRST_ARM_2));
  lcd.write(byte(FIRST_ARM_1));
  lcd.write(byte(LEFT_EYE));
  lcd.write(byte(RIGHT_EYE));
  lcd.write(byte(FIRST_ARM_2));
  lcd.write(byte(FIRST_ARM_1));
  lcd.setCursor(7,1);
  lcd.write(byte(LEFT_LIP));
  lcd.write(byte(RIGHT_LIP));
}
/** Displays the sunglasses emoji
 */
void displaySunglasses(LiquidCrystal &lcd) {
  lcd.clear();
  initSunglasses(lcd);

  lcd.setCursor(6,0);
  lcd.write(byte(SUNGLASSES_3));
  lcd.write(byte(SUNGLASSES_0));
  lcd.write(byte(SUNGLASSES_0));
  lcd.setCursor(7,1);
  lcd.write(byte(SUNGLASSES_1));
  lcd.write(byte(SUNGLASSES_2));
}
/** Clears the lcd
 */
void clearLCD(LiquidCrystal &lcd) {
  lcd.clear();
}
