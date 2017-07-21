#ifndef HUMANNPC_H
#define HUMANNPC_H
#include "humanNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"

void HumanNPC::notify(PC &whoNotified) override {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HumanNPC::attack(PC &player) override {
	player.defendFrom(*this);
}

void HumanNPC::nextTurn() override {

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
