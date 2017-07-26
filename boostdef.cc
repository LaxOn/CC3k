#include "boostdef.h"
#include "pc.h"

using namespace std;

// constructor and destructor
BoostDef::BoostDef(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, defense{5} {
		lifetime = false;
		setDisp('P');
	}

BoostDef::~BoostDef() {
	base.reset();
}

// accessors and mutators
bool BoostDef::getLifetime() {
	return lifetime;
} 

int BoostDef::getDefense() {
	return defense;
}


// other methods
void BoostDef::useItem(PC &pc) {
	pc.changeDef(defense);
}
