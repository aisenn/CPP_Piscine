#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") { return; }

Ice::Ice( Ice const &obj ) {
    *this = obj;
}

Ice::~Ice(void) { return; }

AMateria        *Ice::clone(void) const {
    return (new Ice());
}

void    Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}

Ice            &Ice::operator=(const Ice &obj) {
    // if (this != &rhs)
        this->setXP(obj.getXP());
    return (*this);
}