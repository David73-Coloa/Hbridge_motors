#include <Hbridge_motors.h>
Hbridge_motors::Hbridge_motors(L298H* motor1,L298H* motor2) {
	this -> m1 = motor1;
	this -> m2 = motor2;

}

void Hbridge_motors::goToRight() {
	digitalWrite(m1 -> pin1,HIGH);
	digitalWrite(m1 -> pin2,LOW);
	digitalWrite(m2 -> pin1,LOW);
	digitalWrite(m2 -> pin2,HIGH);
	analogWrite(m1 -> enable,m1 -> speed);
	analogWrite(m2 -> enable,m2 -> speed);
}

void Hbridge_motors::goToLeft() {
	digitalWrite(m1 -> pin1,LOW);
	digitalWrite(m1 -> pin2,HIGH);
	digitalWrite(m2 -> pin1,HIGH);
	digitalWrite(m2 -> pin2,LOW);
	analogWrite(m1 -> enable,m1 -> speed);
	analogWrite(m2 -> enable,m2 -> speed);
}

void Hbridge_motors::goForward() {
	digitalWrite(m1 -> pin1,HIGH);
	digitalWrite(m1 -> pin2,LOW);
	digitalWrite(m2 -> pin1,HIGH);
	digitalWrite(m2 -> pin2,LOW);
	analogWrite(m1 -> enable,m1 -> speed);
	analogWrite(m2 -> enable,m2 -> speed);
}

void Hbridge_motors::goBackward() {
	digitalWrite(m1 -> pin1,LOW);
	digitalWrite(m1 -> pin2,HIGH);
	digitalWrite(m2 -> pin1,LOW);
	digitalWrite(m2 -> pin2,HIGH);
	analogWrite(m1 -> enable,m1 -> speed);
	analogWrite(m2 -> enable,m2 -> speed);
}

void Hbridge_motors::stop() {
	digitalWrite(m1 -> pin1,LOW);
	digitalWrite(m1 -> pin2,LOW);
	digitalWrite(m2 -> pin1,LOW);
	digitalWrite(m2 -> pin2,LOW);
	analogWrite(m1 -> enable,0);
	analogWrite(m2 -> enable,0);
}

void Hbridge_motors::setSpeed(byte speed) {
	m1 -> speed = speed;
	m2 -> speed = speed;
}