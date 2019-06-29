#ifndef IASTEROID_HPP
# define IASTEROID_HPP

#include <string>

class DeepCoreMiner;
class StripMiner;

class IAsteroid
{
	public:
		virtual ~IAsteroid() {}

		virtual std::string			beMined(DeepCoreMiner *laser) const = 0;
		virtual std::string			beMined(StripMiner *laser) const = 0;
		virtual std::string	const	getName(void) const = 0;
};

#endif //IASTEROID_HPP