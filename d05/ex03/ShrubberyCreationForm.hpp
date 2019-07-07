#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;

		ShrubberyCreationForm( void );

	public:
		ShrubberyCreationForm( ShrubberyCreationForm const & );
		ShrubberyCreationForm( std::string const &target );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & );

		virtual void execute( Bureaucrat const & executor ) const;

		std::string const &getTarget( void ) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
