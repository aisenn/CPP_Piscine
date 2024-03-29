#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
	*this = src;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
}

void	TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

ISpaceMarine * TacticalMarine::clone() const {
	return new TacticalMarine;
}

TacticalMarine	&	TacticalMarine::operator=(TacticalMarine const & rhs) {
	if(this != &rhs)
		*this = rhs;
	return *this;
}