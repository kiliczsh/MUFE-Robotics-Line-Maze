int way = 2;
void loop() {  
  /*
   byte coordinate[2];
   followLine(coordinate, way);
   way = decideWay(coordinate);
   
   setMotorSpeed(MOTOR_RIGHT, 255);
   */
   QTRRead();
   pidLineFollow(colorBlack);

      
}

byte decideWay(byte coordinate[]) {
  
}
