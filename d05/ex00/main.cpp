#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
	std::cout << "\033[1;34mTry -> catch for increment" << std::endl;
	try
	{
		Bureaucrat a("Min", 150);

		std::cout << "\tCalling the copy constructor" << std::endl;
		Bureaucrat b(a);
		std::cout << "\t\ta = " << a << "\t\tb = " << b;

		std::cout << "\tCalling the assignation operator" << std::endl;
		Bureaucrat c("Bax", 1);
		a = c;

		std::cout << "\t\ta = " << a << "\t\tc = " << c;
		std::cout << "\tCalling increment method" << std::endl;
		a.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "\t\tError catched: \033[1;91m"
				  << e.what() << std::endl;
	}

	//---------------------------------------------------------------//
	std::cout << "\n\033[1;33mTry -> catch for decrement" << std::endl;
	try
	{
		Bureaucrat a("Max", 1);

		std::cout << "\tCalling the copy constructor" << std::endl;
		Bureaucrat b(a);
		std::cout << "\t\ta = " << a << "\t\tb = " << b;

		std::cout << "\tCalling the assignation operator" << std::endl;
		Bureaucrat c("Bax", 150);
		a = c;

		std::cout << "\t\ta = " << a << "\t\tc = " << c;
		std::cout << "\tCalling decrement method" << std::endl;
		a.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << "\t\tError catched: \033[1;91m"
				  << e.what() << std::endl;
	}

	return (0);
}