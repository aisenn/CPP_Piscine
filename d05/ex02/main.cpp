#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) {
	Bureaucrat a("Ryan", 1);
	Bureaucrat low("Low", 150);

	std::cout << "\033[1;36mPresidentialPardonForm \033[0m" << std::endl;
	Form *p = new PresidentialPardonForm("Villa");
	p->execute(a);
	low.signForm(*p);
	a.signForm(*p);
	p->execute(a);

	std::cout << "\n\033[1;36mShrubberyCreationForm \033[0m" << std::endl;
	Form *s = new ShrubberyCreationForm("Villa");
	s->execute(a);
	low.signForm(*p);
	a.signForm(*s);
	s->execute(a);

	std::cout << "\n\033[1;36mRobotomyRequestForm \033[0m" << std::endl;
	Form *r = new RobotomyRequestForm("Villa");
	r->execute(a);
	low.signForm(*p);
	a.signForm(*r);
	r->execute(a);

	delete p;
	delete s;
	delete r;

	return (0);
}