#include <iostream>
#include "Warrior.hpp"

Warrior::Warrior( void ) {
    std::cout << "Default constructer" << std::endl;
    return;
}

Warrior::Warrior( std::string name ) : Victim(name) {
    std::cout << "This is Sparta!!!" << std::endl;
}

Warrior::Warrior( Warrior &obj ) {
    *this = obj;
    std::cout << "Clone created" << std::endl;
}

Warrior::~Warrior( void ) {
    std::cout << "This is madness" << std::endl;
}

Warrior &Warrior::operator = (Warrior const & rhs) {
    this->setName(rhs.getName());
    return (*this);
}

void	Warrior::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a batterfly!" << std::endl;
}