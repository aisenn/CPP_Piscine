#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50) {
    return;
}

PowerFist::PowerFist( PowerFist & obj ) {
    *this = obj;
}

void PowerFist::attack( void ) const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &PowerFist::operator = ( PowerFist const & obj ) {
    this->_name = obj.getName();
    this->_apcost = obj.getAPCost();
    this->_damage = obj.getDamage();
    
    return *this;
}