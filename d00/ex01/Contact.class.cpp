#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void) { return; }
Contact::~Contact(void) { return; }

int Contact::_id = 0;

std::string Contact::truncate(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool Contact::print_base(void) {
	if (Contact::_id == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return (false);
	}
	else
	{
		std::string output;

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		for (int i = 0; i < Contact::_id; i++)
		{
			std::cout << std::right << "|" << std::setw(10) << (i + 1)  << '|';
			std::cout << std::right << std::setw(10) << truncate(getFirstname(i)) << '|';
			std::cout << std::right << std::setw(10) << truncate(getLastname(i))  << '|';
			std::cout << std::right << std::setw(10) << truncate(getNickname(i))  << '|' << std::endl;;
		}
		std::cout << "---------------------------------------------" << std::endl;
	}
	return (true);
}

void Contact::print_contact(int i) {
	if (i >= 0 && i < Contact::_id)
	{
		std::cout << std::left << std::setfill(' ')
				  << std::setw(17) << "id: " << i + 1 << std::endl
				  << std::setw(17) << "First name: " << getFirstname(i) << std::endl
				  << std::setw(17) << "Last name: " << getLastname(i) << std::endl
				  << std::setw(17) << "Nickname: " << getNickname(i) << std::endl
				  << std::setw(17) << "Login: " << getLogin(i) << std::endl
				  << std::setw(17) << "Postal address: " << getAddress(i) << std::endl
				  << std::setw(17) << "Email address: " << getEmail(i) << std::endl
				  << std::setw(17) << "Phone number: " << getPhone(i) << std::endl
				  << std::setw(17) << "Birthday date: " << getBirthday(i) << std::endl
				  << std::setw(17) << "Favorite meal: " << getFavorite_meal(i) << std::endl
				  << std::setw(17) << "Underwear color: " << getUnderwear_color(i) << std::endl
				  << std::setw(17) << "Darkest secret: " << getDarkest_secret(i) << std::endl << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void Contact::setUser( void ) {
	if (Contact::_id < 8)
	{
        std::string	input;

		std::cout << "Please enter the following contact details:" << std::endl;
		std::cout << "First name: ";
		std::getline(std::cin, input);
		this->setFirstname(input);

		std::cout << "Last name: ";
		std::getline(std::cin, input);
		this->setLastname(input);

		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		this->setNickname(input);

		std::cout << "Login: ";
		std::getline(std::cin, input);
		this->setLogin(input);

		std::cout << "Postal address: ";
		std::getline(std::cin, input);
		this->setAddress(input);

		std::cout << "Email address: ";
		std::getline(std::cin, input);
		this->setEmail(input);

		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		this->setPhone(input);

		std::cout << "Birthday date: ";
		std::getline(std::cin, input);
		this->setBirthday(input);

		std::cout << "Favourite meal: ";
		std::getline(std::cin, input);
		this->setFavorite_meal(input);

		std::cout << "Underwear colour: ";
		std::getline(std::cin, input);
		this->setUnderwear_color(input);

		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		this->setDarkest_secret(input);

		Contact::_id++;
	}
	else
		std::cout << "Your phonebook is full" << std::endl;
}

std::string Contact::getFirstname( int i )	{ return this->_firstname[i]; }
std::string Contact::getLastname( int i )	{ return this->_lastname[i]; }
std::string Contact::getNickname( int i )	{ return this->_nickname[i]; }
std::string Contact::getLogin( int i )		{ return this->_login[i]; }
std::string Contact::getAddress( int i )	{ return this->_address[i]; }
std::string Contact::getEmail( int i )		{ return this->_email[i]; }
std::string Contact::getPhone( int i )		{ return this->_phone[i]; }
std::string Contact::getBirthday( int i )	{ return this->_birthday[i]; }
std::string Contact::getFavorite_meal( int i )		{ return this->_favorite_meal[i]; }
std::string Contact::getUnderwear_color( int i )	{ return this->_underwear_color[i]; }
std::string Contact::getDarkest_secret( int i )     { return this->_darkest_secret[i]; }

void Contact::setFirstname(std::string str)	{ this->_firstname[Contact::_id] = str; }
void Contact::setLastname(std::string str)	{ this->_lastname[Contact::_id] = str; }
void Contact::setNickname(std::string str)	{ this->_nickname[Contact::_id] = str; }
void Contact::setLogin(std::string str)		{ this->_login[Contact::_id] = str; }
void Contact::setAddress(std::string str)	{ this->_address[Contact::_id] = str; }
void Contact::setEmail(std::string str)		{ this->_email[Contact::_id] = str; }
void Contact::setPhone(std::string str)		{ this->_phone[Contact::_id] = str; }
void Contact::setBirthday(std::string str)	{ this->_birthday[Contact::_id] = str; }
void Contact::setFavorite_meal(std::string str)		{ this->_favorite_meal[Contact::_id] = str; }
void Contact::setUnderwear_color(std::string str)	{ this->_underwear_color[Contact::_id] = str; }
void Contact::setDarkest_secret(std::string str)	{ this->_darkest_secret[Contact::_id] = str; }
