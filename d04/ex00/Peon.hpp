#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon(void);

	public:
		Peon(std::string name);
		Peon(Peon & src);
		~Peon(void);

		Peon & operator=(Peon const & obj);

		virtual void		getPolymorphed(void) const;
};

#endif //PEON_HPP
