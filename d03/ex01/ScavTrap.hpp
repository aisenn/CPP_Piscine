#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <time.h>

class ScavTrap
{
	private:
		int _hitPoints;
		int _maxHitPoints;
		int _energy;
		int _maxEnergy;
		int _level;
		std::string _name;
		int _meleeAttackDamage;
		int _rangedAttackDamage;
		int _armorDamageReduction;

	public:
		ScavTrap( void );
		ScavTrap( std::string );
        ScavTrap( const ScavTrap &cp );
		~ScavTrap( void );

        ScavTrap &operator=(ScavTrap const &rhs);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);

        int					getHitPoints() const;
		int         		getMaxHitPoints() const;
		int					getEnergyPoints() const;
		int         		getMaxEnergyPoints() const;
		int         		getLevel() const;
		const std::string	getName() const;
		int					getMeleeAttackDamage() const;
		int					getRangedAttackDamage() const;
		int					getArmorDamageReduction() const;
};

#endif //SCAVTRAP_HPP