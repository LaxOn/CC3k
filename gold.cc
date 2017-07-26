#include "gold.h"
#include "pc.h"

using namespace std;

// constructor and destructor
Gold::Gold(int value, int x, int y, bool dragonHoard) :
	dragonHoard{dragonHoard}, npc{nullptr} {
	this->setCoords(x, y);
	this->setValue(value);
	setDisp('G');
}

Gold::~Gold() {}

// accessors and mutators
string Gold::getDescript() {
	return "Gold";
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
	pc.addMoney(value);
}

void Gold::assignNPC(NPC *npc) {
	npc = npc;
}

void Gold::allowPickup() {
	slain = true;
}
