#include "humanNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"

void HumanNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		willAttack();
	}
}

void HumanNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(1);
	if (hit) player.defendFrom(*this);
}

void HumanNPC::nextTurn() {
	 justAttacked();
}

HumanNPC::HumanNPC(int x, int y, Tile *t) {
	this->setStats(150, 20, 20);
	this->setDisp('H');
	this->setType("HumanNPC");
	this->setCoords(x,y);
	this->setTile(t);
}

HumanNPC::~HumanNPC() {}
