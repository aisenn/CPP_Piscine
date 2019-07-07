#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

OfficeBlock::OfficeBlock(void)
	: _intern(NULL), _signer(NULL), _executor(NULL) { return; }
OfficeBlock::OfficeBlock(OfficeBlock const &rhs) {
	*this = rhs;
}
OfficeBlock &OfficeBlock::operator=(OfficeBlock const &rhs) {
	if (this != &rhs) {
		this->_executor = rhs.getExecutor();
		this->_intern = rhs.getIntern();
		this->_signer = rhs.getSigner();
	}
	return *this;
}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor)
    : _intern(&intern), _signer(&signer), _executor(&executor) { return; }

OfficeBlock::~OfficeBlock(void) { return; }

void OfficeBlock::doBureaucracy(std::string const &name, std::string const &target)
{
    Form *form;

    if (!this->_intern)
        throw(NoInternException());
    if (!this->_signer)
        throw(NoSignerException());
    if (!this->_executor)
        throw(NoExecutorException());

    form = this->_intern->makeForm(name, target);
    if (!form)
		throw(UnknownFunctionException());

    try {
        this->_signer->signForm(*form);
    }
    catch (Form::GradeTooLowException &e) {
        throw(SignerGradeTooLowException());
    }

    try {
        this->_executor->executeForm(*form);
    }
    catch (Form::GradeTooLowException &e) {
        throw(ExecutorGradeTooLowException());
    }
}

Intern 		*OfficeBlock::getIntern() const { return _intern; }
Bureaucrat	*OfficeBlock::getSigner() const { return _signer; }
Bureaucrat	*OfficeBlock::getExecutor() const { return _executor; }

void		OfficeBlock::setIntern(Intern &intern) { _intern = &intern; }
void		OfficeBlock::setSigner(Bureaucrat &signer) { _signer = &signer; }
void		OfficeBlock::setExecutor(Bureaucrat &executor) { _executor = &executor; }

// NoInternException class

OfficeBlock::NoInternException::NoInternException(void) { return; }
OfficeBlock::NoInternException::~NoInternException(void) throw() { return; }
OfficeBlock::NoInternException::NoInternException(NoInternException const &src) {
    *this = src;
}
OfficeBlock::NoInternException &OfficeBlock::NoInternException
    ::operator=(OfficeBlock::NoInternException const &) {
    return *this;
}
char const *OfficeBlock::NoInternException::what(void) const throw() {
    return ("No Intern");
}

// NoSignerException class

OfficeBlock::NoSignerException::NoSignerException(void) { return; }
OfficeBlock::NoSignerException::~NoSignerException(void) throw() { return; }
OfficeBlock::NoSignerException::NoSignerException(NoSignerException const &src) {
    *this = src;
}
OfficeBlock::NoSignerException &OfficeBlock::NoSignerException
    ::operator=(OfficeBlock::NoSignerException const &) {
    return *this;
}
char const *OfficeBlock::NoSignerException::what(void) const throw() {
    return ("No Signer");
}

// NoExecutorException class

OfficeBlock::NoExecutorException::NoExecutorException(void) { return; }
OfficeBlock::NoExecutorException::~NoExecutorException(void) throw() { return; }
OfficeBlock::NoExecutorException::NoExecutorException(NoExecutorException const &src) {
    *this = src;
}
OfficeBlock::NoExecutorException &OfficeBlock::NoExecutorException
    ::operator=(OfficeBlock::NoExecutorException const &) {
    return *this;
}
char const *OfficeBlock::NoExecutorException::what(void) const throw() {
    return ("No Executor");
}

// SignerGradeTooLowException class

OfficeBlock::SignerGradeTooLowException::SignerGradeTooLowException(void) { return; }
OfficeBlock::SignerGradeTooLowException::~SignerGradeTooLowException(void) throw() { return; }
OfficeBlock::SignerGradeTooLowException::SignerGradeTooLowException(SignerGradeTooLowException const &src) {
    *this = src;
}
OfficeBlock::SignerGradeTooLowException &OfficeBlock::SignerGradeTooLowException
    ::operator=(OfficeBlock::SignerGradeTooLowException const &) {
    return *this;
}
char const *OfficeBlock::SignerGradeTooLowException::what(void) const throw() {
    return ("Signer Grade Too Low");
}

// ExecutorGradeTooLowException class

OfficeBlock::ExecutorGradeTooLowException::ExecutorGradeTooLowException(void) { return; }
OfficeBlock::ExecutorGradeTooLowException::~ExecutorGradeTooLowException(void) throw() { return; }
OfficeBlock::ExecutorGradeTooLowException::ExecutorGradeTooLowException(ExecutorGradeTooLowException const &src) {
    *this = src;
}
OfficeBlock::ExecutorGradeTooLowException &OfficeBlock::ExecutorGradeTooLowException
    ::operator=(OfficeBlock::ExecutorGradeTooLowException const &) {
    return *this;
}
char const *OfficeBlock::ExecutorGradeTooLowException::what(void) const throw() {
    return ("Executor Grade Too Low");
}

// UnknownFunctionException class

OfficeBlock::UnknownFunctionException::UnknownFunctionException( void ) { return; }
OfficeBlock::UnknownFunctionException::~UnknownFunctionException( void ) throw() { return; }
OfficeBlock::UnknownFunctionException::UnknownFunctionException(UnknownFunctionException const &src) {
	*this = src;
}
OfficeBlock::UnknownFunctionException	&OfficeBlock::UnknownFunctionException::operator=( OfficeBlock::UnknownFunctionException const & ) {
	return *this;
}
char const					*OfficeBlock::UnknownFunctionException::what(void) const throw() {
	return ("Error: Unknown function");
}