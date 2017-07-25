#include "elfNPC.h"
#include "character.h"
#include "object.h"
#include "npc.h"
#include "pc.h"
#include "info.h"
#include "factory.h"

void ElfNPC::notify(PC &whoNotified) {
	if (this->isNear(this->getInfo(), whoNotified.getInfo())) {
		willAttack();
	}
}

void ElfNPC::attack(PC &player) {
	Factory f;
	int hit = f.randInt(2);
	if (hit) player.defendFrom(*this);
	if (player.getType() != "DrowPC") {
		int hit = f.randInt(2);
		if (hit) player.defendFrom(*this);
	}
}

void ElfNPC::nextTurn() {
	 justAttacked();
}

ElfNPC::ElfNPC(int x, int y, Tile *t) {
	this->setStats(140, 30, 10);
	this->setDisp('E');
	this->setType("ElfNPC");
	this->setCoords(x,y);
	this->setTile(t);
}

ElfNPC::~ElfNPC() {}
