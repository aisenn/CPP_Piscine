#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "Intern.hpp"
# include "Form.hpp"




class Intern
{
	private:


	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		Intern					&operator=(Intern const &rhs);

		Form					*makeForm(std::string name, std::string target);

		Form *newShrubberyCreationForm(std::string target);
        Form *newRobotomyRequestForm(std::string target);
        Form *newPresidentialPardonForm(std::string target);

        class UnknownFunctionException: public std::exception
		{
			public:
				UnknownFunctionException( void );
				UnknownFunctionException( UnknownFunctionException const &src );
				virtual ~UnknownFunctionException( void ) throw();
				UnknownFunctionException		&operator=( UnknownFunctionException const &rhs );

				virtual const char *what() const throw();
		};
};

#endif //INTERN_HPP
