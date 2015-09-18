#include "motor.hpp"

#ifdef __arduino__
#include <Arduino.h>

/*Methods to interface with arduino api*/
void Motor::startUpForArduino() const
{
	pinMode(dir1Pin_,OUTPUT);
	pinMode(dir2Pin_,OUTPUT);
	pinMode(enablePin_,OUTPUT);
	setPWMForArduino();
	setDirPinsForArduino();
}

void Motor::setPWMForArduino() const
{
	analogWrite(enablePin_, speed_);
}

void Motor::setDirPinsForArduino() const
{
//TODO que pasan en el resto de los estados (LOW-LOW/HIGH-HIGH)
	if(forward_ == FORWARD)
	{
	    digitalWrite(dir1Pin_, LOW);
        digitalWrite(dir2Pin_, HIGH);
	}
	else
	{
	    digitalWrite(dir1Pin_, HIGH);
        digitalWrite(dir2Pin_, LOw);
	}
}
#endif

#ifdef __ogham__
void startUpForArduino() const
{
//TODO
}

void setPWMForArduino() const
{
//TODO
}

void setDirPinsForArduino() const
{
//TODO
}
#endif

void sincStartUp() const
{
}

void sincPWM() const
{
}

void sincDir() const
{
}


/*Default constructor*/
Motor::Motor(): dir1Pin_(DIR1PIN_DEFAULT), dir2Pin_(DIR2PIN_DEFAULT), enablePin_(ENABLEPIN_DEFAULT), speed_(0), direction_(FORWARD)
{
	startUpForArduino();
}

/*Parametric constructors*/
Motor::Motor(const int &d1, const int &d2, const int &en): dir1Pin_(d1), dir2Pin_(d2), enablePin_(en), speed_(0), direction_(FORWARD)
{
	startUpForArduino();
}

Motor::Motor(const int &d1, const int &d2, const int &en, const Direction &d):dir1Pin_(d1), dir2Pin_(d2), enablePin_(en), speed_(0), direction_(d)
{
	startUpForArduino();
}

/*TODO aplicar un cambio de escala a s para que cambie de 0-100 a 0-255*/
Motor::Motor(const int &d1, const int &d2, const int &en, const int &s):dir1Pin_(d1), dir2Pin_(d2), enablePin_(en), speed_(s), direction_(FORWARD)
{
	startUpForArduino();
}

/*TODO aplicar un cambio de escala a s para que cambie de 0-100 a 0-255*/
Motor::Motor(const int &d1, const int &d2, const int &en, const int &s, const Direction &d):dir1Pin_(d1), dir2Pin_(d2), enablePin_(en), speed_(s), direction_(d)
{
	startUpForArduino();
}

/*Copy constructor, just copy an static object and trigger arduino's startup*/
Motor::Motor(const Motor & m)
{
	dir1Pin_  = m.dir1Pin_;
	dir2Pin_ = m.dir2Pin_; 
	enablePin_ = m.enablePin_;
	direction_ = m.direction_;
	speed_ = m.speed_;
	startUpForArduino();
}

/*Destructor, nothing dinamic to delete*/
Motor::~Motor()
{}

//Sobrecarga de operadores
Motor const & Motor::operator=(Motor const &m)
{
	if(this != &m)
	{	
		dir1Pin_  = m.dir1Pin_;
		dir2Pin_ = m.dir2Pin_; 
		enablePin_ = m.enablePin_;
		speed_ = m.speed_;
		direction_ = m.direction_;
		startUpForArduino();
	}
	return *this;
}

void Motor::operator()(const int & s, const Direction & d)
{
	speed_ = s;
	direction_ = d;
	setPWMForArduino();
	setDirPinsForArduino();
}

void Motor::operator()(const Direction & d)
{
	direction_ = d;
	setDirPinsForArduino();
}

void Motor::operator()(const int & s)
{
	speed_ = s;
	setPWMForArduino();
}

//getters
const unsigned int & Motor::getSpeed() const
{
	return speed_;
}

const Direction & Motor::getDirection() const
{
	return direction_;
}

const int & Motor::getEnablePin() const
{
	return enablePin_;
}

const int & Motor::getDir1Pin() const
{
	return dir1Pin_;
}

const int & Motor::getDir2Pin() const
{
	return dir2Pin_;
}

//setters
void Motor::setSpeed(const int& s)
{
	speed_ = s;
	setPWMForArduino();
}
void Motor::setDirection(const Direction & f)
{
	direction_ = f;
	setDirPinsForArduino();
}

