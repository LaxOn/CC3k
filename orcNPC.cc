#ifndef ORCNPC_CC
#define ORCNPC_CC
#include "orcNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"

void OrcNPC::notify(PC &whoNotified) override {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void OrcNPC::attack(PC &player) override {
	// gets 50% more damage to goblins
	player.defendFrom(*this);
}

void OrcNPC::nextTurn() override {

}

OrcNPC::OrcNPC(int x, int y) {
	// Tile *address should be set when a OrcPC is created
	this->setStats(180, 30, 25);
	this->setDisp('O');
	this->setType("OrcNPC");
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
	// guards a treasure
}

OrcNPC::~OrcNPC() {}

#endif
