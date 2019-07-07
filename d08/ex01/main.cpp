#include <vector>
#include <iostream>
#include <ctime>
#include "span.hpp"

int main() {
	srand(clock());

	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);


	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span A = Span(10000);
	for (int i = 0; i < 10000; i++)
		A.addNumber(rand() % 10000);

	std::cout << "Min: " << A.shortestSpan() << std::endl;
	std::cout << "Max: " << A.longestSpan() << std::endl;

	Span B = Span(1);
	B.addNumber(9);
	try {
		B.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		B.longestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		B.addNumber(10);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	//fill by range of iterators
	A.addNumber(0, 10000, 42);

	return (0);
}