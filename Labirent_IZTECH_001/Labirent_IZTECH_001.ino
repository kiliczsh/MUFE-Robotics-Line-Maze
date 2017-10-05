#include <AFMotor.h>


#define colorBlack 0
#define colorWhite 1

//sensors pins
const byte sensorsPin[] = {A0, A1, A2, A3, A4, A5, 2, 13};
byte sensorsValue[8];

//Motor pins
AF_DCMotor motorLeft(1); 
AF_DCMotor motorRight(4); 
int qrt;
//motor initial Speed
const int initialLeftSpeed = 100;
const int initialRightSpeed = 100;

//current
int motorSpeedLeft;
int motorSpeedRight;
 
  
//pid values
 float err_past = 0;
 float p_const = 10; // initial error
 float d_const = 10;
//inner qtr 
 float p_const_t1 =45; 
 float d_const_t1 = 45;
//outer qtr
 float p_const_t2 = 45;
 float d_const_t2 = 45;

int positionLast;
int blackSerialFollow = 0 ;
int serial =1;

void qtrPinsDefine() {
  for(byte i=0; i<8; i++) {
    pinMode(sensorsPin[i], INPUT_PULLUP);  
  }
}



void setup() {
 // Serial.begin(9600);
  qtrPinsDefine();
  motorLeft.setSpeed(0);
  motorLeft.run(RELEASE);
  motorRight.setSpeed(0);
  motorRight.run(RELEASE);

  
}
