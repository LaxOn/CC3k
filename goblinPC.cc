#include "goblinPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "factory.h"

void GoblinPC::attack(NPC& enemy){
	int hit = 1;
	if (enemy.getType() == "halflingNPC") {
		Factory f;
		hit = f.randInt(1);
	}
	if (hit) {
		int damage = calcDmg(this->getAtk(), enemy.getDef());
		enemy.changeHP(-damage, false);
		this->addMoney(5);
	}
}

void GoblinPC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	if (enemy.getType() == "orcNPC") damage *= 1.5;
	this->changeHP(-damage, false);
}

void GoblinPC::nextTurn(){
	this->notifyNPCs();
	this->notifyDisplay();
}

GoblinPC::GoblinPC(int x, int y, Tile *t, std::shared_ptr<Display> D) {
	this->setStats(110, 15, 20);
	this->setMaxHP(110);
	this->setType("GoblinPC");
	this->setCoords(x, y);
	this->setTile(t);
	this->attach(D);
}

GoblinPC::~GoblinPC() {}
