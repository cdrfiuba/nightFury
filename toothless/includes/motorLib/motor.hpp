/**


**/

#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

#ifdef ARDUINO
#include <Arduino.h>
#endif

//Default pin
#define DIR1PIN_DEFAULT 7
#define DIR2PIN_DEFAULT 6
#define ENABLEPIN_DEFAULT 5

typedef enum{FORWARD=0,BACKWARD=1}Direction;

class Motor
{
	private:
		int dir1Pin_,dir2Pin_,enablePin_;
		unsigned int speed_;
		Direction direction_;
	public:
		//contructores
		Motor();
		Motor(const int &, const int &, const int &);
		Motor(const int &, const int &, const int &, const int &);
		Motor(const int &, const int &, const int &, const Direction &);
		Motor(const int &, const int &, const int &, const int &, const Direction &);
		Motor(const Motor &);
		~Motor();
		//Operadores sobrecargados.
		Motor const & operator=(Motor const &);
		void operator()(const int&, const Direction&);
		void operator()(const int&);
		void operator()(const Direction&);

		const unsigned int& getSpeed() const;
		const Direction & getDirection() const;
		const int & getEnablePin() const;
		const int & getDir1Pin() const;
		const int & getDir2Pin() const;

		void setSpeed(const int&);
		void setDirection(const Direction&);
		void startUpForArduino() const;
		void setPWMForArduino() const;
		void setDirPinsForArduino() const;
};


#endif

