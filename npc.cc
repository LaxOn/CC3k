#ifndef NPC_H
#define NPC_H
#include <string>
#include <vector>
#include "npc.h"
#include "pc.h"

void NPC::move() {
	if (canMove) {
		// random number from 1 to x
			// x is number of unoccupied adjacent tile
		// call old tile to be removed
		// call new tile to be in
	}
}

void NPC::attack(PC &player) {
	player.defendFrom(this);
}

void NPC::defendFrom(PC &player) {
	// look at paper
}

void NPC::turnHostile() {
	hostile = true;
}

void NPC::cannotMove() {
	canMove = false;
}

void NPC::addLoot(int money) {
	
	// lol idk ask Judy
}

NPC::NPC() {}

NPC::~NPC() {}


#endif
