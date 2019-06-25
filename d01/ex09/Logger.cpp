#include "Logger.hpp"

Logger::Logger( void ) : _filename(this->makeLogEntry(".log")) { return; }
Logger::~Logger( void ) { return; }

void Logger::logToConsole( std::string message )
{
	std::cout << message << std::endl;
}

void Logger::logToFile( std::string message )
{
	std::ofstream ofs (this->_filename, std::ofstream::app);
	if (ofs)
		ofs << message << std::endl;
	else
		std::cout << "Error to write to: " + this->_filename << std::endl;
	ofs.close();
}

std::string Logger::makeLogEntry( std::string str )
{
	std::stringstream buff;
	std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);

	buff << (now->tm_year + 1900)
		 << std::setw(2) << std::setfill('0')
		 << (now->tm_mon + 1)
         << std::setw(2) << std::setfill('0')
		 << now->tm_mday << "_"
         << std::setw(2) << std::setfill('0')
		 << now->tm_hour
         << std::setw(2) << std::setfill('0')
		 << now->tm_min
         << std::setw(2) << std::setfill('0')
		 << now->tm_sec
		 << str;
	return (buff.str());
}

void Logger::log(std::string const & dest, std::string const & message)
{
	std::string fnNames[] = {"logToConsole", "logToFile"};

    typedef void (Logger::*ActionsFn)( std::string message );
    ActionsFn actions[2] = {&Logger::logToConsole, &Logger::logToFile};

	for (int i = 0; i < 2; i++)
	{
		if (fnNames[i] == dest)
		{
			(this->*(actions[i]))(this->makeLogEntry(" " + message));
			return;
		}
	}
}

