#include <Encoder.h>
#include <AFMotor.h>


#define COLOR_BLACK 0
#define COLOR_WHITE 1

//sensors pins
const byte sensorsPin[] = {A0, A1, A2, A3, A4, A5, 2, 13};
int sensorsValue[8];

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

//Line 
byte availableLines[3]; //Keeps the available lines at every T point


  
//pid values
 float err_past = 0;
 float p_const = 10; // initial error
 float d_const = 10;
//inner qtr 
 float p_const_t1 =45; 
 float d_const_t1 = 45;
//outer qtr
 float p_const_t2 = 22;
 float d_const_t2 = 22;

int positionLast;
int blackSerialFollow = 0 ;
int serial =1;

//encoder
// Interrupts pins are 18, 19, 20, 21 for Arduino Mega
Encoder motorLeftEncoder(18,19);
Encoder motorRightEncoder(20,21);

// Encoder Data counter
int motorLeftCounter=0;
int motorRightCounter=0;

// all qtr pins are setted as input
void qtrPinsDefine() {
  for(byte i=0; i<8; i++) {
    pinMode(sensorsPin[i], INPUT_PULLUP);  
  }
}

void motorInit() {
  motorLeft.setSpeed(0);
  motorLeft.run(RELEASE);
  motorRight.setSpeed(0);
  motorRight.run(RELEASE);
}

void setup() {
 Serial.begin(9600);
  qtrPinsDefine();
  motorInit();

}
