#include <iostream>
#include <fstream>
#include "Victim.hpp"

Victim::Victim( void ) { 
	std::cout << "Default constructor" << std::endl;
	return;
}

Victim::Victim( std::string name ) : _name(name) {
	std::cout << "Some random victim called " << this->getName() << " just popped." << std::endl;
}

Victim::Victim( Victim & src ) {
	*this = src;
	std::cout << "Copy contructor called" << std::endl;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator = ( Victim const & obj ) {
	this->setName(obj.getName());
	return *this;
}

std::string	Victim::introduce( void ) const {
	return ("I am " + this->getName() + " and I like otters!");
}

void Victim::getPolymorphed( void ) const {
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

void Victim::setName( std::string name ) {
	this->_name = name;
}

std::string Victim::getName( void ) const {
	return this->_name;
}

std::ostream &operator << ( std::ostream & output, Victim const & obj ) {
	output << obj.introduce() << std::endl;
	return output;
}
