#include "door.h"

using namespace std;

// constructor and destructor
Door::Door(shared_ptr<BasicTile> base) :
	TileDecorator{base} {}

Door::~Door();

// accessors and mutators
shared_ptr<Object> *& Door::getObject(int index) {
	return base->getObject(index);
}

shared_ptr<Tile> *& Door::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Door::addObject(shared_ptr<Object> o) {
	base->addObject(o);
}

void Door::addNeighbr(shared_ptr<Tile> t) {
	base->addNeighbr(o);;
}

void Door::killObject() {
	base->killObject();
}

void Door::moveObj(int direction) {
	base->moveObj(direction);
}

int Door::getType() {
	return base->getType() + 3;
}
