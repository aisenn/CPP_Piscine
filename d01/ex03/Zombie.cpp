#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name, std::string type) : _name(name), _type(type) { return; }
Zombie::Zombie( void ) { return; }

Zombie::~Zombie( void )
{
	std::cout << "Goodbye " << this->_name << std::endl;
	return;
};

void Zombie::announce( void )
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}