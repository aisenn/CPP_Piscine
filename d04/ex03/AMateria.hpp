#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	private:
		std::string _type;
		unsigned int xp_;

	public:
		AMateria( void );
		AMateria(AMateria &);
		AMateria(std::string const & type);
		virtual ~AMateria();

        void setType(std::string const &);
        void setXP( int );
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materias XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria &operator=(AMateria const &);
};

#endif //AMATERIA_HPP