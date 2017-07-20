#include "restorehealth.h"

using namespace std;

// constructor and destructor
RestoreHealth::RestoreHealth(BasicPotion *base) :
	PotionDecorator{base}, health{10} {
		lifetime = true;
	}

RestoreHealth::~RestoreHealth() {}

// accessors and mutators
bool RestoreHealth::getLifetime() {
	return lifetime;
} 

void RestoreHealth::resetEffect() {}

int RestoreHealth::getHealth() {
	return health;
}


// other methods
void RestoreHealth::useItem(PC &pc) {
	for (int i = 0; i < health; ++i) {
		if (pc->getHealth() >= pc->getMaxHP()) break;
		pc->changeHealth(1);
	}
}
