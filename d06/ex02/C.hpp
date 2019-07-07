#ifndef C_H
# define C_H

# include "Base.hpp"

class C: public Base
{
	public:
								C(void);
								~C(void);
								C(C const &src);
		C						&operator=(C const &rhs);
};

#endif //C
