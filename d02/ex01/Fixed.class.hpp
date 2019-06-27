#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 _fixedPoint;
        static int const    _fractBits;

	public:
		Fixed( void );
		Fixed( const Fixed &cp );
		Fixed( const int input);
		Fixed( const float input);
		~Fixed( void );
        
		Fixed   &operator = ( const Fixed &cp );
		int     getRawBits( void ) const;
		void    setRawBits( int const raw );
		float   toFloat( void ) const;
		int     toInt( void ) const;
};

std::ostream &operator << ( std::ostream &output, const Fixed &ref );

#endif //FIXED_CLASS_HPP