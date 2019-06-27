#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPoint;
        static int const _fractBits;

	public:
		Fixed( void );
		Fixed( const Fixed &cp );
		Fixed( const int input);
		Fixed( const float input);
		~Fixed( void );
		Fixed &operator = ( const Fixed &cp );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator > ( const Fixed &ref);
		bool operator < ( const Fixed &ref);
		bool operator >= ( const Fixed &ref);
		bool operator <= ( const Fixed &ref);
		bool operator == ( const Fixed &ref);
		bool operator != ( const Fixed &ref);

		Fixed &operator + ( const Fixed &ref);
		Fixed &operator - ( const Fixed &ref);
		Fixed &operator / ( const Fixed &ref);
		Fixed &operator * ( const Fixed &ref);

		Fixed &operator ++ ( void );
		Fixed &operator -- ( void );
		Fixed operator ++ ( int );
		Fixed operator -- ( int );

// https://alikhuram.wordpress.com/2013/05/20/implementing-fixed-point-numbers-in-c/
        // self& operator+=(const self& x) { m += x.m; return *this; }
        // self& operator-=(const self& x) { m -= x.m; return *this; }
        // self& operator*=(const self& x) { m *= x.m; m >>= E; return *this; }
        // self& operator/=(const self& x) { m /= x.m; m *= factor; return *this; }
        // self& operator*=(int x) { m *= x; return *this; }
        // self& operator/=(int x) { m /= x; return *this; }
        // self operator-( ) { return self(-m); }

		static Fixed        &max( Fixed &a, Fixed &b );
    	const static Fixed  &max( const Fixed &a, const Fixed &b );
		static Fixed        &min( Fixed &a, Fixed &b );
    	const static Fixed  &min( const Fixed &a, const Fixed &b );
};

std::ostream &operator << ( std::ostream &output, const Fixed &ref );

#endif //FIXED_CLASS_HPP