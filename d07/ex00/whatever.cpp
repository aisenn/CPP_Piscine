#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

std::string randomChump( void )
{
	char		vowels[] = {'a','e','i','o','u','y'};
	char		consonants[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
	std::string	name = "";
	int			length = 3 + (rand() % 5);
	bool		count = rand() % 2;

	for(int i = 0; i < length; i++)
	{
		if(count)
			name = name + consonants[rand() % 19];
		else
			name = name + vowels[rand() % 5];
		count = !count;
	}
	name[0] = toupper(name[0]);
	return (name);
}

//*******************************Templated functions*****************************

template<typename T>
void swap(T &a, T &b) {
	T tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T const &min(T &a, T &b) {
	return ((a < b) ? a : b);
}

template<typename T>
T const &max(T &a, T &b) {
	return ((a > b) ? a : b);
}

//********************************************************************************

template<typename T>
void function(T &a, T &b){
	std::cout << std::string(50, '_') << std::endl;
	std::cout << "swap( a = " << std::setw(2) << a << ", b = " << std::setw(2) << b << " )" << std::endl;
	::swap(a, b);
	std::cout << "      a = " << std::setw(2) << a << ", b = " << std::setw(2) << b << std::endl;

	std::cout << "min( a = " << std::setw(2) << a << ", b = " << std::setw(2) << b << " ) = ";
	std::cout << ::min( a, b ) << std::endl;

	std::cout << "max( a = " << std::setw(2) << a << ", b = " << std::setw(2) << b << " ) = ";
	std::cout << ::max( a, b ) << std::endl;
}

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	//--------------------------------Custom tests---------------------------------------
	srand(clock());

	{
		std::cout << std::string(50, '_') << std::endl;
		std::cout << "                      Integer" << std::endl;
		int a = rand() % 100;
		int b = rand() % 100;

		function(a, b);
	}
	{
		std::cout << std::string(50, '_') << std::endl;
		std::cout << "                      Float" << std::endl;
		float a = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		float b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

		function(a, b);
	}
	{
		std::cout << std::string(50, '_') << std::endl;
		std::cout << "                      Double" << std::endl;
		double a = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		double b = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);

		function(a, b);
	}

	std::cout << std::string(50, '_') << std::endl;
	std::string l = randomChump();
	std::string r = randomChump();

	std::cout << "swap( a = " << std::setw(7) << l << ", b = " << std::setw(7) << r << " )" << std::endl;
	::swap(l, r);
	std::cout << "      a = " << std::setw(7) << l << ", b = " << std::setw(7) << r << std::endl << std::endl;
	std::cout << "min( c, d ) = " << ::min( l, r ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( l, r ) << std::endl;

	std::cout << std::string(50, '_') << std::endl;
	return (0);
}
