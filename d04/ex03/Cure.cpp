#include "Cure.hpp"

Cure::Cure( void ) : AMateria("Cure") { return; }

Cure::Cure( Cure const &src) {
	*this = src;
}

Cure::~Cure(void) { return; }

AMateria        *Cure::clone(void) const {
	return (new Cure());
}

void    Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use(target);
}

Cure            &Cure::operator=(const Cure &obj) {
	// if (this != &obj)
		 this->setXP(obj.getXP());
	return (*this);
}