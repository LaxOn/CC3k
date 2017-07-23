#include "basictile.h"

using namespace std;

// constructor and destructor
BasicTile::BasicTile(int x, int y, shared_ptr<Display> dply) {
	setInfo(x, y);
	setOccupy(false);
	setDragonHoard(false);
	setDisplay(dply);
}

BasicTile::~BasicTile() {}

// accessors and mutators
shared_ptr<Object> & BasicTile::getObject(int index) {
	return obj[index];
}

shared_ptr<Tile> & BasicTile::getNeighbr(int index) {
	return neighbours[index];
}

int BasicTile::getNumObject() {
	return numObject;
}

// other methods
void BasicTile::addObject(shared_ptr<Object> o) {
	if (numObject == 0) {
		obj[0] = o;
	} else {
		obj.push_back(obj[numObject - 1]);
		++numObject;
		obj[0] = o;
	}
}

void BasicTile::addNeighbr(shared_ptr<Tile> t) {
	neighbours.push_back(t);
}

void BasicTile::killObject() {
	obj.pop_back();
}

void BasicTile::moveObj(int direction) {

}

int BasicTile::getType() {
	return 0;
}
