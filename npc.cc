#include <string>
#include <vector>
#include "npc.h"
#include "pc.h"
#include "factory.h"
#include "tile.h"

void NPC::move() {
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
			int randNum = f.randInt(count - 1) + 1;
			int index = 0;
			while (randNum) {
				nb = t->getNeighbr(index);
				if (!nb->getType() && !nb->getOccupy()) --randNum;
				++index;
			}
			--index;
			t->moveObj(index);
		} // else there's no space to move out of
	} // can't move so stays in the same place
}

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

void NPC::addLoot(int money) {
	loot += money;
}

int NPC::getMoney() { return loot; }

NPC::NPC() {}

NPC::~NPC() {}

/*
takeNPC(Tile *) {}
takePC(Tile *) {}
t->moveObj(index);
	std::shared_ptr<Tile> nb = getNeighbr(index);
	if (PCobj) {
		nb->takeNPC(this)
	
	} else if (NPCobj) {
	
	}
			 	// calls Tile it currently in with the directions to go
 	// Tile call the neighbour
 	// set Nieghbours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself
*/

