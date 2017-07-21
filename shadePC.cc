#ifndef SHADEPC_H
#define SHADEPC_H
#include "shadePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void ShadePC::attack(NPC& enemy) override{
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void ShadePC::defendFrom(NPC& enemy) override{
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void ShadePC::nextTurn() override{
	// nothing
}

ShadePC::ShadePC(int x, int y) {
	// Tile *address should be set when a ShadePC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(125, 25, 25);
	this->setMaxHP(125);
	this->setType("ShadePC");
	setCoords(int x, int y);
}

ShadePC::~ShadePC() {}

#endif
