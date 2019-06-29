#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <time.h>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap( void );
		ScavTrap(std::string name);
        ScavTrap( const ScavTrap &cp );
		~ScavTrap( void );
		
        ScavTrap &operator=(ScavTrap const &rhs);

		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int amount);
		void challengeNewcomer(std::string const & target);
};

#endif //SCAVTRAP_HPP