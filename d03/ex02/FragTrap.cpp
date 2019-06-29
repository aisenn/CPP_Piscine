#include "FragTrap.hpp"
# include "ClapTrap.hpp"

FragTrap::FragTrap( void )
	: ClapTrap("T2", 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << std::endl << "FR4G-TP " << this->getName() << " constructed" << std::endl
			  << "I live again." << std::endl;
	return;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << std::endl << "FR4G-TP " << this->getName() << " constructed" << std::endl
			  << "I live again." << std::endl;
	return;
}

FragTrap::FragTrap( const FragTrap &cp ) {
	std::cout << "Don't copy me!!! I am not perfect, but I am limited edition!!!!1111" << std::endl;
	*this = cp;
}

FragTrap::~FragTrap( void ) {
	std::cout << std::endl << "FR4G-TP " << this->getName() << " destructed" << std::endl
			  << "This piece of scap metal is going to make a nice washing machine." << std::endl;
	return;
}


FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::rangedAttack(std::string const &target) {
	std::cout << std::endl << "You're a dead man." << std::endl
			  << "FR4G-TP " << this->getName() << " attacks " << target
			  << " at range, causing " << this->getRangedAttackDamage() << " points of damage! \n";
}

void FragTrap::meleeAttack(std::string const &target) {
	std::cout << std::endl << "Fire in the hole!" << std::endl
			  << "FR4G-TP " << this->getName() << " attacks " << target
			  << " at melee, causing " << this->getMeleeAttackDamage() << " points of damage! \n";
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->getEnergy() != 0)
	{
        unsigned int	damage;

        damage = amount - this->getArmorDamageReduction();
        this->setEnergy((damage > (unsigned)this->getEnergy()) ? 0 : this->getEnergy() - damage);
        std::cout << std::endl;
        if (this->getEnergy() == 0)
        {
            std::cout << "Aghrrrrr... I\'m diyng" << std::endl;
            std::cout << "FR4G-TP " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
        else
        {
            std::cout << "Ouch!!! It\'s hurts" << std::endl;
            std::cout << "FR4G-TP " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
    }
    else
		std::cout << std::endl << "Leave it. FR4G-TP " << this->getName() << " is dead. " << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string attack[5] = \
	{
		" picks up a bubblegun: - Oh shit!",
		" picks up a stapler and says: - Don\'t move or I will shoot you!",
		" -I need your clothes, your boots and your motorcycle.",
		" -I have a Sword! (ᗒᗣᗕ)՞o==}::::::::::::>",
		" -Hua-ha-ha... You stepped on my mine. Don't even try to move or it will explode",
	};

	if (this->getEnergy() > 25)
	{
        srand(clock());
		int r = rand() % 5;
		this->setEnergy(this->getEnergy() - 25);

		std::cout << std::endl << "--== VaultHunter.EXE ==--" << std::endl;
		std::cout << "FR4G-TP " << this->getName() << attack[r] << std::endl;
		std::cout << target << " causing " << r * (5 + (rand() % 10)) << " points of damage! \n";
	}
	else
		std::cout << std::endl << "Not enough energy for attack\n";
}
