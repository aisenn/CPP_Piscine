#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

#include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
	public:
		StripMiner(void);
		StripMiner(StripMiner const &src);
		~StripMiner(void);

		StripMiner                   &operator= (const StripMiner &rhs);

		void mine(IAsteroid*);
};

#endif //STRIPMINER_HPP