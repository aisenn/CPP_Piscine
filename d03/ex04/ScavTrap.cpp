#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) 
	: ClapTrap( "WTF", 100, 100, 50, 50, 1, 20, 15, 3 ) 
{
	std::cout << std::endl << "ScavTrap " << this->getName() << " constructed" << std::endl
			  << "Here we go again." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap( name, 100, 100, 50, 50, 1, 20, 15, 3)  
{
	std::cout << std::endl << "ScavTrap " << this->getName() << " constructed" << std::endl
			  << "Here we go again." << std::endl;
	return;
}

ScavTrap::ScavTrap( const ScavTrap &cp ) {
	std::cout << "Copy was made" << std::endl;
	*this = cp;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "Self destruction in \n";
	for (int i = 3; i != 0; i--)
	{
		for (int j = 0; j < 1000000000; j++)
        ;
        std::cout << i  << std::endl;
	}
	std::cout << "ScavTrap " << this->getName() << " destructed" << std::endl
			  << "Ehh... Whatever." << std::endl;

	return;
}

ScavTrap		&ScavTrap::operator=(ScavTrap const	&rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << std::endl << "Ka-ching! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl
			  << "ScavTrap " << this->getName() << " attacks " << target
			  << " at range, causing " << this->getRangedAttackDamage() << " points of damage! \n";
}

void ScavTrap::meleeAttack(std::string const &target) {
	std::cout << std::endl << "Red is definitely your colour..." << std::endl
			  << "ScavTrap " << this->getName() << " attacks " << target
			  << " at melee, causing " << this->getMeleeAttackDamage() << " points of damage! \n";
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->getEnergy() != 0)
	{
        unsigned int	damage;

        damage = amount - this->getArmorDamageReduction();
        this->setEnergy((damage > (unsigned)this->getEnergy()) ? 0 : this->getEnergy() - damage);
        std::cout << std::endl;
        if (this->getEnergy() == 0)
        {
            std::cout << "I'll be back as one of my Kirby friends. They will hunt you forever. Revenge must be served cold. " << std::endl;
            std::cout << "ScavTrap " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
        else
        {
            std::cout << "System detected damage" << std::endl;
            std::cout << "ScavTrap " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
    }
    else
		std::cout << std::endl << "Leave it. FR4G-TP " << this->getName() << " is dead. " << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::string challenge[5] = \
	{
		" Name a colour without the letter E in it",
		" Now here is the ring. And take it to Mordor",
		" Find a dog. Teach it C++",
		" Smash your iPhone. Try not to cry",
		" Press RESET button on the nearby Mac",
	};

	if (this->getEnergy() > 25)
	{
        srand(time(NULL));
		int r = rand() % 5;
		this->setEnergy(this->getEnergy() - 25);

		std::cout << std::endl << "--== challengeNewcomer ==--" << std::endl;
		std::cout << this->getName() << ": - hey " << target << ". "<< challenge[r] << std::endl;
	}
	else
		std::cout << std::endl << "Not enough energy for challenge\n";
	
}
