#include "drowPC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "factory.h"

void DrowPC::attack(NPC& enemy) {
	int hit = 1;
	if (enemy.getType() == "halflingNPC") {
		Factory f;
		hit = f.randInt(2);
	}
	if (hit) {
		int damage = calcDmg(this->getAtk(), enemy.getDef());
		enemy.changeHP(-damage, false);
	}
}

void DrowPC::defendFrom(NPC& enemy) {
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);

	string temp = enemy.getType();
	string attacker = temp.substr(0, temp.length() - 3);
	this->notifyDisplay(attacker + " attacks PC!");
}

void DrowPC::nextTurn() {
	this->notifyNPCs();
	this->notifyDisplay();
}

DrowPC::DrowPC(int x, int y, Tile *t) {
	this->setStats(150, 25, 15);
	this->setPotionMult(1.5);
	this->setMaxHP(150);
	this->setType("DrowPC");
	this->setCoords(x, y);
	this->setTile(t);
}

DrowPC::~DrowPC() {}
