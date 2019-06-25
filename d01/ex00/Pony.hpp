#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony
{
	private:
		std::string _name;
		std::string _breed;
		int			_age;
		int			_height;

	public:
		Pony( std::string name, std::string breed, int height, int age );
		~Pony(void);

		std::string getName( void );
		std::string getBreed( void );
		int getAge( void );
		int getHeight( void );
};

#endif //PONY_HPP