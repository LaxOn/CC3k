#include "wounddef.h"
#include "pc.h"

using namespace std;

// constructor and destructor
WoundDef::WoundDef(shared_ptr<BasicPotion> base) :
	PotionDecorator{base}, defense{-5} {
		lifetime = false;
		setDisp('P');
	}

WoundDef::~WoundDef() {
	base.reset();
}

// accessors and mutators
bool WoundDef::getLifetime() {
	return lifetime;
} 

void WoundDef::resetEffect(PC &pc) {
	pc.changeDef(-defense);
}

int WoundDef::getDefense() {
	return defense;
}


// other methods
void WoundDef::useItem(PC &pc) {
	pc.changeDef(defense);
}
