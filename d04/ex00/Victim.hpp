#ifndef VICTIM_HPP
#define VICTIM_HPP



class Victim
{
	protected:
		std::string	_name;
		Victim( void );

	public:
		Victim( std::string name );
		Victim( Victim & src );
		virtual ~Victim( void );

		Victim & operator = ( Victim const & obj );

		std::string	getName( void ) const;
		void		setName( std::string name );

		std::string	introduce( void ) const;
		virtual void getPolymorphed( void ) const;
};

std::ostream	&operator<<(std::ostream & lhs, Victim const & obj);

#endif //VICTIM_HPP
