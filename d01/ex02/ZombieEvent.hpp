#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string _type;
		
	public:
		ZombieEvent( void );
		~ZombieEvent( void );

		void		setZombieType( std::string type );
		Zombie*		newZombie( std::string name );
		void		randomChump( void );
};

#endif //ZOMBIEEVENT_HPP