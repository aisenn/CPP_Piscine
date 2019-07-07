#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

std::string randomChump( void )
{
	char		vowels[] = {'a','e','i','o','u','y'};
	char		consonants[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	std::string	name = "";
	int			length = 3 + (rand() % 5);
	bool		count = rand() % 2;

	for(int i = 0; i < length; i++)
	{
		if(count)
			name = name + consonants[rand() % 19];
		else
			name = name + vowels[rand() % 5];
		count = !count;
	}
	name[0] = toupper(name[0]);
	return (name);
}

int main( void ) {
	CentralBureaucracy c;
	Bureaucrat *signers[20];
	Bureaucrat *executors[20];
	try {
		for (int i = 0; i < 20; i++) {
			srand(clock());
			signers[i] = new Bureaucrat(randomChump(), 20 + rand() % 130);
			executors[i] = new Bureaucrat(randomChump(), 20 + rand() % 130);
		}
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		for (int k = 0; k < 20; k++) {
			c.feed(*signers[k]);
			c.feed(*executors[k]);
			c.queueUp(randomChump());
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	c.doBureaucracy();
	return (0);
}