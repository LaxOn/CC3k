#ifndef TROLLPC_H
#define TROLLPC_H
#include "trollPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void TrollPC::attack(NPC& enemy) override{
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void TrollPC::defendFrom(NPC& enemy) override{
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void TrollPC::nextTurn() override{
	this->changeHP(5, false);	// special ability
}

TrollPC::TrollPC(int x, int y) {
	// Tile *address should be set when a TrollPC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(120, 25, 15);
	this->setMaxHP(120);
	this->setType("TrollPC");
	setCoords(int x, int y);
}

TrollPC::~TrollPC() {}

#endif
