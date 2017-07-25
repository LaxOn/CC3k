#include "basictile.h"
#include "display.h"
#include "object.h"

using namespace std;

// constructor and destructor
BasicTile::BasicTile(int x, int y, Display &dply) {
	setInfo(x, y);
	setOccupy(false);
	setDragonHoard(false);
	setDisplay(dply);
}

BasicTile::~BasicTile() {}

// accessors and mutators
shared_ptr<Item> & BasicTile::getObject() {
	return obj;
}

Tile *BasicTile::getNeighbr(int index) {
	return neighbours[index];
}

// other methods
void BasicTile::addObject(shared_ptr<Item> o) {
	obj = o;
	char temp = (this->getObject())->getDisp();
	string s(1, temp);
	d->update(*this, s);
}

void BasicTile::addNeighbr(Tile *t) {
	neighbours.push_back(t);
}

void BasicTile::killObject() {
	obj.reset();
}

int BasicTile::getType() {
	return 0;
}
