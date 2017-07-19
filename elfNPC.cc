#ifndef ELFNPC_H
#define ELFNPC_H
#include "elfNPC.h"

void ElfNPC::ability() {
	// gets two attacks against every race except drow
}

void ElfNPC::notify(PC &whoNotified) {
	// if PC is near Elf, it attacks
}

ElfNPC::ElfNPC(int x, int y, Tile *t, Gold *g) {
	this->setStats(140, 30, 10);
	this->setDisp('E');
	this->setType("ElfNPC");
	this->turnHostile();

/*
	void setCoords(int x, int y);
	void setTile(Tile *t);
	addLoot(int money)
*/
}

ElfNPC::~ElfNPC() {}

#endif
