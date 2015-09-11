#include <iostream>
#include "motors.cpp"

struct motorTest
{
	void testConstAndOpEqual();
	void testOperatorsEqual();
};
 
void motorTest::testConstAndOpEqual()
{
	//Default constructor: OK
	std::cout << "Default construct test" << std::endl;
	motor m1;
	m1.printAtt();
	std::cout<<std::endl;
	//Parametric constructor: OK
	std::cout << "Parametric construct test" << std::endl;
	motor m2(1,2,3);
	m2.printAtt();
	std::cout<<std::endl;
	//Copy constructor: OK
	std::cout << "Copy construct test" << std::endl;
	motor m3(m2);
	m3.printAtt();
	std::cout<<std::endl;
	//Op equal
	
}
void motorTest::testOperatorsEqual()
{
	motor m1,m2,m3;
	m1(40,false);
	m2(100,true);
	m3(40,false);

	//Op EqEq: Undefined
	std::cout << "Comparation Op== test" << std::endl;
	if(m3==m2)
		std::cout << "m3 and m2 are equal." << std::endl;
	if(m1==m3)
		std::cout << "m1 and m3 are equal." << std::endl;
	std::cout<<std::endl;
	//Op notEq: Undefined
	std::cout << "Comparation Op!= test" << std::endl;
	if(m1!=m3)
		std::cout << "m1 and m3 are not equal." << std::endl;
	if(m2!=m3)
		std::cout << "m2 and m3 are not equal." << std::endl;
	std::cout<<std::endl;

}

int main()
{
	motorTest test;
//	test.testConstAndOpEqual();
//	test.testOperatorsEqual();
	return 0;
}
