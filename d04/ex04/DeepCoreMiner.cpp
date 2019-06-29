#include "DeepCoreMiner.hpp"
#include <iostream>

DeepCoreMiner::DeepCoreMiner(void) { return; }

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &src) {
	*this = src;
}

DeepCoreMiner::~DeepCoreMiner(void) { return; }

DeepCoreMiner			&DeepCoreMiner::operator=(DeepCoreMiner const &rhs){
	(void)rhs;
	return (*this);
}

void					DeepCoreMiner::mine(IAsteroid *asteroid) {
	std::cout << "* mining deep ... got " << asteroid->beMined(this) << " ! *" << std::endl;
}