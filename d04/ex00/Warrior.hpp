#ifndef WARRIOR_HPP
# define WARRIOR_HPP

# include "Victim.hpp"

class Warrior : public Victim
{
	private:
		Warrior(void);

	public:
		Warrior(std::string name);
		Warrior(Warrior & src);
		~Warrior(void);

		Warrior & operator = (Warrior const & rhs);

		virtual void		getPolymorphed(void) const;
};

#endif //WARRIOR_HPP