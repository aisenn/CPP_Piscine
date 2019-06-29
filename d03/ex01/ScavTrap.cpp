#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) 
	: _hitPoints(100), _maxHitPoints(100), _energy(50), _maxEnergy(50), _level(1),
	  _name("WTF"), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
	std::cout << std::endl << "SC4V-TP " << this->_name << " constructed" << std::endl
			  << "Here we go again." << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string name )
	: _hitPoints(100), _maxHitPoints(100), _energy(50), _maxEnergy(50), _level(1),
	  _name(name), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
	std::cout << std::endl << "SC4V-TP " << this->_name << " constructed" << std::endl
			  << "Here we go again." << std::endl;
	return;
}

ScavTrap::ScavTrap( const ScavTrap &cp ) {
	std::cout << "Copy was made" << std::endl;
	*this = cp;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << std::endl << "SC4V-TP " << this->_name << " destructed" << std::endl
			  << "Ehh... Whatever." << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	this->_hitPoints = rhs.getHitPoints();
	this->_maxHitPoints = rhs.getMaxHitPoints();
	this->_energy = rhs.getEnergyPoints();
	this->_maxEnergy = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getRangedAttackDamage();
	this->_armorDamageReduction = rhs.getArmorDamageReduction();

	return *this;
}

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << std::endl << "Ka-ching! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl
			  << "ScavTrap " << this->_name << " attacks " << target
			  << " at range, causing " << this->_rangedAttackDamage << " points of damage! \n";
}

void ScavTrap::meleeAttack(std::string const &target) {
	std::cout << std::endl << "Red is definitely your colour..." << std::endl
			  << "ScavTrap " << this->_name << " attacks " << target
			  << " at melee, causing " << this->_rangedAttackDamage << " points of damage! \n";
}


void ScavTrap::takeDamage(unsigned int amount) {
    if (this->_energy != 0)
	{
        unsigned int	damage;

        damage = amount - this->_armorDamageReduction;
        this->_energy = (damage > (unsigned)this->_energy) ? 0 : this->_energy - damage;
        std::cout << std::endl;
        if (this->_energy == 0)
        {
            std::cout << "I'll be back as one of my Kirby friends. They will hunt you forever. Revenge must be served cold. " << std::endl;
            std::cout << "ScavTrap " << this->_name << " health is now at " << this->_energy << std::endl;
        }
        else
        {
            std::cout << "System detected damage" << std::endl;
            std::cout << "ScavTrap " << this->_name << " health is now at " << this->_energy << std::endl;
        }
    }
    else
		std::cout << std::endl << "Leave it. FR4G-TP " << this->_name << " is dead. " << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energy == 0)
		std::cout << std::endl << "Can't be repared. ScavTrap " << this->_name << " is dead. " << std::endl;
	else if (this->_energy == this->_maxEnergy)
		std::cout << std::endl << "ScavTrap " << this->_name << " HP is full" << std::endl;
	else
	{
		std::cout << std::endl << "ScavTrap " << this->_name << " HP was: " << this->_energy;
		if ((int)(this->_energy + amount) < this->_maxEnergy)
			this->_energy += amount;
		else
			this->_energy = this->_maxEnergy;
		std::cout << ". It\'s repaired to " << this->_energy << std::endl;
	}	
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

	if (this->_energy > 25)
	{
		int r = rand() % 5;
		this->_energy -= 25;

		srand(time(NULL));
		std::cout << std::endl << "--== challengeNewcomer ==--" << std::endl;
		std::cout << this->_name << ": - hey " << target << ". "<< challenge[r] << std::endl;
	}
	else
		std::cout << std::endl << "Not enough energy for challenge\n";
}

int					ScavTrap::getHitPoints() const { return this->_hitPoints; };
int         		ScavTrap::getMaxHitPoints() const { return this->_maxHitPoints; };
int					ScavTrap::getEnergyPoints() const { return this->_energy; };
int         		ScavTrap::getMaxEnergyPoints() const { return this->_maxEnergy; };
int         		ScavTrap::getLevel() const { return this->_level; };
const std::string	ScavTrap::getName() const { return this->_name; };
int					ScavTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; };
int					ScavTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; };
int					ScavTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; };
