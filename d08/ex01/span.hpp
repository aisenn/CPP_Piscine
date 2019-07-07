#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <numeric>

class Span {
	private:
		unsigned 			_size;
		std::vector<int>	_data;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &cp);
		~Span();

		Span &operator=(Span const &);

		void addNumber(unsigned n);
		void addNumber(size_t amount, unsigned fillWith);
		void addNumber(unsigned begin, unsigned end, unsigned toFill);
		unsigned shortestSpan();
		unsigned longestSpan();
};

#endif //SPAN_HPP
