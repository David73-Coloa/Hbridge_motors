#ifndef Hbridge_motors_H
#define Hbridge_motors_H

#include <L298H.h>

class Hbridge_motors {
  public:
    L298H* m1 = new L298H();
    L298H* m2 = new L298H();
    Hbridge_motors(L298H* motor1, L298H* motor2);
    void goToLeft();
    void goToRight();
    void setSpeed(int speedM1,int speedM2);
    void stop();
    void goForward();
    void goBackward();
    void run(int speedToRun=1000,int _speedToRun=1000);
    void turnPin(bool state1,bool state2,bool state3,bool state4);
};

#endif //Hbridge_motors_H 
