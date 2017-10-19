
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

void turnBack(){
    moveForwardLittle(300);
  resetEncoders();
   while(motorRightEncoder.read()<80   || !digitalRead(2) ){
    motorLeft.setSpeed(100);
    motorLeft.run(BACKWARD);
    motorRight.setSpeed(100);
    motorRight.run(FORWARD);
  }
  stopMotorLeftTurn();
  resetEncoders();
}
void turnLeft(){
  moveForwardLittle(100);
  while(!digitalRead(2)){
    motorLeft.setSpeed(100);
    motorLeft.run(BACKWARD);
    motorRight.setSpeed(150);
    motorRight.run(FORWARD);
  }
  stopMotorLeftTurn();
  resetEncoders();

}
void turnRight(){
  moveForwardLittle(100);
 
  while(!digitalRead(A1)){
    motorRight.setSpeed(100);
    motorRight.run(BACKWARD);
    motorLeft.setSpeed(150);
    motorLeft.run(FORWARD);
    }
  stopMotorRightTurn();


}
void motoMove(int leftSpeed, int rightSpeed) {
  motorLeft.setSpeed(leftSpeed);
  motorRight.setSpeed(rightSpeed);
  motorSpeedLeft = leftSpeed ;
  motorSpeedRight = rightSpeed;
  if( motorSpeedLeft < 0){
      motorLeft.run(BACKWARD);
  }else{
    motorLeft.run(FORWARD);
  }
  if( motorSpeedRight < 0){
      motorRight.run(BACKWARD);
  }else{
    motorRight.run(FORWARD);
  }
}
void stopMotorRightTurn(){
  
  motorLeft.run(BACKWARD);
  motorRight.run(FORWARD);
  motorRight.setSpeed(30);
  motorLeft.setSpeed(30);
  delay(100);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
  
}
void stopMotorLeftTurn(){
  motorRight.run(BACKWARD);
  motorLeft.run(FORWARD);
  motorRight.setSpeed(30);
  motorLeft.setSpeed(30);
  delay(100);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}
// ABS System for robot going forward
void stopMotorForward() {
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
  motorLeft.setSpeed(30);
  motorRight.setSpeed(30);
  delay(100);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void stopMotorBackward() {
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
  motorLeft.setSpeed(30);
  motorRight.setSpeed(30);
  delay(50);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void goBackUntilLine() {
   do {
    motoMove(-30, -30);
    QTRRead();
  }while(!(sensorsValue[0] || sensorsValue[7]));
  stopMotorBackward();
}

// Robot goes 10 step to detect the available line.
void goGivenStep(int givenStep) {
  resetEncoders();

  do {
    QTRRead();
    motoMove(100, 100);
    readEncoders();
  }while(motorLeftCounter < givenStep);
  stopMotorForward();
    
}

void goTAgain() {
  
}


