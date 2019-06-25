#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name, Weapon &w) : _name(name), _weapon(&w) { return; }
HumanB::HumanB(std::string name) : _name(name) { return; }
HumanB::~HumanB( void ) { return; }

void HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &w)
{
	this->_weapon = &w;
}