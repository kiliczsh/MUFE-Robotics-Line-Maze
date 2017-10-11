int way = 2;
void loop() {
/*
    QTRRead();
  
    pidLineFollow(COLOR_BLACK);

    if(isT()) {
      stopMotor();
      delay(2000);
      detectChoosableWays();
     }
    
*/
goBackUntilLine();
delay(10000);
}

void detectChoosableWays() {
  resetAvailableLines();
  detectAvailableLine(true, false, true);
  go10Step();
  detectAvailableLine(false, true, false);
  goBackUntilLine();
  detectAvailableLine(true, false, true);
  
}

byte decideWay(byte coordinate[]) {
  
}
