#include <iostream>
#include <string>
#include "Contact.class.hpp"

int search(Contact &book)
{
	std::string input;

	if (book.print_base())
	{
		std::cout << "In order to display the contact please enter the index of contact." << std::endl;
		char a  = {0};

		while (true)
		{
			std::cout<<"Enter an integer number: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << "CTRL + D pressed, EXIT" << std::endl;
				return (0);
			}
			else if ((input.length() == 1) && isdigit(input[0]) && (input[0] != '9') && (input[0] != '0'))
			{
				a = input[0];
				break;
			}
			std::cout << "Invalid input, please try again" << std::endl;
		}
		book.print_contact((a - '0') - 1);
	}
	return (0);
}

int parse(std::string input, Contact &book)
{
	if (input.compare("EXIT") == 0)
		return (1);
	else if (input.compare("ADD") == 0)
		book.setUser();
	else if (input.compare("SEARCH") == 0)
		search(book);
	else
		std::cout << "Wrong command" << std::endl;
	return (0);
}

int main(void)
{
    std::string	input;
	Contact	book;

	std::cout << "Welcome" << std::endl;
	while(true)
	{
		std::cout << "Enter your command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "CTRL + D pressed, EXIT" << std::endl;
			return (0);
		}
		else if (parse(input, book))
			return (0);
	}
	return (0);
}