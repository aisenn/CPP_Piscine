#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
	private:
		std::string	_name;
		std::string	_title;
		Sorcerer( void );

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer & obj);
		~Sorcerer(void);

		Sorcerer & operator=(Sorcerer const & obj);

		std::string	getName(void) const;
		std::string	getTitle(void) const;

		void		setName(std::string name);
		void		setTitle(std::string title);

		std::string	introduce(void) const;
		void		polymorph(Victim const & v) const;
};

std::ostream	&operator<<(std::ostream & lhs, Sorcerer const & obj);

#endif //SORCERER_HPP
