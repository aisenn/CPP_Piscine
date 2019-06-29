#include <iostream>
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src) {
	*this = src;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I'll be back ..." << std::endl;
}

void	AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void	AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void	AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

ISpaceMarine * AssaultTerminator::clone() const {
	return new AssaultTerminator;
}

AssaultTerminator	&	AssaultTerminator::operator=(AssaultTerminator const & rhs) {
	if(this != &rhs)
		*this = rhs;
	return *this;
}