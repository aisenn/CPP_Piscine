#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "SuperTrap.hpp"
#include "iomanip"


void compare(SuperTrap &super)
{
	std::cout << "\033[1;36m";
	std::cout << "\n-------------- comparison Ninja & FragTrap created ---------------\n";
	NinjaTrap n("LieXin");
	FragTrap f("100010001");

	std::cout << "\nAttributes        SuperTrap           FragTrap           NinjaTrap\n"
		<< std::left << std::setw(20) << "Name:"			<< super.getName() << std::endl
		<< std::left << std::setw(20) << "HitPoints:"		<< super.getHitPoints() << std::right << std::setw(20)				<< f.getHitPoints() << std::endl
		<< std::left << std::setw(20) << "MaxHitPoints:"	<< super.getMaxHitPoints() << std::right << std::setw(20)			<< f.getMaxHitPoints() << std::endl
		<< std::left << std::setw(20) << "Energy:"			<< super.getEnergy() << std::right << std::setw(40)					<< n.getEnergy() << std::endl
		<< std::left << std::setw(20) << "MaxEnergy:"		<< super.getMaxEnergy() << std::right << std::setw(40)				<< n.getMaxEnergy() << std::endl
		<< std::left << std::setw(20) << "MeleeAttack:"		<< super.getMeleeAttackDamage() << std::right << std::setw(40)		<< n.getMeleeAttackDamage() << std::endl
		<< std::left << std::setw(20) << "RangedAttack:"	<< super.getRangedAttackDamage() << std::right << std::setw(20)		<< f.getRangedAttackDamage() << std::endl
		<< std::left << std::setw(20) << "DamageReduction:" << super.getArmorDamageReduction() << std::right << std::setw(20)	<< f.getArmorDamageReduction() << std::endl;
	
	super.rangedAttack	("\033[1;31m Super's attack \033[1;36m");
	n.rangedAttack		("\033[1;31m Ninja's attack \033[1;36m");

	super.meleeAttack	("\033[1;31m Super's attack \033[1;36m");
	f.meleeAttack		("\033[1;31m Frag's attack \033[1;36m");

	super.takeDamage(10);
	super.vaulthunter_dot_exe("Super");
	super.ninjaShoebox(n);
	std::cout << "\033[1;95m";
	std::cout << "\n~~~~~~~~~~~ destructors for comaparison objects calling ~~~~~~~~~~\n";
}

int main( void )
{
	std::cout << "\033[1;32m";
	std::cout << "\n---------------------- SuperTrap creating ------------------------\n";

	SuperTrap super("Super");
	compare(super);

	std::cout << "\033[1;93m";
	std::cout << "\n~~~~~~~~~~~~~~~~ SuperTrap destructors calling ~~~~~~~~~~~~~~~~~~~~\n";
	return (0);
}
