#ifndef HALFLINGNPC_CC
#define HALFLINGNPC_CC
#include "halflingNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void HalflingNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HalflingNPC::attack(PC &player){
	player.defendFrom(*this);
}

void HalflingNPC::nextTurn(){

}

HalflingNPC::HalflingNPC(int x, int y) {
	// Tile *address should be set when a HalflingPC is created
	this->setStats(100, 15, 20);
	this->setDisp('L');
	this->setType("HalflingNPC");
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
}

HalflingNPC::~HalflingNPC() {}

#endif
