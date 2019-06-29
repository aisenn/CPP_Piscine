#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character
{
	private:
		std::string _name;
		int _ap;
		AWeapon *_weapon;

		Character( void );

	public:
		Character( std::string const & name );
		Character( Character &obj );
		~Character();

		void recoverAP();
		void equip( AWeapon* );
		void attack( Enemy* );

		std::string const &getName() const;
		AWeapon *getWeapon() const;
		int getAp() const;

		Character &operator = (Character const & obj);
};

std::ostream &operator << (std::ostream & lhs, Character const & rhs);



#endif //CHARACTER_HPP

