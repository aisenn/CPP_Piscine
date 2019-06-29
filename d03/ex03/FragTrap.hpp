#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <time.h>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap( void );
		FragTrap( std::string );
		FragTrap( const FragTrap & );
		~FragTrap( void );
		
		FragTrap &operator = ( FragTrap const & );

		void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int amount);

		void vaulthunter_dot_exe(std::string const & target);
};

#endif //FRAGTRAP_HPP