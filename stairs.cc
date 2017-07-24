#include "stairs.h"

using namespace std;

// constructor and destructor
Stairs::Stairs(shared_ptr<BasicTile> base) :
	TileDecorator{base} {
	setOccupy(true);
	Info result = base->getInfo();
	setInfo(result.x, result.y);
}

Stairs::~Stairs() {}

// accessors and mutators
shared_ptr<Item> & Stairs::getObject() {
	return base->getObject();
}

Tile *Stairs::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Stairs::addObject(shared_ptr<Item> o) {
	base->addObject(o);
}

void Stairs::addNeighbr(Tile *t) {
	base->addNeighbr(t);;
}

void Stairs::killObject() {
	base->killObject();
}

void Stairs::moveObj(int direction) {
	base->moveObj(direction);
}

int Stairs::getType() {
	return base->getType() + 2;
}

void Stairs::descend(PC &pc) {
	
}
