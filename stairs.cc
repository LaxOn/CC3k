#include "stairs.h"

using namespace std;

// constructor and destructor
Stairs::Stairs(shared_ptr<BasicTile> base) :
	TileDecorator{base} {}

Stairs::~Stairs();

// accessors and mutators
shared_ptr<Object> *& Stairs::getObject(int index) {
	return base->getObject(index);
}

shared_ptr<Tile> *& Stairs::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Stairs::addObject(shared_ptr<Object> o) {
	base->addObject(o);
}

void Stairs::addNeighbr(shared_ptr<Tile> t) {
	base->addNeighbr(o);;
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