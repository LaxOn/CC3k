#include "orcNPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "info.h"
#include "factory.h"

void OrcNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		willAttack();
	}
}

void OrcNPC::attack(PC &player) {
	Factory f;
	int notMiss = f.randInt(1);
	if (notMiss) player.defendFrom(*this);
}

void OrcNPC::nextTurn() {
	 justAttacked();
}

OrcNPC::OrcNPC(int x, int y, Tile *t) {
	this->setStats(180, 30, 25);
	this->setDisp('O');
	this->setType("OrcNPC");
	this->setCoords(x,y);
	this->setTile(t);
}

OrcNPC::~OrcNPC() {}
