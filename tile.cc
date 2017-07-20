#include "tile.h"

using namespace std;

// constructor and destructor
Tile::Tile() {}

Tile::~Tile() {}

// accessors and mutators
Info Tile::getInfo() {
	Info result{x, y};
	return result;
}

void Tile::setInfo(int x, int y) {
	this->x = x;
	this->y = y;
}

bool Tile::getOccupy() {
	return occupy;
}

bool Tile::setOccupy(bool inp) {
	this->occupy = inp;
}

bool Tile::getDragonHoard() {
	return dragonHoard;
}

bool Tile::setDragonHoard(bool inp) {
	this->dragonHoard = inp;
}

void Tile::setDisplay(shared_ptr<Display> dply) {
	this->d = d;
}
	
shared_ptr<Object> *& Tile::getObject(int index) {}

shared_ptr<Tile> *& Tile::getNeighbr(int index) {}

// other methods
void Tile::addObject(shared_ptr<Object> o) {}

void Tile::addNeighbr(shared_ptr<Tile> t) {}

void Tile::killObject() {}

int Tile::getType() {}

void Tile::moveObj(int direction) {}

void Tile::notifyDisplay() {
	d->notify(*this);
}
