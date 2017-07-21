#ifndef VAMPIREPC_H
#define VAMPIREPC_H
#include "vampirePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void VampirePC::attack(NPC& enemy) override{
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// gain 5 HP every successful attack
		// except dwarf lose 5 instead
	// 50% chance to miss against halfling
}

void VampirePC::defendFrom(NPC& enemy) override{
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void VampirePC::nextTurn() override{
	// nothing
}

VampirePC::VampirePC(int x, int y) {
	// Tile *address should be set when a VampirePC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5); // special ability
	this->setMaxHP(150);
	this->setType("VampirePC");
	setCoords(int x, int y);
}

VampirePC::~VampirePC() {}
#endif
