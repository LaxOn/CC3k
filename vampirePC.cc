#include "vampirePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"

void VampirePC::attack(NPC& enemy){
	int damage = calcDmg(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// gain 5 HP every successful attack
		// except dwarf lose 5 instead
	// 50% chance to miss against halfling
}

void VampirePC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void VampirePC::nextTurn(){
	// nothing
}

VampirePC::VampirePC(int x, int y, Tile *t, std::shared_ptr<Display> D) {
	// Tile *address should be set when a VampirePC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5); // special ability
	this->setMaxHP(150);
	this->setType("VampirePC");
	this->setCoords(x,y);
	this->setTile(t);
	this->attach(D);
}

VampirePC::~VampirePC() {}
