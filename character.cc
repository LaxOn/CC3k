#include <string>
#include "character.h"

int Character::ceil(float num) {
    int inum = (int)num;
    if (num == (float)inum) { return inum; }
    return inum + 1;
}

void Character::setStats(int hp, int atk, int def) {
	this->atk = atk;
	this->def = def;
	this->hp = hp;
}

void Character::setType(std::string type) { this->type = type; }

void Character::setMaxHP(int max) { hpMax = max; }

void Character::setPotionMult(int max) { potionMult = max; }

void Character::changeHP(int num, bool forPotion) {
	if (forPotion) hp += potionMult * num;
	else hp += num;
	if (hpMax && (hp > hpMax)) hp = hpMax;
}

void Character::changeAtk(int num) { atk += potionMult * num; }

void Character::changeDef(int num) { def += potionMult * num; }

int Character::getHP() { return hp; }

int Character::getAtk(){ return atk; }

int Character::getDef() { return def; }

int Character::calcDmg(int atk, int def) {
	return ceil(((double) 100 / (100 + def)) * atk);
}

std::string Character::getType() { return type; }

Character::Character() {}

Character::~Character() {}
