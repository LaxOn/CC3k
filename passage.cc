#include "passage.h"
#include "info.h"

using namespace std;

// constructor and destructor
Passage::Passage(shared_ptr<BasicTile> base) :
	TileDecorator{base} {
	
	setOccupy(false);
	Info result = base->getInfo();
	setInfo(result.x, result.y);
	
}

Passage::~Passage() {}

// accessors and mutators
shared_ptr<Item> & Passage::getObject() {
	return base->getObject();
}

Tile *Passage::getNeighbr(int index) {
	return base->getNeighbr(index);
}

// other methods
void Passage::addObject(shared_ptr<Item> o) {
	base->addObject(o);
}

void Passage::addNeighbr(Tile *t) {
	base->addNeighbr(t);;
}

void Passage::killObject() {
	base->killObject();
}

int Passage::getType() {
	return base->getType() + 1;
}
