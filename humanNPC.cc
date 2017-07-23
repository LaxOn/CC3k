#ifndef HUMANNPC_CC
#define HUMANNPC_CC
#include "humanNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void HumanNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HumanNPC::attack(PC &player){
	player.defendFrom(*this);
}

void HumanNPC::nextTurn(){

}

HumanNPC::HumanNPC(int x, int y) {
	// Tile *address should be set when a HumanPC is created
	this->setStats(150, 20, 20);
	this->setDisp('H');
	this->setType("HumanNPC");
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
	// drops 2 normal piles of gold
}

HumanNPC::~HumanNPC() {}

#endif
