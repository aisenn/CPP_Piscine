#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(void) { return; }

AWeapon::AWeapon( std::string const & name, int apcost, int damage )
    : _name(name), _apcost(apcost), _damage(damage) {
    return;
}

AWeapon::AWeapon( AWeapon &obj) {
    *this = obj;
}

AWeapon::~AWeapon( void ) { return; }

std::string const &AWeapon::getName() const { return this->_name; }
int         AWeapon::getAPCost() const { return this->_apcost; }
int         AWeapon::getDamage() const { return this->_damage; }

AWeapon &AWeapon::operator = ( AWeapon const & obj ) {
    this->_name = obj.getName();
    this->_apcost = obj.getAPCost();
    this->_damage = obj.getDamage();

    return *this;
}
