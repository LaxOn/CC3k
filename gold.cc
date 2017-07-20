#include "gold.h"

using namespace std;

// constructor and destructor
Gold(int value, int x, int y, bool dragonHoard) :
	dragonHoard{dragonHoard}, npc{nullptr} {
	this->setCoord(x, y);
	this->setValue(value);
}

Gold::~Gold() {}

// accessors and mutators
std::string Gold::getDescript() {
	return description;
}

bool Gold::getDrgn() {
	return dragonHoard;
}

bool Gold::getSlain() {
	return slain;
}

NPC *& Gold::getNPC() {
	return npc;
}

// other methods
void Gold::useItem(PC &pc) {
	pc->addMoney(value);
}

void Gold::assignNPC(NPC *npc) {
	npc = npc;
}

bool Gold::allowPickup() {
	slain = true;
}

bool Gold::allowSteal() {
	steal = true;
}