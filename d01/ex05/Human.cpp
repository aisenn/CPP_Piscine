#include "Human.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Human::Human() : _brain(Brain()) { return; }
Human::~Human( void ) { return; }

const	Brain &Human::getBrain() const
{
	return this->_brain;
}

std::string	Human::identify() const
{
	return	(this->_brain.identify());
}