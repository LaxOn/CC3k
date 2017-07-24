#include "wall.h"

using namespace std;

// constructor and destructor
Wall::Wall(shared_ptr<BasicTile> base, bool sideWall) :
	TileDecorator{base} {
	setOccupy(true);
	setSideWall(sideWall);
}

Wall::~Wall() {}

// accessors and mutators
shared_ptr<Item> & Wall::getObject() {
	return base->getObject();
}

Tile *Wall::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Wall::addObject(shared_ptr<Item> o) {
	base->addObject(o);
}

void Wall::addNeighbr(Tile *t) {
	base->addNeighbr(t);;
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
