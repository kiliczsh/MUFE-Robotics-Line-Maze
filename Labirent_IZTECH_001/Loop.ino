int way = 2;
void loop() {  
  /*
   byte coordinate[2];
   followLine(coordinate, way);
   way = decideWay(coordinate);
   
   setMotorSpeed(MOTOR_RIGHT, 255);
   */
   QTRRead();
  // motorLeftCounter = motorLeftEncoder.read();
  // motorRightCounter = motorRightEncoder.read();

  
    pidLineFollow(colorBlack);

    if(isT()) {
      stopMotor();
      delay(2000);
      go10Step();
      delay(2000); 
     }
    
   
  

  encoderTest();

}


byte decideWay(byte coordinate[]) {
  
}
