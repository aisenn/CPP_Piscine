#include <string>
#include <time.h>
#include <stdlib.h>
#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
	: _offices(), _officesCount(0), _queue(), _queueSize(0) {
	srand(clock());
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &src)
	: _offices(), _officesCount(0), _queue(), _queueSize(0) {
	*this = src;
}

CentralBureaucracy::~CentralBureaucracy( void ) { return; }

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const &rhs) {
	if (this != &rhs) {
		_officesCount = rhs._officesCount;
		_queueSize = rhs._queueSize;

		for (int i = 0; i < this->_officesCount; i++) {
			_offices[i].setIntern(*(rhs._offices[i].getIntern()));
			_offices[i].setSigner(*(rhs._offices[i].getSigner()));
			_offices[i].setExecutor(*(rhs._offices[i].getExecutor()));
		}
		for (int i = 0; i < this->_queueSize; i++)
			_queue[i] = rhs._queue[i];
	}
	return (*this);
}

void CentralBureaucracy::feed(Bureaucrat &bureaucrat) {
	if (this->_officesCount < 20)
	{
		if (this->_offices[this->_officesCount].getIntern()) {
			this->_offices[this->_officesCount].setExecutor(bureaucrat);
			this->_officesCount++;
		}
		else {
			this->_offices[this->_officesCount].setIntern(*(new Intern));
			this->_offices[this->_officesCount].setSigner(bureaucrat);
		}
		return;
	}
	throw(CentralBureaucracyIsFull());
}

void CentralBureaucracy::queueUp(std::string const &target) {
	if (this->_queueSize < 20)
	{
		this->_queue[_queueSize] = target;
		this->_queueSize++;
		return;
	}
	throw(QueueIsFull());
}

void CentralBureaucracy::doBureaucracy( void ) {
	std::string forms[3] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};


		for (int i = 0; i < this->_queueSize; i++) {
			try {
				srand(clock());
				int rForm = rand() % 3;
				int r;
				if (this->_offices[this->_officesCount - 1].getExecutor())
					r = rand() % _officesCount;
				else
					r = rand() % _officesCount - 2;

				std::cout << "\n\033[1;36mSigner "<< (_offices[r].getSigner())->getName() << ", "
						  << "executor " << (_offices[r].getExecutor())->getName() << " "
						  << forms[rForm] << " form, target " << _queue[i] <<" \033[0m" << std::endl;
				_offices[r].doBureaucracy(forms[rForm], _queue[i]);
			}
			catch (std::exception &e) {
				std::cout << "CentralBureaucracy can not doBureaucracy " << e.what() << std::endl;
			}
		}
		this->_queueSize = 0;

}

// CentralBureaucracyIsFull class

CentralBureaucracy::CentralBureaucracyIsFull::CentralBureaucracyIsFull( void ) { return; }
CentralBureaucracy::CentralBureaucracyIsFull::~CentralBureaucracyIsFull( void ) throw() { return; }
CentralBureaucracy::CentralBureaucracyIsFull::CentralBureaucracyIsFull(CentralBureaucracyIsFull const &src) {
	*this = src;
}
CentralBureaucracy::CentralBureaucracyIsFull	&CentralBureaucracy::CentralBureaucracyIsFull::operator=( CentralBureaucracy::CentralBureaucracyIsFull const & ) {
	return *this;
}
char const					*CentralBureaucracy::CentralBureaucracyIsFull::what(void) const throw() {
	return ("Error: Central Bureaucracy is full");
}

// QueueIsFull class

CentralBureaucracy::QueueIsFull::QueueIsFull( void ) { return; }
CentralBureaucracy::QueueIsFull::~QueueIsFull( void ) throw() { return; }
CentralBureaucracy::QueueIsFull::QueueIsFull(QueueIsFull const &src) {
	*this = src;
}
CentralBureaucracy::QueueIsFull	&CentralBureaucracy::QueueIsFull::operator=( CentralBureaucracy::QueueIsFull const & ) {
	return *this;
}
char const					*CentralBureaucracy::QueueIsFull::what(void) const throw() {
	return ("Error: Central Bureaucracy Queue is full");
}