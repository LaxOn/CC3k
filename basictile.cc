#include "basictile.h"

using namespace std;

// constructor and destructor
BasicTile::BasicTile(int x, int y, std::unique_ptr<Display> dply) {
	setInfo(x, y);
	setOccupy(false);
	setDragonHoard(false);
	setDisplay(d);
}

BasicTile::~BasicTile();

// accessors and mutators
shared_ptr<Object> *& BasicTile::getObject(int index) {
	return obj[i];
}

shared_ptr<Tile> *& BasicTile::getNeighbr(int index) {
	return neighbours[i];
}

// other methods
void BasicTile::addObject(shared_ptr<Object> o) {
	obj.insert(share_ptr<Object>);
	obj[0] = o;
}

void BasicTile::addNeighbr(shared_ptr<Tile> t) {
	neighbours.insert(share_ptr<Tile>);
	neighbours[0] = t;
}

void BasicTile::killObject() {
	obj.pop_back();
}

void BasicTile::moveObj(int direction) {

}

int BasicTile::getType() {
	return 0;
}
