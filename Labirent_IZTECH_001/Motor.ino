

void setMotorSpeed(byte motor, int pwm) {
  byte dirPin;
  byte pwmPin;
  byte way = HIGH;
  if(motor == MOTOR_LEFT) {
    dirPin = motorLeftDirPin;
    pwmPin = motorLeftSpeedPin;
   } else {
    dirPin = motorLeftDirPin;
    pwmPin = motorRightSpeedPin;
   }

   if(pwm < 0) {
      pwm = pwm * -1;
      way = LOW;
      Serial.println(way);
    }
    digitalWrite(dirPin, way);
    analogWrite(pwmPin, pwm);
}

void turnLeft() {
  
}

void turnRight() {
  
}


void motoMove(int leftSpeed, int rightSpeed) {
  setMotorSpeed(MOTOR_LEFT, leftSpeed);
  setMotorSpeed(MOTOR_RIGHT, rightSpeed);
  
}

void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_LEFT)
  {
    digitalWrite(motorLeftDirPin, dir);
    analogWrite(motorLeftSpeedPin, spd);
  }
  else if (motor == MOTOR_RIGHT)
  {
    digitalWrite(motorRightDirPin, dir);
    analogWrite(motorRightSpeedPin, spd);
  }  
}


