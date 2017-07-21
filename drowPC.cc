#ifndef DROWPC_H
#define DROWPC_H
#include "drowPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void DrowPC::attack(NPC& enemy) override{
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void DrowPC::defendFrom(NPC& enemy) override{
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void DrowPC::nextTurn() override{
	// nothing
}

DrowPC::DrowPC(int x, int y) {
	// Tile *address should be set when a DrowPC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5); // special ability
	this->setMaxHP(150);
	this->setType("DrowPC");
	setCoords(int x, int y);
}

DrowPC::~DrowPC() {}

#endif
