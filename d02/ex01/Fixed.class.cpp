#include "Fixed.class.hpp"

int const Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int input ) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint = input * (1 << this->_fractBits);
}

Fixed::Fixed( const float input ) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPoint = roundf(input * (1 << this->_fractBits));
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
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}

float Fixed::toFloat( void ) const {
    return (this->_fixedPoint / roundf(1 << this->_fractBits));
}

int Fixed::toInt( void ) const {
    return (this->_fixedPoint / (1 << this->_fractBits));
}

std::ostream &operator << ( std::ostream &output, const Fixed &rhs ) {
    output << rhs.toFloat();
    return output;
}
