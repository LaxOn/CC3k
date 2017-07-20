#include "poisonhealth.h"

using namespace std;

// constructor and destructor
PoisonHealth::RestoreHealth(BasicPotion *base) :
	PotionDecorator{base}, health{10} {
		lifetime = true;
	}

PoisonHealth::~RestoreHealth() {}

// accessors and mutators
bool PoisonHealth::getLifetime() {
	return lifetime;
} 

void PoisonHealth::resetEffect() {}

int PoisonHealth::getHealth() {
	return health;
}


// other methods
void PoisonHealth::useItem(PC &pc) {
	for (int i = 0; i < health; ++i) {
		if (pc->getHealth() <= 0) break;
		pc->changeHealth(-1);
	}
}

