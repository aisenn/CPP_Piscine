#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <time.h>

class FragTrap
{
	private:
		int         _hitPoints;
		int         _maxHitPoints;
		int         _energy;
		int         _maxEnergy;
		int         _level;
		std::string _name;
		int         _meleeAttackDamage;
		int         _rangedAttackDamage;
		int         _armorDamageReduction;

	public:
		FragTrap( void );
		FragTrap( std::string );
		FragTrap( const FragTrap & );
		~FragTrap( void );

		FragTrap &operator = ( FragTrap const & );

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);

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

#endif //FRAGTRAP_HPP