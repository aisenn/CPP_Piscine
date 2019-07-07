#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "ScalarConversion.hpp"

int				main(int ac, char **av)
{
	if (ac == 2 || ac == 3) {

		const int amount = 6;
		std::string array[amount] = {
				av[1],
				"+inf",
				"-inf",
				"nan",
				"0",
				"42.0f"
		};


		for (int i = 0; i < amount; i++) {
			ScalarConversion test(array[i]);

			if (i == 0)
				std::cout << "\033[1;34mYour arg is: " << array[i] << " \033[1;0m" << std::endl;
			else
				std::cout << "\033[1;34m" << array[i] << " \033[1;0m" << std::endl;
			std::cout << "char: ";
			try {
				char c = static_cast<char>(test);
				if (isprint(c))
					std::cout << '\'' << c << '\'';
				else
					std::cout << "Non displayable";
			}
			catch (std::exception &e) {
				std::cout << e.what();
			}
			std::cout << std::endl;

			std::cout << "int: ";
			try {
				std::cout << static_cast<int>(test);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}

			std::cout << "float: ";
			try {
				std::cout << std::fixed << std::setprecision(1) << static_cast<float>(test) << 'f';
			}
			catch (std::exception &e) {
				std::cout << e.what();
			}

			std::cout << std::endl  << "double: ";
			try {
				std::cout << static_cast<double>(test);
			}
			catch (std::exception &e) {
				std::cout << e.what();
			}
			std::cout << std::endl << std::endl;
			if (ac == 2)
				break;
		}
	}
	else {
		std::cout << "Usage:   ./convert yourArgument " << std::endl
				  << "Write another argument to show tests" << std::endl
				  << "example: ./convert yourArgument +" << std::endl;
	}
}
