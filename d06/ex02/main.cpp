#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
	std::srand(std::clock());
	switch (std::rand() % 3) {
		case 0:
			return (static_cast<Base *>(new A()));
		case 1:
			return (static_cast<Base *>(new B()));
		default:
			return (static_cast<Base *>(new C()));
	}
}

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
}

int main(void)
{
	Base *b = generate();

	identify_from_pointer(b);
	identify_from_reference(*b);

	return (0);
}
