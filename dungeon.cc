#include "dungeon.h"

using namespace std;

// constructor and destructor
Dungeon::Dungeon(int size) :
	size{size}, floors{nullptr} {}

Dungeon::~Dungeon() {
	for (int i = 0; i < 5; ++i) floors.pop();
}

// accessors and mutators
int getSize() {
	return size;
}

shared_ptr<Floor> & getFloor(int whichFloor) {
	return floor[i];
}

// other methods
void constructFloor() {
	for (int i = 0; i < 5; ++i) {
		floors.emplace_back(shared_ptr<Floor> f = make_shared(Floor()));
}

void constructFloor(istream &input) {
	int index = 0;
	for (int i = 0; i < 5; ++i) {
		floors.emplace_back(shared_ptr<Floor> f = make_shared(Floor()));
		(floors.back())->constructFloor(input, index);
		index += 25;
	}
}
