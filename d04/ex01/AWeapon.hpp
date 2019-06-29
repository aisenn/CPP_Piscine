#ifndef AWEAPON_HPP
# define AWEAPON_HPP

class AWeapon
{
	protected:
		std::string _name;
		int _apcost;
		int _damage;

		AWeapon ( void );

	public:
		AWeapon( std::string const & name, int apcost, int damage );
		AWeapon( AWeapon &obj );
		virtual ~AWeapon();

		std::string const &getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;

		AWeapon &operator = ( AWeapon const & obj );
};

#endif //AWEAPON_HPP