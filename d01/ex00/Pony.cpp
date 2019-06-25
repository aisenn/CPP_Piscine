#include "Pony.hpp"

Pony::Pony( std::string name, std::string breed, int height, int age ) : _name(name), _breed(breed), _age(age), _height(height) { return; };
Pony::~Pony( void ) { return; };

std::string Pony::getName() { return this->_name; }
std::string Pony::getBreed() { return this->_breed; }
int Pony::getAge() { return this->_age; }
int Pony::getHeight() { return this->_height; }