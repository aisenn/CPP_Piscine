#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "Ice.hpp"
# include "Cure.hpp"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string                 _name;
        AMateria*                   _inventory[4];
        int                         _index;

    public:
        Character(void);
        Character(const std::string &name);
        Character(const Character &src);
        ~Character(void);

        virtual void                equip(AMateria* m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);
        virtual const std::string   &getName() const;

        Character                   &operator= (const Character &rhs);
};

#endif //CHARACTER_HPP