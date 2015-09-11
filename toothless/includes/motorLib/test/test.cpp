#include <gtest/gtest.h>
#include "../motor.hpp"

//Motor();
TEST(constructorTest, defaultContructor)
{
	Motor m;
	EXPECT_EQ(7,m.getDir1Pin());
	EXPECT_EQ(6,m.getDir2Pin());
	EXPECT_EQ(5,m.getEnablePin());
	EXPECT_EQ(0,m.getSpeed());
	EXPECT_TRUE( FORWARD==m.getDirection() );
}

//Motor(const int &, const int &, const int &);
TEST(constructorTest, parametricPinsContructor)
{
	

}

//Motor(const int &, const int &, const int &, const int &);
TEST(constructorTest, parametricPinsSpeedContructor)
{
	

}

//Motor(const int &, const int &, const int &, const Direction &);
TEST(constructorTest, parametricPinsDirContructor)
{
	

}

//Motor(const int &, const int &, const int &, const int &, const Direction &);
TEST(constructorTest, parametricPinsDirSpeedContructor)
{
	

}

//Motor(const Motor &);
TEST(constructorTest, copyContructor)
{
	

}
