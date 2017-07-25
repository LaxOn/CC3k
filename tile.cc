#include <utility>
#include "tile.h"
#include "display.h"
#include "npc.h"
#include "potion.h"
#include "pc.h"

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

void Tile::setDisplay(Display &d) {
	this->d = &d;
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

									// where does display go
void Tile::stealNPC(Tile *t) {			// set tile of npc and its coordinates

	NPCobj = t->getNPC();
	setOccupy(true);
	getNPC()->setTile(this);
	getNPC()->setCoords(x,y);
	//t->resetNPC();
	t->setOccupy(false);
}

void Tile::stealPC(Tile *t) {

	std::cout << "nb tile is : " <<x <<" " <<y <<std::endl;
	PCobj = t->getPC();

	setOccupy(true);
	getPC()->setTile(this);
	getPC()->setCoords(x,y);
	//t->resetPC();

	t->setOccupy(false);
}

void Tile::moveObj(int dir) {
	std::cout << "origin tile is : " <<x <<" " <<y <<std::endl;
	Tile *nb = getNeighbr(dir);

	if (PCobj) nb->stealPC(this);
	else if (NPCobj) nb->stealNPC(this);
	d->update(*this, ".");

	//d->update(*this, s);
	// else throw an exception
}

void Tile::useItemOn(int dir, PC &pc) {
	Tile *nb = getNeighbr(dir);
	nb->useItemTo(pc);
	// kill item
}

void Tile::useItemTo(PC &pc) {
	getObject()->useItem(pc);
	getObject().reset();
	setOccupy(false);
}

void Tile::addNPC(shared_ptr<NPC> npc) {
	NPCobj = npc;

	//d->update(*this, npc->getType());

	//cout << "update is done " << endl;
}

shared_ptr<NPC> Tile::getNPC() {
	return NPCobj;
}

void Tile::addPC(std::shared_ptr<PC> pc) {
	PCobj = pc;
	//d->update(*this, pc->getType());
}

shared_ptr<PC> Tile::getPC() {
	return PCobj;
}
	
shared_ptr<Item> & Tile::getObject() {
	return obj;
}

Tile *Tile::getNeighbr(int index) {
	return neighbours[index];
}

// other methods
void Tile::addObject(shared_ptr<Item> o) {}

void Tile::addNeighbr(Tile *t) {}

void Tile::killObject() {}

int Tile::getType() {
	return -1;
}

void Tile::notifyDisplay() {
	d->update(*this, "?");
}
