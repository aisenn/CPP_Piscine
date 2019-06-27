#include "Fixed.class.hpp"

int const Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &cp ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cp;
}

Fixed &Fixed::operator = ( const Fixed &cp ) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPoint = cp.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}
