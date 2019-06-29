#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"

class KoalaSteroid
{
	public:
		KoalaSteroid(void);
		KoalaSteroid(KoalaSteroid const &src);
		~KoalaSteroid(void);

		KoalaSteroid			&operator= (const KoalaSteroid &rhs);

		std::string				beMined(DeepCoreMiner *laser) const;
		std::string				beMined(StripMiner *laser) const;
		std::string	const		getName(void) const;
};

#endif //KOALASTEROID_HPP