#include "MySed.class.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		MySed sed;
		
        if (sed.checkArgs(argv[2], argv[3]))
		{
            std::string content = sed.readFromFile(argv[1]);
            if (!content.empty())
			{
                sed.replace(content, argv[2], argv[3]);
                sed.writeToFile(argv[1], content);
            }
        }
	}
	else
		std::cout << "Usage: ./replace filename \"to_replace\" \"replace_with\"" << std::endl;
	
	return (0);
}