#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon &w) : _name(name), _weapon(&w) { return; }
HumanA::HumanA(std::string name) : _name(name) { return; }
HumanA::~HumanA( void ) { return; }

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanA::setWeapon( Weapon &w)
{
	this->_weapon = &w;
}