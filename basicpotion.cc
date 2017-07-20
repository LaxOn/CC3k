#include "basicpotion.h"

using namespace std;

// constructor and destructor
BasicPotion::BasicPotion(int value, string effect, int x, int y) :
	lifetime{false} {
	setValue(value);
	setEffect(effect);
	setCoord(x, y);
}

BasicPotion::~BasicPotion();

// accessors and mutators
bool BasicPotion::getLifetime() {
	return lifetime;
}

void BasicPotion::resetEffect() {}

// other methods
void BasicPotion::useItem(PC &pc) {}
