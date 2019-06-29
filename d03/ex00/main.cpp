#include "FragTrap.hpp"

int main( void )
{
	std::string enemy = "SAM";
	FragTrap t("Bill");

	t.meleeAttack(enemy);
	t.rangedAttack(enemy);
	t.takeDamage(10);
	t.vaulthunter_dot_exe(enemy);
	t.beRepaired(10);
	t.beRepaired(100);
	t.beRepaired(10);
	t.takeDamage(110);

    t.beRepaired(10);
    t.takeDamage(-10);
	return (0);
}