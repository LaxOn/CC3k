#include "wall.h"

using namespace std;

// constructor and destructor
Wall::Wall(shared_ptr<BasicTile> base) :
	TileDecorator{base} {}

Wall::~Wall();

// accessors and mutators
shared_ptr<Object> *& Wall::getObject(int index) {
	return base->getObject(index);
}

shared_ptr<Tile> *& Wall::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Wall::addObject(shared_ptr<Object> o) {
	base->addObject(o);
}

void Wall::addNeighbr(shared_ptr<Tile> t) {
	base->addNeighbr(o);;
}

void Wall::killObject() {
	base->killObject();
}

void Wall::moveObj(int direction) {
	base->moveObj(direction);
}

int Wall::getType() {
	return base->getType() + 4;
}
