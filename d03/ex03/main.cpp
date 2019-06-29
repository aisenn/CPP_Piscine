#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
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
	std::cout << "\033[1;32m";
	std::cout << "--------------NinjaTrap actions-----------------\n\n";
	std::string enemy = "SAM";
	FragTrap Frag("One");
	ScavTrap Scav("Two");
	ClapTrap Clap("Three");

	NinjaTrap t("Bill");

	t.meleeAttack(enemy);
	t.rangedAttack(enemy);
	t.takeDamage(10);
	t.ninjaShoebox(Frag);
	t.ninjaShoebox(Scav);
	t.ninjaShoebox(Clap);
	t.beRepaired(100);
	t.ninjaShoebox(t);
	t.beRepaired(10);
	t.beRepaired(100);
	t.beRepaired(10);
	t.takeDamage(110);

	std::cout << "\033[1;95m";
	std::cout << "\n~~~~~ destructors calling ~~~~~\n";
	return (0);
}
