#ifndef PC_H
#define PC_H
#include "pc.h"
#include "npc.h"

void PC::useItem() {
	item->useItem(this);
	// should be deleted???
}

void PC::pickUpItem(Potion *item) {
	this->item = item;
	// how to pickup item
}

void PC::getGold(Gold &gold) {
	// ask judy how to get gold
}

void PC::move(char dir) {
	// dir correponds to a certain direction
	// call old tile to be removed
	// call new tile to be in
}

void PC::attack(NPC& enemy) {
	enemy.defendFrom(this);
}

void PC::defendFrom(NPC& enemy) {
		// look at paper
}

void PC::attach(NPC* ob) {
	NPCs.emplace_back(ob);
	++numNPCs;
}

void PC::detach(NPC* ob) {
	auto it = std::find(NPCs.begin(), NPCs.end(), ob);
	if (it != v.end()) {
	  	std::swap(*it, v.back());
		v.pop_back();
		--numNPCs;
	}
}

void PC::notifyNPCs() {
	for (auto ob : NPCs) ob->notify(*this);
}

void PC::attach(Display *disp) {
	this->disp = disp;

}

void PC::notifyDisplay() {
	disp->notify(*this);
	// add notify to Display
}

PC::PC() {
	this->setDisp('@');
}

PC::~PC() {}

#endif
