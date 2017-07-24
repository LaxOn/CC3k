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
	t.addNPC(make_shared<DragonNPC>(x,y,&t));
	player->attach(t.getNPC());
}

void Factory::addPC(Tile &t, char race) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	if (race == 's') t.addPC(make_shared<ShadePC>(x,y,&t,D));
	else if (race == 'd') t.addPC(make_shared<DrowPC>(x,y,&t,D));
	else if (race == 'v') t.addPC(make_shared<VampirePC>(x,y,&t,D));
	else if (race == 'g') t.addPC(make_shared<GoblinPC>(x,y,&t,D));
	else if (race == 't') t.addPC(make_shared<TrollPC>(x,y,&t,D));
	player = t.getPC();
}

void Factory::addEnemy(Tile &t) {
	Info tInfo = t.getInfo();
	int x = tInfo.x;
	int y = tInfo.y;
	const int human = 4;
	const int dwarf = 7;
	const int halfling = 12;
	const int elf = 14;
	const int orc = 16;
	const int merchant = 18;
	int enemyNum = randInt(17);
	if (enemyNum < human) t.addNPC(make_shared<HumanNPC>(x,y,&t));
	else if (enemyNum < dwarf) t.addNPC(make_shared<DwarfNPC>(x,y,&t));
	else if (enemyNum < halfling) t.addNPC(make_shared<HalflingNPC>(x,y,&t));
	else if (enemyNum < elf) t.addNPC(make_shared<ElfNPC>(x,y,&t));
	else if (enemyNum < orc) t.addNPC(make_shared<OrcNPC>(x,y,&t));
	else if (enemyNum < merchant) t.addNPC(make_shared<MerchantNPC>(x,y,&t));
	player->attach(t.getNPC());
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
	int potionNum = randInt(5);
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
}

Factory::Factory(shared_ptr<Display> D): D{D} {}

Factory::~Factory() {}
