#include <iostream>
#include <sstream>
#include "Character.hpp"

Character::Character( void ) { return; }

Character::Character(std::string const & name) : _name(name), _ap(40), _weapon(NULL) {
	return;
}

Character::Character( Character & obj ) {
	*this = obj;
}

Character::~Character() { 
	std::cout << "Weapon " << this->getName() << " destroyed."  << std::endl;
}

void Character::recoverAP( void ) {
	int res = this->getAp() + 10;
	this->_ap = res < 40 ? res : 40;
}

void Character::equip( AWeapon *weapon ) {
	this->_weapon = weapon;
}

void	Character::attack( Enemy *enemy ) {
	if (this->getWeapon() != NULL)
	{
		if (this->getAp() >= this->getWeapon()->getAPCost())
		{
			std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
			this->getWeapon()->attack();
			this->_ap -= this->getWeapon()->getAPCost();
			enemy->takeDamage(this->getWeapon()->getDamage());
			if (enemy->getHP() == 0)
				delete enemy;
		}
	}
}

std::string const &Character::getName() const { return this->_name; }
AWeapon *Character::getWeapon() const { return this->_weapon; }
int Character::getAp() const { return this->_ap; }

Character &Character::operator = (Character const & obj) {
	this->_name = obj.getName();
	this->_ap = obj.getAp();
	this->_weapon = obj.getWeapon();

	return *this;
}

std::ostream &operator << (std::ostream & lhs, Character const & rhs) {
	if (rhs.getWeapon() == NULL)
	{
		lhs << rhs.getName() << " has " << rhs.getAp() << " AP and is unarmed" << std::endl;
	}
	else
	{
		lhs << rhs.getName() << " has " << rhs.getAp() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	}
	return lhs;
}