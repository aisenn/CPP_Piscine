#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB( std::string str, Weapon &w );
		HumanB( std::string name );
		~HumanB( void );
		void attack( void );
		void setWeapon( Weapon &w ); 
};

#endif //HUMANB_HPP