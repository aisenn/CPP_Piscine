#include <iostream>

//-*******************************ex00 functions*****************************

/*template<typename T>
T const &min(T const &a, T const &b) {
	return ((a < b) ? a : b);
}

template<typename T>
T const &max(T const &a, T const &b) {
	return ((a > b) ? a : b);
}

//-********************************************************************************

template<typename Array, typename T, typename FnAtributes>
void iter(Array *array, int len, T (*func)(FnAtributes &, FnAtributes &))
{
	for (int i = 0; i < len - 1; i++)
		std::cout << ((*func)(array[i], array[i + 1])) << " ";
	std::cout << std::endl;
}

int main( void )
{
	int				array_ints[] = { 1, 2, 3, 4, 5 };
	std::string		array_strings[] = { "A", "B", "C", "D", "E" };
	char			str[] = { 'a', 'b', 'c', 'd', 'e' };

	iter<int>(array_ints, 5, &min<int>);
	iter<int>(array_ints, 5, &max<int>);

	iter<std::string>(array_strings, 5, &min<std::string>);
	iter<std::string>(array_strings, 5, &max<std::string>);

	iter<char>(str, 5, &min<char>);
	iter<char>(str, 5, &max<char>);

	return (0);
}*/

template<typename T>
void iter(T *array, int len, void (*func)(T const &))
{
	for (int i = 0; i < len - 1; i++)
		func(array[i]);
}

template< typename T >
void print( T const & x ) {
	std::cout << x << std::endl;
}

int main() {

	int				array_ints[] = { 1, 2, 3, 4, 5 };
	std::string		array_strings[] = { "A", "B", "C", "D", "E" };
	char			str[] = { 'a', 'b', 'c', 'd', 'e' };

	iter( array_ints, 5, print );
	iter( array_strings, 5, print );
	iter( str, 5, print );

	return 0;
}
