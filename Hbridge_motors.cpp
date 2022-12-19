#include <Hbridge_motors.h>

Hbridge_motors::Hbridge_motors(L298H* motor1,L298H* motor2) {
  this -> m1 = motor1;
  this -> m2 = motor2;
}

void Hbridge_motors::turnPin(bool state1,bool state2,bool state3,bool state4) {
  digitalWrite(m1 -> pin1,state1);
  digitalWrite(m1 -> pin2,state2);
  digitalWrite(m2 -> pin1,state3);
  digitalWrite(m2 -> pin2,state4);
}

void Hbridge_motors::run(int speedToRun=1000,int _speedToRun=1000) {
  if (speedToRun == 1000 && _speedToRun == 1000) { // The speed was not passed 
    analogWrite(m1 -> enable,m1 -> speed);
    analogWrite(m2 -> enable,m2 -> speed);
  }else {
    analogWrite(m1 -> enable,speedToRun);
    analogWrite(m2 -> enable,_speedToRun);
  }
}

void Hbridge_motors::goToRight() {
  // H L L H 
  turnPin(HIGH,LOW,LOW,LOW);
  run();
}

void Hbridge_motors::goToLeft() {
  // L H H L
  turnPin(LOW,HIGH,HIGH,LOW);
  run();	
}

void Hbridge_motors::goForward() {
  // H L H L
  turnPin(HIGH,LOW,HIGH,LOW);
  run();
}

void Hbridge_motors::goBackward() {
  //L H L 
  turnPin(LOW,HIGH,HIGH,LOW);
  run();
}

void Hbridge_motors::stop() {
  turnPin(LOW,LOW,LOW,LOW);
  // L L L L
  run(0,0);
}


void Hbridge_motors::setSpeed(int speedM1,int speedM2) { m1 -> speed = speedM1; m2 -> speed = speedM2; }
