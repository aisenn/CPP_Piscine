#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant" ) {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

SuperMutant::SuperMutant( SuperMutant &obj ) {
    this->_hp = obj.getHP();
    this->_type = obj.getType();
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
    return;
}

void SuperMutant::takeDamage( int damage ) {
    damage -= 3;
    if (damage > 0)
        this->_hp -= damage;
}