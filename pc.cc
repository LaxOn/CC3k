#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "pc.h"
#include "npc.h"
#include "display.h"
#include "tile.h"
#include "slap.h"
#include "dungeon.h"	

std::string PC::dirToStr(int dir) {
	if (dir == 0) return "North West";
	else if (dir == 1) return "North";
	else if (dir == 2) return "North East";
	else if (dir == 3) return "West";
	else if (dir == 4) return "East";
	else if (dir == 5) return "South West";
	else if (dir == 6) return "South";
	else if (dir == 7) return "South East";
	else return "";
}


void PC::useItem(int dir) {
	Tile *t = this->getTile();
	Tile *nb = t->getNeighbr(dir);
	if ((!nb->getType()) && nb->getObject() &&
		(nb->getObject())->getDisp()=='P') {
			t->useItemOn(dir, *this);
			nb->resetItem();
		 	D->update(*(t->getNeighbr(dir)), ".");
			notifyDisplay("PC uses the Potion in the " + dirToStr(dir) + ".");
	} else {
		throw Slap("There is no Potion in the given direction. Try again.");
	}
}

void PC::attackDir(int dir) {
	Tile *t = this->getTile();
	Tile *nb = t->getNeighbr(dir);
	if ((!nb->getType()) && nb->getOccupy() && nb->getNPC()) {
		attack(*(nb->getNPC()));
		if ((nb->getNPC())->getType() == "MerchantNPC") {
			(nb->getNPC())->turnHostile();
		}
		if ((nb->getNPC())->getHP() <= 0) {
			if ((nb->getNPC())->getType() == "DragonNPC") {
				(((nb->getNPC())->getGold())->getObject())->allowPickup();
			}
			D->update(*nb, ".");
			
			addMoney((nb->getNPC())->getLoot());
			nb->setOccupy(false);
			nb->resetNPC();

			std::cout <<"ran this" <<std::endl;
			notifyDisplay("PC attacks an Enemy in the "
				+ dirToStr(dir) + ". Enemy has died.");
		} else {
			notifyDisplay("PC attacks an Enemy in the "
				+ dirToStr(dir) + ". Enemy has " + 
				std::to_string(nb->getNPC()->getHP()) + " remaining HP.");
		}
	} else {
		throw Slap("No one to attack in the given direction. Try again.");
	}
}

void PC::addMoney(int money) {
	this->money += money;
}

int PC::getMoney() { return money; }

void PC::move(int dir) {
	Tile *t = this->getTile();
	Tile *nb = t->getNeighbr(dir);
	std::shared_ptr<Item> it;
	if (nb->getType() != 2) it = nb->getObject();
	//std::cout << nb->getOccupy() << std::endl;
	if (nb->getType() == 2) {
		notifyDisplay("PC descends to the next floor");
		notifyNPCs();
		dungeon->descend(this);
	} else if (nb->getType()<=3 && (!nb->getOccupy())) {
		t->moveObj(dir);
		notifyDisplay("PC moves " + dirToStr(dir) + ".");
		notifyNPCs();
		//std::cout <<NPCs.size() <<std::endl;
	} else if (it &&  (it->getDisp() == 'G')) {
		if (!(it->getDrgn()) || (it->getSlain())) {
			addMoney(it->getValue());
			nb->resetItem();
		 	D->update(*(t->getNeighbr(dir)), ".");
		}
		t->moveObj(dir);
		notifyDisplay("PC moves " + dirToStr(dir) + " and gains Gold.");
		notifyNPCs();
	} else {
		throw Slap("Can't move in the given direction. Try again.");
	}
}

void PC::attach(std::shared_ptr<NPC> ob) {
	//NPCs.emplace_back(ob)
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

void PC::setDungeon(Dungeon *d) {
	this->dungeon = d;
}

void PC::notifyDisplay(std::string desc) {
	D->setGold(*this);
	D->setHP(*this);
	D->setAtk(*this);
	D->setDef(*this);
	D->setAction(desc);
	D->update(*getTile(), getType());
}

Display *PC::getDisplay() {
	return D;
}

PC::PC() {
	this->setDisp('@');
}

PC::~PC() {}
