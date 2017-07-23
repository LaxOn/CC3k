#include "elfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void ElfNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void ElfNPC::attack(PC &player){
	// attack twice excpet against Drow
	player.defendFrom(*this);
}

void ElfNPC::nextTurn(){

}

ElfNPC::ElfNPC(int x, int y, Tile *t) {
	this->setStats(140, 30, 10);
	this->setDisp('E');
	this->setType("ElfNPC");
	this->turnHostile();
	this->setCoords(x,y);
	this->setTile(t);

	// addLoot(int money)
	// guards a treasure
}

ElfNPC::~ElfNPC() {}
