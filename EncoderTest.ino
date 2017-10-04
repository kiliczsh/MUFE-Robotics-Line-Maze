#include <Encoder.h>

#include <AFMotor.h>


AF_DCMotor MR(4);
AF_DCMotor ML(3);


Encoder myEncL(19, 18);
Encoder myEncR(20, 21);
//PololuWheelEncoders encoders;

void setup() {
  
  Serial.begin(115200);
}

void loop() {

  turnBack();
  delay(500);

}



void turnBack() {
   while(true) {
 const int MRStep=myEncR.read();
 const int MLStep=myEncL.read();
 
  if(MLStep>-51 && MRStep<51){
    MR.run(FORWARD);
    ML.run(BACKWARD);
    MR.setSpeed(90);
    ML.setSpeed(90);
    
  }
  else{
     MR.run(BACKWARD);
     ML.run(FORWARD);
      MR.setSpeed(50);
      ML.setSpeed(50);
      delay(100);
      MR.run(RELEASE);
      ML.run(RELEASE);
     myEncR.write(0);
     myEncL.write(0);
     delay(1000);
     break;
  }
  }
}

