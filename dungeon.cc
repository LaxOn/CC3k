#include "dungeon.h"

using namespace std;

// constructor and destructor
Dungeon::Dungeon(int size) :
	size{size}, floors{new Floor*[5]} {}

Dungeon::~Dungeon() {
	for (int i = 0; i < 5; ++i) delete floors[i];

	delete[] floors;
}

// accessors and mutators
int getSize() {
	return size;
}

Floor *& getFloor(int whichFloor) {
	return floor[i];
}

// other methods
void constructFloor() {
	for (int i = 0; i < 5; ++i) floors[i] = new Floor;
}
