#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

# include <string>
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
	private:
		Intern					*_intern;
		Bureaucrat				*_signer;
		Bureaucrat				*_executor;

        OfficeBlock(OfficeBlock const &);
		OfficeBlock &operator=(OfficeBlock const &);

	public:
		OfficeBlock(void);
        OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
        ~OfficeBlock(void);

		void					doBureaucracy(std::string const &name, std::string const &target);

		Intern					*getIntern() const;
		Bureaucrat				*getSigner() const;
		Bureaucrat				*getExecutor() const;

	void setIntern(Intern &intern);
	void setSigner(Bureaucrat &signer);
	void setExecutor(Bureaucrat &executor);

		class					NoInternException: public std::exception
		{
			public:
									NoInternException(void);
									~NoInternException(void) throw();
									NoInternException(NoInternException const &src);
			NoInternException		&operator=(NoInternException const &rhs);
			char const				*what(void) const throw();
		};

		class					NoSignerException: public std::exception
		{
			public:
									NoSignerException(void);
									~NoSignerException(void) throw();
									NoSignerException(NoSignerException const &src);
			NoSignerException		&operator=(NoSignerException const &rhs);
			char const				*what(void) const throw();
		};

		class					NoExecutorException: public std::exception
		{
			public:
									NoExecutorException(void);
									~NoExecutorException(void) throw();
									NoExecutorException(NoExecutorException const &src);
			NoExecutorException		&operator=(NoExecutorException const &rhs);
			char const				*what(void) const throw();
		};

		class					SignerGradeTooLowException: public std::exception
		{
			public:
									SignerGradeTooLowException(void);
									~SignerGradeTooLowException(void) throw();
									SignerGradeTooLowException(SignerGradeTooLowException const &src);
			SignerGradeTooLowException		&operator=(SignerGradeTooLowException const &rhs);
			char const				*what(void) const throw();
		};

		class					ExecutorGradeTooLowException: public std::exception
		{
			public:
									ExecutorGradeTooLowException(void);
									~ExecutorGradeTooLowException(void) throw();
									ExecutorGradeTooLowException(ExecutorGradeTooLowException const &src);
			ExecutorGradeTooLowException		&operator=(ExecutorGradeTooLowException const &rhs);
			char const				*what(void) const throw();
		};

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

#endif //OFFICEBLOCK_HPP
