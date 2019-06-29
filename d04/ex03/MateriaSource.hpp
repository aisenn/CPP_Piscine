#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria            *_inventory[4];
        int                 _index;

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &src);
        ~MateriaSource(void);

        virtual void        learnMateria(AMateria *m);
        virtual AMateria    *createMateria(const std::string &type);

        MateriaSource       &operator=(const MateriaSource &rhs);
};

#endif //MATERIASOURCE_HPP