#include "dungeon.h"

using namespace std;

// constructor and destructor
Dungeon::Dungeon(int size) :
	size{size}, floors{nullptr} {}

Dungeon::~Dungeon() {
	for (int i = 0; i < 5; ++i) floors.pop_back();
}

// accessors and mutators
int Dungeon::getSize() {
	return size;
}

shared_ptr<Floor> & Dungeon::getFloor(int whichFloor) {
	return floors[whichFloor];
}

// other methods

/*
void Dungeon::constructFloor() {
	for (int i = 0; i < 5; ++i) {
		floors.emplace_back(make_shared<Floor> (i + 1));
}
*/

void Dungeon::constructFloor(istream &input) {
	int index = 0;
	for (int i = 0; i < 5; ++i) {
		floors.emplace_back(make_shared<Floor> (i + 1));
		(floors.back())->constructFloor(input, index);
		index += 25;
	}
}
