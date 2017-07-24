#include "halflingNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"

void HalflingNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		willAttack();
	}
}

void HalflingNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(1);
	if (hit) player.defendFrom(*this);
}

void HalflingNPC::nextTurn() {
	 justAttacked();
}

HalflingNPC::HalflingNPC(int x, int y, Tile *t) {
	this->setStats(100, 15, 20);
	this->setDisp('L');
	this->setType("HalflingNPC");
	this->setCoords(x,y);
	this->setTile(t);
}

HalflingNPC::~HalflingNPC() {}
