#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include <vector>
#include <memory>
#include <iostream>
#include "floor.h"

class Dungeon {
	int size; // number of floors
	std::vector<std::shared_ptr<Floor>> floors; // array of pointers to Floors on the heap

public:
	// constructor and destructor
	Dungeon(int size);
	~Dungeon();

	// accessors and mutators
	int getSize();
	std::shared_ptr<Floor> & getFloor(int whichFloor);

	// other methods
	//void constructFloor(); // Floor construction without input file
	void constructFloor(std::istream &input, int index); 
													// Floor construction
													// with input file
};

#endif
