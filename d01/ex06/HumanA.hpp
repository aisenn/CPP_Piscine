#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanA( std::string str, Weapon &w );
		HumanA( std::string name );
		~HumanA( void );
		void attack( void );
		void setWeapon( Weapon &w ); 
};

#endif //HUMANA_HPP