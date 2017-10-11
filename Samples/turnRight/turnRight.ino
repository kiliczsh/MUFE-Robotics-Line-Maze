void turnRight() {
  goBack();
      while(true) {
 MRStep=myEncR.read();
 MLStep=myEncL.read();
 
  if(MRStep>-24 && MLStep<24){
    MR.run(BACKWARD);
    ML.run(FORWARD);
    MR.setSpeed(90);
    ML.setSpeed(90);
     
  }
  else{
     MR.run(FORWARD);
     ML.run(BACKWARD);
      MR.setSpeed(50);
      ML.setSpeed(50);
      delay(100);
      MR.run(RELEASE);
      ML.run(RELEASE);
     myEncL.write(0);
     myEncR.write(0);
     delay(300);
     break;
  }
  }
  direct++;
    direct = (byte) (direct % 4);
    updateWall();
}
