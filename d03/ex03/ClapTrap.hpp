#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <time.h>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _maxHitPoints;
		int _energy;
		int _maxEnergy;
		int _level;
		int _meleeAttackDamage;
		int _rangedAttackDamage;
		int _armorDamageReduction;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hitPoints, int maxHitPoints, int energy, int maxEnergy,
				 int level, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction);
		ClapTrap(ClapTrap const &);
		~ClapTrap(void);

		ClapTrap &operator=(ClapTrap const &);

		std::string getName(void) const;
		int         getHitPoints(void) const;
		int         getMaxHitPoints(void) const;
		int         getEnergy(void) const;
		int         getMaxEnergy(void) const;
		int         getLevel(void) const;
		int         getMeleeAttackDamage(void) const;
		int			getRangedAttackDamage(void) const;
		int			getArmorDamageReduction(void) const;
		
		void		setName(std::string);
		void		setHitPoints(int);
		void		setMaxHitPoints(int);
		void		setEnergy(int);
		void		setMaxEnergy(int);
		void		setLevel(int);
		void		setMeleeAttackDamage(int);
		void		setRangedAttackDamage(int);
		void		setArmorDamageReduction(int);

		void		rangedAttack(std::string const &target);
		void		meleeAttack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP