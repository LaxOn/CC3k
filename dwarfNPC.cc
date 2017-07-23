#ifndef DWARFNPC_CC
#define DWARFNPC_CC
#include "dwarfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void DwarfNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void DwarfNPC::attack(PC &player){
	player.defendFrom(*this);
}

void DwarfNPC::nextTurn(){

}

DwarfNPC::DwarfNPC(int x, int y) {
	// Tile *address should be set when a DwarfPC is created
	this->setStats(100, 20, 30);
	this->setDisp('W');
	this->setType("DwarfNPC");
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
}

DwarfNPC::~DwarfNPC() {}

#endif
