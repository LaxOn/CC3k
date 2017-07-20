#include "woundatk.h"

using namespace std;

// constructor and destructor
WoundAtk::RestoreHealth(BasicPotion *base) :
	PotionDecorator{base}, attack{-5} {
		lifetime = false;
	}

WoundAtk::~RestoreHealth() {}

// accessors and mutators
bool WoundAtk::getLifetime() {
	return lifetime;
} 

void WoundAtk::resetEffect(PC &pc) {
	pc->changeAtk(-attack);
}

int WoundAtk::getAttack() {
	return attack;
}


// other methods
void WoundAtk::useItem(PC &pc) {
	pc->changeAtk(attack);
}
