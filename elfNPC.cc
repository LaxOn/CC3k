#ifndef ELFNPC_H
#define ELFNPC_H
#include "elfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"

void ElfNPC::notify(PC &whoNotified) override {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void ElfNPC::attack(PC &player) override {
	// attack twice excpet against Drow
	player.defendFrom(*this);
}

void ElfNPC::nextTurn() override {

}

ElfNPC::ElfNPC(int x, int y) {
	// Tile *address should be set when a ElfPC is created
	this->setStats(140, 30, 10);
	this->setDisp('E');
	this->setType("ElfNPC");
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
	// guards a treasure
}

ElfNPC::~ElfNPC() {}

#endif
