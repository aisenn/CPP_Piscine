#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:
		RadScorpion( void );
		RadScorpion( RadScorpion &obj );
		virtual ~RadScorpion();

		// RadScorpion &operator = ( RadScorpion const & obj );
};

#endif //RADSCORPION_HPP