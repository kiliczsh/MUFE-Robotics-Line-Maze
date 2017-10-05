void pidLineFollow(int color){
  int speedLeft = initialLeftSpeed;
  int speedRight = initialRightSpeed;

  int pos = positionSensor(color);

  positionLast = pos;
  float err;
  float err_d;
  if(pos!=0){
    err = pos-0;
    p_const = p_const_t2;
    d_const = d_const_t2;
  }else{
    err = 0;
    err_past = 0;  
  }

  err_d = err -err_past;
  float adj = err*p_const + err_d *d_const;

  motoMove(speedLeft+adj,speedRight-adj);
  err_past = err;
}


void followLine(byte *coordinate, int way) {
  
}
