#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "KoalaSteroid.hpp"
#include "AsteroKreog.hpp"
#include "MiningBarge.hpp"

int				main(void)
{
	MiningBarge		ship;
	DeepCoreMiner	miner_dc;
	StripMiner		miner_s;
	KoalaSteroid	steroid;
	AsteroKreog		astero;

	ship.equip(&miner_dc);
	ship.equip(&miner_s);

	// ship.mine(&steroid);
	ship.mine(&astero);
	return (0);
}