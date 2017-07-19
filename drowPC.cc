#ifndef DROWPC_H
#define DROWPC_H
#include "drowPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"

void DrowPC::attack(NPC& enemy) override{

}

void DrowPC::defendFrom(NPC& enemy) override{

}

void DrowPC::nextTurn() override{

}

DrowPC::DrowPC(int x, int y, Tile *t, Display *disp) {
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5); // special ability
	this->setMaxHP(150);
	this->setType("DrowPC");
}

/*
	setCoords(int x, int y);
	setTile(Tile *t);
	attach(Display *disp)
*/

DrowPC::~DrowPC() {}

#endif
