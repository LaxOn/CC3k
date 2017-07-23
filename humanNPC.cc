#include "humanNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void HumanNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void HumanNPC::attack(PC &player){
	player.defendFrom(*this);
}

void HumanNPC::nextTurn(){

}

HumanNPC::HumanNPC(int x, int y, Tile *t) {
	this->setStats(150, 20, 20);
	this->setDisp('H');
	this->setType("HumanNPC");
	this->turnHostile();
	this->setCoords(x,y);
	this->setTile(t);

	// addLoot(int money)
	// drops 2 normal piles of gold
}

HumanNPC::~HumanNPC() {}
