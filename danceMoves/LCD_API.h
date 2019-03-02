/** Header file to define all LCD_API functions
 *
 */

#include <LiquidCrystal.h>
#include <String.h>

#ifndef LCD_H
#define LCD_H

/** Initializes the LCD
 */
LiquidCrystal initLCD();
/** Prints a string to the lcd
 */
void displayString(LiquidCrystal &, String);
/** Displays the karate emoji
 */
void displayKarate(LiquidCrystal &);
/** Displays the karate kick emoji
 */
void displayKarateKick(LiquidCrystal &);
/** Clears the lcd
 */
void clearLCD(LiquidCrystal &);
/** Displays the "up" version of the excited emoji
 */
void displayExcited_UP(LiquidCrystal &);
/** Displays the "down" version of the excited emoji
 */
void displayExcited_DN(LiquidCrystal &);
/** Displays the "left" verision of the flip emoji
 */
void displayFlip_L(LiquidCrystal &);
/** Displays the "right" version of the flip emoji
 */
void displayFlip_R(LiquidCrystal &);
/** Displays the table emoji
 */
void displayTable(LiquidCrystal &);
/** Displays the "left" version of the look emoji
 */
void displayLook_L(LiquidCrystal &);
/** Displays the "right" version of the look emoji
 */
void displayLook_R(LiquidCrystal &);
/** Displays the "left" version of the waggle emoji
 */
void displayWaggle_L(LiquidCrystal &);
/** Displays the "right" version of the waggle emoji
 */
void displayWaggle_R(LiquidCrystal &);
/** Displays the sunglasses emoji
 */
void displaySunglasses(LiquidCrystal &);

#endif
