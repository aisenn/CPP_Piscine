#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main ( void )
{
	Zombie      *walker;
	Zombie      *white;
	ZombieEvent e;

	std::cout << "\n\033[35m           --=== newZombie ===--" << std::endl;
	std::cout << std::endl;
	e.setZombieType("walker");
	walker = e.newZombie("Jonathan");
	walker->announce();
	delete walker;

	std::cout << std::endl;
	e.setZombieType("white walker");
	white = e.newZombie("Ryan");
	white->announce();
	delete white;

	std::cout << "\n\033[33m           --=== randomChump ===--" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		e.randomChump();
		std::cout << std::endl;
	}

	std::cout << "\033[36m           --=== Zombie in the stack ===--" << std::endl;
	std::cout << std::endl;
	Zombie w("Bim(✖╭╮✖)", "Bummer");
	w.announce();

	return (0);
}