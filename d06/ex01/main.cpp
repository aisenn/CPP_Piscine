#include "header.hpp"
#include <iostream>
#include <stdlib.h>

void		*serialize(void)
{
	char *str = new char[20];
	std::string	alNum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	for (int i = 0; i < 8; i++) {

		str[i] = alNum[rand() % (alNum.length())];
		str[i + 12] = alNum[rand() % (alNum.length())];
	}
	*(reinterpret_cast<int *>(&str[8])) = rand();

	return (reinterpret_cast<void *>(str));
}

Data		*deserialize( void * raw )
{
	Data				*ret = new Data();

	ret->s1.assign(reinterpret_cast<char *>(raw), 8);
	ret->n = *reinterpret_cast<int *>(&reinterpret_cast<char *>(raw)[8]);
	ret->s2.assign(&reinterpret_cast<char *>(raw)[12], 8);

	return (ret);
}


int			main(void)
{
	srand(clock());
	void		*buff = serialize();
	Data		*raw = deserialize(buff);
	std::cout	<< raw->s1 << raw->n << raw->s2 << std::endl;

	return 0;
}
