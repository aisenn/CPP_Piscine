#include <iostream>
#include "Fixed.class.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "------------------------" << std::endl;
    Fixed c(1);
    c = c + 10;
    std::cout << c << std::endl;
    c = c * 2;
    std::cout << c << std::endl;
    c = c / c;
    std::cout << c << std::endl;
    c = c - c;
    std::cout << c << std::endl;
    
	return 0;
}