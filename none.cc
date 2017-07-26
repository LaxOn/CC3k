#include "none.h"

using namespace std;

// constructor and destructor
None::None(shared_ptr<BasicTile> base) :
	TileDecorator{base} {
	setOccupy(true);

	Info result = base->getInfo();
	setInfo(result.x, result.y);
}

None::~None() {}

// accessors and mutators
shared_ptr<Item> & None::getObject() {
	return base->getObject();
}

Tile *None::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void None::addObject(shared_ptr<Item> o) {
	base->addObject(o);
}

void None::addNeighbr(Tile *t) {
	base->addNeighbr(t);;
}

void None::killObject() {
	base->killObject();
}

int None::getType() {
	return base->getType() + 5;
}
