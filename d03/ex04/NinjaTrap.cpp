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


/* NinjaTrap &NinjaTrap::operator = ( NinjaTrap const &obj ) {
	this->_name = obj.getName();
	this->_hitPoints = obj.getHitPoints();
	this->_maxHitPoints = obj.getMaxHitPoints();
	this->_energy = obj.getEnergy();
	this->_maxEnergy = obj.getMaxEnergy();
	this->_level = obj.getLevel();
	this->_meleeAttackDamage = obj.getMeleeAttackDamage();
	this->_rangedAttackDamage = obj.getRangedAttackDamage();
	this->_armorDamageReduction = obj.getArmorDamageReduction();

	return *this;
} */

void NinjaTrap::rangedAttack(std::string const &target) {
	std::cout << std::endl << "NinjaTrap " << this->getName() << " attacks " << target
		<< " at range, causing " << this->getRangedAttackDamage() << " points of damage! \n";
}

void NinjaTrap::meleeAttack(std::string const &target) {
	std::cout << std::endl << "NinjaTrap " << this->getName() << " attacks " << target
		<< " at melee, causing " << this->getMeleeAttackDamage() << " points of damage! \n";
}

void NinjaTrap::ninjaShoebox(std::string const &target) {
	std::string attack[5] = \
	{
		" ninjaShoebox 1 ",
		" ninjaShoebox 2 ",
		" ninjaShoebox 3 ",
		" ninjaShoebox 4 ",
		" ninjaShoebox 5 "
	};

	if (this->getEnergy() > 25)
	{
		int r = rand() % 5;
		this->setEnergy(this->getEnergy() - 25);

		srand(time(NULL));
		std::cout << std::endl << "--== ninjaShoebox ==--" << std::endl;
		std::cout << "NinjaTrap " << this->getName() << attack[r]<< target << std::endl;
	}
	else
		std::cout << std::endl << "Not enough energy for attack\n";
}

void NinjaTrap::ninjaShoebox(ClapTrap const &target){
    this->ninjaShoebox(target.getName());
}

void NinjaTrap::ninjaShoebox(FragTrap const &target){
    this->ninjaShoebox(target.getName());
}

void NinjaTrap::ninjaShoebox(ScavTrap const &target){
    this->ninjaShoebox(target.getName());
}

void NinjaTrap::ninjaShoebox(NinjaTrap const &target){
    this->ninjaShoebox(target.getName());
}
