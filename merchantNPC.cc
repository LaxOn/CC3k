#include "merchantNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"

bool MerchantNPC::hostile = false;

void MerchantNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		if (hostile) willAttack();
	}
}

void MerchantNPC::turnHostile() {
	hostile = true;
}

void MerchantNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(2);
	if (hit) player.defendFrom(*this);
}

void MerchantNPC::nextTurn() {
	 justAttacked();
}

MerchantNPC::MerchantNPC(int x, int y, Tile *t) {
	this->setStats(30, 70, 5);
	this->setDisp('M');
	this->setType("MerchantNPC");
	this->cannotMove();
	this->setCoords(x,y);
	this->setTile(t);
}

MerchantNPC::~MerchantNPC() {}