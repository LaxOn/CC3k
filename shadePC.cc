#include "shadePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"

void ShadePC::attack(NPC& enemy){
	int damage = calcDmg(this->getAtk(), enemy.getDef());
	enemy.changeHP(-damage, false);
	// 50% chance to miss against halfling
}

void ShadePC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void ShadePC::nextTurn(){
	// nothing
}

ShadePC::ShadePC(int x, int y, Tile *t, std::shared_ptr<Display> D) {
	// Tile *address should be set when a ShadePC is created
	// all the NPC should be set as observers (with attach)
	// Display should also be set as an observer (with attach)
	this->setStats(125, 25, 25);
	this->setMaxHP(125);
	this->setType("ShadePC");
	this->setCoords(x,y);
	this->setTile(t);
	this->attach(D);
}

ShadePC::~ShadePC() {}
