#include "boostatk.h"

using namespace std;

// constructor and destructor
BoostAtk::RestoreHealth(BasicPotion *base) :
	PotionDecorator{base}, attack{5} {
		lifetime = false;
	}

BoostAtk::~RestoreHealth() {}

// accessors and mutators
bool BoostAtk::getLifetime() {
	return lifetime;
} 

void BoostAtk::resetEffect(PC &pc) {
	pc->changeAtk(-attack);
}

int BoostAtk::getAttack() {
	return attack;
}


// other methods
void BoostAtk::useItem(PC &pc) {
	pc->changeAtk(attack);
}

