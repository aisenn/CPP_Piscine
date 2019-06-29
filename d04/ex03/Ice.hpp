#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice( void );
        Ice( Ice const & );
        ~Ice(void);

        AMateria        *clone(void) const;
        virtual void    use(ICharacter &target);

        Ice            &operator= (const Ice &rhs);
};

#endif //ICE_HPP