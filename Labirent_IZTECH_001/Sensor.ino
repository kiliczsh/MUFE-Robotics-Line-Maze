int positionSensor(int color){
  if(color == COLOR_WHITE){
    if(!sensorsValue[3] && !sensorsValue[4] ) 
      return 0;
    if(!sensorsValue[0] || !sensorsValue[1])
      return 3;
    else if(!sensorsValue[6] || !sensorsValue[7])
      return -3;
    else if(!sensorsValue[2] || !sensorsValue[3])
      return 2;
    else if(!sensorsValue[4] || !sensorsValue[5])
      return -2;
    else 
      return positionLast ;

  }else {
    if(sensorsValue[3] && sensorsValue[4] ) 
      return 0;
    if(sensorsValue[0] || sensorsValue[1])
      return 3;
    else if(sensorsValue[6] || sensorsValue[7])
      return -3;
    else if(sensorsValue[2] || sensorsValue[3])
      return 2;
    else if(sensorsValue[4] || sensorsValue[5])
      return -2;
    else 
      return positionLast ;
  }
    
}




void resetAvailableLines() {
  for(int i=0; i<3; i++) {
    availableLines[i] = 0;  
  }  
}

void detectAvailableLine(boolean left, boolean up, boolean right) {
    if(left) {
      if(sensorsValue[7] || sensorsValue[6])
        availableLines[0] = 1;
    }
    if(up) {
      if(sensorsValue[3] || sensorsValue[4])
        availableLines[1] = 1;
    }
    if(right) {
      if(sensorsValue[0] || sensorsValue[1])
        availableLines[2] = 1;
    }
}

void QTRRead(){
 
  for(byte i=0; i<8; i++) {
    sensorsValue[i] = digitalRead(sensorsPin[i]);
  }
}



void QTRTest(){
  QTRRead();
  for(int i = 0 ; i < 8 ; i++){
    Serial.print(sensorsValue[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  delay(200);
}

boolean isT() {
  if(sensorsValue[0] == 1 || sensorsValue[7] == 1)
    return true;
   else 
    return false;  
}

void encoderTest() {
  motorLeftCounter = motorLeftEncoder.read();
  motorRightCounter = motorRightEncoder.read();
  Serial.print(motorLeftCounter); Serial.print("  -  "); Serial.println(motorRightCounter);
  
}

boolean isRoundFinish() {
  return false;
}

void resetEncoders() {
  motorLeftEncoder.write(0);
  motorRightEncoder.write(0);
}

void readEncoders() {
  motorLeftCounter = motorLeftEncoder.read();
  motorRightCounter = motorRightEncoder.read();
}

