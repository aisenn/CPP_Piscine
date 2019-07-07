#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <list>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const &cp) {
			*this = cp;
		}
		~MutantStack() {}

		MutantStack &operator=(MutantStack const &rhs) {
			if (this != &rhs)
				this->c = rhs.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::const_iterator iterator;

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
};

#endif //MUTANTSTACK_HPP
