#include <string>
#include <vector>
#include "npc.h"
#include "pc.h"
#include "factory.h"
#include "tile.h"

void NPC::move(Display &D) {
	if (canMove) {
		Tile *t = this->getTile();
		int count = 0;
		Tile *nb;
		for(int i=0; i<=7; ++i) {
			nb = t->getNeighbr(i);
			if (!nb->getType() && !nb->getOccupy()) ++count;
		}
		if (count) {
			Factory f;
			int randNum = f.randInt(count) + 1;
			int index = 0;
			while (randNum) {
				nb = t->getNeighbr(index);
				if (!nb->getType() && !nb->getOccupy()) --randNum;
				++index;
			}
			--index;
			D.update(*getTile(), ".");
			t->moveObj(index);
			D.update(*getTile(), getType());
		} // else there's no space to move out of
	} // can't move so stays in the same place
}

Tile *NPC::getGold() { return goldTile; }

bool NPC::pcInRange() { return attackPC; }

void NPC::guardGold(Tile &goldTile) {
	this->goldTile = &goldTile;
}

void NPC::justAttacked() {
	attackPC = false;
}

void NPC::willAttack() {
	attackPC = true;
}

void NPC::attack(PC &player) {
	player.defendFrom(*this);
}

void NPC::cannotMove() {
	canMove = false;
}

void NPC::freeze(bool b) {
	if (this->getType() != "DragonNPC" &&
		this->getType() != "MerchantNPC") {
		canMove = b;
	}
}

void NPC::addLoot(int money) {
	loot += money;
}

int NPC::getLoot() { return loot; }

void NPC::turnHostile() {}

NPC::NPC() {}

NPC::~NPC() {}
