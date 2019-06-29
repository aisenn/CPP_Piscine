#include <iostream>
#include "Peon.hpp"

Peon::Peon( void ) { 
	std::cout << "Default constructor" << std::endl;
	return;
	}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & src) {
	*this = src;
	std::cout << "Clone created" << std::endl;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon &	Peon::operator=(Peon const & obj) {
	this->setName(obj.getName());
	return *this;
}

void	Peon::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
