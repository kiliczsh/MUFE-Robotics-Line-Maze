int way = 2;
void loop() {
  goOneStep();
}
void goOneStep(){
  QTRRead();
  pidLineFollow();
  readEncoders();
  boolean isTi = isT();
  if(isTi || motorLeftCounter > 65 || motorRightCounter> 65 ){
     stopMotorForward();
     delay(500);
     if(isTi)
      detectChoosableWays();
  /*
    if(availableLines[0]  && !availableLines[1])
      turnLeft();
     if(availableLines[2] &&!availableLines[1])
      turnRight();
     if(availableLines[2]&& availableLines[1]&& availableLines[0]){
         stopMotorForward();
        delay(2000);
        turnRight();
     }
    */
    /*decide action from availableLines*/
    resetEncoders();
    resetAvailableLines();
  }
}
void detectChoosableWays() {
  QTRRead();
  detectAvailableLine(true, false, true);
  goGivenStep(10);
  delay(100);
  QTRRead();
  detectAvailableLine(false, true, false);

  delay(100);
  
}

byte decideWay(byte coordinate[]) {
  
}
