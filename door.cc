#include "door.h"

using namespace std;

// constructor and destructor
Door::Door(shared_ptr<BasicTile> base) :
	TileDecorator{base} {
	setOccupy(false);
	Info result = base->getInfo();
	setInfo(result.x, result.y);
}

Door::~Door() {}

// accessors and mutators
shared_ptr<Item> & Door::getObject() {
	return base->getObject();
}

Tile *Door::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Door::addObject(shared_ptr<Item> o) {
	base->addObject(o);
}

void Door::addNeighbr(Tile *t) {
	base->addNeighbr(t);;
}

void Door::killObject() {
	base->killObject();
}


int Door::getType() {
	return base->getType() + 3;
}
