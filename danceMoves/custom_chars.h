#include <LiquidCrystal.h>

#ifndef C_CHAR_H
#define C_CHAR_H


/* Every custom character must be assigned a value from 0-7.
* This is because the LCD can only store 8 custom characters at
* a time. Multiple characters can have the same value because 
* they will never be initialized at the same time.
*/
#define KARATE_0    0 
#define KARATE_1    1
#define KARATE_2    2
#define KARATE_3    3
#define KARATE_K_2  4
#define KARATE_K_3  5
#define STAR        6

#define EXCITED_01  0
#define EXCITED_2   1
#define EXCITED_3   2
#define BACKSLASH   3

#define FLIP_FACE_0 0
#define FLIP_FACE_1 1
#define FLIP_FACE_2 2
#define FLIP_FACE_3 3
#define FLIP_ARM    4
#define FLIP_ARM_1  4

#define TABLE_0     5
#define TABLE_1     6
#define TABLE_2     7

#define LOOK_LEFT_0 0
#define LOOK_LEFT_1 1
#define LOOK_LEFT_2 2
#define LOOK_LEFT_3 3


#define LOOK_RIGHT_0 0
#define LOOK_RIGHT_1 1
#define LOOK_RIGHT_2 2
#define LOOK_RIGHT_3 3

#define FIRST_ARM_1 0
#define FIRST_ARM_2 1
#define LEFT_EYE 2
#define RIGHT_EYE 3
#define LEFT_LIP 4
#define RIGHT_LIP 5

#define SUNGLASSES_0 0
#define SUNGLASSES_1 1
#define SUNGLASSES_2 2
#define SUNGLASSES_3 3



void initKarate(LiquidCrystal &);
void initExcited(LiquidCrystal &);
void initFlip_L(LiquidCrystal &);
void initFlip_R(LiquidCrystal &);
void initLookLeft(LiquidCrystal &);
void initLookRight(LiquidCrystal &);
void initWaggle_L(LiquidCrystal &);
void initWaggle_R(LiquidCrystal &);
void initSunglasses(LiquidCrystal &);
#endif
