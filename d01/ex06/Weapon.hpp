#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon( std::string str );
		~Weapon ( void );

		std::string const getType( void );
		void setType ( std::string str );
};

#endif //WEAPON_HPP