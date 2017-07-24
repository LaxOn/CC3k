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
shared_ptr<Object> & BasicTile::getObject() {
	return obj[0];
}

shared_ptr<Tile> & BasicTile::getNeighbr(int index) {
	return neighbours[index];
}

// other methods
void BasicTile::addObject(shared_ptr<Object> o) {
	obj.resize(1);

	obj[0] = o;

	char temp = (this->getObject())->getDisp();
	string s(1, temp);

	//cout << "the object is " << obj[0]->getDisp() << endl;
	//cout << "the string is " << s << endl;

	//cout << &d << endl;
	d->update(*this, s);
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
