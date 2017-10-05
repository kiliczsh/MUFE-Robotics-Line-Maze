
#define colorBlack 0
#define colorWhite 1
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
  
//sensors pins

const byte sensorsPin[] = {A0, A1, A2, A3, A4, A5, 8, 9};
byte sensorsValue[8];

//Motor pins
const byte motorLeftDirPin = 12;
const byte motorRightDirPin = 13;
const byte motorLeftSpeedPin = 3;
const byte motorRightSpeedPin = 11;

int qrt;
//motor initial Speed
const int initialLeftSpeed = 100;
const int initialRightSpeed = 100;

//current
int motorSpeedLeft;
int motorSpeedRight;
 
  
//pid values
const float err_past = 0;
const float p_const = 10; // initial error
const float d_const = 10;
//inner qtr 
const float p_const_t1 =45; 
const float d_const_t1 = 45;
//outer qtr
const float p_const_t2 = 45;
const float d_const_t2 = 45;

int positionLast;
int blackSerialFollow = 0 ;
int serial =1;

void qtrPinsDefine() {
  for(byte i=0; i<8; i++) {
    pinMode(sensorsPin[i], INPUT_PULLUP);  
  }
}

void motorPinsDefine() {
  pinMode(motorLeftDirPin, OUTPUT);
  pinMode(motorRightDirPin, OUTPUT);
  pinMode(motorLeftSpeedPin, OUTPUT);
  pinMode(motorRightSpeedPin, OUTPUT);
}




void setup() {
  Serial.begin(9600);
  motorPinsDefine();
  
  
}
