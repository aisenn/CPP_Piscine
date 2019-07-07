#ifndef B_H
#define B_H

#include "Base.hpp"

class B: public Base
{
	public:
		B(void);
		~B(void);
		B(B const &src);

		B &operator=(B const &rhs);
};

#endif //B
