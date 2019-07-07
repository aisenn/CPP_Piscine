#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm()
		: Form("Presidential Pardon Form", 72, 45) { return; }

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &rhs )
		: Form("Robotomy Request Form", 72, 45) {
	*this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm() { return; }

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
		Form("Presidential Pardon Form", 72, 45), _target(target) {
	srand(clock());
}

void						RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	try {
		Form::execute(executor);
		std::cout << "* drilling noises *";
		for (int i = 0; i < 10; i++)
		{
			usleep(100000);
			std::cout << "\a";
			fflush(stdout);
		}
		std::cout << std::endl;

		srand(clock());
		if (rand() % 2)
		{

			std::cout << "\033[1;92m" << this->getTarget() << " has been robotomized successfully\033[0m" << std::endl;
		}
		else
			std::cout << "\033[1;91m" << this->getTarget() << " robotomized has been failed\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\033[1;91m" << this->getTarget() << " robotomize failed\033[0m "<< e.what() << std::endl;
	}
}

std::string const &RobotomyRequestForm::getTarget(void) const { return (this->_target); }