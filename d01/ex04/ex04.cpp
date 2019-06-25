#include <iostream>
#include <string>

int main ( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "string:    " << str	<< std::endl
			  << "pointer:   " << *ptr	<< std::endl
			  << "reference: " << ref	<< std::endl;
	return (0);
}