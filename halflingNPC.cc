#include "halflingNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void HalflingNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HalflingNPC::attack(PC &player){
	player.defendFrom(*this);
}

void HalflingNPC::nextTurn(){

}

HalflingNPC::HalflingNPC(int x, int y, Tile *t) {
	this->setStats(100, 15, 20);
	this->setDisp('L');
	this->setType("HalflingNPC");
	this->turnHostile();
	this->setCoords(x,y);
	this->setTile(t);

	// addLoot(int money)
}

HalflingNPC::~HalflingNPC() {}
