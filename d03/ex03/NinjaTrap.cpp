#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void )
	: ClapTrap("Nani", 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << std::endl << "NinjaTrap " << this->getName() << " constructed" << std::endl
			  << "Be ready I coming for you." << std::endl;
	return;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << std::endl << "NinjaTrap " << this->getName() << " destructed" << std::endl
			  << "Commits seppuku" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name)
	: ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << std::endl << "NinjaTrap " << this->getName() << " constructed" << std::endl
			  << "Be ready I coming for you." << std::endl;
	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void NinjaTrap::rangedAttack(std::string const &target) {
	std::cout << std::endl << "NinjaTrap " << this->getName() << " attacks " << target
		<< " at range, causing " << this->getRangedAttackDamage() << " points of damage! \n";
}

void NinjaTrap::meleeAttack(std::string const &target) {
	std::cout << std::endl << "NinjaTrap " << this->getName() << " attacks " << target
		<< " at melee, causing " << this->getMeleeAttackDamage() << " points of damage! \n";
}

void NinjaTrap::ninjaShoebox(ClapTrap &target) const{
    std::cout << "What’s the best thing about Switzerland? I don’t know, but the flag is a big plus." << std::endl;
    int r = rand() % 5;
    target.takeDamage(r * (5 + (rand() % 10)));
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)  const{
    std::cout << "How do you drown a hipster? Throw him in the mainstream." << std::endl;
    int r = rand() % 5;
    target.takeDamage(r * (5 + (rand() % 10)));
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)  const{
    std::cout << "What do you get when you cross an elephant with a rhino? Elephino." << std::endl;
    int r = rand() % 5;
    target.takeDamage(r * (5 + (rand() % 10)));
}

void NinjaTrap::ninjaShoebox(FragTrap &target)  const{
    std::cout << "Here is no jokes." << std::endl;
    int r = rand() % 5;
    target.takeDamage(r * (5 + (rand() % 10)));
}