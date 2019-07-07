#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) { return; }

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern::~Intern(void) { return; }

Intern				&Intern::operator=( Intern const & ) {
	return (*this);
}

Form *Intern::newShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

Form *Intern::newRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

Form *Intern::newPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

Form				*Intern::makeForm(std::string name, std::string target)
{
	std::string fnNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	Form *(Intern::*fnPtr[])(std::string target) =
	{
		&Intern::newShrubberyCreationForm,
		&Intern::newRobotomyRequestForm,
		&Intern::newPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == fnNames[i])
			return (this->*fnPtr[i])(target);
	}
	throw (Intern::UnknownFunctionException());
}

// UnknownFunctionException class

Intern::UnknownFunctionException::UnknownFunctionException( void ) { return; }
Intern::UnknownFunctionException::~UnknownFunctionException( void ) throw() { return; }
Intern::UnknownFunctionException::UnknownFunctionException(UnknownFunctionException const &src) {
	*this = src;
}
Intern::UnknownFunctionException	&Intern::UnknownFunctionException::operator=( Intern::UnknownFunctionException const & ) {
	return *this;
}
char const					*Intern::UnknownFunctionException::what(void) const throw() {
	return ("Error: Unknown function");
}