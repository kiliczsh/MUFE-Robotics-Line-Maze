

void setMotorSpeed(byte motor, int pwm) {

}

void turnLeft() {
  
}

void turnRight() {
  
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

void driveArdumoto(byte motor, byte dir, byte spd)
{

}


