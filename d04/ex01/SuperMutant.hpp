#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant( void );
		SuperMutant( SuperMutant &obj );
		virtual ~SuperMutant();

		virtual void takeDamage(int);
		// SuperMutant &operator = ( SuperMutant const & obj );
};

#endif //SUPERMUTANT_HPP