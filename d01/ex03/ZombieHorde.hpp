#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
	private:
		Zombie **_z;
		int	_amount;
		
	public:
		ZombieHorde( int n);
		ZombieHorde( void );
		~ZombieHorde( void );

		void announce( void );
        std::string randomChump( void );
};

#endif //ZOMBIEHORDE_HPP