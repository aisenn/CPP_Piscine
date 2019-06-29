#include "Character.hpp"

Character::Character(void) { return; }

Character::Character(const std::string &name)
    : _name(name), _inventory(), _index(0) {
    return;
}

Character::Character(const Character &src) {
    *this = src;
}

Character::~Character(void) { return; }

Character &Character::operator= (const Character &rhs) {
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_index = rhs._index;
        for (int i = 0; i < 4; i += 1)
        {
            this->_inventory[i] = NULL;
            this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return (*this);
}

const std::string &Character::getName(void) const { return (this->_name); }

void Character::equip(AMateria *m) {
    if (this->_index < 3)
    {
        this->_inventory[this->_index] = m;
        this->_index += 1;
    }
    return ;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx <= 3)
        this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < this->_index)
        this->_inventory[idx]->use(target);
}