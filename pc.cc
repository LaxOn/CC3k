#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include "pc.h"
#include "npc.h"
#include "display.h"
#include "tile.h"				

void PC::useItem(int dir) {
	Tile *t = this->getTile();
	std::shared_ptr<Tile> nb = t->getNeighbr(dir);
	if ((!nb->getType()) && nb->getOccupy() &&
		(nb->getObject())->getDisp()=='P') {
			t->useItemOn(dir, *this);
	} // else throw an exception because there are no potions there 
}

void PC::addMoney(int money) {
	this->money += money;
}

int PC::getMoney() { return money; }

void PC::move(int dir) {
	
	Tile *t = this->getTile();
	std::shared_ptr<Tile> nb = t->getNeighbr(dir);
	if (nb->getType()<=3 && !nb->getOccupy()) t->moveObj(dir);
	// else throw an exception because it can't go there;
}

void PC::attach(std::shared_ptr<NPC> ob) {
	NPCs.emplace_back(ob);
	++numNPCs;
}

void PC::detach(std::shared_ptr<NPC> ob) {
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

void PC::attach(Display &D) { 
	this->D = &D; 
	D.update(*getTile(), getType());
}

void PC::notifyDisplay() {
	D->update(this);
}

PC::PC() {
	this->setDisp('@');
}

PC::~PC() {}
