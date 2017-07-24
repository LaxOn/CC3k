#include <string>
#include <vector>
#include "npc.h"
#include "pc.h"

void NPC::move() {
 	// calls Tile it currently in wiht the directions to go
 	// TIle call the neighbour
 	// set Nieghtnours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself
	if (canMove) {
		// random number from 1 to x
			// x is number of unoccupied adjacent tile
		// call old tile to be removed
		// call new tile to be in
	}
}

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
