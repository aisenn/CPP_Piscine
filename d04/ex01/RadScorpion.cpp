#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion" ) {
    std::cout << "* click click click *" << std::endl;
    return;
}

RadScorpion::RadScorpion( RadScorpion &obj ) {
    this->_hp = obj.getHP();
    this->_type = obj.getType();
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
    return;
}