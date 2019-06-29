#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const &);
		virtual ~TacticalMarine();
		virtual ISpaceMarine *clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;

		TacticalMarine &	operator=(TacticalMarine const &);
};

#endif // TACTICALMARINE_HPP