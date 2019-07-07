#include "ScalarConversion.hpp"
#include "errno.h"

ScalarConversion::ScalarConversion() { return; }

ScalarConversion::ScalarConversion(std::string const &data) {
	_data = data;
}

ScalarConversion::ScalarConversion(ScalarConversion const &src) {
	*this = src;
}

ScalarConversion::~ScalarConversion(void) { return; }

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &rhs) {
	if (this != &rhs)
		_data = rhs._data;
	return (*this);
}

ScalarConversion::operator std::string const &(void) const {
	return (_data);
}

ScalarConversion::operator char(void) const {
	char	n = static_cast<char>(std::atoi(this->_data.c_str()));
	if (errno)
		throw (ImpossibleException());
	return (n);
}

ScalarConversion::operator int(void) const {
	int		n = std::atoi(this->_data.c_str());
	if (errno)
		throw (ImpossibleException());
	return (n);
}

ScalarConversion::operator float(void) const {
	return	static_cast<float>(std::atof(this->_data.c_str()));

}

ScalarConversion::operator double(void) const {
	return static_cast<double>(std::atof(this->_data.c_str()));
}



std::ostream &operator<<(std::ostream &os, ScalarConversion const &typestring) {
	os << static_cast<std::string const &>(typestring);
	return (os);
}


// ImpossibleException class

ScalarConversion::ImpossibleException::ImpossibleException( void ) { return; }
ScalarConversion::ImpossibleException::~ImpossibleException( void ) throw() { return; }
ScalarConversion::ImpossibleException::ImpossibleException(ImpossibleException const &src) {
	*this = src;
}
ScalarConversion::ImpossibleException	&ScalarConversion::ImpossibleException
	::operator=( ScalarConversion::ImpossibleException const & ) {
	return *this;
}
char const					*ScalarConversion::ImpossibleException::what(void) const throw() {
	return ("impossible");
}