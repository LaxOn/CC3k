#include "passage.h"

using namespace std;

// constructor and destructor
Passage::Passage(shared_ptr<BasicTile> base) :
	TileDecorator{base} {
		setOccupy(false);
	}

Passage::~Passage() {}

// accessors and mutators
shared_ptr<Object> & Passage::getObject() {
	return base->getObject();
}

shared_ptr<Tile> & Passage::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Passage::addObject(shared_ptr<Object> o) {
	base->addObject(o);
}

void Passage::addNeighbr(shared_ptr<Tile> t) {
	base->addNeighbr(t);;
}

void Passage::killObject() {
	base->killObject();
}

void Passage::moveObj(int direction) {
	base->moveObj(direction);
}

int Passage::getType() {
	return base->getType() + 1;
}
