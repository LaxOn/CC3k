#include "woundatk.h"
#include "pc.h"

using namespace std;

// constructor and destructor
WoundAtk::WoundAtk(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, attack{-5} {
		lifetime = false;
		setDisp('P');
	}

WoundAtk::~WoundAtk() {
	base.reset();
}

// accessors and mutators
bool WoundAtk::getLifetime() {
	return lifetime;
} 

void WoundAtk::resetEffect(PC &pc) {
	pc.changeAtk(-attack);
}

int WoundAtk::getAttack() {
	return attack;
}


// other methods
void WoundAtk::useItem(PC &pc) {
	pc.changeAtk(attack);
}
