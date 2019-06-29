#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	public:
		PowerFist( void );
		PowerFist( PowerFist & obj );

		virtual void attack() const;

		PowerFist &operator = ( PowerFist const & obj );
};

#endif //POWERFIST_HPP