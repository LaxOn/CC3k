#include "shadePC.h"
#include "character.h"
#include "object.h"
#include "pc.h"
#include "npc.h"
#include "factory.h"

void ShadePC::attack(NPC& enemy){
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

void ShadePC::defendFrom(NPC& enemy){
	int damage = calcDmg(enemy.getAtk(), this->getDef());
	this->changeHP(-damage, false);

	string temp = enemy.getType();
	string attacker = temp.substr(0, temp.length() - 3);
	this->notifyDisplay(attacker + " attacks PC!");
}

void ShadePC::nextTurn(){
	this->notifyNPCs();
	this->notifyDisplay();
}

ShadePC::ShadePC(int x, int y, Tile *t) {
	this->setStats(125, 25, 25);
	this->setMaxHP(125);
	this->setType("ShadePC");
	this->setCoords(x,y);
	this->setTile(t);
}

ShadePC::~ShadePC() {}
