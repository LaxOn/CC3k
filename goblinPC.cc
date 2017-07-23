#include "goblinPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"

void GoblinPC::attack(NPC& enemy){
	int damage = calcDmg(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// should steal 5 gold every successful hit
	// 50% chance to miss against halfling
}

void GoblinPC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void GoblinPC::nextTurn(){
	// nothing
}

GoblinPC::GoblinPC(int x, int y, Tile *t, std::shared_ptr<Display> D) {
	// Tile *address should be set when a GoblinPC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(110, 15, 20);
	this->setMaxHP(110);
	this->setType("GoblinPC");
	this->setCoords(x, y);
	this->setTile(t);
	this->attach(D);
}

GoblinPC::~GoblinPC() {}
