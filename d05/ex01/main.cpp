#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void createBureaucrat() {
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
				  << e.what();
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
	std::cout << std::endl;
}

//Creating Forms with HIGH and LOW grades
void createForm() {
	try {
		std::cout << "\033[1;34mTry to create Form with high EXECUTION grade" << std::endl;
		Form f("HIGH", 50, -20);
	}
	catch (std::exception &e)
	{
		std::cout << "Error catched: \033[1;91m" << e.what() << std::endl;
	}
	try {
		std::cout << "\033[1;34mTry to create Form with high SING IN grade" << std::endl;
		Form f("HIGH", -20, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Error catched: \033[1;91m" << e.what() << std::endl;
	}
	try {
		std::cout << "\033[1;34mTry to create Form with low EXECUTION grade" << std::endl;
		Form f("HIGH", 200, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Error catched: \033[1;91m" << e.what() << std::endl;
	}
	try {
		std::cout << "\033[1;34mTry to create Form with low SING IN grade" << std::endl;
		Form f("HIGH", 1, 200);
	}
	catch (std::exception &e)
	{
		std::cout << "Error catched: \033[1;91m" << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void singForm() {
	try
	{
		Bureaucrat a("Jonathan", 19);
		Form f("Contract", 20, 20);
		std::cout << a;
		std::cout << f;

		std::cout << "Calling singForm function" << std::endl;
		a.signForm(f);


		std::cout << "Decrement " << a.getName() << " grade" << std::endl;
		a.decrement();
		a.decrement();
		std::cout << f;
		std::cout << "Calling singForm function" << std::endl;
		a.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << "Error catched: \033[1;91m"
				  << e.what() << std::endl;
	}
}

int main( void ) {
	createBureaucrat();
	createForm();
	singForm();

	return (0);
}