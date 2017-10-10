

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
  
 
    while(!digitalReadFast(2)){
       motorLeft.setSpeed(100);
       motorLeft.run(BACKWARD);
       motorRight.setSpeed(100);
       motorRight.run(FORWARD);
    }
     stopMotor();
 

  
}
void turnRight(){
    moveForwardLittle(100);
  
 
    while(!digitalReadFast(A1)){
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

  if(motorSpeedLeft<50 && motorSpeedLeft>0){
      motorLeft.run(BACKWARD);
    
  }else if(motorSpeedLeft>50){
    //ileri
   motorLeft.run(FORWARD);

  }else{
    //stop
    motorLeft.run(RELEASE);
  }

  if(motorSpeedRight<50 && motorSpeedRight>0){
 
     motorRight.run(BACKWARD);
      
      
  }else if(motorSpeedRight>50){
   
     motorRight.run(FORWARD);
  }else{
    motorRight.run(RELEASE);
  }
}

void stopMotor() {
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
  motorLeft.setSpeed(30);
  motorRight.setSpeed(30);
  delay(100);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void go10Step() {
  resetEncoders();

  do {
    QTRRead();
    pidLineFollow(colorBlack);
    readEncoders();
  }while(motorLeftCounter < 10);
  stopMotor();
    
}

void driveArdumoto(byte motor, byte dir, byte spd)
{

}


