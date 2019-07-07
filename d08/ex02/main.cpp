#include <vector>
#include <iostream>
#include "mutantstack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	MutantStack<int> m;

	m.push(5);
	m.push(17);
	m.push(5);
	m.push(17);
	m.push(5);
	m.push(17);
	mstack = m;

	while (!mstack.empty())
		mstack.pop();

	MutantStack<int>::iterator it2 = m.begin();
	MutantStack<int>::iterator ite2 = m.end();

	++it2;
	--it2;

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;

	return 0; }