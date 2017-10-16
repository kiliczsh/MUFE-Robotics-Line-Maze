int way = 2;
void loop() {

    QTRRead();
  
    pidLineFollow(COLOR_BLACK);

    if(isT()) {
      stopMotorForward();
      delay(2000);
      detectChoosableWays();
     }
    
    // QTRTest();

}

void detectChoosableWays() {
  QTRRead();
  detectAvailableLine(true, false, true);
  goGivenStep(10);
  QTRRead();
  detectAvailableLine(false, true, false);
  delay(1000);
  Serial.print(availableLines[0]); Serial.print("  -  ");
  Serial.print(availableLines[1]); Serial.print("  -  ");
  Serial.print(availableLines[2]); Serial.println("  -  ");
  if(availableLines[0] &&availableLines[1])
    turnLeft();
  else if(availableLines[2] && availableLines[1] )
    turnRight();
  else
    turnLeft();
   resetAvailableLines();
  
}

byte decideWay(byte coordinate[]) {
  
}
