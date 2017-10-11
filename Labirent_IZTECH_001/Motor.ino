
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
     stopMotor();
 

  
}
void turnRight(){
    moveForwardLittle(100);
  
 
    while(!digitalRead(A1)){
       motorLeft.setSpeed(100);
       motorLeft.run(FORWARD);
       motorRight.setSpeed(100);
       motorRight.run(BACKWARD);
 

    }
     stopMotor();


}
void motoMove(int leftSpeed, int rightSpeed) {
    motorLeft.setSpeed(leftSpeed);
   motorRight.setSpeed(rightSpeed);
  motorSpeedLeft = leftSpeed ;
  motorSpeedRight = rightSpeed;

  if(motorSpeedLeft<LIMIT_OF_SPEED && motorSpeedLeft>0){
      motorLeft.run(BACKWARD);
    
  }else if(motorSpeedLeft>LIMIT_OF_SPEED){
    //ileri
   motorLeft.run(FORWARD);

  }else{
    //stop
    motorLeft.run(RELEASE);
  }

  if(motorSpeedRight<LIMIT_OF_SPEED && motorSpeedRight>0){
 
     motorRight.run(BACKWARD);
      
      
  }else if(motorSpeedRight>LIMIT_OF_SPEED){
   
     motorRight.run(FORWARD);
  }else{
    motorRight.run(RELEASE);
  }
}

// ABS System for robot going forward
void stopMotor() {
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
  motorLeft.setSpeed(30);
  motorRight.setSpeed(30);
  delay(100);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

// Robot goes 10 step to detect the available line.
void go10Step() {
  resetEncoders();

  do {
    QTRRead();
    pidLineFollow(COLOR_BLACK);
    readEncoders();
  }while(motorLeftCounter < STEP_FOR_DETECTING_LINE);
  stopMotor();
    
}

void goTAgain() {
  
}


