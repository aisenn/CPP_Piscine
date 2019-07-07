#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void ) {
	Intern i;
	Bureaucrat a("Ryan", 1);
	Bureaucrat low("Low", 150);

	Form *p = NULL;
	Form *s = NULL;
	Form *r = NULL;
	Form *random = NULL;
	try {
		std::cout << "\n\033[1;36mPresidentialPardonForm \033[0m" << std::endl;
		p = i.makeForm("presidential pardon", "Villa");//new PresidentialPardonForm("Villa");
		p->execute(a);
		low.signForm(*p);
		a.signForm(*p);
		p->execute(a);

		std::cout << "\n\033[1;36mShrubberyCreationForm \033[0m" << std::endl;
		s = i.makeForm("shrubbery creation", "Villa");
		s->execute(a);
		low.signForm(*p);
		a.signForm(*s);
		s->execute(a);

		std::cout << "\n\033[1;36mRobotomyRequestForm \033[0m" << std::endl;
		r = i.makeForm("robotomy request", "Villa");
		r->execute(a);
		low.signForm(*p);
		a.signForm(*r);
		r->execute(a);

		std::cout << "\n\033[1;36mSomeRandomForm \033[0m" << std::endl;
		random = i.makeForm("some random", "Villa");
		random->execute(a);
		low.signForm(*p);
		a.signForm(*random);
		random->execute(a);

	}
	catch (std::exception &e)
	{
		std::cout << "Intern's error"  << e.what() << std::endl;
	}

	delete p;
	delete s;
	delete r;
	delete random;
	
	return (0);
}