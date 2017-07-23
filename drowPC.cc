#ifndef DROWPC_CC
#define DROWPC_CC
#include "drowPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"

void DrowPC::attack(NPC& enemy){
	int damage = damageCalc(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void DrowPC::defendFrom(NPC& enemy){
	int damage = damageCalc(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void DrowPC::nextTurn(){
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
	this->setCoords(x, y);
}

DrowPC::~DrowPC() {}

#endif
