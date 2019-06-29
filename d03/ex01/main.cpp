#include "ScavTrap.hpp"
#include "iomanip"

std::string healthBar(int hp, int maxHP, int changes)
{
	int percent = (hp / (maxHP / 50));
	changes = (changes + hp) <= maxHP ? changes : (maxHP - hp);
	int c = (changes / (maxHP / 50));
	char f = changes < 0 ? '-' : '+';
	int tmp = percent + c;
	tmp = tmp >= 0 ? tmp : 0;
	c = c >= 0 ? c : -c;
	if (changes >= 0)
	{
		std::string str = std::string(percent, '#') + std::string(c, f);
		std::cout << "["  << str << std::setfill('.') << std::setw(50 - tmp);
	}
	else
	{
		std::string str = std::string(tmp, '#') + std::string(c, f);
		std::cout << "[" << str  << std::setfill('.') << std::setw(50 - c);
	}
	std::cout << "] " << maxHP / 50 * tmp << '%' << std::endl;
	return ("");
}

int main( void )
{
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

    // healthBar(50, 100, +10);
    // healthBar(50, 100, +100);
    // healthBar(50, 100, -100);
    // healthBar(50, 100, -10);
	return (0);
    
}
