#ifndef SCALARCONVERSION_H
# define SCALARCONVERSION_H

# include <iostream>
# include <exception>

class ScalarConversion
{
	private:
		std::string _data;
		ScalarConversion();

	public:
		ScalarConversion(std::string const &data);
		ScalarConversion(ScalarConversion const &src);
		~ScalarConversion(void);
		ScalarConversion &operator=(ScalarConversion const &rhs);

		operator std::string const &(void) const;
		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;

		class ImpossibleException: public std::exception
		{
			public:
				ImpossibleException( void );
                ImpossibleException( ImpossibleException const & );
                virtual ~ImpossibleException( void ) throw();
                ImpossibleException  &operator=( ImpossibleException const& );

                virtual const char *what() const throw();
		};
};

std::ostream					&operator<<(std::ostream &os, ScalarConversion const &ScalarConversion);

#endif //SCALARCONVERSION_H
