#include "AMateria.hpp"

AMateria::AMateria( void ) { return; };

AMateria::AMateria(AMateria &obj) {
    *this = obj;
}

AMateria::AMateria(std::string const & type) : _type(type), xp_(0) { return; }
AMateria::~AMateria() { return; }

void AMateria::setType(std::string const &str) { this->_type = str; }
void AMateria::setXP( int xp ) { this->xp_ = xp; }
std::string const &AMateria::getType() const { return this->_type; }
unsigned int AMateria::getXP() const { return this->xp_; }

AMateria &AMateria::operator=(AMateria const & obj) {
    // if (this != &obj)
    {
        this->setXP(obj.xp_);
        this->setType(obj._type);
    }
    return (*this);
}

void	AMateria::use(ICharacter& target) {
    (void)target;
    // target.use(this->_index, target);
}