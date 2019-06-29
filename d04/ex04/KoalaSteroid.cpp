#include <string>
#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid(void) { return; }

KoalaSteroid::KoalaSteroid(KoalaSteroid const &src) {
	*this = src;
}

KoalaSteroid::~KoalaSteroid(void) { return; }

KoalaSteroid			&KoalaSteroid::operator=(KoalaSteroid const &rhs) {
	(void)rhs;
	return (*this);
}


std::string				KoalaSteroid::beMined(DeepCoreMiner *laser) const {
	(void)laser;
	return ("Thorite");
}

std::string				KoalaSteroid::beMined(StripMiner *laser) const {
	(void)laser;
	return ("Flavium");
}

std::string	const		KoalaSteroid::getName(void) const {
	return ("KoalaSteroid");
}