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
	Tile *nb = t->getNeighbr(dir);
	if ((!nb->getType()) && nb->getObject() &&
		(nb->getObject())->getDisp()=='P') {
			t->useItemOn(dir, *this);
			D->update(*getTile(), getType());
	} // else throw an exception because there are no potions there 
}

void PC::attackDir(int dir) {
	Tile *t = this->getTile();
	Tile *nb = t->getNeighbr(dir);
	if ((!nb->getType()) && nb->getOccupy() && nb->getNPC()) {
		attack(*(nb->getNPC()));
		D->update(*getTile(), getType());
	} // else throw an exception because there are no NPCs here
}

void PC::addMoney(int money) {
	this->money += money;
}

int PC::getMoney() { return money; }

void PC::move(int dir) {
	std::cout << "before moving: " <<x <<" " <<y <<std::endl;
	Tile *t = this->getTile();
	Tile *nb = t->getNeighbr(dir);

	std::cout << (nb->getType()<=3 && !nb->getOccupy()) <<std::endl;
	if (nb->getType()<=3 && !nb->getOccupy()) {

		std::cout << "before moveObj" <<std::endl;
		t->moveObj(dir);

		std::cout << "after moveObj" <<std::endl;
		notifyDisplay();

		//D->update(*nb, ".");
	}
	std::cout << "after moving: " <<x <<" " <<y <<std::endl;
	// else throw an exception because it can't go there;
}

void PC::attach(std::shared_ptr<NPC> ob) {
	++numNPCs;
	//std::std::cout << "attaching NPC" <<std::std::endl;
	NPCs.resize(numNPCs);

	//std::std::cout << "resizing NPC" <<std::std::endl;
	NPCs.back() = ob;

	//std::std::cout << "vector stuff" <<std::std::endl;
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
	D.setRace(*this);
	notifyDisplay();
}

void PC::notifyDisplay(std::string desc) {
	D->setGold(*this);
	D->setHP(*this);
	D->setAtk(*this);
	D->setDef(*this);
	if (desc != "") D->setAction(desc);
	D->update(*getTile(), getType());
}

PC::PC() {
	this->setDisp('@');
}

PC::~PC() {}
