#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_singinGrade;
		const int			_executeGrade;

		Form();

	public:
		Form( std::string const&, int, int );
		Form( Form const & );
		virtual ~Form( void );
		Form  &operator=(Form const&);

		std::string const	&getName( void ) const;
		bool				isSigned( void ) const;
		int					getSinginGrade( void ) const;
		int					getExecuteGrade( void ) const;

		void				beSigned(Bureaucrat const &obj);
		virtual void 		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
            public:
                GradeTooHighException( void );
                GradeTooHighException( GradeTooHighException const & );
                virtual ~GradeTooHighException( void ) throw();
                GradeTooHighException  &operator=( GradeTooHighException const& );

                virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
            public:
                GradeTooLowException( void );
                GradeTooLowException( GradeTooLowException const & );
                virtual ~GradeTooLowException( void ) throw();
                GradeTooLowException  &operator=( GradeTooLowException const& );

                virtual const char *what() const throw();
		};
		class NotSignedException: public std::exception
		{
			public:
				NotSignedException( void );
				NotSignedException( NotSignedException const &src );
				virtual ~NotSignedException( void ) throw();
				NotSignedException		&operator=( NotSignedException const &rhs );

				virtual const char *what() const throw();
		};
};

std::ostream        &operator<<(std::ostream &o, Form const &i);


#endif // FORM_HPP