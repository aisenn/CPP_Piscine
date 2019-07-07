#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;

		Bureaucrat( void );

	public:

		Bureaucrat( std::string const&, int);
		Bureaucrat( Bureaucrat const& );
		~Bureaucrat( void );
		Bureaucrat  &operator=(Bureaucrat const&);

		std::string	const	&getName( void ) const;
		int					getGrade( void ) const;

		void				increment( void );
		void				decrement( void );

		class GradeTooHighException : public std::exception
		{
            public:
                GradeTooHighException( void );
                GradeTooHighException( GradeTooHighException const & );
                virtual ~GradeTooHighException( void ) throw();
                GradeTooHighException  &operator=(GradeTooHighException const&);

                virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
            public:
                GradeTooLowException( void );
                GradeTooLowException( GradeTooLowException const & );
				virtual ~GradeTooLowException( void ) throw();
                GradeTooLowException  &operator=(GradeTooLowException const&);

                virtual const char *what() const throw();
		};
};

std::ostream        &operator<<(std::ostream &o, Bureaucrat const &i);


#endif // BUREAUCRAT_HPP