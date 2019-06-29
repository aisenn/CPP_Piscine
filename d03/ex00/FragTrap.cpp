#include "FragTrap.hpp"

FragTrap::FragTrap( void ) 
	: _hitPoints(100), _maxHitPoints(100), _energy(100), _maxEnergy(100), _level(1),
	  _name("Nutter"), _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
	std::cout << std::endl << "FR4G-TP " << this->_name << " constructed" << std::endl
			  << "I live again." << std::endl;
	return;
}

FragTrap::FragTrap( std::string name )
	: _hitPoints(100), _maxHitPoints(100), _energy(100), _maxEnergy(100), _level(1),
	  _name(name), _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
	std::cout << std::endl << "FR4G-TP " << this->_name << " constructed" << std::endl
			  << "I live again." << std::endl;
	return;
}

FragTrap::FragTrap( const FragTrap &cp ) {
	std::cout << "Don't copy me!!! I am not perfect, but I am limited edition!!!!1111" << std::endl;
	*this = cp;
}

FragTrap::~FragTrap( void ) {
	std::cout << std::endl << "FR4G-TP " << this->_name << " destructed" << std::endl
			  << "This piece of scap metal is going to make a nice washing machine." << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
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

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->_name << " attacks " << target
			  << " at range, causing " << this->_rangedAttackDamage << " points of damage! \n";
}

void FragTrap::meleeAttack(std::string const & target) {
	std::cout << std::endl << "FR4G-TP " << this->_name << " attacks " << target
			  << " at melee, causing " << this->_meleeAttackDamage << " points of damage! \n";
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_energy != 0)
	{
		int	damage;

		damage = amount - this->_armorDamageReduction;
		this->_energy = (damage > this->_energy) ? 0 : this->_energy - damage;
		std::cout << std::endl;
		if (this->_energy == 0)
		{
			std::cout << "Aghrrrrr... I\'m dying" << std::endl;
			std::cout << "FR4G-TP " << this->_name << " health is now at " << this->_energy << std::endl;
		}
		else
		{
			std::cout << "Ouch!!! It hurts" << std::endl;
			std::cout << "FR4G-TP " << this->_name << " health is now at " << this->_energy << std::endl;
		}
	}
	else
		std::cout << std::endl << "Leave it. FR4G-TP " << this->_name << " is dead. " << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_energy == 0)
		std::cout << std::endl << "Can't be repared. FR4G-TP " << this->_name << " is dead. " << std::endl;
	else if (this->_energy == this->_maxEnergy)
		std::cout << std::endl << "FR4G-TP " << this->_name << " HP is full" << std::endl;
	else
	{
		std::cout << std::endl << "FR4G-TP " << this->_name << " HP was: " << this->_energy;
		if ((int)(this->_energy + amount) < this->_maxEnergy)
			this->_energy += amount;
		else
			this->_energy = this->_maxEnergy;
		std::cout << ". It\'s repaired to " << this->_energy << std::endl;
	}	
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

	if (this->_energy > 25)
	{
		int r = rand() % 5;
		this->_energy -= 25;

		srand(time(NULL));
		std::cout << std::endl << "--== VaultHunter.EXE ==--" << std::endl;
		std::cout << "FR4G-TP " << this->_name << attack[r] << std::endl;
		std::cout << target << " causing " << r * (5 + (rand() % 10)) << " points of damage! \n";
	}
	else
		std::cout << std::endl << "Not enough energy for attack\n";
}

int					FragTrap::getHitPoints() const { return this->_hitPoints; };
int         		FragTrap::getMaxHitPoints() const { return this->_maxHitPoints; };
int					FragTrap::getEnergyPoints() const { return this->_energy; };
int         		FragTrap::getMaxEnergyPoints() const { return this->_maxEnergy; };
int         		FragTrap::getLevel() const { return this->_level; };
const std::string	FragTrap::getName() const { return this->_name; };
int					FragTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; };
int					FragTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; };
int					FragTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; };