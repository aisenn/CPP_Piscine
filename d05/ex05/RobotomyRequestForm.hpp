#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;

		RobotomyRequestForm( void );

	public:
		RobotomyRequestForm( RobotomyRequestForm const & );
		RobotomyRequestForm( std::string const &target );
		~RobotomyRequestForm( void );

		RobotomyRequestForm &operator=( RobotomyRequestForm const & );

		virtual void execute( Bureaucrat const & executor ) const;

		std::string const &getTarget( void ) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
