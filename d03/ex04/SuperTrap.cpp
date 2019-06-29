#include <iostream>
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(void) {
	std::cout << "Contruction complite" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
	:  ClapTrap(name) 
{
   	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energy = 120;
	this->_maxEnergy = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src) {
	*this = src;
	std::cout << "Clonned !" << std::endl;
	return;
}

SuperTrap::~SuperTrap(void) {
	std::cout << "\033[38;5;130m";
	std::cout
		<< "             ____________________________________________________"					<< std::endl
		<< "            /                                                    \\"				<< std::endl
		<< "           |    _____________________________________________     |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |         it's now safe to turn off           |    |"				<< std::endl
		<< "           |   |               your computer                 |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |                                             |    |"				<< std::endl
		<< "           |   |_____________________________________________|    |"				<< std::endl
		<< "           |                                                      |"				<< std::endl
		<< "            \\_____________________________________________________/"				<< std::endl
		<< "                   \\_______________________________________/"						<< std::endl
		<< "                _______________________________________________"					<< std::endl
		<< "             _-\'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_"				<< std::endl
		<< "          _-\'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_"				<< std::endl
		<< "       _-\'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_"			<< std::endl
		<< "    _-\'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_"		<< std::endl
		<< " _-\'.-.-.-.-.-. .---.-. .-----------------------------. .-.---. .---.-.-.-.`-_"	<< std::endl
		<< ":-----------------------------------------------------------------------------:"	<< std::endl
		<< "`---._.-----------------------------------------------------------------._.---\'"	<< std::endl;
	std::cout << "\033[0m";
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs) {
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setMaxHitPoints(rhs.getMaxHitPoints());
	this->setEnergy(rhs.getEnergy());
	this->setMaxEnergy(rhs.getMaxEnergy());
	this->setRangedAttackDamage(rhs.getRangedAttackDamage());
	this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
	this->setArmorDamageReduction(rhs.getArmorDamageReduction());
	return *this;
}

void	SuperTrap::rangedAttack(std::string const & target) {
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target) {
	NinjaTrap::meleeAttack(target);	
}
