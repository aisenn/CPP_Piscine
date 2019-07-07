#ifndef ARRAY_TPP
#define ARRAY_TPP

# include <exception>
#include <istream>

template<typename T>
class Array
{
private:
	unsigned int	_size;
	T				*_data;

public:
	Array<T>(void) : _size(0) , _data(new T[_size]()) { return; }
	Array<T>(int size) : _size(size < 0 ? 0 : size) , _data(new T[this->_size]()) { return; }
	Array<T>(Array<T> const &cp) : _size(0) , _data() {
		*this = cp;
	}
	~Array<T>(void) {
		delete [] this->_data;
	}

	Array<T> &operator=(Array<T> const &rhs) {
		delete [] this->_data;
		this->_size = rhs._size > 0 ? rhs._size : 0;
		this->_data = new T[this->_size]();

		for (unsigned int i = 0; i < this->_size; i++)
			this->_data[i] = rhs._data[i];
		return *this;
	}

	const T &operator [](unsigned int i) const {
		if (!this->_data || i >= this->_size)
			throw std::out_of_range("Error: Out of range");
		return this->_data[i];
	}

	T &operator[](unsigned int i) {
		if (!this->_data || i >= this->_size)
			throw std::out_of_range("Error: Out of range");
		return this->_data[i];
	}

	unsigned int size(void) const {
		return this->_size;
	}
};

template<typename T>
std::ostream &operator<<(std::ostream &os,  const Array<T>  &array) {
	os << "[ ";
	for (int i = 0; i < array.size(); i++) {
		os << array[i] << " ";
	}

	os << "], size = " << array.size() << std::endl;

	return os;
}



#endif //ARRAY_TPP
