#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <string>

class Human
{
	private:
		const Brain _brain;

	public:
		Human( void );
		~Human( void );

		std::string identify( void ) const;
		const Brain &getBrain() const;
};

#endif //HUMAN_HPP