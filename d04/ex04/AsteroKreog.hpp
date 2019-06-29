#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include "IAsteroid.hpp"

class AsteroKreog : public IAsteroid
{
	public:
		AsteroKreog(void);
		AsteroKreog(AsteroKreog const &src);
		~AsteroKreog(void);

		AsteroKreog                   &operator= (const AsteroKreog &rhs);

        std::string				beMined(DeepCoreMiner *laser) const;
		std::string				beMined(StripMiner *laser) const;
		std::string	const		getName(void) const;
};

#endif //ASTEROKREOG_HPP