#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle( void );
		PlasmaRifle( PlasmaRifle & obj );

		virtual void attack() const;

		PlasmaRifle &operator = ( PlasmaRifle const & obj );
};

#endif //PLASMARIFLE_HPP