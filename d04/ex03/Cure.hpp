#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure( void );
        Cure( Cure const & );
        ~Cure(void);

        AMateria        *clone(void) const;
        virtual void    use(ICharacter &target);

        Cure            &operator= (const Cure &rhs);
};

#endif //CURE_HPP