#include <Servo.h>
#include <LiquidCrystal.h>
#include "LCD_API.h"

#define PIEZO_PIN 13

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

void moveUno();
void moveDeux();
void moveTrois();
void babySteps();
void excited();
void crazy();
void song(int dur[], int song[], int songSize);

/**
   Initializes the robots servos to base angles
*/

LiquidCrystal lcd = initLCD();

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

unsigned long start;
int currentTone;

/**
   Loops to execute the dance moves called inside the function
*/
void loop() {


  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(slideID, 4);
  noTone(PIEZO_PIN);
  delay(500);

  start = (unsigned long) millis(); //not playing song rn, on purpose
  currentTone = 0;
  danceSelect(excitedID, 16);
  noTone(PIEZO_PIN);
  delay(500);

  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(waggleID, 10);
  noTone(PIEZO_PIN);
  delay(500);

  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(kickID, 2);
  noTone(PIEZO_PIN);
  delay(500);

  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(babyStepsID, 2);
  delay(500);
  noTone(PIEZO_PIN);

  start = (unsigned long) millis();
  currentTone = 0;
  danceSelect(crazyID, 6);
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
  displayWaggle_L(lcd);
  loopUno(0, 10, 0.5, 20, RF_BASE, 180 - LF_BASE, RLEG_FWD, LLEG_FWD, 2, -3);
  displayWaggle_R(lcd);
  loopUno(0, 10, 0.5, 20, RF_BASE, LF_BASE, RLEG_FWD, LLEG_FWD, -2, 3);
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
