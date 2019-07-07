#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

void intern(Intern i, Bureaucrat a, Bureaucrat low) {
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
}

void office(Intern i, Bureaucrat a, Bureaucrat low) {
	OfficeBlock office(i, a, low);
	OfficeBlock w;
	std::cout << "\n\033[1;36mdoBureaucracy \033[0m" << std::endl;
	try {
		office.doBureaucracy("df", "qwe");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	try {
		office.doBureaucracy("presidential pardon", "!xbille");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	try {
		office.doBureaucracy("robotomy request", "!xbille");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	try {
		office.doBureaucracy("shrubbery creation", "!xbille");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	std::cout << "\n\033[1;36mIncrement and doBureaucracy again \033[0m" << std::endl;
	try {
		for (int k = 0; k < 149; k++)
			low.increment();

		office.doBureaucracy("presidential pardon", "!xbille");
		office.doBureaucracy("robotomy request", "!xbille");
		office.doBureaucracy("shrubbery creation", "!xbille");
	}
	catch (std::exception &e) {
		std::cout << "Increment and try again " << e.what() << std::endl;
	}
}

void office() {
	Intern *i = new Intern;
	Bureaucrat *a = new Bureaucrat("Ryan", 1);
	Bureaucrat *low = NULL;

	std::cout << "\n\033[1;36mdoBureaucracy with empty office \033[0m" << std::endl;

	try {
		OfficeBlock test(*i, *a, *low);
		test.doBureaucracy("presidential pardon", "Sam");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	low  = new Bureaucrat("Low", 150);
	delete a;
	a = NULL;
	try {
		OfficeBlock test(*i, *a, *low);
		test.doBureaucracy("robotomy request", "Sam");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}

	a = new Bureaucrat("Ryan", 1);
	delete i;
	i = NULL;
	try {
		OfficeBlock test(*i, *a, *low);
		test.doBureaucracy("shrubbery creation", "Sam");
	}
	catch (std::exception &e) {
		std::cout << "Can not do bureaucracy " << e.what() << std::endl;
	}
	delete a;
	delete low;
}

int main( void ) {

	Intern i;
	Bureaucrat a("Ryan", 1);
	Bureaucrat low("Low", 150);

	//Empty constructor
	OfficeBlock empty;

	intern(i, a, low);
	office(i, a, low);
	office();
	return (0);
}