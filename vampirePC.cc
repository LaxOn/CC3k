#include "vampirePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "factory.h"

void VampirePC::attack(NPC& enemy){
	int hit = 1;
	if (enemy.getType() == "halflingNPC") {
		Factory f;
		hit = f.randInt(1);
	}
	if (hit) {
		int damage = calcDmg(this->getAtk(), enemy.getDef());
		enemy.changeHP(-damage, false);
		if (enemy.getType() == "dwarfNPC") this->changeHP(-5, false);
		else this->changeHP(5, false);
	}
}

void VampirePC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);
}

void VampirePC::nextTurn(){
	this->notifyNPCs();
	this->notifyDisplay();
}

VampirePC::VampirePC(int x, int y, Tile *t) {
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5); // special ability
	this->setMaxHP(150);
	this->setType("VampirePC");
	this->setCoords(x,y);
	this->setTile(t);
}

VampirePC::~VampirePC() {}
