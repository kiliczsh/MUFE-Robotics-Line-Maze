
#define LIMIT_OF_SPEED 50
#define STEP_FOR_DETECTING_LINE 10



void setMotorSpeed(byte motor, int pwm) {

}

void moveForwardLittle(int dly){
  motorLeft.setSpeed(100);
  motorLeft.run(FORWARD);
  motorRight.setSpeed(100);
  motorRight.run(FORWARD);
  delay(dly);

}
void turnLeft(){
 
    moveForwardLittle(100);
  
 
    while(!digitalRead(2)){
       motorLeft.setSpeed(100);
       motorLeft.run(BACKWARD);
       motorRight.setSpeed(100);
       motorRight.run(FORWARD);
    }
     stopMotor(WAY_FORWARD);
 

  
}
void turnRight(){
    moveForwardLittle(100);
  
 
    while(!digitalRead(A1)){
       motorLeft.setSpeed(100);
       motorLeft.run(FORWARD);
       motorRight.setSpeed(100);
       motorRight.run(BACKWARD);
 

    }
     stopMotor(WAY_FORWARD);


}
void motoMove(int leftSpeed, int rightSpeed) {
    motorLeft.setSpeed(leftSpeed);
   motorRight.setSpeed(rightSpeed);
  motorSpeedLeft = leftSpeed ;
  motorSpeedRight = rightSpeed;

  if( motorSpeedLeft < 0){
      motorLeft.run(BACKWARD);
  }else{
    //stop
    motorLeft.run(FORWARD);
  }

  if( motorSpeedRight < 0){
      motorRight.run(BACKWARD);
  }else{
    //stop
    motorRight.run(FORWARD);
  }

  
}
// ABS System for robot going forward
void stopMotorForward() {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
  motorLeft.setSpeed(30 * currentWay);
  motorRight.setSpeed(30 * currentWay);
  delay(50);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void stopMotorBackward(int currentWay) {
  if (currentWay == WAY_BACKWARD) {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
  } else {
    motorLeft.run(BACKWARD);
    motorRight.run(BACKWARD);
  }
  motorLeft.setSpeed(30 * currentWay);
  motorRight.setSpeed(30 * currentWay);
  delay(50);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void goBackUntilLine() {
   do {
    motoMove(-30, -30);
    QTRRead();
  }while(!(sensorsValue[0] || sensorsValue[7]));
  stopMotor(WAY_BACKWARD);
}

// Robot goes 10 step to detect the available line.
void goGivenStep(int givenStep) {
  resetEncoders();

  do {
    QTRRead();
    motoMove(100, 100);
    readEncoders();
  }while(motorLeftCounter < givenStep);
  stopMotor(WAY_FORWARD);
    
}

void goTAgain() {
  
}


