#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "easyfind.hpp"
#include <ctime>

template<typename T>
void push(T &a) {
	for (int i = 1; i <= 5; i++)
		a.push_back(i);
}

int main() {
	srand(clock());
	{
		std::vector<int> a;
		push(a);

		int toFind = rand() %  10;
		std::cout << "\033[1;34mVector{1, 2, 3, 4, 5} Container. Searching \033[1;0m"
		          << toFind << " ";
		easyfind(a, toFind);
	}
	{
		std::list<int> a;
		push(a);

		int toFind = rand() %  10;
		std::cout << "\033[1;34mList{1, 2, 3, 4, 5} Container. Searching \033[1;0m"
				  << toFind << " ";
		easyfind(a, toFind);
	}
	{
		std::deque<int> a;
		push(a);

		int toFind = rand() %  10;
		std::cout << "\033[1;34mDeque{1, 2, 3, 4, 5} Container. Searching \033[1;0m"
				  << toFind << " ";
		easyfind(a, toFind);
	}

	return 0;
}