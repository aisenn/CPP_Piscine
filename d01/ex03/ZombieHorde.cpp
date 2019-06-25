#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _z(new Zombie * [n]), _amount(n)
{
	for (int i = 0; i < n; i++)
		this->_z[i] = new Zombie(this->randomChump(), "Horde"); 
	return ;
}

ZombieHorde::ZombieHorde( void ) { return; }

ZombieHorde::~ZombieHorde( void )
{
	for (int i = 0; i < this->_amount; i++)
		delete this->_z[i];
	delete [] this->_z;
	return;
}

void ZombieHorde::announce( void )
{
	for(int i = 0; i < this->_amount; i++)
		this->_z[i]->announce();
}

std::string ZombieHorde::randomChump( void )
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
	return (name);
}