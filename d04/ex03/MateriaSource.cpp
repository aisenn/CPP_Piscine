#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _inventory(), _index(0) { return; }

MateriaSource::MateriaSource(const MateriaSource &src) {
    *this = src;
}

MateriaSource::~MateriaSource(void) { return; }

MateriaSource &MateriaSource::operator= (const MateriaSource &rhs) {
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i += 1)
        {
            this->_inventory[i] = NULL;
            this->_inventory[i] = rhs._inventory[0]->clone();
        }
        this->_index = rhs._index;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
    if (this->_index < 3)
    {
        this->_inventory[this->_index] = m;
        this->_index += 1;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    if (type == "ice")
    {
        return (new Ice());
    }
    else if (type == "cure")
    {
        return (new Cure());
    }
    return (NULL);
}
