#include "ZombieEvent.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

ZombieEvent::ZombieEvent( void )
{
	srand(time(NULL));
	this->_type = "Smoker";
	return;
}
ZombieEvent::~ZombieEvent( void ) { return; }

void ZombieEvent::setZombieType( std::string type)
{
	this->_type = type;
}

Zombie* ZombieEvent::newZombie( std::string name )
{
	return (new Zombie(name, this->_type));
}

void ZombieEvent::randomChump( void )
{
	char		vowels[] = {'a','e','i','o','u','y'};
	char		consonants[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	std::string	name = "";
	int			length = 3 + (rand() % 5);
  	bool		count = rand() % 2;

	for(int i = 0; i < length; i++)
	{
		if(count)
			name = name + consonants[rand() % 19];
		else
			name = name + vowels[rand() % 5];
		count = !count;
	}
	name[0] = toupper(name[0]);
	
	Zombie		z(name, "randomChump");
	z.announce();
}
