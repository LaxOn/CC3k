#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "character.h"

void Character::setStats(int hp, int atk, int def) {
	this->atk = atk;
	this->def = def;
	this->hp = hp;
}

void Character::setType(std::string type) {
	this->type = type;	
}

void Character::setMaxHP(int max) { hpMax = max; }

void Character::setPotionMult(int max) { potionMult = max; }

}

void Character::healHP(int num) { HP += num; }
void Character::damageHP(int num) { HP -= num; }

int Character::getHP() { return hp; }

int Character::getAtk(){ return atk; }

int Character::getDef() { return def; }

int Character::damageCalc(int aAtk, int dDef) {
	return ceil(((double) 100 / (100 + dDef))*aAtk);
}

std::string Character::getType() { return type; }

void Character::nextTurn() {
	
}

Character::Character() {}

Character::~Character() {}
		
#endif
