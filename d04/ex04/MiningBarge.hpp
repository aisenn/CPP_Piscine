#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
	private:
		int						_laser_count;
		IMiningLaser			*_lasers[4];

	public:
		MiningBarge(void);
		~MiningBarge(void);
		MiningBarge(MiningBarge const &src);

		MiningBarge				&operator=(MiningBarge const &rhs);

		void					equip(IMiningLaser *laser);
		void					mine(IAsteroid *asteroid) const;
};

#endif //MININGBARGE_HPP