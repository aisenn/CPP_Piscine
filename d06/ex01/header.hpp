#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>
# include <time.h>
# include <stdlib.h>

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void		*serialize(void);
Data		*deserialize(void * raw);

#endif //HEADER_HPP
