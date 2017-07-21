#ifndef HALFLINGNPC_H
#define HALFLINGNPC_H
#include "halflingNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"

void HalflingNPC::notify(PC &whoNotified) override {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HalflingNPC::attack(PC &player) override {
	player.defendFrom(*this);
}

void HalflingNPC::nextTurn() override {

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
