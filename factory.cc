#include "factory.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "character.h"
#include "humanNPC.h"
#include "dwarfNPC.h"
#include "elfNPC.h"
#include "orcNPC.h"
#include "merchantNPC.h"
#include "dragonNPC.h"
#include "halflingNPC.h"
#include "shadePC.h"
#include "drowPC.h"
#include "vampirePC.h"
#include "trollPC.h"
#include "goblinPC.h"
#include "tile.h"
#include "basictile.h"
#include "info.h"
#include <memory>
#include <iostream>
using namespace std;

int Factory::randInt(int max) {
	srand(time(NULL));
	double rawNum = double(rand()) / double(RAND_MAX);
	return int(rawNum * double(max));
}

void Factory::addDragon(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	t.addObject(make_shared<DragonNPC>(x,y,&t));
}

void Factory::addMercant(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	t.addObject(make_shared<MerchantNPC>(x,y,&t));
}

void Factory::addPC(Tile &t, char race) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	if (race == 's') t.addObject(make_shared<ShadePC>(x,y,&t,D));
	else if (race == 'd') t.addObject(make_shared<DrowPC>(x,y,&t,D));
	else if (race == 'v') t.addObject(make_shared<VampirePC>(x,y,&t,D));
	else if (race == 'g') t.addObject(make_shared<GoblinPC>(x,y,&t,D));
	else if (race == 't') t.addObject(make_shared<TrollPC>(x,y,&t,D));
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
	if (enemyNum == human) t.addObject(make_shared<HumanNPC>(x,y,&t));
	else if (enemyNum == dwarf) t.addObject(make_shared<DwarfNPC>(x,y,&t));
	else if (enemyNum == elf) t.addObject(make_shared<ElfNPC>(x,y,&t));
	else if (enemyNum == orc) t.addObject(make_shared<OrcNPC>(x,y,&t));
	else if (enemyNum == halfling) t.addObject(make_shared<HalflingNPC>(x,y,&t));
}

Factory::Factory(shared_ptr<Display> D): D{D} {}

Factory::~Factory() {}
