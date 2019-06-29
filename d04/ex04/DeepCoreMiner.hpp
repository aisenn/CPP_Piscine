#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
	public:
		DeepCoreMiner(void);
		DeepCoreMiner(DeepCoreMiner const &src);
		~DeepCoreMiner(void);

		DeepCoreMiner                   &operator= (const DeepCoreMiner &rhs);

        void mine(IAsteroid*);
};

#endif //DEEPCOREMINER_HPP