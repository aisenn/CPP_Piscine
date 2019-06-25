#include "Logger.hpp"

int main( void )
{
	Logger l;

	l.log("logToConsole", "test1");
	l.log("logToConsole", "test2");
	l.log("logToConsole", "test3");
	l.log("logToFile", "test4");
	l.log("logToFile", "test5");
	l.log("logToConsole", "test6");
	return (0);
}