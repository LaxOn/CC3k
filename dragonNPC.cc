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

}

void DragonNPC::defendFrom(PC &player) override {

}

void DragonNPC::nextTurn() override {

}

DragonNPC::DragonNPC(int x, int y, Tile *t, Gold *g) {
	this->setStats(150, 20, 20);
	this->setDisp('D');
	this->setType("DragonNPC");
	this->cannotMove();
	this->turnHostile();

/*
	void setCoords(int x, int y);
	void setTile(Tile *t);
	addLoot(int money)
*/
}

DragonNPC::~DragonNPC() {}

#endif
