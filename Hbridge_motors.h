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
		void stop();
		void goForward();
		void goBackward();
};

#endif //Hbridge_motors_H 