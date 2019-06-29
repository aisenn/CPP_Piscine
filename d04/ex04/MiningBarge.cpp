#include <string>
#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void)
{
	this->_laser_count = 0;
}

MiningBarge::MiningBarge(MiningBarge const &src)
{
	*this = src;
}

MiningBarge::~MiningBarge(void)
{}

MiningBarge			&MiningBarge::operator=(MiningBarge const &rhs)
{
	int				i;

	if (this != &rhs)
	{
		i = 0;
		while (i < this->_laser_count)
		{
			this->_lasers[i] = rhs._lasers[i];
			i++;
		}
		this->_laser_count = rhs._laser_count;
	}
	return (*this);
}

void				MiningBarge::equip(IMiningLaser *laser)
{
	if (this->_laser_count < 4)
	{
		this->_lasers[this->_laser_count] = laser;
		this->_laser_count++;
	}
}

void				MiningBarge::mine(IAsteroid *asteroid) const
{
	int				i;

	i = 0;
	while (i < this->_laser_count)
	{
		this->_lasers[i]->mine(asteroid);
		i++;
	}
}