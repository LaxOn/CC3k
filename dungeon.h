#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include <vector>
#include <memory>
#include <iostream>
#include "floor.h"

class PC;
class Game;

class Dungeon {
	Game *g;

	int current_floor;

	int size; // number of floors
	std::vector<std::shared_ptr<Floor>> floors; // array of pointers to Floors on the heap

	std::string race;
	std::istream &input;
	
public:
	// constructor and destructor
	Dungeon(int size, Game *g, std::istream &input);
	~Dungeon();

	// accessors and mutators
	int getSize();
	std::shared_ptr<Floor> & getFloor(int whichFloor);

	// other methods
	void constructFloor(std::string race); 
													// Floor construction
													// with input file
	void constructFloor(std::string race, PC *pc);
	void descend(PC *pc);
};

#endif
