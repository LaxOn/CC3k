#include "dungeon.h"
#include "game.h"
#include "slap.h"
using namespace std;

// constructor and destructor
Dungeon::Dungeon(int size, Game *g, istream &input) :
	g{g}, current_floor{1},
	size{size}, floors{nullptr}, input{input} {}

Dungeon::~Dungeon() {
}

// accessors and mutators
int Dungeon::getSize() {
	return size;
}

shared_ptr<Floor> & Dungeon::getFloor(int whichFloor) {
	return floors[whichFloor];
}

// other methods
void Dungeon::constructFloor(string race) {
	this->race = race;
	floors.emplace_back(make_shared<Floor> (current_floor, this));
	(floors.back())->constructFloor(input, (current_floor - 1)*25, race, nullptr);
}

void Dungeon::constructFloor(string race, PC *pc) {
	++current_floor;
	floors.emplace_back(make_shared<Floor> (current_floor, this));
	(floors.back())->constructFloor(input, (current_floor - 1)*25, race, pc);
}

void Dungeon::descend(PC *pc) {
	if (current_floor < 5) constructFloor(race, pc);
	else throw Slap("Win");
	g->descend();
}
