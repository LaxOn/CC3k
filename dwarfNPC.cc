#include "dwarfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void DwarfNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void DwarfNPC::attack(PC &player){
	player.defendFrom(*this);
}

void DwarfNPC::nextTurn(){

}

DwarfNPC::DwarfNPC(int x, int y, Tile *t) {
	this->setStats(100, 20, 30);
	this->setDisp('W');
	this->setType("DwarfNPC");
	this->turnHostile();
	this->setCoords(x,y);
	this->setTile(t);

	// addLoot(int money)
}

DwarfNPC::~DwarfNPC() {}
