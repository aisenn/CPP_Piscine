#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5, 21) {
    return;
}

PlasmaRifle::PlasmaRifle( PlasmaRifle & obj ) {
    *this = obj;
}

void PlasmaRifle::attack( void ) const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle &PlasmaRifle::operator = ( PlasmaRifle const & obj ) {
    this->_name = obj.getName();
    this->_apcost = obj.getAPCost();
    this->_damage = obj.getDamage();
    
    return *this;
}