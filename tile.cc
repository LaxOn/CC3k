#include "tile.h"
#include "display.h"

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

void Tile::setOccupy(bool inp) {
	this->occupy = inp;
}

bool Tile::getDragonHoard() {
	return dragonHoard;
}

void Tile::setDragonHoard(bool inp) {
	this->dragonHoard = inp;
}

void Tile::setDisplay(shared_ptr<Display> dply) {
	this->d = d;
}

bool Tile::getSideWall() {
	return sideWall;
}

void Tile::setSideWall(bool b) {
	sideWall = b;
}

int Tile::getChamberID() {
	return chamberID;
}

void Tile::setChamberID(int id) {
	chamberID = id;
}

void Tile::addNPC(std::shared_ptr<NPC> npc) {
	NPCobj = npc;
}

std::shared_ptr<NPC> Tile::getNPC() {
	return NPCobj;
}

void Tile::addPC(std::shared_ptr<PC> pc) {
	PCobj = pc;
}

std::shared_ptr<PC> Tile::getPC() {
	return PCobj;
}
	
shared_ptr<Object> & Tile::getObject(int index) {
	return obj[index];
}

shared_ptr<Tile> & Tile::getNeighbr(int index) {
	return neighbours[index];
}

// other methods
void Tile::addObject(shared_ptr<Object> o) {}

void Tile::addNeighbr(shared_ptr<Tile> t) {}

void Tile::killObject() {}

int Tile::getType() {
	return -1;
}

void Tile::moveObj(int direction) {}

void Tile::notifyDisplay() {
	//d->update(*this, "?");
}
