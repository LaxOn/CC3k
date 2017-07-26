#include "poisonhealth.h"
#include "pc.h"

using namespace std;

// constructor and destructor
PoisonHealth::PoisonHealth(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, health{-10} {
		lifetime = true;
		setDisp('P');
	}

PoisonHealth::~PoisonHealth() {
	base.reset();
}

// accessors and mutators
bool PoisonHealth::getLifetime() {
	return lifetime;
} 

int PoisonHealth::getHealth() {
	return health;
}


// other methods
void PoisonHealth::useItem(PC &pc) {
		pc.changeHP(health, true);
}
