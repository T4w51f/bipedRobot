#include <Servo.h>
#include <LiquidCrystal.h>

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

//Header file function definitions from when the code was modular
void initKarate(LiquidCrystal &);
void initExcited(LiquidCrystal &);
void initFlip_L(LiquidCrystal &);
void initFlip_R(LiquidCrystal &);
void initLookLeft(LiquidCrystal &);
void initLookRight(LiquidCrystal &);
void initWaggle_L(LiquidCrystal &);
void initWaggle_R(LiquidCrystal &);
void initSunglasses(LiquidCrystal &);

/**
 * More Header function defintions from when the code was modular
 */

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
//Defines the pins needed on the metro mini for the lcd
#define RS 11
#define EN 10
#define D4_PIN 6
#define D5_PIN 7
#define D6 8
#define D7 9
//Initializes the number of lcd panels on the lcd
#define ROWS 2
#define COLS 16
/** Initializes the LCD
 */
LiquidCrystal initLCD() {
  LiquidCrystal lcd(RS, EN, D4_PIN, D5_PIN, D6, D7);
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

//Defines the pin for the buzzer
#define PIEZO_PIN 13
//Defines note names to frequencies in Hz for the buzzer
#define  c      261
#define  cSharp 277
#define  d      294
#define  e      329
#define  f      349
#define  fSharp 370
#define  g      392
#define  gSharp 830
#define  a      440
#define  aSharp 466
#define  b      493
#define  C      523
#define FSharp4 370
#define FSharp5 740
#define C4 261
#define C5 523
#define F4 349
#define A4 440
#define D4 293
#define D5 587
#define G5 783
#define G4 392
#define E4 329
#define E5 659
#define B3 246
#define B4 493
#define B5 987
#define F4 349
#define CSharp5 554
#define CSharp4 277
#define ASharp4 466
#define ASharp5 932
#define DSharp4 311
#define DSharp5 622
#define GSharp4 415
#define GSharp5 830

#define BEAT 1

//Servo motor definitions
Servo leftLeg;
Servo rightLeg;
Servo rightFoot;
Servo leftFoot;

//Servo motor digital IO pin numbers
int leftFootPin = 2;
int leftLegPin = 4;
int rightFootPin = 1;
int rightLegPin = 3;

//Servo motor arm reference positions
int RF_BASE = 100;
int LF_BASE = 90;
int LEG_SIDES = 30;
int LLEG_FWD = 125;
int RLEG_FWD = 60;

//Move set
int waggleID = 1;
int slideID = 2;
int kickID = 3;
int babyStepsID = 4;
int excitedID = 5;
int crazyID = 6;


//SONGS
int jinglen[] = {  C,  b,  g,  C,  b,   e,  e,  C,  c,  g, a, C };  //contains notes of the sampe song
int jingled[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 }; //contains duration of eac note in the sample song
int jingleSize = 12;
int despaciton[]  = {d, cSharp, b, fSharp, fSharp, fSharp, fSharp, fSharp, b, b, b, b, b, a, b, g, g, g, g, g, b, b, b, b, b, cSharp, d, a, a , a, a, a, d, d, d, d, d, e, e, cSharp};
int despacitod[] = {8, 8, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2,   2, 6, 2, 2, 2, 2, 2 , 2, 2, 2, 4, 2};
int despacitoSize = 40;
int chargen[] = {c, e, g, a, g, a, c, e, g, a, g, a, c, e, g, a, g, a, c, e, g, a, g, a}; //aSharp, f, g, a, , a, fSharp, gSharp, aSharp,
int charged[] = {4, 4, 4, 8, 4, 16, 4, 4, 4, 8, 4, 16, 4, 4, 4, 8, 4, 16, 4, 4, 4, 8, 4, 16};
int chargeSize = 24;
int anthemn[] = {G4, E4, C4, E4, G4, C5, E4, D5, C5, E4, GSharp4, G4, G4, E5, D5, C5, B4, A4, B4, C5, C5, G4, E4, C4, G4, E4, C4, E4, G4, C5, E5, D5, C5, E4, GSharp4, G4, G4, E5, D5, C5, B4, A4, B4, C5, C5, G4, E4, C4, E5, E5, E5, FSharp5, G5, G5, FSharp5, E5, D5, E5, FSharp5, FSharp5, FSharp5, E5, D5, C5, B4, A4, B4, C5, E4, GSharp4, G4, C5, C5, C5, B4, A4, A4, A4, D5, FSharp5, E5, D5, C5, C5, B4, G4, G4, C5, D5, E5, FSharp5, G5, C5, D5, E5, FSharp5, D5, C5};
int anthemd[] = {3, 1, 4, 4, 4, 8, 3, 1, 4, 4, 4, 8, 2, 2, 6, 2, 4, 8, 3, 1, 4, 4, 4, 4, 8, 3, 1, 4, 4, 4, 8, 3, 1, 4, 4, 4, 8, 2, 2, 6, 2, 4, 8, 3, 1, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 8, 2, 2, 4, 4, 4, 8, 4, 6, 2, 4, 8, 3, 1, 6, 4, 4, 8, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4, 2, 2, 6, 2, 2, 2, 8, 2, 2, 6, 2, 4, 8, 1}; //76 + 26 = 102
int anthemSize = 102;
int mii_themeDur[] = {4 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 2 * BEAT, 2 * BEAT, 14 * BEAT, 2 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 6 * BEAT, 2 * BEAT, 8 * BEAT, 4 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 2 * BEAT, 8 * BEAT, 2 * BEAT, 2 * BEAT, 8 * BEAT, 4 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 2 * BEAT, 2 * BEAT, 8 * BEAT, 6 * BEAT, 2 * BEAT, 2 * BEAT, 4 * BEAT, 4 * BEAT, 2 * BEAT, 8 * BEAT};
int mii_themenotes[] = {FSharp4, A4, CSharp5, A4, FSharp4, D4, D4, D4, FSharp4, A4, CSharp5, A4, FSharp4, E5, DSharp5, D5, GSharp4, CSharp5, FSharp4, CSharp5, GSharp4, CSharp5, G4, FSharp4, E4, E4, E4, E4, E4, E4, E4, DSharp4, D4, CSharp4, A4, CSharp5, A4, FSharp4, E4, E4, E4, E5, E5, E5, FSharp4, A4, CSharp5, A4}; //,FSharp4,E5};
int mii_themeSize = 48;
int happyBirthdayNotes[] = {C4, C4, D4, C4, F4, E4,C4, C4, D4, C4, G4, F4,C4, C4, C5, A4, F4, F4, E4, D4,ASharp4, ASharp4, A4, F4, G4, F4};
int happyBirthdayDur[] = {8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 8, 8, 4, 2, 8, 8, 4, 4, 4, 2};
int happyBirthdaySize = 26; 


//rfoot base = 80; height = 130
//lfoot base = 83; height = 133
//lleg left = 30; forward = 140
//rleg right = 30; forward = 140

//Each of the 6 dance moves
void moveUno();
void moveDeux();
void moveTrois();
void babySteps();
void excited();
void crazy();
void song(int dur[], int song[], int songSize);

//Required variables for the function song() to keep track of which tone is playing
unsigned long start;
int currentTone;

/**
   Initializes the robots servos to base angles
*/

//Sets up the global lcd used in all emojis
LiquidCrystal lcd = initLCD();

//Initializes all servos and sets them such that the robot starts upright
void setup() {
  leftFoot.attach(leftFootPin);
  leftFoot.write(LF_BASE);

  rightFoot.attach(rightFootPin);
  rightFoot.write(RF_BASE);

  leftLeg.attach(leftLegPin);
  leftLeg.write(LLEG_FWD);

  rightLeg.attach(rightLegPin);
  rightLeg.write(RLEG_FWD);

  //Serial.begin(9600);

}


/**
   Loops to execute the dance moves called inside the function
*/
void loop() {

  //Resets the song to match the next dance move
  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(slideID, 4);      //Starts the dance move "slide"
  noTone(PIEZO_PIN);
  delay(500);

  //Resets the song to match the next dance move
  start = (unsigned long) millis(); 
  currentTone = 0;
  danceSelect(excitedID, 16); //Starts the dance move "excited"
  noTone(PIEZO_PIN);
  delay(500);

  //Resets the song to match the next dance move
  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(waggleID, 10);    //Starts the dance move "waggle"
  noTone(PIEZO_PIN);
  delay(500);

  //Resets the song to match the next dance move
  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(kickID, 2);     //Starts the dance move "kick"
  noTone(PIEZO_PIN);
  delay(500);

  //Resets the song to match the next dance move
  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(babyStepsID, 2);    //Starts the dance move "babySteps"
  delay(500);
  noTone(PIEZO_PIN);

  //Resets the song to match the next dance move
  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(crazyID, 6);      //Starts the dance move "crazy"
  noTone(PIEZO_PIN);
  delay(500);
}

/**
   This function lets the user select the dance move
   and make it loop a certain number of times
*/
void danceSelect(int move, int loops) {
  if (move == 1) {
    for (int i = 0; i < loops; i++) {
      moveUno(); //play anthem
    }
  } else if (move == 2) {
    for (int i = 0; i < loops; i++) {
      moveDeux(); //play mii
    }
  } else if (move == 3) {
    for (int i = 0; i < loops; i++) {
      moveTrois();
    }
  } else if (move == 4) {
    for (int i = 0; i < loops; i++) {
      babySteps(); //play despacito
    }
  } else if (move == 5) {
    for (int i = 0; i < loops; i++) {
      excited(); //play jingle
    }
  } else {
    for (int i = 0; i < loops; i++) {
      crazy();  //play charged
    }
  }
}

/**
   This method makes the robot execute the 'waggle'
   dance move
*/
void moveUno() {
  displayWaggle_L(lcd);       //displays the "waggle" face
  loopUno(0, 10, 0.5, 20, RF_BASE, 180 - LF_BASE, RLEG_FWD, LLEG_FWD, 2, -3);       //Moves the feet to the left
  displayWaggle_R(lcd);       
  loopUno(0, 10, 0.5, 20, RF_BASE, LF_BASE, RLEG_FWD, LLEG_FWD, -2, 3);             //Moves the feet to the right
}

/**
   Helper method for the 'waggle' dance move
*/
void loopUno(double init, double fin, double increment, int pause, double rf, double lf, double rl, double ll, double mul1, double mul2) {
  for (double i = init; i < fin; i += increment) {
    song(anthemd, anthemn,  anthemSize);
    rightFoot.write(rf + mul1 * i);
    leftFoot.write(lf + mul1 * i);

    song(anthemd, anthemn, anthemSize);

    leftLeg.write(ll + mul2 * i);
    rightLeg.write(rl + mul2 * i);
    delay(pause);
  }
  song(anthemd, anthemn,  anthemSize);
  for (double i = fin; i >= init; i -= increment) {
    song(anthemd, anthemn, anthemSize);
    rightFoot.write(rf + mul1 * i);
    leftFoot.write(lf + mul1 * i);

    song(anthemd, anthemn, anthemSize);

    leftLeg.write(ll + mul2 * i);
    rightLeg.write(rl + mul2 * i);
    delay(pause);
  }
}

/**
   This method makes the robot perform the 'slide'
   dance move
*/
void moveDeux() {
  displayLook_L(lcd);
  for (int i = 0; i < 4; i++) {
    loopDeux('r');
  }
  displayLook_R(lcd);
  for (int j = 0; j < 4; j++) {
    loopDeux('l');
  }
}

/**
   Helper method for the 'slide' dance move
*/
void loopDeux(char side) {
  if (side == 'r') {
    for (double i = 0; i < 15; i += 0.5) {
      rightFoot.write(RF_BASE - 2 * i);
      delay(20);
      song(mii_themeDur, mii_themenotes,  mii_themeSize);
    }

    for (double i = 15; i >= 0; i -= 0.5) {
      rightFoot.write(RF_BASE + 2 * i);
      song(mii_themeDur, mii_themenotes, mii_themeSize);
    }
  }

  if (side == 'l') {
    for (double i = 0; i < 15; i += 0.5) {
      leftFoot.write(LF_BASE + 2 * i);
      song(mii_themeDur, mii_themenotes, mii_themeSize);
      delay(20);
    }

    for (double i = 15; i >= 0; i -= 0.5) {
      leftFoot.write(LF_BASE  - 2 * i);
      song(mii_themeDur, mii_themenotes, mii_themeSize);
    }
  }
}

/**
 * Helper function to perform the "kick" dance
 */
void moveTrois() {
  displayKarate(lcd);
  for (double i = 0; i < 35; i += 0.5) {
    song(jingled, jinglen, jingleSize);
    rightFoot.write(RF_BASE + 2 * i);
    leftFoot.write(LF_BASE - 2 * i);
    delay(20);
  }
  song(jingled, jinglen, jingleSize);

  for (int j = 0; j < 10; j++) {
    song(jingled, jinglen, jingleSize);
    delay(50);
  }


  rightFoot.write(RF_BASE - 50);

  for (int j = 0; j < 16; j++) {
    song(jingled, jinglen,  jingleSize);
    delay(50);
  }

  leftFoot.write(LF_BASE);
  leftLeg.write(LLEG_FWD - 30);
  for (int j = 0; j < 4; j++) {
    song(jingled, jinglen, jingleSize);
    delay(50);
  }
  displayKarateKick(lcd);
  leftFoot.write(LF_BASE - 70);
  leftLeg.write(LLEG_FWD);

  for (int j = 0; j < 20; j++) {
    song(jingled, jinglen, jingleSize);
    delay(50);
  }

  for (double i = 35; i >= 0; i -= 0.5) {
    song(jingled, jinglen, jingleSize);
    rightFoot.write(RF_BASE + 2 * i);
    leftFoot.write(LF_BASE - 2 * i);
    delay(20);
  }
}

/**
 * Helper function to perform the "babySteps" dance
 */
void babySteps() {
  //////////////////////////////////Left Step
  displayFlip_L(lcd);
  for (double i = 0; i < 28; i += 0.5) {
    rightFoot.write(RF_BASE - 2 * i);
    leftFoot.write(LF_BASE - 10 * i);
    song(despacitod, despaciton, despacitoSize);
    delay(12);
  }
  leftFoot.write(LF_BASE);
  delay(50);
  for (double i = 0; i < 28; i += 0.5) {
    rightLeg.write(RLEG_FWD - i);
    song(despacitod, despaciton,  despacitoSize);
    delay(10);
  }
  delay(150);
  for (double i = 28; i >= 0; i -= 0.5) {
    song(despacitod, despaciton, despacitoSize);
    rightFoot.write(RF_BASE - 1.5 * i);
    delay(15);
  }
  rightLeg.write(RLEG_FWD);
  /////////////////////////////////////////Right Step after this point
  displayFlip_R(lcd);
  for (double i = 0; i < 28; i += 0.5) {
    song(despacitod, despaciton, despacitoSize);
    leftFoot.write(LF_BASE + 2 * i);
    rightFoot.write(RF_BASE + 10 * i);
    delay(12);
  }
  rightFoot.write(RF_BASE);
  song(despacitod, despaciton, despacitoSize);

  delay(50);
  song(despacitod, despaciton,  despacitoSize);

  for (double i = 0; i < 28; i += 0.5) {
    leftLeg.write(LLEG_FWD + i);
    song(despacitod, despaciton,  despacitoSize);
    delay(10);
  }
  delay(150);
  for (double i = 28; i >= 0; i -= 0.5) {
    leftFoot.write(LF_BASE + 1.5 * i);
    song(despacitod, despaciton,  despacitoSize);
    delay(12);
  }
  leftLeg.write(LLEG_FWD);
}

/**
 * Helper function to perform the "excited" dance
 */
void excited() {
  displayExcited_UP(lcd);
  for (double i = 0; i < 30; i += 0.5) {
    leftFoot.write(LF_BASE - 1.5 * i);
    rightFoot.write(RF_BASE + 1.5 * i);
    song(happyBirthdayDur, happyBirthdayNotes,happyBirthdaySize);
    delay(4);
  }
  displayExcited_DN(lcd);
  for (double i = 30; i >= 0; i -= 0.5) {
    leftFoot.write(LF_BASE - 1.5 * i);
    rightFoot.write(RF_BASE + 1.5 * i);
    song(happyBirthdayDur, happyBirthdayNotes,happyBirthdaySize);
    delay(4);
  }
}

/**
 * Helper function to perform the "crazy" dance
 */
void crazy() { //play charged
  displaySunglasses(lcd);

  for (double i = 0; i < 15; i += 0.5) {
    song(charged, chargen,  chargeSize);
    rightFoot.write(RF_BASE + i * 2);
    leftFoot.write(LF_BASE -  i * 2);

    leftLeg.write(LLEG_FWD + i);
    rightLeg.write(RLEG_FWD - i);
    delay(10);
  }
  for (double i = 15; i >= 0; i -= 0.5) {
    song(charged, chargen,  chargeSize);
    rightFoot.write(RF_BASE  + i * 2);
    leftFoot.write(LF_BASE - i * 2);

    leftLeg.write(LLEG_FWD + i);
    rightLeg.write(RLEG_FWD -  i);
    delay(10);
  }
  for (double i = 0; i < 15; i += 0.5) {
    song(charged, chargen,  chargeSize);
    rightFoot.write(RF_BASE - i * 2);
    leftFoot.write(LF_BASE +  i * 2);

    leftLeg.write(LLEG_FWD - 3 * i);
    rightLeg.write(RLEG_FWD + 3 * i);
    delay(10);
  }
  for (double i = 15; i >= 0; i -= 0.5) {
    song(charged, chargen, chargeSize);
    rightFoot.write(RF_BASE  - i * 2);
    leftFoot.write(LF_BASE + i * 2);

    leftLeg.write(LLEG_FWD - 3 * i);
    rightLeg.write(RLEG_FWD +  3 * i);
    delay(10);
  }

}

/**
 * Checks of we need to update the current tone or not and does so accordingly
 */
void song(int dur[], int song[], int songSize) {
  unsigned long currentToneDuration = dur[currentTone];
  //Serial.print(currentTone);
  
  if ((unsigned long)millis() - start > currentToneDuration*100) {
    start += currentToneDuration*100;
    currentTone++;
    //if (currentTone >= songSize) {
      //noTone(PIEZO_PIN);
    //} else {
      tone(PIEZO_PIN, song[currentTone]);
    //}
  }
}
