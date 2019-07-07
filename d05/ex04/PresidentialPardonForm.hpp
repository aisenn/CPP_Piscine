#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

	PresidentialPardonForm( void );

public:
	PresidentialPardonForm( PresidentialPardonForm const & );
	PresidentialPardonForm( std::string const &target );
	~PresidentialPardonForm( void );

	PresidentialPardonForm &operator=( PresidentialPardonForm const & );

	virtual void execute( Bureaucrat const & executor ) const;

	std::string const &getTarget( void ) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
