#include "wounddef.h"

using namespace std;

// constructor and destructor
WoundDef::RestoreHealth(BasicPotion *base) :
	PotionDecorator{base}, defense{-5} {
		lifetime = false;
	}

WoundDef::~RestoreHealth() {}

// accessors and mutators
bool WoundDef::getLifetime() {
	return lifetime;
} 

void WoundDef::resetEffect(PC &pc) {
	pc->changeDef(-defense);
}

int WoundDef::getDefense() {
	return defense;
}


// other methods
void WoundDef::useItem(PC &pc) {
	pc->changeDef(defense);
}
