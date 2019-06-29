#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	std::cout << "\033[1;32m";
	std::cout << "--------------ScavTrap actions-----------------\n\n";
	std::string enemy = "SAM";
	ScavTrap t("Bill");

	t.meleeAttack(enemy);
	t.rangedAttack(enemy);
	t.takeDamage(10);
	t.challengeNewcomer(enemy);
	t.beRepaired(10);
	t.beRepaired(100);
	t.beRepaired(10);
	t.takeDamage(110);
	std::cout << "\033[0m";

	std::cout << "\033[1;95m";
	std::cout << "\n--------------FragTrap actions-----------------\n\n";
	enemy = "Tom";
	FragTrap a("Lee");

	a.meleeAttack(enemy);
	a.rangedAttack(enemy);
	a.takeDamage(10);
	a.vaulthunter_dot_exe(enemy);
	a.beRepaired(10);
	a.beRepaired(100);
	a.beRepaired(10);
	a.takeDamage(110);
	std::cout << "\033[0m";

	std::cout << "\033[1;96m";
	std::cout << "\n--------------ClapTrap actions-----------------\n\n";
	enemy = "Jack";
	ClapTrap b("Ryan");

	b.meleeAttack(enemy);
	b.rangedAttack(enemy);
	b.takeDamage(10);
	b.beRepaired(10);
	b.beRepaired(100);
	b.beRepaired(10);
	b.takeDamage(110);
	std::cout << "\033[0m";
	std::cout << "\033[1;33m";

	std::cout << "\n~~~~~ destructors calling ~~~~~\n";
	return (0);
}
