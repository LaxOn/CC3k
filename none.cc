#include "none.h"

using namespace std;

// constructor and destructor
None::None(shared_ptr<BasicTile> base) :
	TileDecorator{base} {}

None::~None() {}

// accessors and mutators
shared_ptr<Object> & None::getObject(int index) {
	return base->getObject(index);
}

shared_ptr<Tile> & None::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void None::addObject(shared_ptr<Object> o) {
	base->addObject(o);
}

void None::addNeighbr(shared_ptr<Tile> t) {
	base->addNeighbr(t);;
}

void None::killObject() {
	base->killObject();
}

void None::moveObj(int direction) {
	base->moveObj(direction);
}

int None::getType() {
	return base->getType() + 5;
}
