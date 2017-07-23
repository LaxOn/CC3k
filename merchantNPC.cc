#include "merchantNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"

void MerchantNPC::notify(PC &whoNotified){
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		attack(whoNotified);
	}
}

void MerchantNPC::attack(PC &player){
	player.defendFrom(*this);
}

void MerchantNPC::nextTurn(){

}

MerchantNPC::MerchantNPC(int x, int y) {
	// Tile *address should be set when a MerchantPC is created
	this->setStats(30, 70, 5);
	this->setDisp('M');
	this->setType("MerchantNPC");
	this->cannotMove();
	this->setCoords(x,y);

	// addLoot(int money)
	// drops merchant loot
}

MerchantNPC::~MerchantNPC() {}
