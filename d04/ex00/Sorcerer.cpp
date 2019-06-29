#include <iostream>
#include <fstream>
#include <sstream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ) { 
	std::cout << "Default constructor" << std::endl;
	return; }
Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer &obj) : _name(obj._name), _title(obj._title) { return; }

Sorcerer::~Sorcerer(void) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &	Sorcerer::operator=(Sorcerer const & obj) {
	this->setName(obj.getName());
	this->setTitle(obj.getTitle());
	return (*this);
}

std::string	Sorcerer::introduce(void) const {
	std::string output;

	output = "I am "	+ this->getName() + ", " + this->getTitle() + ", and I like ponies !";
	return output;
}

void	Sorcerer::polymorph(Victim const & obj) const {
	obj.getPolymorphed();
}

void	Sorcerer::setName(std::string name) { this->_name = name; }
void	Sorcerer::setTitle(std::string title) { this->_title = title; }

std::string Sorcerer::getName(void) const { return this->_name; }
std::string Sorcerer::getTitle(void) const { return this->_title; }

std::ostream	&operator<<(std::ostream & lhs, Sorcerer const & obj) {
	lhs << obj.introduce();
	lhs << std::endl;
	return lhs;
}
