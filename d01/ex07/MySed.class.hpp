#ifndef MYSED_CLASS_HPP
# define MYSED_CLASS_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class MySed
{
	public:
		MySed( void );
		~MySed( void );
		bool        checkArgs(std::string s1, std::string s2);
		std::string readFromFile( std::string filename );
		std::string replace(std::string &str, const std::string &toFind, const std::string &replaceWith);
		void        writeToFile( std::string filename, std::string content );
};

#endif //MYSED_CLASS_HPP