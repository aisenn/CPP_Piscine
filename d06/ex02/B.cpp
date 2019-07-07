#include "B.hpp"

B::B(void) {}

B::B(B const &src) {
	*this = src;
}

B::~B(void) {}

B &B::operator=(B const &) {
	return (*this);
}
