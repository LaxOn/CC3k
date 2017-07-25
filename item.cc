#include "item.h"

using namespace std;

// constructor and destructor
Item::Item() {}

Item::~Item() {}

// accessors and mutators
int Item::getValue() {
	return value;
}

void Item::setValue(int value) {
	this->value = value;
}

bool Item::getDrgn() { return false; }
bool Item::getSlain() { return false; }

// other methods
void Item::useItem(PC &pc) {};

void Item::allowPickup() {}
