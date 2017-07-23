#include "orcNPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "info.h"

void OrcNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void OrcNPC::attack(PC &player){
	// gets 50% more damage to goblins
	player.defendFrom(*this);
}

void OrcNPC::nextTurn(){

}

OrcNPC::OrcNPC(int x, int y, Tile *t) {
	this->setStats(180, 30, 25);
	this->setDisp('O');
	this->setType("OrcNPC");
	this->turnHostile();
	this->setCoords(x,y);
	this->setTile(t);

	// addLoot(int money)
	// guards a treasure
}

OrcNPC::~OrcNPC() {}
