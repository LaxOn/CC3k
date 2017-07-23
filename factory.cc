#include "rand.h"
#include "humanNPC.h"
#include "dwarfNPC.h"
#include "elfNPC.h"
#include "orcNPC.h"
#include "merchantNPC.h"
#include "dragonNPC.h"
#include "halflingNPC.h"
#include "tile.h"
#include "basictile.h"
#include "info.h"
#include <memory>
#include <iostream>


int Factory::randInt(int max) {
	srand(time(NULL));
	double rawNum = double(rand()) / double(RAND_MAX);
	return int(rawNum * double(max));
}

void Factory::addEnemy(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	const int human = 0;
	const int dwarf = 1;
	const int elf = 2;
	const int orc = 3;
	const int halfling = 4;
	int enemyNum = randInt(4);
	if (enemyNum == human) t.addObject(std::make_shared<HumanNPC>(x,y));
	else if (enemyNum == dwarf) t.addObject(std::make_shared<DwarfNPC>(x,y));
	else if (enemyNum == elf) t.addObject(std::make_shared<ElfNPC>(x,y));
	else if (enemyNum == orc) t.addObject(std::make_shared<OrcNPC>(x,y));
	else if (enemyNum == halfling) t.addObject(std::make_shared<HalflingNPC>(x,y));
}
