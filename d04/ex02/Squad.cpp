#include <iostream>
#include "Squad.hpp"

int Squad::_unitsAmount = 0;

Squad::Squad( void ) : _marinesSquad(NULL), _next(NULL) { return; }

Squad::Squad( Squad &obj ) {
	*this = obj;
}

Squad::~Squad( void ) {
	delete this->_marinesSquad;
	delete this->_next;
}

int Squad::getCount() const {
	return (Squad::_unitsAmount);
}

ISpaceMarine *Squad::getUnit(int n) const {
	
	if (n >= 0 && n < this->getCount())
	{
		if (n == 0)
			return this->_marinesSquad;
		else
			return this->_next->Squad::getUnit(n - 1);
	}
	else
		return NULL;
}

int	Squad::push(ISpaceMarine *objToAdd) {
	Squad*	tmp = this;

	while (tmp->_next)
	{
		if (tmp->_marinesSquad == objToAdd)
			return (Squad::_unitsAmount);
		tmp = tmp->_next;
	}
	if (objToAdd != NULL && tmp->_marinesSquad == NULL)
	{
		tmp->_marinesSquad = objToAdd;
		tmp->_next = new Squad;
		Squad::_unitsAmount += 1;
	}
	return (Squad::_unitsAmount);
}

Squad	&Squad::operator=(Squad const & rhs) {
	this->_marinesSquad = rhs.getUnit(Squad::_unitsAmount);
	this->_next = rhs._next;
	return *this;
}