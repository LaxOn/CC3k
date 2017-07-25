#include "dwarfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"

void DwarfNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		willAttack();
	}
}

void DwarfNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(2);
	if (hit) player.defendFrom(*this);
}

void DwarfNPC::nextTurn() {
	 justAttacked();
}

DwarfNPC::DwarfNPC(int x, int y, Tile *t) {
	this->setStats(100, 20, 30);
	this->setDisp('W');
	this->setType("DwarfNPC");
	this->setCoords(x,y);
	this->setTile(t);
}

DwarfNPC::~DwarfNPC() {}
