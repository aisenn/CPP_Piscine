#include <string>
#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog(void) { return; }

AsteroKreog::AsteroKreog(AsteroKreog const &src) {
	*this = src;
}

AsteroKreog::~AsteroKreog(void) { return; }

AsteroKreog			&AsteroKreog::operator=(AsteroKreog const &rhs) {
	(void)rhs;
	return (*this);
}


std::string				AsteroKreog::beMined(DeepCoreMiner *laser) const {
	(void)laser;
	return ("Thorite");
}

std::string				AsteroKreog::beMined(StripMiner *laser) const {
	(void)laser;
	return ("Flavium");
}

std::string	const		AsteroKreog::getName(void) const {
	return ("AsteroKreog");
}