#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("DETHault"), _hitPoints(0), _maxHitPoints(0), _energy(0), _maxEnergy(0), _level(0),
	  _meleeAttackDamage(0), _rangedAttackDamage(0), _armorDamageReduction(0)
{
	std::cout << "Born to be wild..." << std::endl;
	std::cout << "ClapTrap " << this->getName() << " constructed." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(0), _maxHitPoints(0), _energy(0), _maxEnergy(0), _level(0),
	  _meleeAttackDamage(0), _rangedAttackDamage(0), _armorDamageReduction(0)
{
	std::cout << "Born to be wild..." << std::endl;
	std::cout << "ClapTrap " << this->getName() << " constructed." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int maxHitPoints, int energy, int maxEnergy,
				   int level, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction)
	: _name(name), _hitPoints(hitPoints), _maxHitPoints(maxHitPoints), _energy(energy),_maxEnergy(maxEnergy),
	  _level(level), _meleeAttackDamage(meleeAttackDamage), _rangedAttackDamage(rangedAttackDamage),
	  _armorDamageReduction(armorDamageReduction)
{
	std::cout << "Born to be wild..." << std::endl;
	std::cout << "ClapTrap " << this->getName() << " constructed." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
	: _hitPoints(), _maxHitPoints(0), _energy(0), _maxEnergy(0), _level(0),
	  _meleeAttackDamage(0), _rangedAttackDamage(0), _armorDamageReduction(0)
{
	*this = obj;
	std::cout << "ClapTrap copied" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Wake me up before you go-go" << std::endl;
	std::cout << "ClapTrap destructed" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator = ( ClapTrap const &obj ) {
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
}

std::string ClapTrap::getName(void) const { return this->_name; }
int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
int ClapTrap::getMaxHitPoints(void) const { return this->_maxHitPoints; }
int ClapTrap::getEnergy(void) const { return this->_energy; }
int ClapTrap::getMaxEnergy(void) const { return this->_maxEnergy; }
int ClapTrap::getLevel(void) const { return this->_level; }
int ClapTrap::getMeleeAttackDamage(void) const { return this->_meleeAttackDamage; }
int ClapTrap::getRangedAttackDamage(void) const {return this->_rangedAttackDamage;}
int ClapTrap::getArmorDamageReduction(void) const { return this->_armorDamageReduction; }

void ClapTrap::setName(std::string name) { this->_name = name; }
void ClapTrap::setHitPoints(int value) { this->_hitPoints = value; }
void ClapTrap::setMaxHitPoints(int value) { this->_maxHitPoints = value; }
void ClapTrap::setEnergy(int value) { this->_energy = value; }
void ClapTrap::setMaxEnergy(int value) { this->_maxEnergy = value; }
void ClapTrap::setLevel(int value) { this->_level = value; }
void ClapTrap::setMeleeAttackDamage(int value) { this->_meleeAttackDamage = value; }
void ClapTrap::setRangedAttackDamage(int value) { this->_rangedAttackDamage = value; }
void ClapTrap::setArmorDamageReduction(int value) { this->_armorDamageReduction = value; }

void ClapTrap::rangedAttack(std::string const &target) {
	std::cout << "Can you run 850 ft/s? If not, your head better be bulletproof" << std::endl;
	std::cout << std::endl << "Claptrap " << this->getName() << " attacks " << target
		<< " at range, causing " << this->getRangedAttackDamage() << " points of damage! \n";
}

void ClapTrap::meleeAttack(std::string const &target) {
	std::cout << "I have two speeds: Walk and Kill" << std::endl;
	std::cout << std::endl << "Claptrap " << this->getName() << " attacks " << target
		<< " at melee, causing " << this->getMeleeAttackDamage() << " points of damage! \n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_energy != 0)
	{
        unsigned int	damage;

        damage = amount - this->getArmorDamageReduction();
        this->setEnergy(((int)damage > this->getEnergy()) ? 0 : this->getEnergy() - damage);
        std::cout << std::endl;
        if (this->getEnergy() == 0)
        {
            std::cout << "Impossibru!!!!111 " << std::endl;
            std::cout << "Claptrap " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
        else
        {
            std::cout << "Ouch...!!! Do it again ( ͡ᵔ ͜ ͡ᵔ )" << std::endl;
            std::cout << "Claptrap " << this->getName() << " health is now at " << this->getEnergy() << std::endl;
        }
    }
    else
		std::cout << std::endl << "Leave it. ClapTrap " << this->_name << " is dead. " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << std::endl;
	if (this->getEnergy() == 0)
		std::cout << "Can't be repared. " << this->getName() << " is dead (✖﹏✖) R.I.P" << std::endl;
	else if (this->getEnergy() == this->getMaxEnergy())
		std::cout << this->getName() << " HP is full" << std::endl;
	else
	{
		std::cout << this->getName() << " HP was: " << this->getEnergy();
		if ((this->getEnergy() + (int)amount) < this->getMaxEnergy())
			this->setEnergy(this->getEnergy() + amount);
		else
			this->setEnergy(this->getMaxEnergy());
		std::cout << ". It\'s repaired to " << this->getEnergy() << std::endl;
	}
}