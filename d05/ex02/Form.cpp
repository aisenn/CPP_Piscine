#include "Form.hpp"
#include <iomanip>

Form::Form() : _name("default"), _isSigned(false), _singinGrade(150), _executeGrade(150) { return; }

Form::Form( std::string const& name, int singinGrade, int executeGrade)
    : _name(name), _isSigned(false), _singinGrade(singinGrade), _executeGrade(executeGrade) {
	if (this->_executeGrade < 1 || this->_singinGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_executeGrade > 150 || this->_singinGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Form::Form( Form const &obj )
	: _name(obj.getName()), _isSigned(obj.isSigned()),
	  _singinGrade(obj.getSinginGrade()), _executeGrade(obj.getExecuteGrade()) {
	if (this->_executeGrade < 1 || this->_singinGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_executeGrade > 150 || this->_singinGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Form::~Form( void ) { return; }

Form  &Form::operator=(Form const &obj) {
	if (this != &obj)
		this->_isSigned = obj.isSigned();
	return (*this);
}

std::string const	&Form::getName( void ) const { return this->_name; }
bool				Form::isSigned(void) const { return this->_isSigned; }
int					Form::getSinginGrade( void ) const { return this->_singinGrade; }
int					Form::getExecuteGrade( void ) const { return this->_executeGrade; }

void				Form::beSigned(Bureaucrat const &obj) {
    if (obj.getGrade() > this->_singinGrade)
        throw(Form::GradeTooLowException());
    this->_isSigned = true;
}

void 		Form::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_executeGrade)
		throw (GradeTooLowException());
	if (!this->isSigned())
		throw (NotSignedException());
}

// GradeTooHighException class

Form::GradeTooHighException::GradeTooHighException( void ) { return; }
Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const &obj ) {
    *this = obj;
}
Form::GradeTooHighException::~GradeTooHighException( void ) throw() { return; }
Form::GradeTooHighException  &Form::GradeTooHighException
	::operator=( Form::GradeTooHighException const & ) {
    return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Error: Grade is too high");
}

// GradeTooLowException class

Form::GradeTooLowException::GradeTooLowException( void ) { return; }
Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const &obj ) {
    *this = obj;
}
Form::GradeTooLowException::~GradeTooLowException( void ) throw() { return; }
Form::GradeTooLowException  &Form::GradeTooLowException
	::operator=(Form::GradeTooLowException const & ) {
    return *this;
}
const char *Form::GradeTooLowException::what() const throw() {
    return ("Error: Grade is too low");
}

std::ostream				&operator<<(std::ostream &os, Form const &form)
{
	if (!form.isSigned())
		os	<< form.getName() << " form is not signed. ";
	else
		os	<< form.getName() << " form is signed. ";
	os << "Signin grade:    " << form.getSinginGrade() << " "
	   << "Execution grade: " << form.getExecuteGrade() << std::endl;
	return (os);
}

// NotSignedException class

Form::NotSignedException::NotSignedException( void ) { return; }
Form::NotSignedException::~NotSignedException( void ) throw() { return; }
Form::NotSignedException::NotSignedException(NotSignedException const &src) {
	*this = src;
}
Form::NotSignedException	&Form::NotSignedException::operator=( Form::NotSignedException const & ) {
	return *this;
}

char const					*Form::NotSignedException::what(void) const throw()
{
	return ("Error: Form not signed");
}