#include "potion.h"

using namespace std;

// constructor and destructor
Potion::Potion() {}

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

void Potion::resetEffect(PC &pc) {}

// other methods
void Potion::useItem(PC &pc) {}
