#include <iostream>
#include "StripMiner.hpp"

StripMiner::StripMiner(void) { return; }

StripMiner::StripMiner(StripMiner const &src) {
	*this = src;
}

StripMiner::~StripMiner(void) { return; }

StripMiner			&StripMiner::operator=(StripMiner const &rhs){
	(void)rhs;
	return (*this);
}

void					StripMiner::mine(IAsteroid *asteroid) {
	std::cout << "* strip mining ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}