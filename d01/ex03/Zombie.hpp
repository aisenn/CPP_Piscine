#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string	_name;
		std::string	_type;

	public:
		Zombie( std::string type, std::string name );
		Zombie( void );
		~Zombie( void );

		void		announce( void );
};

#endif //ZOMBIE_HPP