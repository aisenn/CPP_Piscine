#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

# include <string>
# include "OfficeBlock.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"



class CentralBureaucracy
{
	private:
		OfficeBlock				_offices[20];
		int						_officesCount;
		std::string				_queue[20];
		int						_queueSize;
		
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const &src);
		~CentralBureaucracy(void);

		CentralBureaucracy &operator=(CentralBureaucracy const &rhs);

		void					feed(Bureaucrat &bureaucrat);
		void					queueUp(std::string const &target);
		void					doBureaucracy(void);

		class CentralBureaucracyIsFull: public std::exception
		{
			public:
				CentralBureaucracyIsFull( void );
				CentralBureaucracyIsFull( CentralBureaucracyIsFull const &src );
				virtual ~CentralBureaucracyIsFull( void ) throw();
				CentralBureaucracyIsFull		&operator=( CentralBureaucracyIsFull const &rhs );

				virtual const char *what() const throw();
		};

		class QueueIsFull: public std::exception
		{
			public:
				QueueIsFull( void );
				QueueIsFull( QueueIsFull const &src );
				virtual ~QueueIsFull( void ) throw();
				QueueIsFull		&operator=( QueueIsFull const &rhs );

				virtual const char *what() const throw();
		};
};

#endif
