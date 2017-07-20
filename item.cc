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

// other methods
void Item::useItem(PC &pc) {};
