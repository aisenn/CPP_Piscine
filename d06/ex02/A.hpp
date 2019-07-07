#ifndef A_H
#define A_H

#include "Base.hpp"

class A: public Base
{
	public:
		A(void);
		~A(void);
		A(A const &src);

		A &operator=(A const &rhs);
};

#endif //A
