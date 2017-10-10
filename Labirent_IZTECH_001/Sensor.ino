int positionSensor(int color){
  if(color == colorWhite){
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


void LinesDetect(){
  Lines[0] = 0 ;
  Lines[1] = 0 ;
  Lines[2] = 0 ;
  if(sensorsValue[0])
    Lines[0] = 1;
  if(sensorsValue[7])
    Lines[2] = 1; 


    
}
void QTRRead(){
 
  for(byte i=0; i<8; i++) {
    sensorsValue[i] = digitalRead(sensorsPin[i]);
  }
  LinesDetect();
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

void resetEncoders() {
  motorLeftEncoder.write(0);
  motorRightEncoder.write(0);
    
}

void readEncoders() {
  motorLeftCounter = motorLeftEncoder.read();
  motorRightCounter = motorRightEncoder.read();
}

