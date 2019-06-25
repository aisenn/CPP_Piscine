#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

class Contact
{
	private:
		std::string		_firstname[8];
		std::string		_lastname[8];
		std::string		_nickname[8];
		std::string		_login[8];
		std::string		_address[8];
		std::string		_email[8];
		std::string		_phone[8];
		std::string		_birthday[8];
		std::string		_favorite_meal[8];
		std::string		_underwear_color[8];
		std::string		_darkest_secret[8];
		static int		_id;

		std::string truncate(std::string str);

	public:
		Contact(void);
		~Contact(void);

		bool	print_base(void);
		void	print_contact(int i);
		void	setUser( void );

		std::string getFirstname( int i );
		std::string getLastname( int i );
		std::string getNickname( int i );
		std::string getLogin( int i );
		std::string getAddress( int i );
		std::string getEmail( int i );
		std::string getPhone( int i );
		std::string getBirthday( int i );
		std::string getFavorite_meal( int i );
		std::string getUnderwear_color( int i );
		std::string getDarkest_secret( int i );

		void setFirstname(std::string str);
		void setLastname(std::string str);
		void setNickname(std::string str);
		void setLogin(std::string str);
		void setAddress(std::string str);
		void setEmail(std::string str);
		void setPhone(std::string str);
		void setBirthday(std::string str);
		void setFavorite_meal(std::string str);
		void setUnderwear_color(std::string str);
		void setDarkest_secret(std::string str);
};

#endif //CONTACT_CLASS_HPP