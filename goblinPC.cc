#ifndef GOBLINPC_H
#define GOBLINPC_H
#include "goblinPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void GoblinPC::attack(NPC& enemy) override{
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// should steal 5 gold every successful hit
	// 50% chance to miss against halfling
}

void GoblinPC::defendFrom(NPC& enemy) override{
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void GoblinPC::nextTurn() override{
	// nothing
}

GoblinPC::GoblinPC(int x, int y) {
	// Tile *address should be set when a GoblinPC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(110, 15, 20);
	this->setMaxHP(110);
	this->setType("GoblinPC");
	setCoords(int x, int y);
}

GoblinPC::~GoblinPC() {}

#endif
