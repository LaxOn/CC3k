#include "basicpotion.h"

using namespace std;

// constructor and destructor
BasicPotion::BasicPotion(int value, string effect, bool lifetime, int x, int y) {
	this->lifetime = lifetime;
	setValue(value);
	setEffect(effect);
	setCoords(x, y);
}

BasicPotion::~BasicPotion() {}

// accessors and mutators
bool BasicPotion::getLifetime() {
	return lifetime;
}

void BasicPotion::resetEffect(PC &pc) {}

// other methods
void BasicPotion::useItem(PC &pc) {}
