#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

template<typename T>
void easyfind(T a, int toFind) {
	if (std::find(a.begin(), a.end() , toFind) != a.end())
		std::cout << "\033[1;92mValue " << toFind << " found\033[1;0m" << std::endl;
	else
		std::cout << "\033[1;91mValue not found\033[1;0m" << std::endl;
}

#endif //EASYFIND_HPP