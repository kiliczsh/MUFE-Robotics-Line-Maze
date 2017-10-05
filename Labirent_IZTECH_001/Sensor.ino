
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

int isT(int color){
  if(color == 1){
     if((!sensorsValue[6] && !sensorsValue[7] ) || (!sensorsValue[0] && !sensorsValue[1] )) 
      return 1 ;
     else 
      return 0;       
  }else return 0;

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

