#include "dragonNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"
#include "tile.h"
#include "basictile.h"

void DragonNPC::notify(PC &whoNotified) {
	Info DragonInfo = this->getInfo();
	Info DHoardInfo = (goldTile->getObject(1))->getInfo();
	if (this->isNear(DragonInfo, whoNotified.getInfo()) || 
	 	(this->isNear(DHoardInfo, whoNotified.getInfo()))) {
			willAttack();
	}
}

void DragonNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(1);
	if (hit) player.defendFrom(*this);
}

void DragonNPC::nextTurn() { 
	 justAttacked();
}

DragonNPC::DragonNPC(int x, int y, Tile *t) {
	this->setStats(150, 20, 20);
	this->setDisp('D');
	this->setType("DragonNPC");
	this->cannotMove();
	this->setCoords(x,y);
	this->setTile(t);
}

DragonNPC::~DragonNPC() {}
