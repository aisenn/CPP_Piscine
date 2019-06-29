#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
	private:
		static int				_unitsAmount;
		ISpaceMarine	*_marinesSquad;
		Squad			*_next;

	public:
		Squad( void );
		Squad( Squad &obj);
		virtual ~Squad( void );
		
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);

		Squad &operator=(Squad const &);
};

#endif // SQUAD_HPP