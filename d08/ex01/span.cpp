#include "span.hpp"

Span::Span() : _size(0), _data() {}
Span::Span(unsigned int size)
	:  _size(0), _data(size) {

}
Span::Span(Span const &cp)
	:  _size(0), _data() {
	*this = cp;
}
Span::~Span() {}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->_size = rhs._size;
		this->_data = rhs._data;
	}
	return *this;
}

void Span::addNumber(unsigned n) {
	if (_size < _data.size()) {
		_data[_size] = n;
		_size++;
	}
	else
		throw std::out_of_range("Error: Span out of range");
}

void Span::addNumber(size_t amount, unsigned fillWith) {
	if ((amount + _size) > _data.size())
		throw std::out_of_range("Error: Span out of range");
	std::fill(this->_data.begin() + amount, this->_data.end(), fillWith);

}


void	Span::addNumber(unsigned begin, unsigned end, unsigned toFill)
{
	if (begin <= _size && end <= _size)
		fill(_data.begin() + begin, _data.begin() + end, toFill);
	else
		throw std::out_of_range("Error: Span out of range");
}

unsigned Span::shortestSpan() {
	if (this->_size < 2)
		throw std::runtime_error("Error: No span");

	std::vector<int> tmp = _data;
	sort(tmp.begin(), tmp.end());

	std::vector<int>::iterator min;
	std::vector<int>::iterator min2;

	min = std::min_element(tmp.begin(), tmp.end());
	min2 = std::min_element(tmp.begin() + 1, tmp.end());

	return *min2 - *min;
}

unsigned Span::longestSpan() {
	if (this->_size < 2)
		throw std::runtime_error("Error: No span");

	std::vector<int>::iterator		min;
	std::vector<int>::iterator		max;

	min = std::min_element(this->_data.begin(), this->_data.end());
	max = std::max_element(this->_data.begin(), this->_data.end());

	return *max - *min;
}
