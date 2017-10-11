int way = 2;
void loop() {

    
  
    pidLineFollow(COLOR_BLACK);

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
