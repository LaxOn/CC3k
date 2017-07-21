#ifndef DRAGONNPC_H
#define DRAGONNPC_H
#include "dragonNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"

void DragonNPC::notify(PC &whoNotified) override {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void DragonNPC::attack(PC &player) override {
	player.defendFrom(*this);
}

void DragonNPC::nextTurn() override {

}

DragonNPC::DragonNPC(int x, int y) {
	// Tile *address should be set when a DragonPC is created
	this->setStats(150, 20, 20);
	this->setDisp('D');
	this->setType("DragonNPC");
	this->cannotMove();
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
	// guards a treasure
}

DragonNPC::~DragonNPC() {}

#endif
