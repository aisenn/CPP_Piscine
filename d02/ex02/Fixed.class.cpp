#include "Fixed.class.hpp"

int const Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _fixedPoint(0) {
	return;
}

Fixed::Fixed( const int input ) {
    this->_fixedPoint = input * (1 << this->_fractBits);
}

Fixed::Fixed( const float input ) {
    this->_fixedPoint = roundf(input * (1 << this->_fractBits));
}

Fixed::~Fixed( void ) {
	return;
}

Fixed::Fixed( const Fixed &cp ) {
	*this = cp;
}

Fixed &Fixed::operator = ( const Fixed &cp ) {
	this->_fixedPoint = cp.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw ){
	this->_fixedPoint = raw;
}

float Fixed::toFloat( void ) const {
    return (this->_fixedPoint / roundf(1 << this->_fractBits));
}

int Fixed::toInt( void ) const {
    return (this->_fixedPoint / (1 << this->_fractBits));
}

std::ostream &operator << ( std::ostream &output, const Fixed &ref ) {
    output << ref.toFloat();
    return output;
}

//-----------
bool Fixed::operator > ( const Fixed &ref) { return (ref.getRawBits() > this->_fixedPoint); }
bool Fixed::operator < ( const Fixed &ref) { return (ref.getRawBits() < this->_fixedPoint); }
bool Fixed::operator >= ( const Fixed &ref) { return (ref.getRawBits() >= this->_fixedPoint); }
bool Fixed::operator <= ( const Fixed &ref) { return (ref.getRawBits() <= this->_fixedPoint); }
bool Fixed::operator == ( const Fixed &ref) { return (ref.getRawBits() == this->_fixedPoint); }
bool Fixed::operator != ( const Fixed &ref) { return (ref.getRawBits() != this->_fixedPoint); }

//calls new constructer
// Fixed Fixed::operator + ( const Fixed &ref) const { return (Fixed(this->toFloat() + ref.toFloat())); }
// Fixed Fixed::operator - ( const Fixed &ref) const { return (Fixed(this->toFloat() - ref.toFloat())); }
// Fixed Fixed::operator / ( const Fixed &ref) const { return (Fixed(this->toFloat() / ref.toFloat())); }
// Fixed Fixed::operator * ( const Fixed &ref) const { return (Fixed(this->toFloat() * ref.toFloat())); }

Fixed &Fixed::operator+(const Fixed &copy) {
    this->_fixedPoint += copy.getRawBits();
    return (*this);
}

Fixed &Fixed::operator-(const Fixed &copy) {
    this->_fixedPoint -= copy.getRawBits();
    return (*this);
}

Fixed &Fixed::operator*(const Fixed &copy) {
    this->_fixedPoint *= copy.toFloat();
    return (*this);
}

Fixed &Fixed::operator/(const Fixed &copy) {
    this->_fixedPoint /= copy.toFloat();
    return (*this);
}

Fixed &Fixed::operator ++ ( void ) {
	++this->_fixedPoint;
	return (*this);
}

Fixed &Fixed::operator -- ( void ) {
	--this->_fixedPoint;
	return (*this);
}

Fixed Fixed::operator ++ ( int ) {
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator -- ( int ) {
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}


Fixed &Fixed::max( Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed &Fixed::min( Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}