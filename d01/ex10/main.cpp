#include <iostream>
#include <fstream>
#include <sys/stat.h>

void	writeToConsole(std::istream &str)
{
	std::cout << str.rdbuf();
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		writeToConsole(std::cin);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			struct stat		sb;
			std::string		fileName(argv[i]);
			std::ifstream	ifs(fileName);

			if (-1 == stat(argv[i], &sb))
				std::cout << "cato9tails: " << fileName << ": " << strerror(errno) << std::endl;
			else if ((sb.st_mode & S_IFMT) == S_IFDIR)
				std::cout << "cato9tails: " << fileName << ": Is a directory" << std::endl;
			else if (!ifs.fail())
				writeToConsole(ifs);
			else
				std::cout << "cato9tails: " << fileName << ": " << strerror(errno) << std::endl;
		}
	}
	return (0);
}
