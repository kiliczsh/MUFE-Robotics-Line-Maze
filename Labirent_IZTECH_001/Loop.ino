int way = 2;
void loop() {

    QTRRead();
  
    pidLineFollow(COLOR_BLACK);

    if(isT()) {
      stopMotorForward();
      delay(2000);
      detectChoosableWays();
     }
    

}

void detectChoosableWays() {
  resetAvailableLines();
  detectAvailableLine(true, false, true);
  goGivenStep(10);
  QTRRead();
  detectAvailableLine(false, true, false);
  delay(1000);
  goBackUntilLine();
  detectAvailableLine(true, false, true);
  Serial.print(availableLines[0]); Serial.print("  -  ");
  Serial.print(availableLines[1]); Serial.print("  -  ");
  Serial.print(availableLines[2]); Serial.println("  -  ");
  
}

byte decideWay(byte coordinate[]) {
  
}
