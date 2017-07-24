#include "boostatk.h"
#include "pc.h"

using namespace std;

// constructor and destructor
BoostAtk::BoostAtk(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, attack{5} {
		lifetime = false;
		setDisp('P');
	}

BoostAtk::~BoostAtk() {
	base.reset();
}

// accessors and mutators
bool BoostAtk::getLifetime() {
	return lifetime;
} 

void BoostAtk::resetEffect(PC &pc) {
	pc.changeAtk(-attack);
}

int BoostAtk::getAttack() {
	return attack;
}


// other methods
void BoostAtk::useItem(PC &pc) {
	pc.changeAtk(attack);
}
