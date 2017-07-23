#include "gold.h"
#include "pc.h"

using namespace std;

// constructor and destructor
Gold::Gold(int value, int x, int y, bool dragonHoard) :
	dragonHoard{dragonHoard}, npc{nullptr} {
	this->setCoords(x, y);
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

bool Gold::getSteal() {
	return steal;
}

NPC *& Gold::getNPC() {
	return npc;
}

// other methods
void Gold::useItem(PC &pc) {
	pc.addMoney(value);
}

void Gold::assignNPC(NPC *npc) {
	npc = npc;
}

void Gold::allowPickup() {
	slain = true;
}

void Gold::allowSteal() {
	steal = true;
}