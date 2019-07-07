#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) { return; }

Bureaucrat::Bureaucrat( std::string const &name, int grade) : _name(name) {
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const & obj ) : _name(obj.getName()) {
    *this = obj;
}

Bureaucrat::~Bureaucrat( void ) { return; }

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &obj){
 	if(this != &obj)
 		this->_grade = obj.getGrade();
    return *this;
}

std::string	const	&Bureaucrat::getName( void ) const { return this->_name; }
int					Bureaucrat::getGrade( void ) const { return this->_grade; }

void				Bureaucrat::increment( void ) {
    if (this->getGrade() <= 1)
        throw (Bureaucrat::GradeTooHighException());
    this->_grade--;
}

void				Bureaucrat::decrement( void ) {
    if (this->getGrade() >= 150)
        throw (Bureaucrat::GradeTooLowException());
    this->_grade++;
}

void                Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signs " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

// GradeTooHighException class

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) { return; }
Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const &obj ) {
    *this = obj;
}
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() { return; }
Bureaucrat::GradeTooHighException  &Bureaucrat::GradeTooHighException
	::operator=( Bureaucrat::GradeTooHighException const & ) {
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Error: Grade is too high");
}

// GradeTooLowException class

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) { return; }
Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const &obj ) {
    *this = obj;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() { return; }
Bureaucrat::GradeTooLowException  &Bureaucrat::GradeTooLowException
	::operator=( Bureaucrat::GradeTooLowException const & ) {
    return *this;
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Error: Grade is too low");
}

std::ostream				&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}