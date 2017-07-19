#ifndef HALFLINGNPC_H
#define HALFLINGNPC_H
#include "halflingNPC.h"

void DwarfNPC::ability() {
	// Vampire are allergic to Dwarf
	// Vampire lose 5 HP instead of gain
}

void DwarfNPC::notify(PC &whoNotified) {
	// if near Dwarf attacks
}

DwarfNPC::DwarfNPC(int x, int y, Tile *t, Gold *g) {
	this->setStats(100, 20, 30);
	this->setDisp('W');
	this->setType("DwarfNPC");
	this->turnHostile();

/*
	void setCoords(int x, int y);
	void setTile(Tile *t);
	addLoot(int money)
*/
}

DwarfNPC::~DwarfNPC() {}

#endif
