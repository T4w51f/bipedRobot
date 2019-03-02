#include <LiquidCrystal.h>
#include "custom_chars.h"

//The following are all custom characters for the LCD faces
//in byte form.
byte karate_0[] = {
  B01100,
  B00110,
  B11111,
  B11111,
  B00000,
  B01000,
  B00100,
  B00010
};
byte karate_1[] = {
  B00110,
  B01100,
  B11111,
  B11111,
  B00000,
  B00010,
  B00100,
  B01000
};
byte karate_2[] = {
  B00100,
  B01000,
  B00000,
  B00000,
  B01111,
  B00000,
  B00000,
  B00000
};
byte karate_3[] = {
  B00100,
  B00010,
  B00000,
  B00000,
  B11110,
  B00000,
  B00000,
  B00000
};

byte karateKick_2[] = {
  B00100,
  B01000,
  B00000,
  B00001,
  B00010,
  B00010,
  B00001,
  B00000
};

byte karateKick_3[] = {
  B00100,
  B00010,
  B00000,
  B10000,
  B01000,
  B01000,
  B10000,
  B00000
};
byte star[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B11011,
  B10001,
  B00000
};
byte excited_01[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000
};
byte excited_2[] = {
  B00000,
  B00000,
  B01111,
  B01000,
  B00100,
  B00011,
  B00000,
  B00000
};
byte excited_3[] = {
  B00000,
  B00000,
  B11110,
  B00010,
  B00100,
  B11000,
  B00000,
  B00000
};
byte backslash[] = {
  B00000,
  B10000,
  B01000,
  B00100,
  B00010,
  B00001,
  B00000,
  B00000
};
byte flipFace_0[] = {
  B00000,
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00011
};
byte flipFace_1[] = {
  B00000,
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B11000
};
byte flipFace_2[] = {
  B00010,
  B00010,
  B00011,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte flipFace_3[] = {
  B01000,
  B01000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte flipArm[] = {
  B00000,
  B00010,
  B00010,
  B00100,
  B01000,
  B10000,
  B00000,
  B00000
};
byte flipArm_1[] = {
  B00000,
  B01000,
  B01000,
  B00100,
  B00010,
  B00001,
  B00000,
  B00000
};
byte table_0[] = {
  B00000,
  B00110,
  B00110,
  B00110,
  B00110,
  B11111,
  B11111,
  B00000
};
byte table_1[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000
};
byte table_2[] = {
  B00000,
  B01100,
  B01100,
  B01100,
  B01100,
  B11111,
  B11111,
  B00000
};
byte lookRight1[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10111,
  B10111,
  B01110,
  B00000
};
byte lookRight2[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10111,
  B10111,
  B01110,
  B00000
};
byte lookRight3[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B00000,
  B00000,
  B00000
};
byte lookRight4[] = {
  B00000,
  B00000,
  B00000,
  B00010,
  B11100,
  B00000,
  B00000,
  B00000
};
byte lookLeft1[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B11101,
  B11101,
  B01110,
  B00000
};
byte lookLeft2[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B11101,
  B11101,
  B01110,
  B00000
};
byte lookLeft3[] = {
  B00000,
  B00000,
  B00000,
  B01000,
  B00111,
  B00000,
  B00000,
  B00000
};
byte lookLeft4[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11100,
  B00000,
  B00000,
  B00000
};
//Waggle
byte firstArms1[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000
};
byte firstArms2[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B01010,
  B00100
};
byte leftEye[] = {
  B00000,
  B00000,
  B00000,
  B00110,
  B00110,
  B00000,
  B00000,
  B00011
};
byte rightEye[] = {
  B00000,
  B00000,
  B00000,
  B01100,
  B01100,
  B00000,
  B00000,
  B11000
};
byte leftLip[] = {
  B00010,
  B00011,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte rightLip[] = {
  B01000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte sunglasses_0[] = {
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};

byte sunglasses_1[] = {
  B00000,
  B00000,
  B00000,
  B01111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte sunglasses_2[] = {
  B00000,
  B00000,
  B00010,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000
};
byte sunglasses_3[] = {
  B00000,
  B00000,
  B11111,
  B10000,
  B10000,
  B00000,
  B00000,
  B00000
};

//Initializes the 7 characters needed during the kick dance move
void initKarate(LiquidCrystal &lcd) {
  lcd.createChar(KARATE_0, karate_0);
  lcd.createChar(KARATE_1, karate_1);
  lcd.createChar(KARATE_2, karate_2);
  lcd.createChar(KARATE_3, karate_3);
  lcd.createChar(KARATE_K_2, karateKick_2);
  lcd.createChar(KARATE_K_3, karateKick_3);
  lcd.createChar(STAR, star);
}

//Initializes the 4 characters needed during the excited dance move
void initExcited(LiquidCrystal &lcd) {
  lcd.createChar(EXCITED_01, excited_01);
  lcd.createChar(EXCITED_2, excited_2);
  lcd.createChar(EXCITED_3, excited_3);
  lcd.createChar(BACKSLASH, backslash);  
}

//Initializes the 8 characters needed during one half of the crazy dance move.
//The LCD depicts a character flipping a table to the left.
void initFlip_L(LiquidCrystal &lcd) {
  lcd.createChar(FLIP_FACE_0, flipFace_0);
  lcd.createChar(FLIP_FACE_1, flipFace_1);
  lcd.createChar(FLIP_FACE_2, flipFace_2);
  lcd.createChar(FLIP_FACE_3, flipFace_3);
  lcd.createChar(FLIP_ARM, flipArm);
  lcd.createChar(TABLE_0, table_0);
  lcd.createChar(TABLE_1, table_1);
  lcd.createChar(TABLE_2, table_2);
}

//Initializes the 8 characters needed during one half of the crazy dance move.
//The LCD depicts a character flipping a table to the right.
void initFlip_R(LiquidCrystal &lcd) {
  lcd.createChar(FLIP_FACE_0, flipFace_0);
  lcd.createChar(FLIP_FACE_1, flipFace_1);
  lcd.createChar(FLIP_FACE_2, flipFace_2);
  lcd.createChar(FLIP_FACE_3, flipFace_3);
  lcd.createChar(FLIP_ARM_1, flipArm_1);
  lcd.createChar(TABLE_0, table_0);
  lcd.createChar(TABLE_1, table_1);
  lcd.createChar(TABLE_2, table_2);
}

//For the sliding dance move, the next two functions initialize the characters
// that look left and right
void initLookLeft(LiquidCrystal &lcd) {
  lcd.createChar(LOOK_LEFT_0, lookLeft1);
  lcd.createChar(LOOK_LEFT_1, lookLeft2);
  lcd.createChar(LOOK_LEFT_2, lookLeft3);
  lcd.createChar(LOOK_LEFT_3, lookLeft4);
}
void initLookRight(LiquidCrystal &lcd) {
  lcd.createChar(LOOK_RIGHT_0, lookRight1);
  lcd.createChar(LOOK_RIGHT_1, lookRight2);
  lcd.createChar(LOOK_RIGHT_2, lookRight3);
  lcd.createChar(LOOK_RIGHT_3, lookRight4);  
}

//Creates characters required for an emoji with wavy
// arms (for both left and right sides).
void initWaggle_L(LiquidCrystal &lcd) {
  lcd.createChar(FIRST_ARM_1, firstArms1);
  lcd.createChar(FIRST_ARM_2, firstArms2);
  lcd.createChar(LEFT_EYE, leftEye);
  lcd.createChar(RIGHT_EYE, rightEye);   
  lcd.createChar(LEFT_LIP, leftLip);
  lcd.createChar(RIGHT_LIP, rightLip);   
}
void initWaggle_R(LiquidCrystal &lcd) {
  lcd.createChar(FIRST_ARM_1, firstArms1);
  lcd.createChar(FIRST_ARM_2, firstArms2);
  lcd.createChar(LEFT_EYE, leftEye);
  lcd.createChar(RIGHT_EYE, rightEye);   
  lcd.createChar(LEFT_LIP, leftLip);
  lcd.createChar(RIGHT_LIP, rightLip);  
}

//Creates the characters for an emoji with sunglasses
void initSunglasses(LiquidCrystal &lcd) {
  lcd.createChar(SUNGLASSES_0, sunglasses_0);
  lcd.createChar(SUNGLASSES_1, sunglasses_1);
  lcd.createChar(SUNGLASSES_2, sunglasses_2);
  lcd.createChar(SUNGLASSES_3, sunglasses_3);

}
