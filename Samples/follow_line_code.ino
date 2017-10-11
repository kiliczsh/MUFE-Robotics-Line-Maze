/* 5.10.2017
 * 
 */

//import libraries
#include <QTRSensors.h>

// define motorshield pins
    // left motor pins
      int enableLeft ;
      int leftInputOne ;
      int leftInputTwo ;
      int motorVoltageLeft ;
    // right motor pins
      int enableRight ;
      int rightInputOne ;
      int rightInputTwo ;
      int motorVoltageRight ;
    // other pins
      int vcc ;
      int gnd ;
      int 5v ;

void setup() {
  // put your setup code here, to run once:

  // define pin modes
    pinMode(enableLeft,OUTPUT);
    pinMode(leftInputOne,OUTPUT);
    pinMode(leftInputTwo,OUTPUT);
    pinMode(enableRight,OUTPUT);
    pinMode(rightInputOne,OUTPUT);
    pinMode(rightInputTwo,OUTPUT);
    
      
      
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
