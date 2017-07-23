#include "trollPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"

void TrollPC::attack(NPC& enemy){
	int damage = calcDmg(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void TrollPC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void TrollPC::nextTurn(){
	this->changeHP(5, false);	// special ability
}

TrollPC::TrollPC(int x, int y) {
	// Tile *address should be set when a TrollPC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(120, 25, 15);
	this->setMaxHP(120);
	this->setType("TrollPC");
	this->setCoords(x,y);
}

TrollPC::~TrollPC() {}
