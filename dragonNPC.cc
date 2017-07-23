#include "dragonNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void DragonNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
	// near gold as well
}

void DragonNPC::attack(PC &player){
	player.defendFrom(*this);
}

void DragonNPC::nextTurn(){

}

DragonNPC::DragonNPC(int x, int y) {
	
	// Tile *address should be set when a DragonPC is created
	this->setStats(150, 20, 20);
	this->setDisp('D');
	this->setType("DragonNPC");
	this->cannotMove();
	this->turnHostile();
	this->setCoords(x,y);

	// addLoot(int money)
	// guards a treasure
}

DragonNPC::~DragonNPC() {}
