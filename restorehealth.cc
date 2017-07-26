#include "restorehealth.h"
#include "pc.h"

using namespace std;

// constructor and destructor
RestoreHealth::RestoreHealth(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, health{10} {
	lifetime = true;
	setDisp('P');
}

RestoreHealth::~RestoreHealth() {
	base.reset();
}

// accessors and mutators
bool RestoreHealth::getLifetime() {
	return lifetime;
} 

int RestoreHealth::getHealth() {
	return health;
}

// other methods
void RestoreHealth::useItem(PC &pc) {
		pc.changeHP(health, true);
}
