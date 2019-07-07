#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("Presidential Pardon Form", 25, 5) { return; }

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &rhs )
	: Form("Presidential Pardon Form", 25, 5) {
	*this = rhs;
	std::cout << "Intern creates a "
			  << this->getName() << " (s.grade " << this->getSinginGrade() << ", ex.grade " << this->getExecuteGrade()
			  << ") targeted on " << this->getTarget() << "("
			  << (this->isSigned() ? "Signed" : "Unsigned") << ")"
			  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() { return; }

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
		Form("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << "Intern creates a "
			  << this->getName() << " (s.grade " << this->getSinginGrade() << ", ex.grade " << this->getExecuteGrade()
			  << ") targeted on " << this->getTarget() << "("
			  << (this->isSigned() ? "Signed" : "Unsigned") << ")"
			  << std::endl;
}

void						PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	try {
		Form::execute(executor);
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getTarget() << " was not pardoned "<< e.what() << std::endl;
	}
}

std::string const &PresidentialPardonForm::getTarget(void) const { return (this->_target); }
