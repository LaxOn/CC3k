#include <algorithm>
#include <vector>
#include "pc.h"
#include "npc.h"
												// uncomment later
//#include "display.h"					

void PC::useItem(int dir) {
	// picking up potions
	// PC will call useItem(int dir)
		//call soemthing in the tile which passes PC and direction
	// Tile will calls its neighbour
	// neighbour call potion with PC as the parameter
}

void PC::addMoney(int money) {
	// picking up gold
	// Tile will check if PC and a gold is in itself
	// if yes, Tile will call PC
			// .... ask JUDY later
}


int PC::getMoney() { return money; }

void PC::move(int dir) {
	 	// calls Tile it currently in with the directions to go
 	// Tile call the neighbour
 	// set Nieghbours ptr to character
 	// oldTIle = nullptr
 	// newTile call character with itself
}


void PC::attach(NPC* ob) {
	NPCs.emplace_back(ob);
	++numNPCs;
}

void PC::detach(NPC* ob) {
														// look at piazza if it's okay to use algorithm
	auto it = std::find(NPCs.begin(), NPCs.end(), ob);
	if (it != NPCs.end()) {
	  	std::swap(*it, NPCs.back());
		NPCs.pop_back();
		--numNPCs;
	}
}

void PC::notifyNPCs() {
	for (auto ob : NPCs) ob->notify(*this);
}

void PC::attach( std::shared_ptr<Display> D) { this->D = D; }

														// uncomment later
void PC::notifyDisplay() {
	// disp->update(*this);
	// add notify to Display
}

PC::PC() {
	this->setDisp('@');
}

PC::~PC() {}
