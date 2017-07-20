#include "potion.h"

using namespace std;

// constructor and destructor
Potion() {}

Potion::~Potion() {}

// accessors and mutators
string Potion::getEffect() {
	return effect;
}

void Potion::setEffect(string effect) {
	this->effect = effect;
}

bool Potion::getLifetime() {
	return lifetime;
}

void Potion::resetEffect() {}

// other methods
void Potion::useItem(PC &pc) {}
