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
#include "basicpotion.h"
#include "restorehealth.h"
#include "boostatk.h"
#include "boostdef.h"
#include "poisonhealth.h"
#include "woundatk.h"
#include "wounddef.h"
#include "gold.h"
#include "passage.h"
#include "basictile.h"
#include "stairs.h"
#include "door.h"
#include "wall.h"
#include "none.h"
#include "info.h"
#include <memory>
#include <cstdlib>
#include <iostream>

using namespace std;


// returns a pseudo-random number [0 to 9)
int Factory::randInt(int max) {
	double rawNum = double(rand()) / double(RAND_MAX);
	int result = rawNum * double(max);
	if (result == max) return randInt(max);
	else return result;
}

void Factory::addDragon(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	t.addNPC(make_shared<DragonNPC>(x,y,&t));
	player->attach(t.getNPC());
	t.setOccupy(true);
}

void Factory::addGold(Tile &t) {
	//cout << "tracker 3 " << endl;
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;

	const int small = 1;
	const int normal = 6;
	const int dragon = 7;

	int goldNum = randInt(8);
	//cout << "goldNum is " << goldNum << endl;

	if (goldNum <= small) {
		t.addObject(make_shared<Gold>(1,x,y,false));
		t.setOccupy(true);
	} else if (goldNum <= normal) {
		t.addObject(make_shared<Gold>(2,x,y,false));
		t.setOccupy(true);
	} else if (goldNum <= dragon) {
		//cout << "checking dragon hoard 1" << endl;
		// check if there are empty neighbours
		int freeNeigbrs = 0;
		Tile *nb;
		for(int i=0; i<=7; ++i) {
			nb = t.getNeighbr(i);
			if (nb->getType()==0 && !nb->getOccupy()) {
				++freeNeigbrs;
			}
		}
		// randomize among neighbours
		//cout << "number of free neighbours is " << freeNeigbrs << endl;
		if (freeNeigbrs) {
			int randNum = randInt(freeNeigbrs) +1;
			int dragonIndex = 0;
			while (randNum) {
				nb = t.getNeighbr(dragonIndex);
				if (!nb->getOccupy()) --randNum;
				++dragonIndex;
			}
			--dragonIndex;
			// add the gold and the dragon
			//cout << "constructing dragon hoard" << endl;
			t.addObject(make_shared<Gold>(6,x,y,true));
			t.setOccupy(true);
			Tile *dragonTile = t.getNeighbr(dragonIndex);
			addDragon(*dragonTile);
			dragonTile->setOccupy(true);
			(dragonTile->getNPC())->guardGold(t);
			D->update(*dragonTile, (dragonTile->getNPC())->getType());
		} else { 
			addGold(t); 
		}
		//cout << "checking dragon hoard 2" << endl;
	}
}

void Factory::addPC(Tile &t, string race) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	if (race == "s") t.addPC(make_shared<ShadePC>(x,y,&t));
	else if (race == "d") t.addPC(make_shared<DrowPC>(x,y,&t));
	else if (race == "v") t.addPC(make_shared<VampirePC>(x,y,&t));
	else if (race == "g") t.addPC(make_shared<GoblinPC>(x,y,&t));
	else if (race == "t") t.addPC(make_shared<TrollPC>(x,y,&t));
	player = t.getPC();
	//player->attach(*D);
	t.setOccupy(true);
}

void Factory::addEnemy(Tile &t) {
	//cout << "the tile type is " << t.getType() << endl;
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	const int human = 3;
	const int merchant = 5;
	const int dwarf = 8;
	const int halfling = 13;
	const int elf = 15;
	const int orc = 17;
	int enemyNum = randInt(18);
	if (enemyNum <= human) t.addNPC(make_shared<HumanNPC>(x,y,&t));
	else if (enemyNum <= merchant) t.addNPC(make_shared<MerchantNPC>(x,y,&t));
	else if (enemyNum <= dwarf) t.addNPC(make_shared<DwarfNPC>(x,y,&t));
	else if (enemyNum <= halfling) t.addNPC(make_shared<HalflingNPC>(x,y,&t));
	else if (enemyNum <= elf) t.addNPC(make_shared<ElfNPC>(x,y,&t));
	else if (enemyNum <= orc) t.addNPC(make_shared<OrcNPC>(x,y,&t));
	player->attach(t.getNPC());
	t.setOccupy(true);
	int loot;
	if (enemyNum <= human || enemyNum <= merchant) loot = 4;
	else loot = randInt(2) + 1;
	t.getNPC()->addLoot(loot);
	D->update(t, (t.getNPC())->getType());
}

void Factory::addPotion(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	const int RH = 0;
	const int BA = 1;
	const int BD = 2;
	const int PH = 3;
	const int WA = 4;
	const int WD = 5;
	int potionNum = randInt(6);
	if (potionNum == RH) t.addObject(make_shared<RestoreHealth>
		(make_shared<BasicPotion>(0,"", true, x, y)));
	else if (potionNum == BA) t.addObject(make_shared<BoostAtk>
		(make_shared<BasicPotion>(0,"", false, x, y)));
	else if (potionNum == BD) t.addObject(make_shared<BoostDef>
		(make_shared<BasicPotion>(0,"", false, x, y)));
	else if (potionNum == PH) t.addObject(make_shared<PoisonHealth>
		(make_shared<BasicPotion>(0,"", true, x, y)));
	else if (potionNum == WA) t.addObject(make_shared<WoundAtk>
		(make_shared<BasicPotion>(0,"", false, x, y)));
	else if (potionNum ==WD) t.addObject(make_shared<WoundDef>
		(make_shared<BasicPotion>(0,"", false, x, y)));
	t.setOccupy(true);
}

Factory::Factory() {}

Factory::Factory(Display &D): D{&D} {}

Factory::~Factory() {}
