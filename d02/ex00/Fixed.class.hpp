#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
	private:
		int                 _fixedPoint;
        static int const    _fractBits;

	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const Fixed &cp );
        
		Fixed   &operator = ( const Fixed &cp );
		int     getRawBits( void ) const;
		void    setRawBits( int const raw );
};

#endif //FIXED_CLASS_HPP