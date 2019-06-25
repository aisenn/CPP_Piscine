#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <sstream>
# include <fstream>
# include <sstream>

class Logger
{
	private:
		void logToConsole( std::string str );
		void logToFile( std::string str );
		std::string makeLogEntry( std::string str );

		std::string _filename;
	public:
		Logger( void );
		~Logger( void );
		void log(std::string const & dest, std::string const & message);
};
#endif //LOGGER_HPP